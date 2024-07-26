#include "headers/iutils.h"

/*
 * check if instruction has any prefixes
 */
bool instr_has_prefix(uchar8_t opcode) {
  switch (opcode) {
  case PREFIX_LOCK:
  case PREFIX_REPNE_Z:
  case PREFIX_REP_E_Z:
  case PREFIX_CS:
  case PREFIX_DS:
  case PREFIX_SS:
  case PREFIX_ES:
  case PREFIX_FS:
  case PREFIX_GS:
  case PREFIX_OPSIZE_OVERRIDE:
  case PREFIX_ASZ_OVERRIDE:
    return true;

  default:
    return false;
  }
}

/*
 * check if instruction has vex
 */
bool instr_has_vex(uchar8_t opcode) {
  switch (opcode) {
  case 0xC5:
  case 0xC4:
    return true;
  default:
    return false;
  }
}

/*
 * check if instruction has rex
 */
bool instr_has_rex(uchar8_t opcode) {
  // rex prefixes are a set of 16 opcodes that span one row of the opcode map
  // and occupy entries 40h to 4fh. these opcodes represent valid instructions
  // (inc or dec) in ia-32 operating modes and in compatibility mode. in 64-bit
  // mode, the same opcodes represent the instruction prefix rex and are not
  // treated as individual instructions. the single-byte-opcode forms of the
  // inc/dec instructions are not available in 64-bit mode. inc/dec
  // functionality is still available using modr/m forms of the same
  // instructions (opcodes ff/0 and ff/1).
  switch (opcode) {
  case 0x40:
  case 0x41:
  case 0x42:
  case 0x43:
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x47:
  case 0x48:
  case 0x49:
  case 0x4A:
  case 0x4B:
  case 0x4C:
  case 0x4D:
  case 0x4E:
  case 0x4F:
    return true;
  default:
    return false;
  }
}

/*
 * check if instruction has modrm byte
 */
