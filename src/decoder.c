#include "headers/iutils.h"
#include "headers/mnemonic.h"
#include <string.h>

/*
 * Initializes the struct
 */
Dinstruction *init_instruction() {
  Dinstruction *decoded = (Dinstruction *)calloc(1, sizeof(Dinstruction));
  return decoded;
}

/*
 * Zeroes the struct, but preserves the mode
 */
void zero_instruction(Dinstruction *decoded) {
  // save the mode in order to restore it after zeroing the struct
  unsigned int mode = decoded->mode;
  memset(decoded, 0, sizeof(Dinstruction));
  decoded->mode = mode;
}

/*
 * Frees the struct
 */
void free_instrucion(Dinstruction *decoded) { free(decoded); }

/*
 * Sets instruction operands according to status
 */
void set_instruction_operand(Dinstruction *decoded, size_t op_size) {
  unsigned long *field;
  if (HAS_STATUS(decoded->status, STATUS_IMMEDIATE_OPERAND))
    field = &decoded->imm;
  else if (HAS_STATUS(decoded->status, STATUS_REL_OFFSET_OPERAND))
    field = &decoded->rel;
  else if (HAS_STATUS(decoded->status, STATUS_DIRECT_ADDR_OPERAND))
    field = &decoded->dir;

  for (size_t i = 0; i < op_size; i++) {
    unsigned long temp =
        decoded->buffer.bytes[decoded->buffer.size - op_size + i];
    temp = temp << (0x08 * i);
    *field += temp;
  }
}

/*
 * Decodes 32-bit instruction
 */
