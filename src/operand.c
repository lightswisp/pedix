#include <pedix/operand.h>
#include <pedix/defines.h>
#include <pedix/iutils.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

const char *modrm_reg8[]           = {"al", "cl", "dl", "bl", "ah", "ch", "dh", "bh"};
const char *modrm_reg16[]          = {"ax", "cx", "dx", "bx", "sp", "bp", "si", "di"};
const char *modrm_reg32[]          = {"eax", "ecx", "edx", "ebx", "esp", "ebp", "esi", "edi"};
const char *modrm_reg16_override[] = {"bx+si", "bx+di", "bp+si", "bp+di", "si", "di", "bp", "bx"};
const char *st_reg[]               = {"st0", "st1", "st2", "st3", "st4", "st5", "st6", "st7"};

#define GET_SIGN(value, size) ( (value & (0x80 << (size - 8))) >> (size - 1) == 1 ? 0x2d : 0x2b )
#define GET_VALUE_BY_SIGN(value, sign) ( sign == 0x2d ? ~value + 1 : value )

#define MOD_REGISTER_ADDRESSING 3
#define MOD_FOUR_BYTE_DISPLACEMENT 2
#define MOD_ONE_BYTE_DISPLACEMENT 1
#define MOD_SIB_OR_REGISTER_INDIRECT_ADDRESSING 0

#define MOD_NO_DISPLACEMENT_EXCEPT_110 0
#define MOD_TWO_BYTE_DISPLACEMENT 2