bool instr_modrm(Dinstruction *decoded) {
  if (HAS_STATUS(decoded->status, STATUS_EXTENDED)) {
    switch (decoded->op1) {
    case 0x00:
    case 0x01:
    case 0x02:
    case 0x03:
    case 0x0D:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x18:
    case 0x19:
    case 0x1A:
    case 0x1B:
    case 0x1C:
    case 0x1D:
    case 0x1E:
    case 0x28:
    case 0x29:
    case 0x2A:
    case 0x2B:
    case 0x2C:
    case 0x2D:
    case 0x2E:
    case 0x2F:
    case 0x40:
    case 0x41:
    case 0x42:
    case 0x43:
    case 0x44:
    case 0x45:
    case 0x46:
    case 0x47:
    case 0x48:
    case 0x49:
    case 0x4A:
    case 0x4B:
    case 0x4C:
    case 0x4D:
    case 0x4E:
    case 0x4F:
    case 0x51:
    case 0x52:
    case 0x53:
    case 0x54:
    case 0x55:
    case 0x56:
    case 0x57:
    case 0x58:
    case 0x59:
    case 0x5A:
    case 0x5B:
    case 0x5C:
    case 0x5D:
    case 0x5E:
    case 0x5F:
    case 0x60:
    case 0x61:
    case 0x62:
    case 0x63:
    case 0x64:
    case 0x65:
    case 0x66:
    case 0x67:
    case 0x68:
    case 0x69:
    case 0x6A:
    case 0x6B:
    case 0x6C:
    case 0x6D:
    case 0x6E:
    case 0x6F:
    case 0x70:
    case 0x71:
    case 0x72:
    case 0x73:
    case 0x74:
    case 0x75:
    case 0x76:
    case 0x78:
    case 0x79:
    case 0x7C:
    case 0x7D:
    case 0x7E:
    case 0x7F:
    case 0x90:
    case 0x91:
    case 0x92:
    case 0x93:
    case 0x94:
    case 0x95:
    case 0x96:
    case 0x97:
    case 0x98:
    case 0x99:
    case 0x9A:
    case 0x9B:
    case 0x9C:
    case 0x9D:
    case 0x9E:
    case 0x9F:
    case 0xA3:
    case 0xA4:
    case 0xA5:
    case 0xAB:
    case 0xAC:
    case 0xAD:
    case 0xAE:
    case 0xAF:
    case 0xB0:
    case 0xB1:
    case 0xB2:
    case 0xB3:
    case 0xB4:
    case 0xB5:
    case 0xB6:
    case 0xB7:
    case 0xB8:
    case 0xB9:
    case 0xBA:
    case 0xBB:
    case 0xBC:
    case 0xBD:
    case 0xBE:
    case 0xBF:
    case 0xC0:
    case 0xC1:
    case 0xC2:
    case 0xC3:
    case 0xC4:
    case 0xC5:
    case 0xC6:
    case 0xC7:
    case 0xD0:
    case 0xD1:
    case 0xD2:
    case 0xD3:
    case 0xD4:
    case 0xD5:
    case 0xD6:
    case 0xD7:
    case 0xD8:
    case 0xD9:
    case 0xDA:
    case 0xDB:
    case 0xDC:
    case 0xDD:
    case 0xDE:
    case 0xDF:
    case 0xE0:
    case 0xE1:
    case 0xE2:
    case 0xE3:
    case 0xE4:
    case 0xE5:
    case 0xE6:
    case 0xE7:
    case 0xE8:
    case 0xE9:
    case 0xEA:
    case 0xEB:
    case 0xEC:
    case 0xED:
    case 0xEE:
    case 0xEF:
    case 0xF0:
    case 0xF1:
    case 0xF2:
    case 0xF3:
    case 0xF4:
    case 0xF5:
    case 0xF6:
    case 0xF7:
    case 0xF8:
    case 0xF9:
    case 0xFA:
    case 0xFB:
    case 0xFC:
    case 0xFD:
    case 0xFE:
    case 0xFF:
    case 0x1F:
      return true;
    default:
      return false;
    }
  }
  switch (decoded->op1) {
  case 0x00:
  case 0x01:
  case 0x02:
  case 0x03:
  case 0x08:
  case 0x09:
  case 0x0A:
  case 0x0B:
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x18:
  case 0x19:
  case 0x1A:
  case 0x1B:
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x28:
  case 0x29:
  case 0x2A:
  case 0x2B:
  case 0x30:
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x38:
  case 0x39:
  case 0x3A:
  case 0x3B:
  case 0x63:
  case 0x69:
  case 0x6B:
  case 0x80:
  case 0x81:
  case 0x82:
  case 0x83:
  case 0x84:
  case 0x85:
  case 0x86:
  case 0x87:
  case 0x88:
  case 0x89:
  case 0x8A:
  case 0x8B:
  case 0x8C:
  case 0x8E:
  case 0x8F:
  case 0xC6:
  case 0xC7:
  case 0xC0:
  case 0xC1:
  case 0xD0:
  case 0xD1:
  case 0xD2:
  case 0xD3:
  case 0xF6:
  case 0xF7:
  case 0x62:
  case 0x8D:
  case 0xC4:
  case 0xC5:
  case 0xD8:
  case 0xD9:
  case 0xDA:
  case 0xDB:
  case 0xDC:
  case 0xDD:
  case 0xDE:
  case 0xDF:
  case 0xFE:
  case 0xFF:
    return true;
  default:
    return false;
  }
}

/*
 * check if instruction is "other"
 */
bool instr_other(Dinstruction *decoded) {
  if (HAS_STATUS(decoded->status, STATUS_EXTENDED)) {
    switch (decoded->op1) {
    case 0x20:
    case 0x21:
    case 0x22:
    case 0x23:
    case 0x24:
    case 0x26:
    case 0x50:
    case 0x80:
    case 0x81:
    case 0x82:
    case 0x83:
    case 0x84:
    case 0x85:
    case 0x86:
    case 0x87:
    case 0x88:
    case 0x89:
    case 0x8A:
    case 0x8B:
    case 0x8C:
    case 0x8D:
    case 0x8E:
    case 0x8F:
      return true;
    default:
      return false;
    }
  }
  switch (decoded->op1) {
  case 0x04:
  case 0x05:
  case 0x0C:
  case 0x0D:
  case 0x14:
  case 0x15:
  case 0x1C:
  case 0x1D:
  case 0x24:
  case 0x25:
  case 0x2C:
  case 0x2D:
  case 0x34:
  case 0x35:
  case 0x3C:
  case 0x3D:
  case 0x68:
  case 0x6A:
  case 0x70:
  case 0x71:
  case 0x72:
  case 0x73:
  case 0x74:
  case 0x75:
  case 0x76:
  case 0x77:
  case 0x78:
  case 0x79:
  case 0x7A:
  case 0x7B:
  case 0x7C:
  case 0x7D:
  case 0x7E:
  case 0x7F:
  case 0x9A:
  case 0xA0:
  case 0xA1:
  case 0xA2:
  case 0xA3:
  case 0xA8:
  case 0xA9:
  case 0xB0:
  case 0xB1:
  case 0xB2:
  case 0xB3:
  case 0xB4:
  case 0xB5:
  case 0xB6:
  case 0xB7:
  case 0xB8:
  case 0xB9:
  case 0xBA:
  case 0xBB:
  case 0xBC:
  case 0xBD:
  case 0xBE:
  case 0xBF:
  case 0xC2:
  case 0xCA:
  case 0xCD:
  case 0xD4:
  case 0xD5:
  case 0xE0:
  case 0xE1:
  case 0xE2:
  case 0xE3:
  case 0xE4:
  case 0xE5:
  case 0xE6:
  case 0xE7:
  case 0xE8:
  case 0xE9:
  case 0xEA:
  case 0xEB:
  case 0xC8:
    return true;

  default:
    return false;
  }
}