bool decode32(Dinstruction *decoded, unsigned char *instruction) {
  // TODO: ADD VALID PREFIX CHECK
  // EX: 66 0f 74 04 00 -> IS A VALID INSTRUCTION, WHILE f3 0f 74 04 00 IS NOT

  // https://sparksandflames.com/files/x86InstructionChart.html
  unsigned char *i_ptr = instruction;
  while (instr_has_prefix(*i_ptr)) {
    decoded->status |= STATUS_PREFIX;
    if (*i_ptr == PREFIX_OPSZ_OVERRIDE)
      decoded->status |= STATUS_OPSIZE_OVERRIDE;

    decoded->prefixes.prefix[decoded->prefixes.size] = *i_ptr;
    memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, BYTE_SZ);
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
    decoded->status |= STATUS_EXTENDED;
    memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, BYTE_SZ);
    decoded->buffer.size += BYTE_SZ;
    i_ptr++;

    if (*i_ptr == 0x38 || *i_ptr == 0x3A) {
      // if it has secondary opcode
      decoded->op1 = *i_ptr;
      memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, BYTE_SZ);
      decoded->buffer.size += BYTE_SZ;

      i_ptr++;
      decoded->op2 = *i_ptr;
      memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, BYTE_SZ);
      decoded->buffer.size += BYTE_SZ;

      i_ptr++;
      decoded->instr_type = INSTR_MODRM;
      decoded->modrm.field = *i_ptr;
      decoded->modrm.mod = (decoded->modrm.field & 0xC0) >> 6;
      decoded->modrm.reg = (decoded->modrm.field & 0x38) >> 3;
      decoded->modrm.rm = (decoded->modrm.field & 0x07);

      size_t modrm_size = get_modrm_size(decoded, i_ptr);
      memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, modrm_size);
      decoded->buffer.size += modrm_size;
      decoded->operand_capacity = get_operand_capacity32(decoded);

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
        memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, WORD_SZ);
        decoded->buffer.size += WORD_SZ;
        decoded->operand_capacity =
            get_operand_capacity32(decoded);
        return true;
      default:
        return false;
      }
    } else {
      decoded->op1 = *i_ptr;
      memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, BYTE_SZ);
      decoded->buffer.size += BYTE_SZ;

      if (instr_zero(decoded)) {
        decoded->instr_type = INSTR_ZERO;
        decoded->operand_capacity =
            get_operand_capacity32(decoded);
        return true; // if no other bytes are coming after
      }

      if (instr_other(decoded)) {
        decoded->instr_type = INSTR_OTHER;
        size_t op_size = get_operand_size32(decoded);
        if (op_size == 0)
          return false;

        i_ptr++;
        memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, op_size);
        decoded->buffer.size += op_size;
        decoded->operand_capacity =
            get_operand_capacity32(decoded);

        if (instr_has_immediate_operand(decoded))
          decoded->status |= STATUS_IMMEDIATE_OPERAND;
        else if (instr_has_rel_offset_operand(decoded))
          decoded->status |= STATUS_REL_OFFSET_OPERAND;
        else if (instr_has_direct_addr_operand(decoded))
          decoded->status |= STATUS_DIRECT_ADDR_OPERAND;
        else
          return false;

        set_instruction_operand(decoded, op_size);
        return true;
      }

      if (instr_modrm(decoded)) {
        i_ptr++;
        decoded->instr_type = INSTR_MODRM;
        decoded->modrm.field = *i_ptr;
        decoded->modrm.mod = (decoded->modrm.field & 0xC0) >> 6;
        decoded->modrm.reg = (decoded->modrm.field & 0x38) >> 3;
        decoded->modrm.rm = (decoded->modrm.field & 0x07);

        if (instr_has_opcode_extension(decoded) &&
            instr_has_valid_extension(decoded)) {
          decoded->status |= STATUS_OPCODE_EXTENSION;
          size_t op_size =
              get_opcode_extension_operand_size(decoded);
          memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, op_size);
          decoded->buffer.size += op_size;
        }

        size_t modrm_size = get_modrm_size(decoded, i_ptr);
        memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, modrm_size);
        decoded->buffer.size += modrm_size;
        decoded->operand_capacity =
            get_operand_capacity32(decoded);
        return true;
      }

      return false;
    }
  } else { // one byte opcode is gonna be here

    decoded->op1 = *i_ptr;
    memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, BYTE_SZ);
    decoded->buffer.size += BYTE_SZ;

    if (instr_zero(decoded)) {
      decoded->instr_type = INSTR_ZERO;
      decoded->operand_capacity = get_operand_capacity32(decoded);
      return true; // if no other bytes are coming after
    }

    if (instr_other(decoded)) {
      decoded->instr_type = INSTR_OTHER;
      size_t op_size = get_operand_size32(decoded);
      if (op_size == 0)
        return false;

      i_ptr++;
      memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, op_size);
      decoded->buffer.size += op_size;
      decoded->operand_capacity = get_operand_capacity32(decoded);

      if (instr_has_immediate_operand(decoded))
        decoded->status |= STATUS_IMMEDIATE_OPERAND;
      else if (instr_has_rel_offset_operand(decoded))
        decoded->status |= STATUS_REL_OFFSET_OPERAND;
      else if (instr_has_direct_addr_operand(decoded))
        decoded->status |= STATUS_DIRECT_ADDR_OPERAND;
      else
        return false;

      set_instruction_operand(decoded, op_size);
      return true;
    }

    if (instr_modrm(decoded)) {
      i_ptr++;
      decoded->instr_type = INSTR_MODRM;
      decoded->modrm.field = *i_ptr;
      decoded->modrm.mod = (decoded->modrm.field & 0xC0) >> 6;
      decoded->modrm.reg = (decoded->modrm.field & 0x38) >> 3;
      decoded->modrm.rm = (decoded->modrm.field & 0x07);

      if (instr_has_opcode_extension(decoded) &&
          instr_has_valid_extension(decoded)) {
        decoded->status |= STATUS_OPCODE_EXTENSION;
        size_t op_size =
            get_opcode_extension_operand_size(decoded);
        memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, op_size);
        decoded->buffer.size += op_size;
      }

      size_t modrm_size = get_modrm_size(decoded, i_ptr);
      memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, modrm_size);
      decoded->buffer.size += modrm_size;
      decoded->operand_capacity = get_operand_capacity32(decoded);
      return true;
    }
  }

  return false;
}

/*
 * Decodes 64-bit instruction
 */
