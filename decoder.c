#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "decoder.h"
#include "defines.h"

void dump(Dinstruction* decoded){
    printf("instruction size: %llu\n", decoded->size);
    printf("has_prefix: %d\n", decoded->has_prefix);
    printf("extended: %d\n", decoded->extended);

    if(decoded->instr_type){
        switch(decoded->instr_type){
            case INSTR_ZERO:
                printf("type: ZERO\n");
                break;
            case INSTR_MODRM:
                printf("type: HAS MOD R/M\n");
                break;
            case INSTR_OTHER:
                printf("type: OTHER\n");
                break;
            case INSTR_UNDEC:
                printf("type: UNDEC\n");
                break;
        }
    }

    if(decoded->has_prefix)
        printf("instruction prefix 1: 0x%02X\n", decoded->prefixes[0]);

    if(decoded->extended)
        printf("instruction prefix 2: 0x%02X\n", decoded->prefixes[1]);

    printf("instruction opcode 1: 0x%02X\n", decoded->op1);
    printf("instruction opcode 2: 0x%02X\n", decoded->op2);
}

Dinstruction* init_instruction(){
    Dinstruction* decoded = (Dinstruction*)calloc(1, sizeof(Dinstruction));
    return decoded;
}

void zero_instruction(Dinstruction* decoded){
    memset(decoded, 0, sizeof(Dinstruction));
}

void free_instrucion(Dinstruction* decoded){
    free(decoded);
}

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
    }
    return false;
}

bool instr_has_extended_opcode(unsigned char instruction){
    // it means that the opcode size is 2bytes long
    if(instruction == 0x0F)
        return true;
    return false;
}

bool instr_modrm(unsigned char opcode){
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
            return true;
    }
    return false;
}

bool instr_other(unsigned char opcode){
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
        case 0xE8: case 0xE9: case 0xEA: case 0xEB:
            return true;
    }
    return false;
}

bool instr_zero(unsigned char opcode){
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
    }
    return false;
}

bool instr_undec(unsigned char opcode){
    switch(opcode){

    }
    return false;
}

bool instr_has_immediate_operand(unsigned char opcode){
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
            return true;
    }
    return false;
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
    }
    return false;
}

bool instr_has_direct_addr_operand(unsigned char opcode){
    // absolute address jump/call
    switch (opcode) {
        case 0x9A: case 0xEA:
            return true;
    }
    return false;
}


unsigned int get_immediate_operand_size(unsigned char opcode){
    switch(opcode){
        case 0x04: case 0x0C: case 0x14: case 0x1C: case 0x24:
        case 0x2C: case 0x34: case 0x3C: case 0x6A: case 0xA8: 
        case 0xB0: case 0xB1: case 0xB2: case 0xB3: case 0xB4: 
        case 0xB5: case 0xB6: case 0xB7: case 0xCD: case 0xD4: 
        case 0xD5: case 0xE4: case 0xE5: case 0xE6: case 0xE7:
        case 0x6B: case 0x80: case 0x82: case 0x83: case 0xC0:
        case 0xC1: case 0xC6:
            return BYTE_SZ; 

        case 0xC2: case 0xCA:
            return WORD_SZ;

        case 0x05: case 0x0D: case 0x15: case 0x1D: case 0x25:
        case 0x2D: case 0x35: case 0x3D: case 0x68: case 0xA1:
        case 0xA3: case 0xA9: case 0xB8: case 0xB9: case 0xBA:
        case 0xBB: case 0xBC: case 0xBD: case 0xBE: case 0xBF:
        case 0x69: case 0x81: case 0xC7:
            return DOUBLEWORD_SZ;

    }
    return 0;
}

unsigned int get_rel_offset_operand_size(unsigned char opcode){
    switch (opcode) {
        case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: 
        case 0x75: case 0x76: case 0x77: case 0x78: case 0x79: 
        case 0x7A: case 0x7B: case 0x7C: case 0x7D: case 0x7E: 
        case 0x7F: case 0xE0: case 0xE1: case 0xE2: case 0xE3:
        case 0xEB:
            return BYTE_SZ;

        case 0xE8: case 0xE9:
            return DOUBLEWORD_SZ;

    }
    return 0;
}

unsigned int get_direct_addr_operand_size(unsigned char opcode){
    switch (opcode) {
        case 0x9A: case 0xEA:
        return ADDR_48_SZ;
    }
    return 0;
}


