#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/decoder.h"
#include "headers/defines.h"
#include "headers/iutils.h"
#include "headers/mnemonic.h"

void dump(Dinstruction *decoded) {
  printf("========================================\n");
  printf("instruction size: %lu\n", decoded->buffer.size);
  printf("has_prefix: %d\n", decoded->status.has_prefix);
  printf("0x0f extended: %d\n", decoded->status.extended);

  if (decoded->instr_type) {
    switch (decoded->instr_type) {
    case INSTR_ZERO:
      printf("type: ZERO\n");
      break;
    case INSTR_MODRM:
      printf("type: HAS MOD R/M\n");
      break;
    case INSTR_OTHER:
      printf("type: OTHER\n");
      break;
    }
  }

  if (decoded->status.has_prefix) {
    for (size_t i = 0; i < decoded->prefixes.size; i++) {
      printf("instruction prefix %zu: 0x%02X\n", i,
             decoded->prefixes.prefix[i]);
    }
  }

  printf("instruction opcode 1: 0x%02X\n", decoded->op1);
  printf("instruction opcode 2: 0x%02X\n", decoded->op2);
  printf("========================================\n\n");
}

Dinstruction *init_instruction() {
  Dinstruction *decoded = (Dinstruction *)calloc(1, sizeof(Dinstruction));
  return decoded;
}

void zero_instruction(Dinstruction *decoded) {
  memset(decoded, 0, sizeof(Dinstruction));
}

void free_instrucion(Dinstruction *decoded) { free(decoded); }

bool decode32(Dinstruction *decoded, unsigned char *instruction) {
  // TODO: ADD VALID PREFIX CHECK
  // EX: 66 0f 74 04 00 -> IS A VALID INSTRUCTION, WHILE f3 0f 74 04 00 IS NOT

  // https://sparksandflames.com/files/x86InstructionChart.html
  decoded->mode = 32;

  unsigned char *i_ptr = instruction;

  while (instr_has_prefix(*i_ptr)) {
    decoded->status.has_prefix = true;
    if(*i_ptr == 0x66)
      decoded->status.opsize_override = true;
    
    decoded->prefixes.prefix[decoded->prefixes.size] = *i_ptr;
    decoded->buffer.size += BYTE_SZ;
    decoded->prefixes.size = decoded->buffer.size;
    i_ptr++;
  }

  // 00-3f: arith-logical operations: ADD, ADC,SUB,SBB,AND...
  // 40-7f: INC/PUSH/POP, Jcc,...
  // 80-bf: data movement: MOV,LODS,STOS,...
  // c0-ff: misc and escape groups

  if (instr_has_extended_opcode(*i_ptr)) {
    // 0x0f (two byte opcode is gonna be decoded here)
    decoded->status.extended = true;
    decoded->buffer.size += BYTE_SZ;
    i_ptr++;

    if (*i_ptr == 0x38 || *i_ptr == 0x3A) {
      // if it has secondary opcode
      decoded->op1 = *i_ptr;
      decoded->buffer.size += BYTE_SZ;

      i_ptr++;
      decoded->op2 = *i_ptr;
      decoded->buffer.size += BYTE_SZ;

      i_ptr++;
      decoded->instr_type = INSTR_MODRM;
      decoded->modrm.field = *i_ptr;
      decoded->modrm.mod = (decoded->modrm.field & 0xC0) >> 6;
      decoded->modrm.reg = (decoded->modrm.field & 0x38) >> 3;
      decoded->modrm.rm = (decoded->modrm.field & 0x07);
      size_t modrm_size = get_modrm_size(decoded, i_ptr);
      decoded->buffer.size += modrm_size;

      return true;
    } else if (*i_ptr == 0x01) {
      decoded->op1 = *i_ptr;
      i_ptr++;
      // actually this block of code is a whole mess, because it is not aware of
      // sgdt, sidt, lgdt, lidt, smsw, lmsw and invlpg instructions. да похуй
      // уже?
      switch (*i_ptr) {
      // VMCALL, VMLAUNCH, VMRESUME, VMXOFF, MONITOR, MWAIT, XGETBV, XSETBV and
      // RDTSCP
      case 0xC1:
      case 0xC2:
      case 0xC3:
      case 0xC4:
      case 0xC8:
      case 0xC9:
      case 0xD0:
      case 0xD1:
      case 0xF9:
        decoded->op2 = *i_ptr;
        decoded->buffer.size += WORD_SZ;
        return true;
      default:
        return false;
      }
    } else {
      decoded->op1 = *i_ptr;
      decoded->buffer.size += BYTE_SZ;

      if (instr_zero(decoded, decoded->op1)) {
        decoded->instr_type = INSTR_ZERO;
        return true; // if no other bytes are coming after
      }

      if (instr_other(decoded, decoded->op1)) {
        decoded->instr_type = INSTR_OTHER;
        size_t op_size = get_operand_size32(decoded, decoded->op1);
        if (op_size == 0)
          return false;

        decoded->buffer.size += op_size;
        return true;
      }

      if (instr_modrm(decoded, decoded->op1)) {
        i_ptr++;
        decoded->instr_type = INSTR_MODRM;
        decoded->modrm.field = *i_ptr;
        decoded->modrm.mod = (decoded->modrm.field & 0xC0) >> 6;
        decoded->modrm.reg = (decoded->modrm.field & 0x38) >> 3;
        decoded->modrm.rm = (decoded->modrm.field & 0x07);

        if (instr_has_opcode_extension(decoded, decoded->op1)) {
          if (!instr_has_valid_extension(decoded, decoded->op1)) {
            return false;
          }
          decoded->status.has_opcode_extension = true;
          decoded->buffer.size +=
              get_opcode_extension_operand_size(decoded, decoded->op1);
        }

        size_t modrm_size = get_modrm_size(decoded, i_ptr);
        decoded->buffer.size += modrm_size;
        return true;
      }

      return false;
    }
  } else { // one byte opcode is gonna be here

    decoded->op1 = *i_ptr;
    decoded->buffer.size += BYTE_SZ;

    if (instr_zero(decoded, decoded->op1)) {
      decoded->instr_type = INSTR_ZERO;
      return true; // if no other bytes are coming after
    }

    if (instr_other(decoded, decoded->op1)) {
      decoded->instr_type = INSTR_OTHER;
      size_t op_size = get_operand_size32(decoded, decoded->op1);
      if (op_size == 0)
        return false;

      decoded->buffer.size += op_size;
      return true;
    }

    if (instr_modrm(decoded, decoded->op1)) {
      i_ptr++;
      decoded->instr_type = INSTR_MODRM;
      decoded->modrm.field = *i_ptr;
      decoded->modrm.mod = (decoded->modrm.field & 0xC0) >> 6;
      decoded->modrm.reg = (decoded->modrm.field & 0x38) >> 3;
      decoded->modrm.rm = (decoded->modrm.field & 0x07);

      if (instr_has_opcode_extension(decoded, decoded->op1)) {
        if (!instr_has_valid_extension(decoded, decoded->op1)) {

          return false;
        }
        decoded->status.has_opcode_extension = true;
        decoded->buffer.size +=
            get_opcode_extension_operand_size(decoded, decoded->op1);
      }

      size_t modrm_size = get_modrm_size(decoded, i_ptr);
      decoded->buffer.size += modrm_size;
      return true;
    }
  }

  return false;
}

