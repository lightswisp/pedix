#include "iutils.h"
#include "defines.h"

bool instr_has_prefix(unsigned char instruction){
    switch(instruction){
        case PREFIX_LOCK: 
        case PREFIX_REPNE_Z:
        case PREFIX_REP_E_Z: 
        case PREFIX_CS:
        case PREFIX_DS: 
        case PREFIX_SS:
        case PREFIX_ES: 
        case PREFIX_FS:
        case PREFIX_GS: 
        case PREFIX_OPSZ_OVERRIDE:
        case PREFIX_ASZ_OVERRIDE:
            return true;

        default:
            return false;
    }
}

bool instr_modrm(Dinstruction* decoded, unsigned char opcode){
    if(decoded->extended){
        switch(opcode){

            case 0x00: case 0x01: case 0x02: case 0x03: case 0x0D:
            case 0x10: case 0x11: case 0x12: case 0x13: case 0x14:
            case 0x15: case 0x16: case 0x17: case 0x18: case 0x19:
            case 0x1A: case 0x1B: case 0x1C: case 0x1D: case 0x1E:
            case 0x28: case 0x29: case 0x2A: case 0x2B: case 0x2C: 
            case 0x2D: case 0x2E: case 0x2F: case 0x40: case 0x41:
            case 0x42: case 0x43: case 0x44: case 0x45: case 0x46:
            case 0x47: case 0x48: case 0x49: case 0x4A: case 0x4B:
            case 0x4C: case 0x4D: case 0x4E: case 0x4F: case 0x51: 
            case 0x52: case 0x53: case 0x54: case 0x55: case 0x56:
            case 0x57: case 0x58: case 0x59: case 0x5A: case 0x5B:
            case 0x5C: case 0x5D: case 0x5E: case 0x5F: case 0x60:
            case 0x61: case 0x62: case 0x63: case 0x64: case 0x65:
            case 0x66: case 0x67: case 0x68: case 0x69: case 0x6A:
            case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F:
            case 0x70: case 0x71: case 0x72: case 0x73: case 0x74:

                return true;
            default:
                return false;
        }
    }
    switch(opcode){
        case 0x00: case 0x01: case 0x02: case 0x03: case 0x08: 
        case 0x09: case 0x0A: case 0x0B: case 0x10: case 0x11:
        case 0x12: case 0x13: case 0x18: case 0x19: case 0x1A:
        case 0x1B: case 0x20: case 0x21: case 0x22: case 0x23:
        case 0x28: case 0x29: case 0x2A: case 0x2B: case 0x30:
        case 0x31: case 0x32: case 0x33: case 0x38: case 0x39:
        case 0x3A: case 0x3B: case 0x63: case 0x69: case 0x6B:
        case 0x80: case 0x81: case 0x82: case 0x83: case 0x84:
        case 0x85: case 0x86: case 0x87: case 0x88: case 0x89:
        case 0x8A: case 0x8B: case 0x8C: case 0x8E: case 0x8F:
        case 0xC6: case 0xC7: case 0xC0: case 0xC1: case 0xD0:
        case 0xD1: case 0xD2: case 0xD3: case 0xF6: case 0xF7:
        case 0x62: case 0x8D: case 0xC4: case 0xC5: case 0xD8:
        case 0xD9: case 0xDA: case 0xDB: case 0xDC: case 0xDD:
        case 0xDE: case 0xDF: case 0xFE: case 0xFF: 
            return true;
        default:
            return false;
    }
}


