#include <pedix/operand.h>
#include <pedix/defines.h>
#include <pedix/iutils.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

const char *modrm_reg8[]  = {"al", "cl", "dl", "bl", "ah", "ch", "dh", "bh"};
const char *modrm_reg16[] = {"ax", "cx", "dx", "bx", "sp", "bp", "si", "di"};
const char *modrm_reg32[] = {"eax", "ecx", "edx", "ebx", "esp", "ebp", "esi", "edi"};

#define GET_SIGN(value, size) ( (value & (0x80 << (size - 8))) >> (size - 1) == 1 ? 0x2d : 0x2b )
#define GET_VALUE_BY_SIGN(value, sign) ( sign == 0x2d ? ~value + 1 : value )

#define MOD_REGISTER_ADDRESSING 3
#define MOD_FOUR_BYTE_DISPLACEMENT 2
#define MOD_ONE_BYTE_DISPLACEMENT 1
#define MOD_SIB_OR_REGISTER_INDIRECT_ADDRESSING 0

// M only

#define SET_OPERAND_M_BY_SIZE(SZ)                                              \
  switch (decoded->modrm.mod) {                                                \
  case MOD_SIB_OR_REGISTER_INDIRECT_ADDRESSING:                                \
    if (decoded->sib.size) {                                                   \
      if (decoded->sib.base == 5) {                                            \
        char sign = GET_SIGN((uint32_t)decoded->displacement.field, 32);       \
        uint32_t value =                                                       \
            GET_VALUE_BY_SIGN((uint32_t)decoded->displacement.field, sign);    \
                                                                               \
        sprintf(dst, SIB_FOUR_BYTE_DISP_NO_REG_ADDRESSING_OP##SZ,              \
                decoded->segment_text, modrm_reg32[decoded->sib.index],        \
                1 << decoded->sib.scale, sign, value);                         \
      } else {                                                                 \
        if (decoded->sib.index == 4) {                                         \
          sprintf(dst, SIB_FOUR_BYTE_NO_DISP_NO_SCALE_ADDRESSING_OP##SZ,       \
                  decoded->segment_text, modrm_reg32[decoded->sib.base]);      \
        } else {                                                               \
          sprintf(dst, SIB_FOUR_BYTE_NO_DISP_ADDRESSING_OP##SZ,                \
                  decoded->segment_text, modrm_reg32[decoded->sib.base],       \
                  modrm_reg32[decoded->sib.index], 1 << decoded->sib.scale);   \
        }                                                                      \
      }                                                                        \
    } else {                                                                   \
      if (decoded->modrm.rm == 5)                                              \
        sprintf(dst, DISPLACEMENT_ONLY_MODE, decoded->segment_text,            \
                (uint32_t)decoded->displacement.field);                        \
      else                                                                     \
        sprintf(dst, INDIRECT_ADDRESSING_OP##SZ, decoded->segment_text,        \
                modrm_reg32[decoded->modrm.rm]);                               \
    }                                                                          \
    break;                                                                     \
  case MOD_ONE_BYTE_DISPLACEMENT:                                              \
    if (decoded->sib.size) {                                                   \
      if (decoded->sib.index == 4) {                                           \
        char sign = GET_SIGN((uchar8_t)decoded->displacement.field, 8);        \
        uchar8_t value =                                                       \
            GET_VALUE_BY_SIGN((uchar8_t)decoded->displacement.field, sign);    \
                                                                               \
        sprintf(dst, SIB_ONE_BYTE_DISP_NO_SCALE_ADDRESSING_OP##SZ,             \
                decoded->segment_text, modrm_reg32[decoded->sib.base], sign,   \
                value);                                                        \
      } else {                                                                 \
        char sign = GET_SIGN((uchar8_t)decoded->displacement.field, 8);        \
        uchar8_t value =                                                       \
            GET_VALUE_BY_SIGN((uchar8_t)decoded->displacement.field, sign);    \
                                                                               \
        sprintf(dst, SIB_ONE_BYTE_DISP_ADDRESSING_OP##SZ,                      \
                decoded->segment_text, modrm_reg32[decoded->sib.base],         \
                modrm_reg32[decoded->sib.index], 1 << decoded->sib.scale,      \
                sign, value);                                                  \
      }                                                                        \
    } else {                                                                   \
      char sign = GET_SIGN((uint8_t)decoded->displacement.field, 8);           \
      uint8_t value =                                                          \
          GET_VALUE_BY_SIGN((uint8_t)decoded->displacement.field, sign);       \
                                                                               \
      sprintf(dst, ONE_BYTE_DISP_ADDRESSING_OP##SZ, decoded->segment_text,     \
              modrm_reg32[decoded->modrm.rm], sign, value);                    \
    }                                                                          \
    break;                                                                     \
  case MOD_FOUR_BYTE_DISPLACEMENT:                                             \
    if (decoded->sib.size) {                                                   \
      if (decoded->sib.index == 4) {                                           \
        char sign = GET_SIGN((uint32_t)decoded->displacement.field, 32);       \
        uint32_t value =                                                       \
            GET_VALUE_BY_SIGN((uint32_t)decoded->displacement.field, sign);    \
                                                                               \
        sprintf(dst, SIB_FOUR_BYTE_DISP_NO_SCALE_ADDRESSING_OP##SZ,            \
                decoded->segment_text, modrm_reg32[decoded->sib.base], sign,   \
                value);                                                        \
      } else {                                                                 \
        char sign = GET_SIGN((uint32_t)decoded->displacement.field, 32);       \
        uint32_t value =                                                       \
            GET_VALUE_BY_SIGN((uint32_t)decoded->displacement.field, sign);    \
                                                                               \
        sprintf(dst, SIB_FOUR_BYTE_DISP_ADDRESSING_OP##SZ,                     \
                decoded->segment_text, modrm_reg32[decoded->sib.base],         \
                modrm_reg32[decoded->sib.index], 1 << decoded->sib.scale,      \
                sign, value);                                                  \
      }                                                                        \
    } else {                                                                   \
      char sign = GET_SIGN((uint32_t)decoded->displacement.field, 32);         \
      uint32_t value =                                                         \
          GET_VALUE_BY_SIGN((uint32_t)decoded->displacement.field, sign);      \
                                                                               \
      sprintf(dst, FOUR_BYTE_DISP_ADDRESSING_OP##SZ, decoded->segment_text,    \
              modrm_reg32[decoded->modrm.rm], sign, value);                    \
    }                                                                          \
    break;                                                                     \
  }

