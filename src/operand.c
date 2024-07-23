#include "headers/operand.h"
#include "headers/defines.h"
#include <stdio.h>
#include <string.h>

void set_operand_by_size(Dinstruction *decoded, unsigned int operand) {
//  if (operand > MAX_OPERANDS - 1)
//    return;

  /*
  switch (decoded->operands[operand].size) {
  case BYTE_SZ:
    sprintf(decoded->operands[operand].str, "0x%02x", decoded->operand2);
    break;
  case WORD_SZ:
    sprintf(decoded->mnemonic.str + decoded->mnemonic.cur_size, "0x%04x",
            decoded->operand2);
    break;
  case DOUBLEWORD_SZ:
    sprintf(decoded->mnemonic.str + decoded->mnemonic.cur_size, "0x%08x",
            decoded->operand2);
    break;
  }
  */
}

bool set_operands32(Dinstruction *decoded, unsigned char instruction) {
  char *op;
  size_t op_len;
  // d = 0 (adding from register to memory)
  // d = 1 (adding from memory to register)
  unsigned char d = (instruction & 2) >> 1;
  // s = 0 (8-bit operands)
  // s = 1 (16 or 32-bit operands)
  unsigned char s = (instruction & 1);
  switch (decoded->instr_type) {
  case INSTR_MODRM:
    switch (decoded->modrm.mod) {
    case 0:
      // todo
      break;
    case 1:
      // todo
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
      unsigned int reg1_len = strlen(reg1);
      unsigned int reg2_len = strlen(reg2);
      if (d == 0) {
        //        memcpy(decoded->operands[0].str, reg2, reg2_len);
        //        memcpy(decoded->operands[1].str, reg1, reg1_len);
      } else {
        //       memcpy(decoded->operands[1].str, reg2, reg2_len);
        //       memcpy(decoded->operands[0].str, reg1, reg1_len);
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

bool set_operands64(Dinstruction *decoded, unsigned char instruction) {
  // todo
  return false;
}

bool set_operands(Dinstruction *decoded, unsigned char instruction) {
  switch (decoded->mode) {
  case 32:
    return set_operands32(decoded, instruction);
  case 64:
    return set_operands64(decoded, instruction);
  }
  return false;
}
