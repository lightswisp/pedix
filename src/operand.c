#include "headers/operand.h"
#include "headers/defines.h"
#include <stdio.h>
#include <string.h>

bool set_operands32(Dinstruction *decoded, uchar8_t instruction) {
  char *op;
  size_t op_len;
  // d = 0 (adding from register to memory)
  // d = 1 (adding from memory to register)
  uchar8_t d = (instruction & 2) >> 1;
  // s = 0 (8-bit operands)
  // s = 1 (16 or 32-bit operands)
  uchar8_t s = (instruction & 1);
  switch (decoded->instr_type) {
  case INSTR_MODRM:
    switch (decoded->modrm.mod) {
    case 0:
      // todo 
      break;
    case 1:
      // mod == 01 (disp8 mode)
      if (decoded->modrm.rm == 4){
        // sib + disp8 mode
      }
      else{

      }
      break;
    case 2:
      // todo
      break;
    case 3:
      // mod == 11 (register addressing mode)
      char *reg1, *reg2;
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
      uint8_t reg1_len = strlen(reg1);
      uint8_t reg2_len = strlen(reg2);
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
    break;
  case INSTR_OTHER:
    if (HAS_STATUS(decoded->status, STATUS_OPSIZE_OVERRIDE)) {
      // 16-bit
      op = o_instr_op16[instruction];
    } else {
      // 32-bit
      op = o_instr_op32[instruction];
    }
    op_len = strlen(op);
    
    if(HAS_STATUS(decoded->status, STATUS_IMMEDIATE_OPERAND))
      sprintf(decoded->operands.str, op, decoded->imm);
    else if(HAS_STATUS(decoded->status, STATUS_REL_OFFSET_OPERAND))
      sprintf(decoded->operands.str, op, decoded->rel + decoded->operands.size + BYTE_SZ);
    else if(HAS_STATUS(decoded->status, STATUS_DIRECT_ADDR_OPERAND))
      sprintf(decoded->operands.str, op, decoded->dir >> (HAS_STATUS(decoded->status, STATUS_OPSIZE_OVERRIDE) ? 0x10 : 0x20), decoded->dir);
    break;
  }
  return false;
}

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