/* 
 * check if instruction has zero/one operand
 */
bool instr_zero(Dinstruction *decoded) {
  if (HAS_STATUS(decoded->status, STATUS_EXTENDED)) {
    switch (decoded->op1) {
    case 0x05:
    case 0x06:
    case 0x07:
    case 0x08:
    case 0x09:
    case 0x0B:
    case 0x30:
    case 0x31:
    case 0x32:
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x37:
    case 0x77:
    case 0xA0:
    case 0xA1:
    case 0xA2:
    case 0xA8:
    case 0xA9:
    case 0xAA:
    case 0xC8:
    case 0xC9:
    case 0xCA:
    case 0xCB:
    case 0xCC:
    case 0xCD:
    case 0xCE:
    case 0xCF:

      return true;
    default:
      return false;
    }
  }

  switch (decoded->op1) {
  case 0x06:
  case 0x07:
  case 0x0E:
  case 0x16:
  case 0x17:
  case 0x1E:
  case 0x1F:
  case 0x27:
  case 0x2F:
  case 0x37:
  case 0x3F:
  case 0x40:
  case 0x41:
  case 0x42:
  case 0x43:
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x47:
  case 0x48:
  case 0x49:
  case 0x4A:
  case 0x4B:
  case 0x4C:
  case 0x4D:
  case 0x4E:
  case 0x4F:
  case 0x50:
  case 0x51:
  case 0x52:
  case 0x53:
  case 0x54:
  case 0x55:
  case 0x56:
  case 0x57:
  case 0x58:
  case 0x59:
  case 0x5A:
  case 0x5B:
  case 0x5C:
  case 0x5D:
  case 0x5E:
  case 0x5F:
  case 0x60:
  case 0x61:
  case 0x6C:
  case 0x6D:
  case 0x6E:
  case 0x6F:
  case 0x90:
  case 0x91:
  case 0x92:
  case 0x93:
  case 0x94:
  case 0x95:
  case 0x96:
  case 0x97:
  case 0x98:
  case 0x99:
  case 0x9B:
  case 0x9C:
  case 0x9D:
  case 0x9E:
  case 0x9F:
  case 0xA4:
  case 0xA5:
  case 0xA6:
  case 0xA7:
  case 0xAA:
  case 0xAB:
  case 0xAC:
  case 0xAD:
  case 0xAE:
  case 0xAF:
  case 0xC3:
  case 0xC9:
  case 0xCB:
  case 0xCC:
  case 0xCE:
  case 0xCF:
  case 0xD7:
  case 0xEC:
  case 0xED:
  case 0xEE:
  case 0xEF:
  case 0xF4:
  case 0xF5:
  case 0xF8:
  case 0xF9:
  case 0xFA:
  case 0xFB:
  case 0xFC:
  case 0xFD:
    return true;

  default:
    return false;
  }
}

/*
 * check if instruction has secondary opcode
 */
bool instr_has_secondary_opcode(uchar8_t opcode) {
  switch (opcode) {
  case 0x38:
  case 0x3A:
    return true;
  }
  return false;
}

/*
 * check if instruction has opcode extension
 */
