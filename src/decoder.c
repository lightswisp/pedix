#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "decoder.h"
#include "defines.h"
#include "iutils.h"

void dump(Dinstruction* decoded){
    printf("========================================\n");
    printf("instruction size: %llu\n", decoded->size);
    printf("has_prefix: %d\n", decoded->has_prefix);
    printf("0x0f extended: %d\n", decoded->extended);

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
        }
    }

    if(decoded->has_prefix){
        printf("instruction prefix 1: 0x%02X\n", decoded->prefixes[0]);
        printf("instruction extended opcode: 0x%02X\n", decoded->prefixes[1]);
    }
    else{
        if(decoded->extended)
            printf("instruction extended opcode: 0x%02X\n", decoded->prefixes[0]);
    }

    printf("instruction opcode 1: 0x%02X\n", decoded->op1);
    printf("instruction opcode 2: 0x%02X\n", decoded->op2);
    printf("========================================\n\n");
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

bool decode32(unsigned char* insruction, Dinstruction* decoded, unsigned int mode){

    // https://sparksandflames.com/files/x86InstructionChart.html

    unsigned char* i_ptr = insruction;

    if(instr_has_prefix(*i_ptr)){
        decoded->has_prefix = true;
        decoded->prefixes[0] = *i_ptr;
        decoded->size+=BYTE_SZ;
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

        decoded->size+=BYTE_SZ;
        i_ptr++;

        if(*i_ptr == 0x38 || *i_ptr == 0x3A){
            // if it has secondary opcode
            decoded->op1 = *i_ptr;
            decoded->size+=BYTE_SZ;
            printf("I_PTR: 0x%02x\n", *i_ptr);
            i_ptr++;
            decoded->op2 = *i_ptr;
            decoded->size+=BYTE_SZ;
            printf("I_PTR: 0x%02x\n", *i_ptr);
            size_t modrm_size = get_modrm_size(decoded, i_ptr);
            printf("MODRM_SZ: %d\n", modrm_size);
            printf("SIZE BEFORE: %d\n", decoded->size);
            if(modrm_size == 0)
                return false;
            
            printf("SIZE: %d\n", modrm_size);
            decoded->size += modrm_size;

            return true;
        }
        else if(*i_ptr == 0x01){
            decoded->op1 = *i_ptr;
            i_ptr++;
            //maybe i should also add VMCALL, VMLAUNCH, VMRESUME, VMXOFF, MONITOR, MWAIT, XGETBV, XSETBV and RDTSCP support as well?
            switch(*i_ptr){
                case 0xC1: case 0xC2: case 0xC3: case 0xC4:
                case 0xC8: case 0xC9: case 0xD0: case 0xD1:
                case 0xF9:
                    decoded->op2 = *i_ptr;
                    decoded->size+=WORD_SZ;
                    return true;
                default:
                    return false;
            }
        }  
        else{
            // todo: implement extended opcodes
            decoded->op1 = *i_ptr;
            decoded->size+=1;

            if(extended_instr_zero(decoded->op1)){
                decoded->instr_type = INSTR_ZERO;
                return true;  // if no (mod/rm, imm or rel jmp offset) byte is coming after
            }

            if(extended_instr_other(decoded->op1)){
                decoded->instr_type = INSTR_OTHER;
                size_t op_size = get_operand_size(decoded, decoded->op1);
                if(op_size == 0)
                    return false;

                decoded->size+=op_size;
                return true;
            }

            if(extended_instr_modrm(decoded->op1)){
                size_t modrm_size = get_modrm_size(decoded, i_ptr);
                if(modrm_size == 0)
                    return false;            

                decoded->size += modrm_size;
                return true;
            }
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
            size_t op_size = get_operand_size(decoded, decoded->op1);
            if(op_size == 0)
                return false;

            decoded->size+=op_size;
            return true;
        }

        if(instr_modrm(decoded->op1)){
            size_t modrm_size = get_modrm_size(decoded, i_ptr);
            if(modrm_size == 0)
                return false;

            decoded->size += modrm_size;
            return true;
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