bool instr_other(Dinstruction* decoded, unsigned char opcode){
    if(decoded->extended){
        switch(opcode){
            case 0x20: case 0x21: case 0x22: case 0x23: case 0x24:
            case 0x26: case 0x50:
                return true;
            default:
                return false;
        }
    }
    switch(opcode){
        case 0x04: case 0x05: case 0x0C: case 0x0D: case 0x14:
        case 0x15: case 0x1C: case 0x1D: case 0x24: case 0x25:
        case 0x2C: case 0x2D: case 0x34: case 0x35: case 0x3C: 
        case 0x3D: case 0x68: case 0x6A: case 0x70: case 0x71:
        case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: 
        case 0x77: case 0x78: case 0x79: case 0x7A: case 0x7B:
        case 0x7C: case 0x7D: case 0x7E: case 0x7F: case 0x9A:
        case 0xA0: case 0xA1: case 0xA2: case 0xA3: case 0xA8:
        case 0xA9: case 0xB0: case 0xB1: case 0xB2: case 0xB3:
        case 0xB4: case 0xB5: case 0xB6: case 0xB7: case 0xB8:
        case 0xB9: case 0xBA: case 0xBB: case 0xBC: case 0xBD: 
        case 0xBE: case 0xBF: case 0xC2: case 0xCA: case 0xCD:
        case 0xD4: case 0xD5: case 0xE0: case 0xE1: case 0xE2:
        case 0xE3: case 0xE4: case 0xE5: case 0xE6: case 0xE7: 
        case 0xE8: case 0xE9: case 0xEA: case 0xEB: case 0xC8:
            return true;

        default:
            return false;
    }
}

bool instr_zero(Dinstruction* decoded, unsigned char opcode){
    if(decoded->extended){
        switch(opcode){
            case 0x05: case 0x06: case 0x07: case 0x08: case 0x09:
            case 0x0B: case 0x30: case 0x31: case 0x32: case 0x33:
            case 0x34: case 0x35: case 0x37:

                return true;
            default:
                return false;
        }
    }

    switch(opcode){
        case 0x06: case 0x07: case 0x0E: case 0x16: case 0x17:
        case 0x1E: case 0x1F: case 0x27: case 0x2F: case 0x37:
        case 0x3F: case 0x40: case 0x41: case 0x42: case 0x43:
        case 0x44: case 0x45: case 0x46: case 0x47: case 0x48:
        case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D:
        case 0x4E: case 0x4F: case 0x50: case 0x51: case 0x52:
        case 0x53: case 0x54: case 0x55: case 0x56: case 0x57:
        case 0x58: case 0x59: case 0x5A: case 0x5B: case 0x5C:
        case 0x5D: case 0x5E: case 0x5F: case 0x60: case 0x61:
        case 0x6C: case 0x6D: case 0x6E: case 0x6F: case 0x90:
        case 0x91: case 0x92: case 0x93: case 0x94: case 0x95:
        case 0x96: case 0x97: case 0x98: case 0x99: case 0x9B:
        case 0x9C: case 0x9D: case 0x9E: case 0x9F: case 0xA4:
        case 0xA5: case 0xA6: case 0xA7: case 0xAA: case 0xAB: 
        case 0xAC: case 0xAD: case 0xAE: case 0xAF: case 0xC3: 
        case 0xC9: case 0xCB: case 0xCC: case 0xCE: case 0xCF: 
        case 0xD7: case 0xEC: case 0xED: case 0xEE: case 0xEF:
        case 0xF4: case 0xF5: case 0xF8: case 0xF9: case 0xFA: 
        case 0xFB: case 0xFC: case 0xFD:   
            return true;

        default:
            return false;
    }
}

bool instr_has_opcode_extension(Dinstruction* decoded, unsigned char opcode){
    //Table A-6. Opcode Extensions for One- and Two-byte Opcodes by Group Number
    // VEX.0F38 F3 todo
    if(decoded->extended){
        switch(opcode){
            case 0x00: case 0x01: case 0xBA: case 0xC7: case 0xB9:
            case 0x71: case 0x72: case 0x73: case 0xAE: case 0x18:
                return true;
            default: 
                return false;
        }
    }
    switch(opcode){
        case 0x80: case 0x81: case 0x82: case 0x83: case 0x8F:
        case 0xC0: case 0xC1: case 0xD0: case 0xD1: case 0xD2:
        case 0xD3: case 0xF6: case 0xF7: case 0xFE: case 0xFF:
        case 0xC6: case 0xC7: 
            return true;
        default:
            return false;
    }
}