bool instr_has_opcode_extension(Dinstruction *decoded) {
  // table a-6. opcode extensions for one- and two-byte opcodes by group number
  //  vex.0f38 f3 todo
  if (HAS_STATUS(decoded->status, STATUS_EXTENDED)) {
    switch (decoded->op1) {
    case 0x00:
    case 0x01:
    case 0xBA:
    case 0xC7:
    case 0xB9:
    case 0x71:
    case 0x72:
    case 0x73:
    case 0xAE:
    case 0x18:
      return true;
    default:
      return false;
    }
  }
  switch (decoded->op1) {
  case 0x80:
  case 0x81:
  case 0x82:
  case 0x83:
  case 0x8F:
  case 0xC0:
  case 0xC1:
  case 0xD0:
  case 0xD1:
  case 0xD2:
  case 0xD3:
  case 0xF6:
  case 0xF7:
  case 0xFE:
  case 0xFF:
  case 0xC6:
  case 0xC7:
    return true;
  default:
    return false;
  }
}

/*
 * check if instruction has valid extension
 */
bool instr_has_valid_extension(Dinstruction *decoded) {
  // table a-6. opcode extensions for one- and two-byte opcodes by group number
  // todo: add validation by  prefix
  // check for  decoded->prefixes[0] in both  cases (extended and not)
  if (HAS_STATUS(decoded->status, STATUS_EXTENDED)) {
    switch (decoded->op1) {
    case 0x00:
      switch (decoded->modrm.reg) {
      case 0x06:
      case 0x07:
        return false;
      default:
        return true;
      }
    case 0x01:
      switch (decoded->modrm.reg) {
      case 0x05:
        return false;
      default:
        return true;
      }
    case 0xBA:
      switch (decoded->modrm.reg) {
      case 0x04:
      case 0x05:
      case 0x06:
      case 0x07:
        return true;
      default:
        return false;
      }
    case 0xC7:
      switch (decoded->modrm.reg) {
      case 0x01:
      case 0x06:
      case 0x07:
        return true;
      default:
        return false;
      }
    case 0xB9:
      return true;
    case 0x71:
      switch (decoded->modrm.reg) {
      case 0x02:
      case 0x04:
      case 0x06:
        return true;
      default:
        return false;
      }
    case 0x72:
      switch (decoded->modrm.reg) {
      case 0x02:
      case 0x04:
      case 0x06:
        return true;
      default:
        return false;
      }
    case 0x73:
      switch (decoded->modrm.reg) {
      case 0x02:
      case 0x03:
      case 0x06:
      case 0x07:
        return true;
      default:
        return false;
      }
    case 0xAE:
      return true;
    case 0x18:
      return true;
    }
  }
  switch (decoded->op1) {
  case 0x80:
  case 0x81:
  case 0x82:
  case 0x83:
    return true;
  case 0x8F:
    switch (decoded->modrm.reg) {
    case 0x00:
      return true;
    default:
      return false;
    }
  case 0xC0:
  case 0xC1:
  case 0xD0:
  case 0xD1:
  case 0xD2:
  case 0xD3:
    switch (decoded->modrm.reg) {
    case 0x06:
      return false;
    default:
      return true;
    }
  case 0xF6:
  case 0xF7:
    switch (decoded->modrm.reg) {
    case 0x01:
      return false;
    default:
      return true;
    }
  case 0xFE:
    switch (decoded->modrm.reg) {
    case 0x00:
    case 0x01:
      return true;
    default:
      return false;
    }
  case 0xFF:
    switch (decoded->modrm.reg) {
    case 0x07:
      return false;
    default:
      return true;
    }
  case 0xC6:
  case 0xC7:
    switch (decoded->modrm.reg) {
    case 0x00:
    case 0x07:
      return true;
    default:
      return false;
    }
  }
  return false;
}

/* 
 * check if instruction has extended opcode
 */
bool instr_has_extended_opcode(uchar8_t opcode) {
  // it means that the instruction size is at least 2 bytes long
  if (opcode == 0x0F)
    return true;
  return false;
}

/*
 * check if instruction has immediate operand
 */