bool decode64(Dinstruction *decoded, unsigned char *instruction) {
  //     In 64-bit mode, instruction formats do not change. Bits needed to
  //     define fields in the 64-bit context are provided by the
  // addition of REX prefixes.
  decoded->mode = 64;
  unsigned char *i_ptr = instruction;

  while (instr_has_prefix(*i_ptr)) {
    decoded->status.has_prefix = true;
    if(*i_ptr == 0x66)
      decoded->status.opsize_override = true;

    decoded->prefixes.prefix[decoded->prefixes.size] = *i_ptr;
    decoded->buffer.size += BYTE_SZ;
    decoded->prefixes.size = decoded->buffer.size;
    i_ptr++;
  }

  if (instr_has_rex(*i_ptr)) {
    decoded->status.has_rex = true;
    decoded->buffer.size += BYTE_SZ;
    decoded->rex.field = *i_ptr;
    decoded->rex.w = (decoded->rex.field & 0x08) >> 3;
    decoded->rex.r = (decoded->rex.field & 0x04) >> 2;
    decoded->rex.x = (decoded->rex.field & 0x02) >> 1;
    decoded->rex.b = (decoded->rex.field & 0x01);
    i_ptr++;
  }

  if (instr_has_extended_opcode(*i_ptr)) {
    // 0x0f (two byte opcode is gonna be decoded here)
    decoded->status.extended = true;
    decoded->buffer.size += BYTE_SZ;
    i_ptr++;
    if (*i_ptr == 0x38 || *i_ptr == 0x3A) {
      // if it has secondary opcode
      decoded->op1 = *i_ptr;
      decoded->buffer.size += BYTE_SZ;

      i_ptr++;
      decoded->op2 = *i_ptr;
      decoded->buffer.size += BYTE_SZ;

      i_ptr++;
      decoded->instr_type = INSTR_MODRM;
      decoded->modrm.field = *i_ptr;
      decoded->modrm.mod = (decoded->modrm.field & 0xC0) >> 6;
      decoded->modrm.reg = (decoded->modrm.field & 0x38) >> 3;
      decoded->modrm.rm = (decoded->modrm.field & 0x07);
      size_t modrm_size = get_modrm_size(decoded, i_ptr);
      decoded->buffer.size += modrm_size;

      return true;
    } else if (*i_ptr == 0x01) {
      decoded->op1 = *i_ptr;
      i_ptr++;
      switch (*i_ptr) {
      case 0xC1:
      case 0xC2:
      case 0xC3:
      case 0xC4:
      case 0xC8:
      case 0xC9:
      case 0xD0:
      case 0xD1:
      case 0xF9:
        decoded->op2 = *i_ptr;
        decoded->buffer.size += WORD_SZ;
        return true;
      default:
        return false;
      }
    } else {
      decoded->op1 = *i_ptr;
      decoded->buffer.size += BYTE_SZ;

      if (instr_zero(decoded, decoded->op1)) {
        decoded->instr_type = INSTR_ZERO;
        return true; // if no other bytes are coming after
      }

      if (instr_other(decoded, decoded->op1)) {
        decoded->instr_type = INSTR_OTHER;
        size_t op_size = get_operand_size32(decoded, decoded->op1);
        if (op_size == 0)
          return false;

        decoded->buffer.size += op_size;
        return true;
      }

      if (instr_modrm(decoded, decoded->op1)) {
        i_ptr++;
        decoded->instr_type = INSTR_MODRM;
        decoded->modrm.field = *i_ptr;
        decoded->modrm.mod = (decoded->modrm.field & 0xC0) >> 6;
        decoded->modrm.reg = (decoded->modrm.field & 0x38) >> 3;
        decoded->modrm.rm = (decoded->modrm.field & 0x07);

        if (instr_has_opcode_extension(decoded, decoded->op1)) {
          if (!instr_has_valid_extension(decoded, decoded->op1)) {
            return false;
          }
          decoded->status.has_opcode_extension = true;
          decoded->buffer.size +=
              get_opcode_extension_operand_size(decoded, decoded->op1);
        }

        size_t modrm_size = get_modrm_size(decoded, i_ptr);
        decoded->buffer.size += modrm_size;
        return true;
      }
    }
    return false;
  }

  if (instr_has_vex(*i_ptr)) {
    decoded->status.has_vex = true;
    decoded->buffer.size += get_vex_size(*i_ptr);
    i_ptr++;
  }

  decoded->op1 = *i_ptr;
  decoded->buffer.size += BYTE_SZ;

  if (instr_zero(decoded, decoded->op1)) {
    decoded->instr_type = INSTR_ZERO;
    return true; // if no other bytes are coming after
  }

  if (instr_other(decoded, decoded->op1)) {
    decoded->instr_type = INSTR_OTHER;
    size_t op_size = get_operand_size64(decoded, decoded->op1);
    if (op_size == 0)
      return false;

    decoded->buffer.size += op_size;
    return true;
  }

  if (instr_modrm(decoded, decoded->op1)) {
    i_ptr++;
    decoded->instr_type = INSTR_MODRM;
    decoded->modrm.field = *i_ptr;
    decoded->modrm.mod = (decoded->modrm.field & 0xC0) >> 6;
    decoded->modrm.reg = (decoded->modrm.field & 0x38) >> 3;
    decoded->modrm.rm = (decoded->modrm.field & 0x07);

    if (instr_has_opcode_extension(decoded, decoded->op1)) {
      if (!instr_has_valid_extension(decoded, decoded->op1)) {
        return false;
      }
      decoded->status.has_opcode_extension = true;
      decoded->buffer.size +=
          get_opcode_extension_operand_size(decoded, decoded->op1);
    }

    size_t modrm_size = get_modrm_size(decoded, i_ptr);
    decoded->buffer.size += modrm_size;
    return true;
  }

  return false;
}

bool decode(Dinstruction *decoded, unsigned char *instruction,
            unsigned int mode) {
  switch (mode) {
  case 32:
    return decode32(decoded, instruction);
  case 64:
    return decode64(decoded, instruction);
  default:
    return false;
  }
}
