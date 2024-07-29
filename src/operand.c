#include "headers/operand.h"
#include "headers/defines.h"
#include <stdio.h>
#include <string.h>

#define GET_DIRECTION(d) ((d & 2) >> 1)
#define GET_SIZE(s) (s & 1)

#define MAX_TEMP_FMT_LEN 50
#define REGISTER_ADDRESSING 3
#define FOUR_BYTE_DISPLACEMENT 2
#define ONE_BYTE_DISPLACEMENT 1
#define SIB_OR_REGISTER_INDIRECT_ADDRESSING 0

/*
 * set operand string
 */
static bool set_operands32(Dinstruction *decoded, uchar8_t instruction) {
  // todo: add extended opcode check
  uint8_t scale;
  char temp[MAX_TEMP_FMT_LEN];
  const char *base, *index, *op, *modrm_fmt, *reg1, *reg2;
  // d = 0 (adding from register to memory)
  // d = 1 (adding from memory to register)
  uchar8_t d = GET_DIRECTION(instruction);
  // s = 0 (8-bit operands)
  // s = 1 (16 or 32-bit operands)
  uchar8_t s = GET_SIZE(instruction);
  switch (decoded->instr_type) {
  case INSTR_MODRM:

    switch (decoded->modrm.mod) {
    case SIB_OR_REGISTER_INDIRECT_ADDRESSING:
      if (HAS_STATUS(decoded->status, STATUS_SIB)){
        /* sib */
        if(decoded->sib.base == 5){
          if (s == 0) {
            // 8-bit operands
            reg1 = modrm_reg8[decoded->modrm.reg];
            modrm_fmt = SIB_FOUR_BYTE_DISP_OP_8_NO_REG_ADDRESSING;
          } else if (HAS_STATUS(decoded->status, STATUS_OPSIZE_OVERRIDE)) {
            // 16-bit operands
            reg1 = modrm_reg16[decoded->modrm.reg];
            modrm_fmt = SIB_FOUR_BYTE_DISP_OP_16_NO_REG_ADDRESSING;
          } else {
            // 32-bit operands
            reg1 = modrm_reg32[decoded->modrm.reg];
            modrm_fmt = SIB_FOUR_BYTE_DISP_OP_32_NO_REG_ADDRESSING;
          }
          index = modrm_reg32[decoded->sib.index];
          scale = 1 << decoded->sib.scale;
          snprintf(temp, MAX_TEMP_FMT_LEN + 1, modrm_fmt, index, scale,
                   decoded->displacement.field);
        }
        else{

          if (s == 0) {
            // 8-bit operands
            reg1 = modrm_reg8[decoded->modrm.reg];
            modrm_fmt = SIB_FOUR_BYTE_OP_8_NO_DISP_ADDRESSING;
          } else if (HAS_STATUS(decoded->status, STATUS_OPSIZE_OVERRIDE)) {
            // 16-bit operands
            reg1 = modrm_reg16[decoded->modrm.reg];
            modrm_fmt = SIB_FOUR_BYTE_OP_16_NO_DISP_ADDRESSING;
          } else {
            // 32-bit operands
            reg1 = modrm_reg32[decoded->modrm.reg];
            modrm_fmt = SIB_FOUR_BYTE_OP_32_NO_DISP_ADDRESSING;
          }
          base = modrm_reg32[decoded->sib.base];
          index = modrm_reg32[decoded->sib.index];
          scale = 1 << decoded->sib.scale;
          snprintf(temp, MAX_TEMP_FMT_LEN + 1, modrm_fmt, base, index, scale);
        }
      }
      else{
        /* register indirect addressing */
        if (s == 0) {
          // 8-bit operands
          reg1 = modrm_reg8[decoded->modrm.reg];
          reg2 = modrm_reg32[decoded->modrm.rm];
          modrm_fmt = INDIRECT_OP_8_ADDRESSING;
        } else if (HAS_STATUS(decoded->status, STATUS_OPSIZE_OVERRIDE)) {
          // 16-bit operands
          reg1 = modrm_reg16[decoded->modrm.reg];
          reg2 = modrm_reg32[decoded->modrm.rm];
          modrm_fmt = INDIRECT_OP_16_ADDRESSING;
        } else {
          // 32-bit operands
          reg1 = modrm_reg32[decoded->modrm.reg];
          reg2 = modrm_reg32[decoded->modrm.rm];
          modrm_fmt = INDIRECT_OP_32_ADDRESSING;
        }
        snprintf(temp, MAX_TEMP_FMT_LEN + 1, modrm_fmt, reg2,
                 decoded->displacement.field);
      }

      if (d == 0)
        snprintf(decoded->operands.str, MAX_TEMP_FMT_LEN + 1, REG_TO_MEM, temp, reg1);
      else
        snprintf(decoded->operands.str, MAX_TEMP_FMT_LEN + 1, MEM_TO_REG, reg1, temp);

      break;
    case ONE_BYTE_DISPLACEMENT:
      // mod == 01 (disp8 mode)
      if (HAS_STATUS(decoded->status, STATUS_SIB)){
        /* sib + disp8 mode */
        if(s == 0){
          // 8-bit operands
          reg1 = modrm_reg8[decoded->modrm.reg];
          modrm_fmt = SIB_ONE_BYTE_DISP_OP_8_ADDRESSING;
        } else if (HAS_STATUS(decoded->status, STATUS_OPSIZE_OVERRIDE)) {
          // 16-bit operands
          reg1 = modrm_reg16[decoded->modrm.reg];
          modrm_fmt = SIB_ONE_BYTE_DISP_OP_16_ADDRESSING;
        }
        else{
          // 32-bit operands
          reg1 = modrm_reg32[decoded->modrm.reg];
          modrm_fmt = SIB_ONE_BYTE_DISP_OP_32_ADDRESSING;
        }
        base = modrm_reg32[decoded->sib.base];
        index = modrm_reg32[decoded->sib.index];
        scale = 1 << decoded->sib.scale; 
        snprintf(temp, MAX_TEMP_FMT_LEN + 1, modrm_fmt, base, index, scale, decoded->displacement.field); 
      }
      else{
        /* disp8 mode */
        if(s == 0){
          // 8-bit operands
          reg1 = modrm_reg8[decoded->modrm.reg];
          reg2 = modrm_reg32[decoded->modrm.rm];
          modrm_fmt = ONE_BYTE_DISP_OP_8_ADDRESSING;
        } else if (HAS_STATUS(decoded->status, STATUS_OPSIZE_OVERRIDE)) {
          // 16-bit operands
          reg1 = modrm_reg16[decoded->modrm.reg];
          reg2 = modrm_reg32[decoded->modrm.rm];
          modrm_fmt = ONE_BYTE_DISP_OP_16_ADDRESSING;
        } else {
          // 32-bit operands
          reg1 = modrm_reg32[decoded->modrm.reg];
          reg2 = modrm_reg32[decoded->modrm.rm];
          modrm_fmt = ONE_BYTE_DISP_OP_32_ADDRESSING;
        }
        snprintf(temp, MAX_TEMP_FMT_LEN + 1, modrm_fmt, reg2, decoded->displacement.field); 
      }

      if (d == 0)
        snprintf(decoded->operands.str, MAX_TEMP_FMT_LEN + 1, REG_TO_MEM, temp, reg1);
      else
        snprintf(decoded->operands.str, MAX_TEMP_FMT_LEN + 1, MEM_TO_REG, reg1, temp);

      break;
    case FOUR_BYTE_DISPLACEMENT:
      /* mod == 10 */
      if (HAS_STATUS(decoded->status, STATUS_SIB)) {
        /* sib + disp32*/
        if (s == 0) {
          // 8-bit operands
          reg1 = modrm_reg8[decoded->modrm.reg];
          modrm_fmt = SIB_FOUR_BYTE_DISP_OP_8_ADDRESSING;
        } else if (HAS_STATUS(decoded->status, STATUS_OPSIZE_OVERRIDE)) {
          // 16-bit operands
          reg1 = modrm_reg16[decoded->modrm.reg];
          modrm_fmt = SIB_FOUR_BYTE_DISP_OP_16_ADDRESSING;
        } else {
          // 32-bit operands
          reg1 = modrm_reg32[decoded->modrm.reg];
          modrm_fmt = SIB_FOUR_BYTE_DISP_OP_32_ADDRESSING;
        }
        base = modrm_reg32[decoded->sib.base];
        index = modrm_reg32[decoded->sib.index];
        scale = 1 << decoded->sib.scale;
        snprintf(temp, MAX_TEMP_FMT_LEN + 1, modrm_fmt, base, index, scale, decoded->displacement.field);
      } else {
        /* disp32 */
        if (s == 0) {
          // 8-bit operands
          reg1 = modrm_reg8[decoded->modrm.reg];
          reg2 = modrm_reg32[decoded->modrm.rm];
          modrm_fmt = FOUR_BYTE_DISP_OP_8_ADDRESSING;
        } else if (HAS_STATUS(decoded->status, STATUS_OPSIZE_OVERRIDE)) {
          // 16-bit operands
          reg1 = modrm_reg16[decoded->modrm.reg];
          reg2 = modrm_reg32[decoded->modrm.rm];
          modrm_fmt = FOUR_BYTE_DISP_OP_16_ADDRESSING;
        } else {
          // 32-bit operands
          reg1 = modrm_reg32[decoded->modrm.reg];
          reg2 = modrm_reg32[decoded->modrm.rm];
          modrm_fmt = FOUR_BYTE_DISP_OP_32_ADDRESSING;
        }
        snprintf(temp, MAX_TEMP_FMT_LEN + 1, modrm_fmt, reg2, decoded->displacement.field);
      }

      if (d == 0)
        snprintf(decoded->operands.str, MAX_TEMP_FMT_LEN + 1, REG_TO_MEM, temp, reg1);
      else
        snprintf(decoded->operands.str, MAX_TEMP_FMT_LEN + 1, MEM_TO_REG, reg1, temp);

      break;
    case REGISTER_ADDRESSING:
      // mod == 11 (register addressing mode)
      if (s == 0) {
        // 8-bit operands
        reg1 = modrm_reg8[decoded->modrm.reg];
        reg2 = modrm_reg8[decoded->modrm.rm];
      } else if (HAS_STATUS(decoded->status, STATUS_OPSIZE_OVERRIDE)) {
        // 16-bit operands
        reg1 = modrm_reg16[decoded->modrm.reg];
        reg2 = modrm_reg16[decoded->modrm.rm];
      } else {
        // 32-bit operands
        reg1 = modrm_reg32[decoded->modrm.reg];
        reg2 = modrm_reg32[decoded->modrm.rm];
      }
      if (d == 0) {
        snprintf(decoded->operands.str, MAX_TEMP_FMT_LEN + 1, REG_TO_REG, reg2, reg1);
      } else {
        snprintf(decoded->operands.str, MAX_TEMP_FMT_LEN + 1, REG_TO_REG, reg1, reg2);
      }

      break;
    }
    return true;
  case INSTR_ZERO:

    if (HAS_STATUS(decoded->status, STATUS_OPSIZE_OVERRIDE)) {
      // 16-bit
      op = z_instr_op16[instruction];
    } else {
      // 32-bit
      op = z_instr_op32[instruction];
    }
    snprintf(decoded->operands.str, MAX_TEMP_FMT_LEN + 1, SINGLE_OPERAND, op);
    return true;
  case INSTR_OTHER:
    if (HAS_STATUS(decoded->status, STATUS_OPSIZE_OVERRIDE)) {
      // 16-bit
      op = o_instr_op16[instruction];
    } else {
      // 32-bit
      op = o_instr_op32[instruction];
    }

    if (HAS_STATUS(decoded->status, STATUS_IMMEDIATE_OPERAND))
      snprintf(decoded->operands.str, MAX_TEMP_FMT_LEN + 1, op, decoded->imm);
    else if (HAS_STATUS(decoded->status, STATUS_REL_OFFSET_OPERAND))
      snprintf(decoded->operands.str, MAX_TEMP_FMT_LEN + 1, op,
               decoded->rel + decoded->operands.size + BYTE_LEN);
    else if (HAS_STATUS(decoded->status, STATUS_DIRECT_ADDR_OPERAND))
      snprintf(decoded->operands.str, MAX_TEMP_FMT_LEN + 1, op,
               decoded->dir >>
                   (HAS_STATUS(decoded->status, STATUS_OPSIZE_OVERRIDE) ? 0x10
                                                                        : 0x20),
               decoded->dir);
    else 
      /* unknown status */
      return false; 

    return true;
  }

  /* return false by default */
  return false;
}

/*
 * set operand string
 */
static bool set_operands64(Dinstruction *decoded, uchar8_t instruction) {
  // todo
  return false;
}

bool set_operands(Dinstruction *decoded, uchar8_t instruction) {
  switch (decoded->mode) {
  case 32:
    return set_operands32(decoded, instruction);
  case 64:
    return set_operands64(decoded, instruction);
  default:
    return false;
  }
}