bool instr_has_immediate_operand(Dinstruction *decoded) {
  if (HAS_STATUS(decoded->status, STATUS_EXTENDED)) {
    switch (decoded->op1) {
    case 0x3A:
    case 0x38:
      switch (decoded->op2) {
      case 0x08:
      case 0x09:
      case 0x0A:
      case 0x0B:
      case 0x0C:
      case 0x0D:
      case 0x0E:
      case 0x14:
      case 0x15:
      case 0x16:
      case 0x17:
      case 0x20:
      case 0x21:
      case 0x22:
      case 0x42:
      case 0x60:
      case 0x61:
      case 0x62:
      case 0x63:
        return true;
      default:
        return false;
      }
    case 0x70:
    case 0x71:
    case 0x72:
    case 0x73:
    case 0xA4:
    case 0xAC:
    case 0xBA:
    case 0xC2:
    case 0xC4:
    case 0xC5:
    case 0xC6:
      return true;
    default:
      return false;
    }
  }
  switch (decoded->op1) {
  case 0x04:
  case 0x05:
  case 0x0C:
  case 0x0D:
  case 0x14:
  case 0x15:
  case 0x1C:
  case 0x1D:
  case 0x24:
  case 0x25:
  case 0x2C:
  case 0x2D:
  case 0x34:
  case 0x35:
  case 0x3C:
  case 0x3D:
  case 0x68:
  case 0x6A:
  case 0xA8:
  case 0xA9:
  case 0xB0:
  case 0xB1:
  case 0xB2:
  case 0xB3:
  case 0xB4:
  case 0xB5:
  case 0xB6:
  case 0xB7:
  case 0xB8:
  case 0xB9:
  case 0xBA:
  case 0xBB:
  case 0xBC:
  case 0xBD:
  case 0xBE:
  case 0xBF:
  case 0xC2:
  case 0xCA:
  case 0xCD:
  case 0xD4:
  case 0xD5:
  case 0xE4:
  case 0xE5:
  case 0xE6:
  case 0xE7:
  case 0x69:
  case 0x6B:
  case 0x80:
  case 0x81:
  case 0x82:
  case 0x83:
  case 0xC0:
  case 0xC1:
  case 0xC6:
  case 0xC7:
  case 0xC8:
    return true;

  default:
    return false;
  }
}

/*
 * check if instruction has relative offset operand
 */
bool instr_has_rel_offset_operand(Dinstruction *decoded) {
  // relative address jumps
  if (HAS_STATUS(decoded->status, STATUS_EXTENDED)) {
    switch (decoded->op1) {
    case 0x80:
    case 0x81:
    case 0x82:
    case 0x83:
    case 0x84:
    case 0x85:
    case 0x86:
    case 0x87:
    case 0x88:
    case 0x89:
    case 0x8A:
    case 0x8B:
    case 0x8C:
    case 0x8D:
    case 0x8E:
    case 0x8F:
      return true;
    }
  } else {
    switch (decoded->op1) {
    case 0x70:
    case 0x71:
    case 0x72:
    case 0x73:
    case 0x74:
    case 0x75:
    case 0x76:
    case 0x77:
    case 0x78:
    case 0x79:
    case 0x7A:
    case 0x7B:
    case 0x7C:
    case 0x7D:
    case 0x7E:
    case 0x7F:
    case 0xE0:
    case 0xE1:
    case 0xE2:
    case 0xE3:
    case 0xE8:
    case 0xE9:
    case 0xEB:
    case 0xA0:
    case 0xA1:
    case 0xA2:
    case 0xA3:
      return true;
    }
  }
  return false;
}

/*
 * check if instruction has direct addr operand
 */
bool instr_has_direct_addr_operand(Dinstruction *decoded) {
  // absolute address jump/call
  switch (decoded->op1) {
  case 0x9A:
  case 0xEA:
    return true;
  default:
    return false;
  }
}

size_t get_vex_size(uchar8_t vex_byte) {
  switch (vex_byte) {
  case 0xC5:
    return WORD_LEN;
  case 0xC4:
    return THREE_BYTE_LEN;
  case 0x8F:
    return THREE_BYTE_LEN;
  }
  return 0;
}

size_t get_opcode_extension_operand_size(Dinstruction *decoded) {
  switch (decoded->op1) {
  case 0xF6:
    if (decoded->modrm.reg == 0x00) {
      return BYTE_LEN;
    }
  case 0xF7:
    if (decoded->modrm.reg == 0x00) {
      return DOUBLEWORD_LEN;
    }
  }
  return 0x00;
}

