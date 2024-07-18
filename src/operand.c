#include "headers/operand.h"
#include "headers/defines.h"
#include <stdio.h>
#include <string.h>

bool set_operands32(Dinstruction *decoded, unsigned char instruction) {
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
      } else if (decoded->status.opsize_override) {
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
        memcpy(decoded->mnemonic.str + decoded->mnemonic.cur_size, reg2,
               reg2_len);
        decoded->mnemonic.cur_size += reg2_len;
        decoded->mnemonic.str[decoded->mnemonic.cur_size] = ',';
        decoded->mnemonic.cur_size += 1;
        memcpy(decoded->mnemonic.str + decoded->mnemonic.cur_size, reg1,
               reg1_len);
      } else {
        memcpy(decoded->mnemonic.str + decoded->mnemonic.cur_size, reg1,
               reg1_len);
        decoded->mnemonic.cur_size += reg1_len;
        decoded->mnemonic.str[decoded->mnemonic.cur_size] = ',';
        decoded->mnemonic.cur_size += 1;
        memcpy(decoded->mnemonic.str + decoded->mnemonic.cur_size, reg2,
               reg2_len);
      }

      break;
    }
    break;
  case INSTR_ZERO:
    // todo
    char *op;
    if (decoded->status.opsize_override) {
      // 16-bit
      op = z_instr_op16[instruction];
    } else {
      // 32-bit
      op = z_instr_op32[instruction];
    }
    unsigned int op_len = strlen(op);
    memcpy(decoded->mnemonic.str + decoded->mnemonic.cur_size, op, op_len);
    decoded->mnemonic.cur_size += op_len;
    break;
  case INSTR_OTHER:
    // todo
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