bool decode32(unsigned char* insruction, Dinstruction* decoded, unsigned int mode){

    // https://sparksandflames.com/files/x86InstructionChart.html

    unsigned char* i_ptr = insruction;

    if(instr_has_prefix(*i_ptr)){
        decoded->has_prefix = true;
        decoded->prefixes[0] = *i_ptr;
        decoded->size+=1;
        i_ptr++;
    }
    
    // 00-3f: arith-logical operations: ADD, ADC,SUB,SBB,AND...
    // 40-7f: INC/PUSH/POP, Jcc,...
    // 80-bf: data movement: MOV,LODS,STOS,...
    // c0-ff: misc and escape groups

    if(instr_has_extended_opcode(*i_ptr)){
        // 0x0f (two byte opcode is gonna be decoded here)
        decoded->extended = true;
        if(decoded->has_prefix){
            decoded->prefixes[1] = *i_ptr;
        }
        else{
            decoded->prefixes[0] = *i_ptr;
        }
        decoded->size+=1;
        i_ptr++;

        if(*i_ptr == 0x38 || *i_ptr == 0x3A){
            // if it has secondary opcode
            decoded->op1 = *i_ptr;
            i_ptr++;
            decoded->size+=1;

            decoded->op2 = *i_ptr;
            i_ptr++;
            decoded->size+=1;
        }
        // else if -> maybe i should also add VMCALL, VMLAUNCH, VMRESUME, VMXOFF, MONITOR, MWAIT, XGETBV, XSETBV and RDTSCP support as well?
        else{
            decoded->op1 = *i_ptr;
            i_ptr++;
            decoded->size+=1;
        }
    }
    else{  // one byte opcode is gonna be here

        decoded->op1 = *i_ptr;
        decoded->size+=1;   

        if(instr_zero(decoded->op1)){
            decoded->instr_type = INSTR_ZERO;
            return true;  // if no (mod/rm, imm or rel jmp offset) byte is coming after
        }

        if(instr_other(decoded->op1)){
            decoded->instr_type = INSTR_OTHER;
            if(instr_has_immediate_operand(decoded->op1))
                decoded->size+=get_immediate_operand_size(decoded->op1);

            if(instr_has_rel_offset_operand(decoded->op1))
                decoded->size+=get_rel_offset_operand_size(decoded->op1);

            if(instr_has_direct_addr_operand(decoded->op1))
                decoded->size+=get_direct_addr_operand_size(decoded->op1);

            return true;
        }

        if(instr_modrm(decoded->op1)){
            decoded->instr_type = INSTR_MODRM;
            i_ptr++;
            // mod/rm part is gonna be here
            unsigned int mod = (*i_ptr & 0xC0) >> 6;
            unsigned int reg = (*i_ptr & 0x38) >> 3;
            unsigned int rm  = (*i_ptr & 0x07);

            decoded->mod = mod;

            decoded->size+=1; //mod/rm byte
            // Some instructions cannot make use of the REG portion of the ModR/M byte. 
            // Many of these instructions are "multiplexed" using this field, where a single opcode can refer to multiple instructions, and the REG field determines the instruction. 
            // In opcode listings, these are specified by following the opcode with a slash (/) and a digit 0-7
            

            // MOD R/M Addressing Mode
            // === === ================================
            // 00  000 [ eax ]
            // 01  000 [ eax + disp8 ]              
            // 10  000 [ eax + disp32 ]
            // 11  000 register  ( al / ax / eax )   
            // 00  001 [ ecx ]
            // 01  001 [ ecx + disp8 ]
            // 10  001 [ ecx + disp32 ]
            // 11  001 register  ( cl / cx / ecx )
            // 00  010 [ edx ]
            // 01  010 [ edx + disp8 ]
            // 10  010 [ edx + disp32 ]
            // 11  010 register  ( dl / dx / edx )
            // 00  011 [ ebx ]
            // 01  011 [ ebx + disp8 ]
            // 10  011 [ ebx + disp32 ]
            // 11  011 register  ( bl / bx / ebx )
            // 00  100 SIB  Mode                     
            // 01  100 SIB  +  disp8  Mode
            // 10  100 SIB  +  disp32  Mode
            // 11  100 register  ( ah / sp / esp )
            // 00  101 32-bit Displacement-Only Mode 
            // 01  101 [ ebp + disp8 ]
            // 10  101 [ ebp + disp32 ]
            // 11  101 register  ( ch / bp / ebp )
            // 00  110 [ esi ]
            // 01  110 [ esi + disp8 ]
            // 10  110 [ esi + disp32 ]
            // 11  110 register  ( dh / si / esi )
            // 00  111 [ edi ]
            // 01  111 [ edi + disp8 ]
            // 10  111 [ edi + disp32 ]
            // 11  111 register  ( bh / di / edi )

            switch(mod){
                case 0:
                    switch(rm){
                        case 4:
                            // SIB MODE
                            decoded->size+=1; //1 sib byte follows mod/rm field
                            break;
                        case 5:
                            decoded->size+=4; //4 byte displacement field follows mod/rm field
                            // 32-bit Displacement-Only Mode
                            break;
                    }
                    break;
                case 1:
                    decoded->size+=1; // one byte signed displacement (disp8)
                    break;
                case 2:
                    decoded->size+=4; // four byte signed displacement (disp32)
                    break;
                case 3:
                    // register addressing mode
                    break;

            }

            if(instr_has_immediate_operand(decoded->op1))
                decoded->size+=get_immediate_operand_size(decoded->op1);

            return true;
        }

        if(instr_undec(decoded->op1)){
            decoded->instr_type = INSTR_UNDEC;
            return false;
        }


        /*
            Example:
            ADD opcode => [0 0 0 0 0 0 d s]
            d = 0 if adding from register to memory
            d = 1 if adding from memory to register
            s = 0 if adding 8bit operands
            s = 1 if adding 16bit or 32bit operands

            REMARK: 
            d = 1 => instruction source is in reg field
            d = 0 => instruction destination is in reg field
            
            bit marked "d" specifies the direction of data transfer:
            if d = 0 then we add from register to memory
                add [ebx], al
            
            [0 0 0 0 0 0 0 0] [0 0 0 0 0 0 1 1]
            reg1 = instruction & 

            if d = 1 then we add from memory to register
                add al, [ebx]

            [0 0 0 0 0 0 1 0] [0 0 0 0 0 0 1 1]
        */


    }



    //printf("%x\n", *i_ptr);
    return false;
}

bool decode64(unsigned char* insruction, Dinstruction* decoded, unsigned int mode){
    // todo
    return false;
}

bool decode(unsigned char* insruction, Dinstruction* decoded, unsigned int mode){
    switch(mode){
        case 32:
            return decode32(insruction, decoded, mode);
        case 64:
            return decode64(insruction, decoded, mode);
        default: 
            return false;
    }
}