bool instr_has_sib(Dinstruction *decoded) {
 /* |mod|rm|  
  *  00 100 sib            mode                     
  *  01 100 sib  +  disp8  mode
  *  10 100 sib  +  disp32 mode
  */
  if  (decoded->modrm.rm  == 4 &&
      (decoded->modrm.mod == 0 || decoded->modrm.mod == 1 ||
       decoded->modrm.mod == 2))
    return true;
  return false;
}

bool instr_has_displacement(Dinstruction *decoded){
  switch (decoded->modrm.mod) {
  case 0:
    if (decoded->modrm.rm == 4) {
      uint8_t base = decoded->sib.base & 0x07;
      if (base == 5)
        return true;
    }
    else if (decoded->modrm.rm == 5)
      return true;
    break;
  case 1:
  case 2:
    return true;
  }
  return false;
}

void set_sib(Dinstruction *decoded, uchar8_t *i_ptr){
  decoded->sib.field = *i_ptr;
  decoded->sib.size  = BYTE_LEN;
  decoded->sib.scale = (decoded->sib.field & 0xC0) >> 6;
  decoded->sib.index = (decoded->sib.field & 0x38) >> 3;
  decoded->sib.base  = (decoded->sib.field & 0x07);
}

void set_displacement(Dinstruction *decoded){
  size_t size;
  switch (decoded->modrm.mod) {
  case 0:
    if (decoded->modrm.rm == 4) {
      uint8_t base = decoded->sib.base & 0x07;
      if (base == 5) {
        size = DOUBLEWORD_LEN;
        break;
      }
    } else if (decoded->modrm.rm == 5) {
      size = DOUBLEWORD_LEN;
      break;
    }
  case 1:
    size = BYTE_LEN;
    break;
  case 2:
    size = DOUBLEWORD_LEN;
    break;
  }

  decoded->displacement.size = size;
}

void set_modrm(Dinstruction *decoded, uchar8_t *i_ptr) {
  decoded->modrm.size = BYTE_LEN;
  decoded->modrm.field = *i_ptr;
  decoded->modrm.mod   = (decoded->modrm.field & 0xC0) >> 6;
  decoded->modrm.reg   = (decoded->modrm.field & 0x38) >> 3;
  decoded->modrm.rm    = (decoded->modrm.field & 0x07);
}

void set_operand_capacity32(Dinstruction *decoded) {
  if (HAS_STATUS(decoded->status, STATUS_EXTENDED)) {
    // todo
    switch (decoded->instr_type) {}
  } else {
    switch (decoded->instr_type) {
    case INSTR_ZERO:
      switch (decoded->op1) {
      case 0x27:
      case 0x2F:
      case 0x37:
      case 0x3F:
      case 0x60:
      case 0x61:
      case 0x90:
      case 0x98:
      case 0x99:
      case 0x9B:
      case 0x9E:
      case 0x9F:
      case 0xC3:
      case 0xC9:
      case 0xCB:
      case 0xCC:
      case 0xCE:
      case 0xCF:
      case 0xD7:
      case 0xF4:
      case 0xF5:
      case 0xF8:
      case 0xF9:
      case 0xFA:
      case 0xFB:
      case 0xFC:
      case 0xFD:
        decoded->operands.capacity = 0;
        break;
      default:
        decoded->operands.capacity = 1;
        break;
      }
    case INSTR_OTHER:
      switch (decoded->op1) {
      case 0x68:
      case 0x6A:
      case 0x70:
      case 0x71:
      case 0x72:
      case 0x73:
      case 0x74:
      case 0x75:
      case 0x76:
      case 0x77:
      case 0x78:
      case 0x79:
      case 0x7A:
      case 0x7B:
      case 0x7C:
      case 0x7D:
      case 0x7E:
      case 0x7F:
      case 0x9A:
      case 0xC2:
      case 0xCA:
      case 0xCD:
      case 0xD4:
      case 0xD5:
      case 0xE0:
      case 0xE1:
      case 0xE2:
      case 0xE3:
      case 0xE8:
      case 0xE9:
      case 0xEA:
      case 0xEB:
        // jump/call/push
        decoded->operands.capacity = 1;
        break;
      default:
        // all other
        decoded->operands.capacity = 2;
        break;
      }

    case INSTR_MODRM:
      switch (decoded->op1) {
      case 0x69:
      case 0x6B:
        // imul
        decoded->operands.capacity = 3;
        break;

      case 0x8F:
        // pop
        decoded->operands.capacity = 1;
        break;
      default:
        decoded->operands.capacity = 2;
        break;
      }
    }
  }
}

