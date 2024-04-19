#include <stdio.h>
#include <stdlib.h>
#include "decoder.h"

void dump(Dinstruction* decoded){
    printf("instruction size: %llu\n", decoded->size);
    printf("has_prefix: %d\n", decoded->has_prefix);
    printf("extended: %d\n", decoded->extended);
    printf("instruction prefix: 0x%02X\n", decoded->prefix);
    printf("instruction opcode 1: 0x%02X\n", decoded->op1);
    printf("instruction opcode 2: 0x%02X\n", decoded->op2);
}

Dinstruction* init_instruction(){
    Dinstruction* decoded = (Dinstruction*)calloc(1, sizeof(Dinstruction));
    return decoded;
}

void free_instrucion(Dinstruction* decoded){
    free(decoded);
}

bool instr_has_prefix(unsigned char instruction){
    switch(instruction){
        case LOCK: 
        case REPNE_Z:
        case REP_E_Z: 
        case CS:
        case DS: 
        case SS:
        case ES: 
        case FS:
        case GS: 
        case OPSZ_OVERRIDE:
        case ASZ_OVERRIDE:
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

bool instr_has_zero_operands(unsigned char opcode){
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
        return true;
    }
    return false;
}

bool instr_has_rel_offset_operand(unsigned char opcode){
    return false;
}

bool instr_has_modrm(unsigned char opcode){
    return false;
}

unsigned int get_immediate_operand_size(unsigned char opcode){
    switch(opcode){
        case 0x04: case 0x0C: case 0x14: case 0x1C: case 0x24:
        case 0x2C: case 0x34: case 0x3C: case 0x6A: case 0x70: 
        case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: 
        case 0x76: case 0x77: case 0x78: case 0x79: case 0x7A:
        case 0x7B: case 0x7C: case 0x7D: case 0x7E: case 0x7F: 
        case 0xA8: case 0xB0: case 0xB1: case 0xB2: case 0xB3: 
        case 0xB4: case 0xB5: case 0xB6: case 0xB7: case 0xCD: 
        case 0xD4: case 0xD5: case 0xE0: case 0xE1: case 0xE2: 
        case 0xE3: case 0xE4: case 0xE5: case 0xE6: case 0xE7:
        case 0xEB:
            return IMM_BYTE; 
    }
}

unsigned int get_rel_offset_operand_size(unsigned char opcode){

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

        if(instr_has_zero_operands(decoded->op1 )){ // if no (mod/rm, imm or rel jmp offset) byte is coming after
            return true;
        }

        if(instr_has_immediate_operand(decoded->op1)){
            i_ptr++;
            decoded->size+=get_immediate_operand_size(decoded->op1);

            return true;
        }

        if(instr_has_rel_offset_operand(decoded->op1)){
            i_ptr++;
            decoded->size+=get_rel_offset_operand_size(decoded->op1); // probably not just one :)
            return true;
        }

        i_ptr++;

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
    return true;
}

bool decode64(unsigned char* insruction, Dinstruction* decoded, unsigned int mode){
    // todo
    return true;
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