static void pedix_set_operand_m(decoded_instruction_t *decoded, char* dst){
  char sign;
  uint32_t value;
  if (decoded->address_size == WORD_LEN) {
    switch(decoded->modrm.mod){
      case MOD_NO_DISPLACEMENT_EXCEPT_110: 
       if(decoded->modrm.rm == 6)
         sprintf(dst, 
                 FMT_DISPLACEMENT_ONLY_MODE_ASZ_OVERRIDE,
                 decoded->ptr_text,
                 decoded->segment_text,
                 (uint16_t)decoded->displacement.field);
       else 
         sprintf(dst, 
                 FMT_INDIRECT_ADDRESSING_OP,
                 decoded->ptr_text,
                 decoded->segment_text,
                 modrm_reg16_override[decoded->modrm.rm]);
       break; 
      case MOD_ONE_BYTE_DISPLACEMENT: 
       sign = GET_SIGN((uint8_t)decoded->displacement.field, 8);
       value = GET_VALUE_BY_SIGN((uint8_t)decoded->displacement.field, sign);
       sprintf(dst, 
               FMT_ONE_BYTE_DISPLACEMENT_ASZ_OVERRIDE, 
               decoded->ptr_text,
               decoded->segment_text, 
               modrm_reg16_override[decoded->modrm.rm],
               sign, 
               (uint8_t)value);
       break;
      case MOD_TWO_BYTE_DISPLACEMENT:
       sign = GET_SIGN((uint16_t)decoded->displacement.field, 16);
       value = GET_VALUE_BY_SIGN((uint16_t)decoded->displacement.field, sign);
       sprintf(dst, 
               FMT_TWO_BYTE_DISPLACEMENT_ASZ_OVERRIDE, 
               decoded->ptr_text,
               decoded->segment_text, 
               modrm_reg16_override[decoded->modrm.rm],
               sign, 
               (uint16_t)value);
       break;
      default:
       assert(!"fatal error, memory operand can't have register addressing");
    } 
  } else {
    switch (decoded->modrm.mod) {
    case MOD_SIB_OR_REGISTER_INDIRECT_ADDRESSING:
      if (decoded->sib.size) {
        if (decoded->sib.base == 5) {
          sign = GET_SIGN((uint32_t)decoded->displacement.field, 32);
          value = GET_VALUE_BY_SIGN((uint32_t)decoded->displacement.field, sign);

          sprintf(dst, 
                  FMT_SIB_FOUR_BYTE_DISP_NO_REG_ADDRESSING_OP,
                  decoded->ptr_text, 
                  decoded->segment_text,
                  modrm_reg32[decoded->sib.index], 
                  1 << decoded->sib.scale,
                  sign, 
                  value);
        } else {
          if (decoded->sib.index == 4) {
            sprintf(dst, 
                    FMT_SIB_FOUR_BYTE_NO_DISP_NO_SCALE_ADDRESSING_OP,
                    decoded->ptr_text, 
                    decoded->segment_text,
                    modrm_reg32[decoded->sib.base]);
          } else {
            sprintf(dst, 
                    FMT_SIB_FOUR_BYTE_NO_DISP_ADDRESSING_OP,
                    decoded->ptr_text, 
                    decoded->segment_text,
                    modrm_reg32[decoded->sib.base],
                    modrm_reg32[decoded->sib.index], 
                    1 << decoded->sib.scale);
          }
        }
      } else {
        if (decoded->modrm.rm == 5)
          sprintf(dst, 
                  FMT_DISPLACEMENT_ONLY_MODE, 
                  decoded->ptr_text,
                  decoded->segment_text,
                  (uint32_t)decoded->displacement.field);
        else
          sprintf(dst, 
                  FMT_INDIRECT_ADDRESSING_OP, 
                  decoded->ptr_text,
                  decoded->segment_text, 
                  modrm_reg32[decoded->modrm.rm]);
      }
      break;
    case MOD_ONE_BYTE_DISPLACEMENT:
      if (decoded->sib.size) {
        if (decoded->sib.index == 4) {
          sign = GET_SIGN((uint8_t)decoded->displacement.field, 8);
          value = GET_VALUE_BY_SIGN((uint8_t)decoded->displacement.field, sign);

          sprintf(dst, 
                  FMT_SIB_ONE_BYTE_DISP_NO_SCALE_ADDRESSING_OP,
                  decoded->ptr_text, 
                  decoded->segment_text,
                  modrm_reg32[decoded->sib.base], 
                  sign, 
                  (uint8_t)value);
        } else {
          sign = GET_SIGN((uint8_t)decoded->displacement.field, 8);
          value = GET_VALUE_BY_SIGN((uint8_t)decoded->displacement.field, sign);

          sprintf(dst, 
                  FMT_SIB_ONE_BYTE_DISP_ADDRESSING_OP, 
                  decoded->ptr_text,
                  decoded->segment_text, 
                  modrm_reg32[decoded->sib.base],
                  modrm_reg32[decoded->sib.index], 
                  1 << decoded->sib.scale,
                  sign, 
                  (uint8_t)value);
        }
      } else {
        sign = GET_SIGN((uint8_t)decoded->displacement.field, 8);
        value = GET_VALUE_BY_SIGN((uint8_t)decoded->displacement.field, sign);

        sprintf(dst, 
                FMT_ONE_BYTE_DISP_ADDRESSING_OP, 
                decoded->ptr_text,
                decoded->segment_text, 
                modrm_reg32[decoded->modrm.rm], 
                sign,
                (uint8_t)value);
      }
      break;
    case MOD_FOUR_BYTE_DISPLACEMENT:
      if (decoded->sib.size) {
        if (decoded->sib.index == 4) {
          sign = GET_SIGN((uint32_t)decoded->displacement.field, 32);
          value = GET_VALUE_BY_SIGN((uint32_t)decoded->displacement.field, sign);

          sprintf(dst, 
                  FMT_SIB_FOUR_BYTE_DISP_NO_SCALE_ADDRESSING_OP,
                  decoded->ptr_text, 
                  decoded->segment_text,
                  modrm_reg32[decoded->sib.base], 
                  sign, 
                  value);
        } else {
          sign = GET_SIGN((uint32_t)decoded->displacement.field, 32);
          value = GET_VALUE_BY_SIGN((uint32_t)decoded->displacement.field, sign);

          sprintf(dst, 
                  FMT_SIB_FOUR_BYTE_DISP_ADDRESSING_OP, 
                  decoded->ptr_text,
                  decoded->segment_text, 
                  modrm_reg32[decoded->sib.base],
                  modrm_reg32[decoded->sib.index], 
                  1 << decoded->sib.scale,
                  sign, 
                  value);
        }
      } else {
        sign = GET_SIGN((uint32_t)decoded->displacement.field, 32);
        value = GET_VALUE_BY_SIGN((uint32_t)decoded->displacement.field, sign);

        sprintf(dst, 
                FMT_FOUR_BYTE_DISP_ADDRESSING_OP,
                decoded->ptr_text,
                decoded->segment_text, 
                modrm_reg32[decoded->modrm.rm], 
                sign,
                value);
      }
      break;
    default:
      assert(!"fatal error, memory operand can't have register addressing");
    }
  }
}