void set_operand_capacity64(Dinstruction *decoded) {
  // todo
  return;
}

void set_operand_size32(Dinstruction *decoded) {
  if (HAS_STATUS(decoded->status, STATUS_EXTENDED)) {
    switch (decoded->op1) {
    case 0x38:
    case 0x3A:
      switch (decoded->op1) {
      case 0x08:
      case 0x09:
      case 0x0A:
      case 0x0B:
      case 0x0C:
      case 0x0D:
      case 0x0E:
      case 0x14:
      case 0x15:
      case 0x16:
      case 0x17:
      case 0x20:
      case 0x21:
      case 0x22:
      case 0x42:
      case 0x60:
      case 0x61:
      case 0x62:
      case 0x63:
        decoded->operands.size = BYTE_LEN;
        break;
      }
    case 0x20:
    case 0x21:
    case 0x22:
    case 0x23:
    case 0x24:
    case 0x26:
    case 0x50:
    case 0x70:
    case 0x71:
    case 0x72:
    case 0x73:
    case 0xA4:
    case 0xAC:
    case 0xBA:
    case 0xC2:
    case 0xC4:
    case 0xC5:
    case 0xC6:
      decoded->operands.size = BYTE_LEN;
      break;
    case 0x80:
    case 0x81:
    case 0x82:
    case 0x83:
    case 0x84:
    case 0x85:
    case 0x86:
    case 0x87:
    case 0x88:
    case 0x89:
    case 0x8A:
    case 0x8B:
    case 0x8C:
    case 0x8D:
    case 0x8E:
    case 0x8F:
      decoded->operands.size = DOUBLEWORD_LEN;
      break;
    }
  } else {
    switch (decoded->op1) {
    case 0x04:
    case 0x0C:
    case 0x14:
    case 0x1C:
    case 0x24:
    case 0x2C:
    case 0x34:
    case 0x3C:
    case 0x6A:
    case 0xA8:
    case 0xB0:
    case 0xB1:
    case 0xB2:
    case 0xB3:
    case 0xB4:
    case 0xB5:
    case 0xB6:
    case 0xB7:
    case 0xCD:
    case 0xD4:
    case 0xD5:
    case 0xE4:
    case 0xE5:
    case 0xE6:
    case 0xE7:
    case 0x6B:
    case 0x80:
    case 0x82:
    case 0x83:
    case 0xC0:
    case 0xC1:
    case 0xC6:
    case 0xD0:
    case 0xD1:
    case 0xD2:
    case 0xD3:
    case 0x70:
    case 0x71:
    case 0x72:
    case 0xEB:
    case 0x73:
    case 0x74:
    case 0x75:
    case 0x76:
    case 0x77:
    case 0x78:
    case 0x79:
    case 0x7A:
    case 0x7B:
    case 0x7C:
    case 0x7D:
    case 0x7E:
    case 0x7F:
    case 0xE0:
    case 0xE1:
    case 0xE2:
    case 0xE3:
      decoded->operands.size = BYTE_LEN;
      break;

    case 0xC2:
    case 0xCA:
      decoded->operands.size = WORD_LEN;
      break;

    case 0x05:
    case 0x0D:
    case 0x15:
    case 0x1D:
    case 0x25:
    case 0x2D:
    case 0x35:
    case 0x3D:
    case 0x68:
    case 0xA0:
    case 0xA1:
    case 0xA2:
    case 0xA3:
    case 0xA9:
    case 0xB8:
    case 0xB9:
    case 0xBA:
    case 0xBB:
    case 0xBC:
    case 0xBD:
    case 0xBE:
    case 0xBF:
    case 0x69:
    case 0x81:
    case 0xC7:
    case 0xE8:
    case 0xE9:
      decoded->operands.size = (HAS_STATUS(decoded->status, STATUS_OPSIZE_OVERRIDE) ? WORD_LEN: DOUBLEWORD_LEN);
      break;

    case 0xC8:
      decoded->operands.size = (WORD_LEN + BYTE_LEN);
      break;

    case 0x9A:
    case 0xEA:
      decoded->operands.size = (HAS_STATUS(decoded->status, STATUS_OPSIZE_OVERRIDE) ? DOUBLEWORD_LEN : ADDR_48_LEN);
      break;
    }
  }
}