// RM only

#define SET_OPERAND_RM_BY_SIZE(SZ)                                             \
  switch (decoded->modrm.mod) {                                                \
  case MOD_SIB_OR_REGISTER_INDIRECT_ADDRESSING:                                \
    if (decoded->sib.size) {                                                   \
      if (decoded->sib.base == 5) {                                            \
        char sign = GET_SIGN((uint32_t)decoded->displacement.field, 32);       \
        uint32_t value =                                                       \
            GET_VALUE_BY_SIGN((uint32_t)decoded->displacement.field, sign);    \
                                                                               \
        sprintf(dst, SIB_FOUR_BYTE_DISP_NO_REG_ADDRESSING_OP##SZ,              \
                decoded->segment_text, modrm_reg32[decoded->sib.index],        \
                1 << decoded->sib.scale, sign, value);                         \
      } else {                                                                 \
        if (decoded->sib.index == 4) {                                         \
          sprintf(dst, SIB_FOUR_BYTE_NO_DISP_NO_SCALE_ADDRESSING_OP##SZ,       \
                  decoded->segment_text, modrm_reg32[decoded->sib.base]);      \
        } else {                                                               \
          sprintf(dst, SIB_FOUR_BYTE_NO_DISP_ADDRESSING_OP##SZ,                \
                  decoded->segment_text, modrm_reg32[decoded->sib.base],       \
                  modrm_reg32[decoded->sib.index], 1 << decoded->sib.scale);   \
        }                                                                      \
      }                                                                        \
    } else {                                                                   \
      if (decoded->modrm.rm == 5)                                              \
        sprintf(dst, DISPLACEMENT_ONLY_MODE, decoded->segment_text,            \
                (uint32_t)decoded->displacement.field);                        \
      else                                                                     \
        sprintf(dst, INDIRECT_ADDRESSING_OP##SZ, decoded->segment_text,        \
                modrm_reg32[decoded->modrm.rm]);                               \
    }                                                                          \
    break;                                                                     \
  case MOD_ONE_BYTE_DISPLACEMENT:                                              \
    if (decoded->sib.size) {                                                   \
      if (decoded->sib.index == 4) {                                           \
        char sign = GET_SIGN((uchar8_t)decoded->displacement.field, 8);        \
        uchar8_t value =                                                       \
            GET_VALUE_BY_SIGN((uchar8_t)decoded->displacement.field, sign);    \
                                                                               \
        sprintf(dst, SIB_ONE_BYTE_DISP_NO_SCALE_ADDRESSING_OP##SZ,             \
                decoded->segment_text, modrm_reg32[decoded->sib.base], sign,   \
                value);                                                        \
      } else {                                                                 \
        char sign = GET_SIGN((uchar8_t)decoded->displacement.field, 8);        \
        uchar8_t value =                                                       \
            GET_VALUE_BY_SIGN((uchar8_t)decoded->displacement.field, sign);    \
                                                                               \
        sprintf(dst, SIB_ONE_BYTE_DISP_ADDRESSING_OP##SZ,                      \
                decoded->segment_text, modrm_reg32[decoded->sib.base],         \
                modrm_reg32[decoded->sib.index], 1 << decoded->sib.scale,      \
                sign, value);                                                  \
      }                                                                        \
    } else {                                                                   \
      char sign = GET_SIGN((uchar8_t)decoded->displacement.field, 8);          \
      uchar8_t value =                                                         \
          GET_VALUE_BY_SIGN((uchar8_t)decoded->displacement.field, sign);      \
                                                                               \
      sprintf(dst, ONE_BYTE_DISP_ADDRESSING_OP##SZ, decoded->segment_text,     \
              modrm_reg32[decoded->modrm.rm], sign, value);                    \
    }                                                                          \
    break;                                                                     \
  case MOD_FOUR_BYTE_DISPLACEMENT:                                             \
    if (decoded->sib.size) {                                                   \
      if (decoded->sib.index == 4) {                                           \
        char sign = GET_SIGN((uint32_t)decoded->displacement.field, 32);       \
        uint32_t value =                                                       \
            GET_VALUE_BY_SIGN((uint32_t)decoded->displacement.field, sign);    \
                                                                               \
        sprintf(dst, SIB_FOUR_BYTE_DISP_NO_SCALE_ADDRESSING_OP##SZ,            \
                decoded->segment_text, modrm_reg32[decoded->sib.base], sign,   \
                value);                                                        \
      } else {                                                                 \
        char sign = GET_SIGN((uint32_t)decoded->displacement.field, 32);       \
        uint32_t value =                                                       \
            GET_VALUE_BY_SIGN((uint32_t)decoded->displacement.field, sign);    \
                                                                               \
        sprintf(dst, SIB_FOUR_BYTE_DISP_ADDRESSING_OP##SZ,                     \
                decoded->segment_text, modrm_reg32[decoded->sib.base],         \
                modrm_reg32[decoded->sib.index], 1 << decoded->sib.scale,      \
                sign, value);                                                  \
      }                                                                        \
    } else {                                                                   \
      char sign = GET_SIGN((uint32_t)decoded->displacement.field, 32);         \
      uint32_t value =                                                         \
          GET_VALUE_BY_SIGN((uint32_t)decoded->displacement.field, sign);      \
                                                                               \
      sprintf(dst, FOUR_BYTE_DISP_ADDRESSING_OP##SZ, decoded->segment_text,    \
              modrm_reg32[decoded->modrm.rm], sign, value);                    \
    }                                                                          \
    break;                                                                     \
  case MOD_REGISTER_ADDRESSING:                                                \
    strcpy(dst, modrm_reg##SZ[decoded->modrm.rm]);                             \
    break;                                                                     \
  }

/*
 * this function sets dst according to modrm RM field and operand size
 * +4 in call trace
 */
static void pedix_set_operand_m_by_size(decoded_instruction_t *decoded, char* dst, uint8_t size){
  switch(size){
    case 8: 
      SET_OPERAND_M_BY_SIZE(8);
      break;
    case 16:
      SET_OPERAND_M_BY_SIZE(16);
      break;
    case 32: 
      SET_OPERAND_M_BY_SIZE(32);
      break;
    default: 
      assert(!"illegal operand size");
  }
}

/*
 * this function sets dst according to modrm RM field and operand size
 * +4 in call trace
 */
static void pedix_set_operand_rm_by_size(decoded_instruction_t *decoded, char* dst, uint8_t size){
  switch(size){
    case 8: 
      SET_OPERAND_RM_BY_SIZE(8);
      break;
    case 16:
      SET_OPERAND_RM_BY_SIZE(16);
      break;
    case 32: 
      SET_OPERAND_RM_BY_SIZE(32);
      break;
    default: 
      assert(!"illegal operand size");
  }
}

/*
 * it sets dst according to id
 * +3 in call trace 
 */
static void pedix_set_operand_by_id32(decoded_instruction_t *decoded, __operand_t id, char* dst){
  switch (id) {
  case OPERAND_IMM_8: 
    sprintf(dst, OPERAND_BYTE, (uchar8_t)decoded->imm);
    break;
  case OPERAND_IMM_16: 
    sprintf(dst, OPERAND_WORD, (uint16_t)decoded->imm);
    break;
  case OPERAND_IMM_32: 
    sprintf(dst, OPERAND_DWORD, (uint32_t)decoded->imm);
    break;
  case OPERAND_IMM_16_32:
    if (pedix_instr_has_specific_prefix(decoded, PREFIX_OPSIZE_OVERRIDE))
      sprintf(dst, OPERAND_WORD, (uint16_t)decoded->imm);
    else 
      sprintf(dst, OPERAND_DWORD, (uint32_t)decoded->imm);
    break;
  case OPERAND_REG_EAX: 
    if (pedix_instr_has_specific_prefix(decoded, PREFIX_OPSIZE_OVERRIDE))
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
    pedix_set_operand_rm_by_size(decoded, dst, 8);
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
    if (pedix_instr_has_specific_prefix(decoded, PREFIX_OPSIZE_OVERRIDE)){
      pedix_set_operand_rm_by_size(decoded, dst, 16);
    }
    else{
      pedix_set_operand_rm_by_size(decoded, dst, 32);
    }
    break;
  case OPERAND_R_16_32:
    if (pedix_instr_has_specific_prefix(decoded, PREFIX_OPSIZE_OVERRIDE))
      strcpy(dst, modrm_reg16[decoded->modrm.reg]);
    else
      strcpy(dst, modrm_reg32[decoded->modrm.reg]);
    break;
  case OPERAND_M_8:
    pedix_set_operand_m_by_size(decoded, dst, 8);
    break;
  case OPERAND_M_ALL:
    pedix_set_operand_m_by_size(decoded, dst, 32);
    break;
  case OPERAND_REL_8:
    sprintf(dst, OPERAND_BYTE, (uchar8_t)decoded->rel);
    break;
  case OPERAND_REL_16_32: 
    if (pedix_instr_has_specific_prefix(decoded, PREFIX_OPSIZE_OVERRIDE))
      sprintf(dst, OPERAND_WORD, (uint16_t)decoded->rel);
    else
      sprintf(dst, OPERAND_DWORD, (uint32_t)decoded->rel);
    break;
  case R_PLUS_8:
    strcpy(dst, modrm_reg8[decoded->buffer.bytes[0] & 0x07]);
    break;
  case R_PLUS_16_32:
    if (pedix_instr_has_specific_prefix(decoded, PREFIX_OPSIZE_OVERRIDE))
      strcpy(dst, modrm_reg16[decoded->buffer.bytes[0] & 0x07]);
    else
      strcpy(dst, modrm_reg32[decoded->buffer.bytes[0] & 0x07]);
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