bool decode64(Dinstruction *decoded, unsigned char *instruction) {
  //     In 64-bit mode, instruction formats do not change. Bits needed to
  //     define fields in the 64-bit context are provided by the
  // addition of REX prefixes.
  unsigned char *i_ptr = instruction;

  while (instr_has_prefix(*i_ptr)) {
    decoded->status |= STATUS_PREFIX;
    if (*i_ptr == PREFIX_OPSZ_OVERRIDE)
      decoded->status |= STATUS_OPSIZE_OVERRIDE;

    decoded->prefixes.prefix[decoded->prefixes.size] = *i_ptr;
    memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, BYTE_SZ);
    decoded->buffer.size += BYTE_SZ;
    decoded->prefixes.size = decoded->buffer.size;
    i_ptr++;
  }

  if (instr_has_rex(*i_ptr)) {
    decoded->status |= STATUS_REX;
    memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, BYTE_SZ);
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
    decoded->status |= STATUS_EXTENDED;
    memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, BYTE_SZ);
    decoded->buffer.size += BYTE_SZ;
    i_ptr++;
    if (*i_ptr == 0x38 || *i_ptr == 0x3A) {
      // if it has secondary opcode
      decoded->op1 = *i_ptr;
      memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, BYTE_SZ);
      decoded->buffer.size += BYTE_SZ;

      i_ptr++;
      decoded->op2 = *i_ptr;
      memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, BYTE_SZ);
      decoded->buffer.size += BYTE_SZ;

      i_ptr++;
      decoded->instr_type = INSTR_MODRM;
      decoded->modrm.field = *i_ptr;
      decoded->modrm.mod = (decoded->modrm.field & 0xC0) >> 6;
      decoded->modrm.reg = (decoded->modrm.field & 0x38) >> 3;
      decoded->modrm.rm = (decoded->modrm.field & 0x07);

      size_t modrm_size = get_modrm_size(decoded, i_ptr);
      memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, modrm_size);
      decoded->buffer.size += modrm_size;
      decoded->operand_capacity = get_operand_capacity64(decoded);

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
        memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, WORD_SZ);
        decoded->buffer.size += WORD_SZ;
        decoded->operand_capacity =
            get_operand_capacity64(decoded);
        return true;
      default:
        return false;
      }
    } else {
      decoded->op1 = *i_ptr;
      memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, BYTE_SZ);
      decoded->buffer.size += BYTE_SZ;

      if (instr_zero(decoded)) {
        decoded->instr_type = INSTR_ZERO;
        decoded->operand_capacity =
            get_operand_capacity64(decoded);
        return true; // if no other bytes are coming after
      }

      if (instr_other(decoded)) {
        decoded->instr_type = INSTR_OTHER;
        size_t op_size = get_operand_size32(decoded);
        if (op_size == 0)
          return false;

        memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, op_size);
        decoded->buffer.size += op_size;
        decoded->operand_capacity =
            get_operand_capacity64(decoded);
        return true;
      }

      if (instr_modrm(decoded)) {
        i_ptr++;
        decoded->instr_type = INSTR_MODRM;
        decoded->modrm.field = *i_ptr;
        decoded->modrm.mod = (decoded->modrm.field & 0xC0) >> 6;
        decoded->modrm.reg = (decoded->modrm.field & 0x38) >> 3;
        decoded->modrm.rm = (decoded->modrm.field & 0x07);

        if (instr_has_opcode_extension(decoded) &&
            instr_has_valid_extension(decoded)) {
          decoded->status |= STATUS_OPCODE_EXTENSION;
          size_t op_size =
              get_opcode_extension_operand_size(decoded);
          memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, op_size);
          decoded->buffer.size += op_size;
        }

        size_t modrm_size = get_modrm_size(decoded, i_ptr);
        memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, modrm_size);
        decoded->buffer.size += modrm_size;
        decoded->operand_capacity =
            get_operand_capacity64(decoded);
        return true;
      }
    }
    return false;
  }

  if (instr_has_vex(*i_ptr)) {
    decoded->status |= STATUS_VEX;
    size_t vex_size = get_vex_size(*i_ptr);
    memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, vex_size);
    decoded->buffer.size += vex_size;
    i_ptr++;
  }

  decoded->op1 = *i_ptr;
  memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, BYTE_SZ);
  decoded->buffer.size += BYTE_SZ;

  if (instr_zero(decoded)) {
    decoded->instr_type = INSTR_ZERO;
    decoded->operand_capacity = get_operand_capacity64(decoded);
    return true; // if no other bytes are coming after
  }

  if (instr_other(decoded)) {
    decoded->instr_type = INSTR_OTHER;
    size_t op_size = get_operand_size64(decoded);
    if (op_size == 0)
      return false;

    memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, op_size);
    decoded->buffer.size += op_size;
    decoded->operand_capacity = get_operand_capacity64(decoded);
    return true;
  }

  if (instr_modrm(decoded)) {
    i_ptr++;
    decoded->instr_type = INSTR_MODRM;
    decoded->modrm.field = *i_ptr;
    decoded->modrm.mod = (decoded->modrm.field & 0xC0) >> 6;
    decoded->modrm.reg = (decoded->modrm.field & 0x38) >> 3;
    decoded->modrm.rm = (decoded->modrm.field & 0x07);

    if (instr_has_opcode_extension(decoded) &&
        instr_has_valid_extension(decoded)) {
      decoded->status |= STATUS_OPCODE_EXTENSION;
      size_t op_size = get_opcode_extension_operand_size(decoded);
      memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, op_size);
      decoded->buffer.size += op_size;
    }

    size_t modrm_size = get_modrm_size(decoded, i_ptr);
    memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, modrm_size);
    decoded->buffer.size += modrm_size;
    decoded->operand_capacity = get_operand_capacity64(decoded);
    return true;
  }

  return false;
}

bool decode(Dinstruction *decoded, unsigned char *instruction) {
  switch (decoded->mode) {
  case 32:
    return decode32(decoded, instruction);
  case 64:
    return decode64(decoded, instruction);
  default:
    return false;
  }
}