static void pedix_set_operand_rm(decoded_instruction_t *decoded, char* dst){
  char sign;
  uint32_t value;
  if (decoded->address_size == WORD_LEN) {
    switch(decoded->modrm.mod){
      case MOD_NO_DISPLACEMENT_EXCEPT_110: 
       if(decoded->modrm.rm == 6)
         sprintf(dst, 
                 FMT_DISPLACEMENT_ONLY_MODE_ASZ_OVERRIDE,
                 decoded->ptr_text,
                 decoded->segment_text,
                 (uint16_t)decoded->displacement.field);
       else 
         sprintf(dst, 
                 FMT_INDIRECT_ADDRESSING_OP,
                 decoded->ptr_text,
                 decoded->segment_text,
                 modrm_reg16_override[decoded->modrm.rm]);
       break; 
      case MOD_ONE_BYTE_DISPLACEMENT: 
       sign = GET_SIGN((uint8_t)decoded->displacement.field, 8);
       value = GET_VALUE_BY_SIGN((uint8_t)decoded->displacement.field, sign);
       sprintf(dst, 
               FMT_ONE_BYTE_DISPLACEMENT_ASZ_OVERRIDE, 
               decoded->ptr_text,
               decoded->segment_text, 
               modrm_reg16_override[decoded->modrm.rm],
               sign, 
               (uint8_t)value);
       break;
      case MOD_TWO_BYTE_DISPLACEMENT:
       sign = GET_SIGN((uint16_t)decoded->displacement.field, 16);
       value = GET_VALUE_BY_SIGN((uint16_t)decoded->displacement.field, sign);
       sprintf(dst, 
               FMT_TWO_BYTE_DISPLACEMENT_ASZ_OVERRIDE, 
               decoded->ptr_text,
               decoded->segment_text, 
               modrm_reg16_override[decoded->modrm.rm],
               sign, 
               (uint16_t)value);
       break;
      case MOD_REGISTER_ADDRESSING:
       switch (decoded->operand_size) {
       case BYTE_LEN:
         strcpy(dst, modrm_reg8[decoded->modrm.rm]);
         break;
       case WORD_LEN:
         strcpy(dst, modrm_reg16[decoded->modrm.rm]);
         break;
       case DOUBLEWORD_LEN:
         strcpy(dst, modrm_reg32[decoded->modrm.rm]);
         break;
       default:
         assert(!"unsupported operand size!");
       }
       break;
    } 
  } else {
    switch (decoded->modrm.mod) {
    case MOD_SIB_OR_REGISTER_INDIRECT_ADDRESSING:
      if (decoded->sib.size) {
        if (decoded->sib.base == 5) {
          sign = GET_SIGN((uint32_t)decoded->displacement.field, 32);
          value = GET_VALUE_BY_SIGN((uint32_t)decoded->displacement.field, sign);

          sprintf(dst, 
                  FMT_SIB_FOUR_BYTE_DISP_NO_REG_ADDRESSING_OP,
                  decoded->ptr_text, 
                  decoded->segment_text,
                  modrm_reg32[decoded->sib.index], 
                  1 << decoded->sib.scale,
                  sign, 
                  value);
        } else {
          if (decoded->sib.index == 4) {
            sprintf(dst, 
                    FMT_SIB_FOUR_BYTE_NO_DISP_NO_SCALE_ADDRESSING_OP,
                    decoded->ptr_text, 
                    decoded->segment_text,
                    modrm_reg32[decoded->sib.base]);
          } else {
            sprintf(dst, 
                    FMT_SIB_FOUR_BYTE_NO_DISP_ADDRESSING_OP,
                    decoded->ptr_text, 
                    decoded->segment_text,
                    modrm_reg32[decoded->sib.base],
                    modrm_reg32[decoded->sib.index], 
                    1 << decoded->sib.scale);
          }
        }
      } else {
        if (decoded->modrm.rm == 5)
          sprintf(dst, 
                  FMT_DISPLACEMENT_ONLY_MODE, 
                  decoded->ptr_text,
                  decoded->segment_text,
                  (uint32_t)decoded->displacement.field);
        else
          sprintf(dst, 
                  FMT_INDIRECT_ADDRESSING_OP, 
                  decoded->ptr_text,
                  decoded->segment_text, 
                  modrm_reg32[decoded->modrm.rm]);
      }
      break;
    case MOD_ONE_BYTE_DISPLACEMENT:
      if (decoded->sib.size) {
        if (decoded->sib.index == 4) {
          sign = GET_SIGN((uint8_t)decoded->displacement.field, 8);
          value = GET_VALUE_BY_SIGN((uint8_t)decoded->displacement.field, sign);

          sprintf(dst, 
                  FMT_SIB_ONE_BYTE_DISP_NO_SCALE_ADDRESSING_OP,
                  decoded->ptr_text, 
                  decoded->segment_text,
                  modrm_reg32[decoded->sib.base], 
                  sign, 
                  (uint8_t)value);
        } else {
          sign = GET_SIGN((uint8_t)decoded->displacement.field, 8);
          value = GET_VALUE_BY_SIGN((uint8_t)decoded->displacement.field, sign);

          sprintf(dst, 
                  FMT_SIB_ONE_BYTE_DISP_ADDRESSING_OP, 
                  decoded->ptr_text,
                  decoded->segment_text, 
                  modrm_reg32[decoded->sib.base],
                  modrm_reg32[decoded->sib.index], 
                  1 << decoded->sib.scale,
                  sign, 
                  (uint8_t)value);
        }
      } else {
        sign = GET_SIGN((uint8_t)decoded->displacement.field, 8);
        value = GET_VALUE_BY_SIGN((uint8_t)decoded->displacement.field, sign);

        sprintf(dst, 
                FMT_ONE_BYTE_DISP_ADDRESSING_OP, 
                decoded->ptr_text,
                decoded->segment_text, 
                modrm_reg32[decoded->modrm.rm], 
                sign,
                (uint8_t)value);
      }
      break;
    case MOD_FOUR_BYTE_DISPLACEMENT:
      if (decoded->sib.size) {
        if (decoded->sib.index == 4) {
          sign = GET_SIGN((uint32_t)decoded->displacement.field, 32);
          value = GET_VALUE_BY_SIGN((uint32_t)decoded->displacement.field, sign);

          sprintf(dst, 
                  FMT_SIB_FOUR_BYTE_DISP_NO_SCALE_ADDRESSING_OP,
                  decoded->ptr_text, 
                  decoded->segment_text,
                  modrm_reg32[decoded->sib.base], 
                  sign, 
                  value);
        } else {
          sign = GET_SIGN((uint32_t)decoded->displacement.field, 32);
          value = GET_VALUE_BY_SIGN((uint32_t)decoded->displacement.field, sign);

          sprintf(dst, 
                  FMT_SIB_FOUR_BYTE_DISP_ADDRESSING_OP, 
                  decoded->ptr_text,
                  decoded->segment_text, 
                  modrm_reg32[decoded->sib.base],
                  modrm_reg32[decoded->sib.index], 
                  1 << decoded->sib.scale,
                  sign, 
                  value);
        }
      } else {
        sign = GET_SIGN((uint32_t)decoded->displacement.field, 32);
        value = GET_VALUE_BY_SIGN((uint32_t)decoded->displacement.field, sign);

        sprintf(dst, 
                FMT_FOUR_BYTE_DISP_ADDRESSING_OP,
                decoded->ptr_text,
                decoded->segment_text, 
                modrm_reg32[decoded->modrm.rm], 
                sign,
                value);
      }
      break;
    case MOD_REGISTER_ADDRESSING:
      switch(decoded->operand_size){
        case BYTE_LEN: 
          strcpy(dst, modrm_reg8[decoded->modrm.rm]);
          break;
        case WORD_LEN: 
          strcpy(dst, modrm_reg16[decoded->modrm.rm]);
          break;
        case DOUBLEWORD_LEN: 
          strcpy(dst, modrm_reg32[decoded->modrm.rm]);
          break;
        default: 
          assert(!"unsupported operand size!");
      }
      break;
    }
  }
}

