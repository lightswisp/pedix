#include "headers/operand.h"
#include "headers/defines.h"
#include <stdio.h>
#include <string.h>

#define GET_DIRECTION(d) ((d & 2) >> 1)
#define GET_SIZE(s) (s & 1)

#define REGISTER_ADDRESSING 3
#define FOUR_BYTE_DISPLACEMENT 2
#define ONE_BYTE_DISPLACEMENT 1
#define SIB_OR_REGISTER_INDIRECT_ADDRESSING 0

/*
 * set operand string
 */
bool set_operands32(Dinstruction *decoded, uchar8_t instruction) {
  // todo: add extended opcode check
  char *op;
  char* modrm_fmt;
  char *reg1, *reg2;
  size_t op_len;
  uint8_t reg1_len, reg2_len;
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
      // todo 
      break;
    case ONE_BYTE_DISPLACEMENT:
      // mod == 01 (disp8 mode)
      if (HAS_STATUS(decoded->status, STATUS_SIB)){
        // todo
        // sib + disp8 mode
      }
      else{
        if(s == 0){
          // 8-bit operands
          reg1 = modrm_reg8[decoded->modrm.reg];
          reg2 = modrm_reg32[decoded->modrm.rm];
          modrm_fmt = ONE_BYTE_DISP_OP_8_ADDRESSING;
        } else if (HAS_STATUS(decoded->status, STATUS_OPSIZE_OVERRIDE)) {
          // 16-bit operands
          reg1 = modrm_reg8[decoded->modrm.reg];
          reg2 = modrm_reg32[decoded->modrm.rm];
          modrm_fmt = ONE_BYTE_DISP_OP_16_ADDRESSING;
        } else {
          // 32-bit operands
          reg1 = modrm_reg32[decoded->modrm.reg];
          reg2 = modrm_reg32[decoded->modrm.rm];
          modrm_fmt = ONE_BYTE_DISP_OP_32_ADDRESSING;
        }
        reg1_len = strlen(reg1);
        reg2_len = strlen(reg2);
        char temp[50];
        if (d == 0) {
          sprintf(temp, modrm_fmt, reg2, decoded->displacement.field); 
          sprintf(decoded->operands.str, REG_TO_MEM, temp, reg1);
        } else {
          sprintf(temp, modrm_fmt, reg2, decoded->displacement.field); 
          sprintf(decoded->operands.str, MEM_TO_REG, reg1, temp);
        }
      }
      break;
    case FOUR_BYTE_DISPLACEMENT:
      // todo
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
      reg1_len = strlen(reg1);
      reg2_len = strlen(reg2);
      if (d == 0) {
        sprintf(decoded->operands.str, REG_TO_REG, reg2, reg1);
      } else {
        sprintf(decoded->operands.str, REG_TO_REG, reg1, reg2);
      }

      break;
    }
    break;
  case INSTR_ZERO:

    if (HAS_STATUS(decoded->status, STATUS_OPSIZE_OVERRIDE)) {
      // 16-bit
      op = z_instr_op16[instruction];
    } else {
      // 32-bit
      op = z_instr_op32[instruction];
    }
    op_len = strlen(op);
    memcpy(decoded->operands.str, op, op_len);
    return true;
  case INSTR_OTHER:
    if (HAS_STATUS(decoded->status, STATUS_OPSIZE_OVERRIDE)) {
      // 16-bit
      op = o_instr_op16[instruction];
    } else {
      // 32-bit
      op = o_instr_op32[instruction];
    }
    //op_len = strlen(op);
    
    if(HAS_STATUS(decoded->status, STATUS_IMMEDIATE_OPERAND))
      sprintf(decoded->operands.str, op, decoded->imm);
    else if(HAS_STATUS(decoded->status, STATUS_REL_OFFSET_OPERAND))
      sprintf(decoded->operands.str, op, decoded->rel + decoded->operands.size + BYTE_LEN);
    else if(HAS_STATUS(decoded->status, STATUS_DIRECT_ADDR_OPERAND))
      sprintf(decoded->operands.str, op, decoded->dir >> (HAS_STATUS(decoded->status, STATUS_OPSIZE_OVERRIDE) ? 0x10 : 0x20), decoded->dir);
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
bool set_operands64(Dinstruction *decoded, uchar8_t instruction) {
  // todo
  return false;
}

bool set_operands(Dinstruction *decoded, uchar8_t instruction) {
  switch (decoded->mode) {
  case 32:
    return set_operands32(decoded, instruction);
  case 64:
    return set_operands64(decoded, instruction);
  }
  return false;
}