bool instr_has_valid_extension(Dinstruction* decoded, unsigned char opcode){
    // Table A-6. Opcode Extensions for One- and Two-byte Opcodes by Group Number
    unsigned int reg = (decoded->mod & 0x38) >> 3;
    if(decoded->extended){
        switch(opcode){
            case 0x00:
                switch(reg){
                    case 0x06: case 0x07:
                        return false;
                    default:
                        return true;
                }
            case 0x01:
                switch(reg){
                    case 0x05:
                        return false;
                    default:
                        return true;
                }
            case 0xBA:
                switch(reg){
                    case 0x04: case 0x05: case 0x06: case 0x07:
                        return true;
                    default:
                        return false;
                }
            case 0xC7:
                switch(reg){
                    case 0x01: case 0x06: case 0x07:
                        return true;
                    default:
                        return false;
                }
            case 0xB9:
                return true;
            case 0x71:
                switch(reg){
                    case 0x02: case 0x04: case 0x06:
                        return true;
                    default:
                        return false;
                }
            case 0x72:
                switch(reg){
                    case 0x02: case 0x04: case 0x06:
                        return true;
                    default:
                        return false;
                }
            case 0x73:
                switch(reg){
                    case 0x02: case 0x03: case 0x06: case 0x07:
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
    switch(opcode){
        case 0x80: case 0x81: case 0x82: case 0x83: 
            return true;
        case 0x8F:
            switch(reg){
                case 0x00:
                    return true;
                default: 
                    return false;
            }
        case 0xC0: case 0xC1: case 0xD0: 
        case 0xD1: case 0xD2: case 0xD3:
            switch(reg){
                case 0x06:
                    return false;
                default:
                    return true;
            }
        case 0xF6: case 0xF7:
            switch(reg){
                case 0x01:
                    return false;
                default:
                    return true;
            }
        case 0xFE:
            switch(reg){
                case 0x01: case 0x02:
                    return true;
                default:
                    return false;
            }
        case 0xFF:
            switch(reg){
                case 0x07:
                    return false;
                default:
                    return true;
            }
        case 0xC6: case 0xC7:
            switch(reg){
                case 0x00: case 0x07:
                    return true;
                default:
                    return false;
            }
        
    }
}

bool instr_has_extended_opcode(unsigned char instruction){
    // it means that the opcode size is 2bytes long
    if(instruction == 0x0F)
        return true;
    return false;
}

bool instr_has_immediate_operand(Dinstruction* decoded, unsigned char opcode){
    if(decoded->extended){
        switch(opcode){
            case 0x3A: case 0x38:
                switch(decoded->op2){
                    case 0x08: case 0x09: case 0x0A: case 0x0B: case 0x0C:
                    case 0x0D: case 0x0E: case 0x14: case 0x15: case 0x16:
                    case 0x17: case 0x20: case 0x21: case 0x22: case 0x42:
                    case 0x60: case 0x61: case 0x62: case 0x63:
                        return true;
                    default:
                        return false;
                }
            case 0x70: case 0x71: case 0x72: case 0x73:
                return true;
            default:
                return false;
        }            
        
    }
    switch(opcode){
        case 0x04: case 0x05: case 0x0C: case 0x0D: case 0x14:
        case 0x15: case 0x1C: case 0x1D: case 0x24: case 0x25:
        case 0x2C: case 0x2D: case 0x34: case 0x35: case 0x3C:
        case 0x3D: case 0x68: case 0x6A: case 0xA8: case 0xA9:
        case 0xB0: case 0xB1: case 0xB2: case 0xB3: case 0xB4:
        case 0xB5: case 0xB6: case 0xB7: case 0xB8: case 0xB9: 
        case 0xBA: case 0xBB: case 0xBC: case 0xBD: case 0xBE:
        case 0xBF: case 0xC2: case 0xCA: case 0xCD: case 0xD4:
        case 0xD5: case 0xE4: case 0xE5: case 0xE6: case 0xE7:
        case 0x69: case 0x6B: case 0x80: case 0x81: case 0x82:
        case 0x83: case 0xC0: case 0xC1: case 0xC6: case 0xC7:
        case 0xC8: 
            return true;

        default:
            return false;
    }
}

bool instr_has_rel_offset_operand(unsigned char opcode){
    // relative address jumps
    switch (opcode) {
        case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: 
        case 0x75: case 0x76: case 0x77: case 0x78: case 0x79: 
        case 0x7A: case 0x7B: case 0x7C: case 0x7D: case 0x7E: 
        case 0x7F: case 0xE0: case 0xE1: case 0xE2: case 0xE3: 
        case 0xE8: case 0xE9: case 0xEB:
            return true;

        default:
            return false;
    }
}

bool instr_has_direct_addr_operand(unsigned char opcode){
    // absolute address jump/call
    switch (opcode) {
        case 0x9A: case 0xEA:
            return true;
        default:
            return false;
    }
}

size_t get_modrm_size(Dinstruction* decoded){
    size_t modrm_size = 0;
    // mod/rm part is gonna be here
    unsigned int mod = (decoded->mod & 0xC0) >> 6;
    unsigned int reg = (decoded->mod & 0x38) >> 3;
    unsigned int rm  = (decoded->mod & 0x07);

    decoded->mod = mod;

    modrm_size+=1; //mod/rm byte

    switch(mod){
        case 0:
            switch(rm){
                case 4:
                    // SIB MODE
                    modrm_size+=BYTE_SZ; //1 sib byte follows mod/rm field  (SIB with no displacement)
                    break;
                case 5:
                    modrm_size+=DOUBLEWORD_SZ; //4 byte displacement field follows mod/rm field
                    // 32-bit Displacement-Only Mode
                    break;
            }
            break;
        case 1:
            if(rm == 4) // SIB MODE
                modrm_size+=BYTE_SZ;

            modrm_size+=BYTE_SZ; // one byte signed displacement (disp8)
            break;
        case 2:
            if(rm == 4) // SIB MODE
                modrm_size+=BYTE_SZ;

            modrm_size+=DOUBLEWORD_SZ; // four byte signed displacement (disp32)
            break;
        case 3:
            // register addressing mode
            break;

    }

    if(instr_has_immediate_operand(decoded, decoded->op1)){
        modrm_size+=get_operand_size(decoded, decoded->op1);
    }
            

    return modrm_size;
}

size_t get_operand_size(Dinstruction* decoded, unsigned char opcode){
    if(decoded->extended){
        switch(opcode){
            case 0x38: case 0x3A:
                switch(opcode){
                    case 0x08: case 0x09: case 0x0A: case 0x0B: case 0x0C:
                    case 0x0D: case 0x0E: case 0x14: case 0x15: case 0x16:
                    case 0x17: case 0x20: case 0x21: case 0x22: case 0x42:
                    case 0x60: case 0x61: case 0x62: case 0x63:
                        return BYTE_SZ;
                }
            case 0x20: case 0x21: case 0x22: case 0x23: case 0x24:
            case 0x26: case 0x50: case 0x70: case 0x71: case 0x72: 
            case 0x73:
                return BYTE_SZ;
            default:
                return 0;
        }
    }
    switch(opcode){
        case 0x04: case 0x0C: case 0x14: case 0x1C: case 0x24:
        case 0x2C: case 0x34: case 0x3C: case 0x6A: case 0xA8: 
        case 0xB0: case 0xB1: case 0xB2: case 0xB3: case 0xB4: 
        case 0xB5: case 0xB6: case 0xB7: case 0xCD: case 0xD4: 
        case 0xD5: case 0xE4: case 0xE5: case 0xE6: case 0xE7:
        case 0x6B: case 0x80: case 0x82: case 0x83: case 0xC0:
        case 0xC1: case 0xC6: case 0x70: case 0x71: case 0x72: 
        case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
        case 0x78: case 0x79: case 0x7A: case 0x7B: case 0x7C: 
        case 0x7D: case 0x7E: case 0x7F: case 0xE0: case 0xE1: 
        case 0xE2: case 0xE3: case 0xEB:
            return BYTE_SZ; 

        case 0xC2: case 0xCA:
            return WORD_SZ;

        case 0x05: case 0x0D: case 0x15: case 0x1D: case 0x25:
        case 0x2D: case 0x35: case 0x3D: case 0x68: case 0xA1:
        case 0xA3: case 0xA9: case 0xB8: case 0xB9: case 0xBA:
        case 0xBB: case 0xBC: case 0xBD: case 0xBE: case 0xBF:
        case 0x69: case 0x81: case 0xC7: case 0xE8: case 0xE9:
            return DOUBLEWORD_SZ;
        
        case 0xC8:
            return (WORD_SZ + BYTE_SZ); // ENTER Iw Ib => Word + Byte = 3 

        case 0x9A: case 0xEA:
            return ADDR_48_SZ;

        default:
            return 0;

    }
}