static void pedix_set_operand_by_id32(decoded_instruction_t *decoded, __operand_t id, char* dst){
  switch (id) {
  case OPERAND_IMM_8: 
    sprintf(dst, OPERAND_BYTE, (uint8_t)decoded->imm);
    break;
  case OPERAND_IMM_16: 
    sprintf(dst, OPERAND_WORD, (uint16_t)decoded->imm);
    break;
  case OPERAND_IMM_32: 
    sprintf(dst, OPERAND_DWORD, (uint32_t)decoded->imm);
    break;
  case OPERAND_IMM_16_32:
    if (decoded->operand_size == WORD_LEN)
      sprintf(dst, OPERAND_WORD, (uint16_t)decoded->imm);
    else 
      sprintf(dst, OPERAND_DWORD, (uint32_t)decoded->imm);
    break;
  case OPERAND_REG_EAX: 
    if (decoded->operand_size == WORD_LEN)
      strcpy(dst, "ax");
    else 
      strcpy(dst, "eax");
    break;
  case OPERAND_REG_AL: 
    strcpy(dst, "al");
    break;
  case OPERAND_ONE: 
    strcpy(dst, "1");
    break;
  case OPERAND_RM_8:
    strcpy(decoded->ptr_text, "BYTE PTR");
    pedix_set_operand_rm(decoded, dst);
    break;
  case OPERAND_R_8:
    strcpy(dst, modrm_reg8[decoded->modrm.reg]);
    break;
  case OPERAND_R_16: 
    strcpy(dst, modrm_reg16[decoded->modrm.reg]);
    break;
  case OPERAND_R_32: 
    strcpy(dst, modrm_reg32[decoded->modrm.reg]);
    break;
  case OPERAND_RM_16_32:
    if (decoded->operand_size == WORD_LEN) {
      strcpy(decoded->ptr_text, "WORD PTR");
      pedix_set_operand_rm(decoded, dst);
    } else {
      strcpy(decoded->ptr_text, "DWORD PTR");
      pedix_set_operand_rm(decoded, dst);
    }
    break;
  case OPERAND_R_16_32:
    if (decoded->operand_size == WORD_LEN)
      strcpy(dst, modrm_reg16[decoded->modrm.reg]);
    else
      strcpy(dst, modrm_reg32[decoded->modrm.reg]);
    break;
  case OPERAND_M_8:
    strcpy(decoded->ptr_text, "BYTE PTR");
    pedix_set_operand_m(decoded, dst);
    break;
  case OPERAND_M_16: 
    strcpy(decoded->ptr_text, "WORD PTR");
    pedix_set_operand_m(decoded, dst);
    break;
  case OPERAND_M_ALL:
    strcpy(decoded->ptr_text, "DWORD PTR");
    pedix_set_operand_m(decoded, dst);
    break;
  case OPERAND_REL_8:
    sprintf(dst, OPERAND_BYTE, (uint8_t)decoded->rel);
    break;
  case OPERAND_REL_16_32:
    if (decoded->operand_size == WORD_LEN)
      sprintf(dst, OPERAND_WORD, (uint16_t)decoded->rel);
    else
      sprintf(dst, OPERAND_DWORD, (uint32_t)decoded->rel);
    break;
  case R_PLUS_8:
    strcpy(dst, modrm_reg8[decoded->instruction->primary_opcode & 0x07]);
    break;
  case R_PLUS_16_32:
    if (decoded->operand_size == WORD_LEN)
      strcpy(dst, modrm_reg16[decoded->instruction->primary_opcode & 0x07]);
    else
      strcpy(dst, modrm_reg32[decoded->instruction->primary_opcode & 0x07]);
    break;
  case OPERAND_MOFFS_32:
    sprintf(dst, FMT_MOFFS, decoded->segment_text, decoded->moffs);
    break;
  case OPERAND_M_32: 
    strcpy(decoded->ptr_text, "DWORD PTR");
    pedix_set_operand_m(decoded, dst);
    break;
  case OPERAND_REG_ST: 
    strcpy(dst, "st");
    break;
  case OPERAND_REG_STI: 
    strcpy(dst, st_reg[decoded->instruction->secondary_opcode & 0x07]);
    break;

  default:
    printf("id not implemented: %d\n", id);
    assert(!"not yet implemented");
  }
}

