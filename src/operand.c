#include "headers/operand.h"
#include "headers/defines.h"
#include "headers/iutils.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define GET_DIRECTION(d) ((d & 2) >> 1)
#define GET_SIZE(s) (s & 1)

#define MOD_REGISTER_ADDRESSING 3
#define MOD_FOUR_BYTE_DISPLACEMENT 2
#define MOD_ONE_BYTE_DISPLACEMENT 1
#define MOD_SIB_OR_REGISTER_INDIRECT_ADDRESSING 0

#define SET_OPERAND_M_BY_SIZE(SZ)                                              \
  switch (decoded->modrm.mod) {                                                \
  case MOD_SIB_OR_REGISTER_INDIRECT_ADDRESSING:                                \
    if (decoded->sib.size) {                                                   \
      if (decoded->sib.base == 5) {                                            \
        sprintf(dst, SIB_FOUR_BYTE_DISP_NO_REG_ADDRESSING_OP##SZ,              \
                modrm_reg32[decoded->modrm.rm], 1 << decoded->sib.scale,       \
                decoded->displacement.field);                                  \
      } else {                                                                 \
        sprintf(dst, SIB_FOUR_BYTE_NO_DISP_ADDRESSING_OP##SZ,                  \
                modrm_reg32[decoded->sib.base],                                \
                modrm_reg32[decoded->sib.index], 1 << decoded->sib.scale);     \
      }                                                                        \
    } else {                                                                   \
      sprintf(dst, INDIRECT_ADDRESSING_OP##SZ,                                 \
              modrm_reg32[decoded->modrm.rm]);                                 \
    }                                                                          \
    break;                                                                     \
  case MOD_ONE_BYTE_DISPLACEMENT:                                              \
    if (decoded->sib.size) {                                                   \
      sprintf(dst, SIB_ONE_BYTE_DISP_ADDRESSING_OP##SZ,                        \
              modrm_reg32[decoded->sib.base], modrm_reg32[decoded->sib.index], \
              1 << decoded->sib.scale, decoded->displacement.field);           \
    } else {                                                                   \
      sprintf(dst, ONE_BYTE_DISP_ADDRESSING_OP##SZ,                            \
              modrm_reg32[decoded->modrm.rm], decoded->displacement.field);    \
    }                                                                          \
    break;                                                                     \
  case MOD_FOUR_BYTE_DISPLACEMENT:                                             \
    if (decoded->sib.size) {                                                   \
      sprintf(dst, SIB_FOUR_BYTE_DISP_ADDRESSING_OP##SZ,                       \
              modrm_reg32[decoded->sib.base], modrm_reg32[decoded->sib.index], \
              1 << decoded->sib.scale, decoded->displacement.field);           \
    } else {                                                                   \
      sprintf(dst, FOUR_BYTE_DISP_ADDRESSING_OP##SZ,                           \
              modrm_reg32[decoded->modrm.rm], decoded->displacement.field);    \
    }                                                                          \
    break;                                                                     \
  }