void set_operand_size64(Dinstruction *decoded) {
  if (HAS_STATUS(decoded->status, STATUS_REX)) {
    switch (decoded->op1) {
    case 0xB8:
    case 0xB9:
    case 0xBA:
    case 0xBB:
    case 0xBC:
    case 0xBD:
    case 0xBE:
    case 0xBF:
      decoded->operands.size = QUADWORD_LEN;
      break;
    }
  }
  if (HAS_STATUS(decoded->status, STATUS_EXTENDED)) {
    switch (decoded->op1) {
    case 0x38:
    case 0x3A:
      switch (decoded->op1) {
      case 0x08:
      case 0x09:
      case 0x0A:
      case 0x0B:
      case 0x0C:
      case 0x0D:
      case 0x0E:
      case 0x14:
      case 0x15:
      case 0x16:
      case 0x17:
      case 0x20:
      case 0x21:
      case 0x22:
      case 0x42:
      case 0x60:
      case 0x61:
      case 0x62:
      case 0x63:
        decoded->operands.size = BYTE_LEN;
        break;
      }
    case 0x20:
    case 0x21:
    case 0x22:
    case 0x23:
    case 0x24:
    case 0x26:
    case 0x50:
    case 0x70:
    case 0x71:
    case 0x72:
    case 0x73:
    case 0xA4:
    case 0xAC:
    case 0xBA:
    case 0xC2:
    case 0xC4:
    case 0xC5:
    case 0xC6:
      decoded->operands.size = BYTE_LEN;
      break;
    case 0x80:
    case 0x81:
    case 0x82:
    case 0x83:
    case 0x84:
    case 0x85:
    case 0x86:
    case 0x87:
    case 0x88:
    case 0x89:
    case 0x8A:
    case 0x8B:
    case 0x8C:
    case 0x8D:
    case 0x8E:
    case 0x8F:
      decoded->operands.size = DOUBLEWORD_LEN;
      break;
    }
  }
  switch (decoded->op1) {
  case 0x04:
  case 0x0C:
  case 0x14:
  case 0x1C:
  case 0x24:
  case 0x2C:
  case 0x34:
  case 0x3C:
  case 0x6A:
  case 0xA8:
  case 0xB0:
  case 0xB1:
  case 0xB2:
  case 0xB3:
  case 0xB4:
  case 0xB5:
  case 0xB6:
  case 0xB7:
  case 0xCD:
  case 0xD4:
  case 0xD5:
  case 0xE4:
  case 0xE5:
  case 0xE6:
  case 0xE7:
  case 0x6B:
  case 0x80:
  case 0x82:
  case 0x83:
  case 0xC0:
  case 0xC1:
  case 0xC6:
  case 0xD0:
  case 0xD1:
  case 0xD2:
  case 0xD3:
  case 0x70:
  case 0x71:
  case 0x72:
  case 0xEB:
  case 0x73:
  case 0x74:
  case 0x75:
  case 0x76:
  case 0x77:
  case 0x78:
  case 0x79:
  case 0x7A:
  case 0x7B:
  case 0x7C:
  case 0x7D:
  case 0x7E:
  case 0x7F:
  case 0xE0:
  case 0xE1:
  case 0xE2:
  case 0xE3:
    decoded->operands.size = BYTE_LEN;
    break;

  case 0xC2:
  case 0xCA:
    decoded->operands.size = WORD_LEN;
    break;

  case 0x05:
  case 0x0D:
  case 0x15:
  case 0x1D:
  case 0x25:
  case 0x2D:
  case 0x35:
  case 0x3D:
  case 0x68:
  case 0xA9:
  case 0x69:
  case 0x81:
  case 0xC7:
  case 0xE8:
  case 0xE9:
  case 0xB8:
  case 0xB9:
  case 0xBA:
  case 0xBB:
  case 0xBC:
  case 0xBD:
  case 0xBE:
  case 0xBF:
    decoded->operands.size = DOUBLEWORD_LEN;
    break;

  case 0xC8:
    decoded->operands.size = (WORD_LEN + BYTE_LEN);
    break;

  case 0x9A:
  case 0xEA:
    decoded->operands.size = ADDR_48_LEN;
    break;

  case 0xA0:
  case 0xA1:
  case 0xA2:
  case 0xA3:
    decoded->operands.size = QUADWORD_LEN;
    break;

  }
}