static void pedix_set_operands32(decoded_instruction_t *decoded) {
  // operand1 is assumed to be present
  for(size_t i = 0; i < decoded->instruction->operands.size; i++){
    if(decoded->instruction->operands.operand[i] == OPERAND_VOID)
      break;

    pedix_set_operand_by_id32(decoded, decoded->instruction->operands.operand[i], decoded->operands[i]);
  }
}

static void pedix_set_operands64(decoded_instruction_t *decoded) {
  // todo
  assert(!"pedix_set_operands64 is not implemented yet!");
}

void pedix_merge_operands(decoded_instruction_t *decoded) {
  if (decoded->instruction->operands.operand[0] != OPERAND_VOID){
      // add space
      decoded->text[strlen(decoded->text)] = 0x20;
      strcat(decoded->text, decoded->operands[0]);
  }

  for(size_t i = 1; i < decoded->instruction->operands.size; i++){
      decoded->text[strlen(decoded->text)] = 0x2c;
      strcat(decoded->text, decoded->operands[i]);
  }
}

/*
 * general-purpose function that cares only about bit depth
 */
void pedix_set_operands(decoded_instruction_t *decoded) {
  switch (decoded->mode) {
  case MODE_32:
      pedix_set_operands32(decoded);
      break;
  case MODE_64:
      pedix_set_operands64(decoded);
      break;
  default:
      assert(!"illegal mode selected");
  }
}