#define SET_OPERAND_RM_BY_SIZE(SZ)                                             \
  switch (decoded->modrm.mod) {                                                \
  case MOD_SIB_OR_REGISTER_INDIRECT_ADDRESSING:                                \
    if (decoded->sib.size) {                                                   \
      if (decoded->sib.base == 5) {                                            \
        sprintf(dst, SIB_FOUR_BYTE_DISP_NO_REG_ADDRESSING_OP##SZ,              \
                modrm_reg32[decoded->modrm.rm], 1 << decoded->sib.scale,       \
                decoded->displacement.field);                                  \
      } else {                                                                 \
        sprintf(dst, SIB_FOUR_BYTE_NO_DISP_ADDRESSING_OP##SZ,                  \
                modrm_reg32[decoded->sib.base],                                \
                modrm_reg32[decoded->sib.index], 1 << decoded->sib.scale);     \
      }                                                                        \
    } else {                                                                   \
      sprintf(dst, INDIRECT_ADDRESSING_OP##SZ,                                 \
              modrm_reg32[decoded->modrm.rm]);                                 \
    }                                                                          \
    break;                                                                     \
  case MOD_ONE_BYTE_DISPLACEMENT:                                              \
    if (decoded->sib.size) {                                                   \
      sprintf(dst, SIB_ONE_BYTE_DISP_ADDRESSING_OP##SZ,                        \
              modrm_reg32[decoded->sib.base], modrm_reg32[decoded->sib.index], \
              1 << decoded->sib.scale, decoded->displacement.field);           \
    } else {                                                                   \
      sprintf(dst, ONE_BYTE_DISP_ADDRESSING_OP##SZ,                            \
              modrm_reg32[decoded->modrm.rm], decoded->displacement.field);    \
    }                                                                          \
    break;                                                                     \
  case MOD_FOUR_BYTE_DISPLACEMENT:                                             \
    if (decoded->sib.size) {                                                   \
      sprintf(dst, SIB_FOUR_BYTE_DISP_ADDRESSING_OP##SZ,                       \
              modrm_reg32[decoded->sib.base], modrm_reg32[decoded->sib.index], \
              1 << decoded->sib.scale, decoded->displacement.field);           \
    } else {                                                                   \
      sprintf(dst, FOUR_BYTE_DISP_ADDRESSING_OP##SZ,                           \
              modrm_reg32[decoded->modrm.rm], decoded->displacement.field);    \
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
static void pedix_set_operand_m_by_size(Dinstruction *decoded, char* dst, uint8_t size){
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
static void pedix_set_operand_rm_by_size(Dinstruction *decoded, char* dst, uint8_t size){
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
static void pedix_set_operand_by_id32(Dinstruction *decoded, _Operand id, char* dst){
  switch (id) {
  case OPERAND_IMM_8: 
    sprintf(dst, OPERAND_BYTE, decoded->imm);
    break;
  case OPERAND_IMM_16: 
    sprintf(dst, OPERAND_WORD, decoded->imm);
    break;
  case OPERAND_IMM_32: 
    sprintf(dst, OPERAND_DWORD, decoded->imm);
    break;
  case OPERAND_IMM_16_32:
    if (pedix_instr_has_specific_prefix(decoded, PREFIX_OPSIZE_OVERRIDE))
      sprintf(dst, OPERAND_WORD, decoded->imm);
    else 
      sprintf(dst, OPERAND_BYTE, decoded->imm);
    break;
  case OPERAND_REG_EAX: 
    if (pedix_instr_has_specific_prefix(decoded, PREFIX_OPSIZE_OVERRIDE))
      strcpy(dst, "ax");
    else 
      strcpy(dst, "eax");
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
    sprintf(dst, OPERAND_BYTE, decoded->rel);
    break;
  case OPERAND_REL_16_32: 
    if (pedix_instr_has_specific_prefix(decoded, PREFIX_OPSIZE_OVERRIDE))
      sprintf(dst, OPERAND_WORD, decoded->rel);
    else
      sprintf(dst, OPERAND_DWORD, decoded->rel);
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

/*
 * it sets specific N operand's text field by its id that is stored in
 * decoded->instruction->operand1
 * +2 in call trace
 */ 
static void pedix_set_operand_by_n32(Dinstruction *decoded, uint8_t n){
  switch(n){
    case 1:
      pedix_set_operand_by_id32(decoded, decoded->instruction->operand1, decoded->operand1);
      break;
    case 2:
      pedix_set_operand_by_id32(decoded, decoded->instruction->operand2, decoded->operand2);
      break;
    case 3:
      pedix_set_operand_by_id32(decoded, decoded->instruction->operand3, decoded->operand3);
      break;
    case 4:
      pedix_set_operand_by_id32(decoded, decoded->instruction->operand4, decoded->operand4);
      break;

    default: 
      assert(!"wrong operand num");
  }
}

/* 
 * it cares only about which operands are present
 * +1 in call trace
 */
static void pedix_set_operands32(Dinstruction *decoded) {
  // operand1 is assumed to be present
  pedix_set_operand_by_n32(decoded, 1);
  if (decoded->instruction->operand2 != OPERAND_VOID)
      pedix_set_operand_by_n32(decoded, 2);
  if (decoded->instruction->operand3 != OPERAND_VOID)
      pedix_set_operand_by_n32(decoded, 3);
  if (decoded->instruction->operand4 != OPERAND_VOID)
      pedix_set_operand_by_n32(decoded, 4);
}

static void pedix_set_operands64(Dinstruction *decoded) {
  // todo
  assert(!"pedix_set_operands64 is not implemented yet!");
}

void pedix_merge_operands(Dinstruction *decoded) {
  if (decoded->instruction->operand1 != OPERAND_VOID){
      // add space
      decoded->text[strlen(decoded->text)] = 0x20;
      strcat(decoded->text, decoded->operand1);
  }
  if (decoded->instruction->operand2 != OPERAND_VOID){
      // add comma
      decoded->text[strlen(decoded->text)] = 0x2c;
      strcat(decoded->text, decoded->operand2);
  }
  if (decoded->instruction->operand3 != OPERAND_VOID){
      decoded->text[strlen(decoded->text)] = 0x2c;
      strcat(decoded->text, decoded->operand3);
  }
  if (decoded->instruction->operand4 != OPERAND_VOID){
      decoded->text[strlen(decoded->text)] = 0x2c;
      strcat(decoded->text, decoded->operand4);
  }
}

/*
 * general-purpose function that cares only about bit depth
 */
void pedix_set_operands(Dinstruction *decoded) {
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
