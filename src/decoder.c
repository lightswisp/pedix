#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "decoder.h"
#include "utils.h"

void dump(Dinstruction* decoded){
    printf("========================================\n");
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
        }
    }

    if(decoded->has_prefix)
        printf("instruction prefix 1: 0x%02X\n", decoded->prefixes[0]);

    if(decoded->extended)
        printf("instruction prefix 2: 0x%02X\n", decoded->prefixes[1]);

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
            // todo: implement extended opcodes
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
            if(instr_has_immediate_operand(decoded->op1)){
                decoded->size+=get_immediate_operand_size(decoded->op1);
                return true;
            }

            else if(instr_has_rel_offset_operand(decoded->op1)){
                decoded->size+=get_rel_offset_operand_size(decoded->op1);
                return true;
            }

            else if(instr_has_direct_addr_operand(decoded->op1)){
                decoded->size+=get_direct_addr_operand_size(decoded->op1);
                return true;
            }

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
                    if(rm == 4) // SIB MODE
                        decoded->size+=1;

                    decoded->size+=1; // one byte signed displacement (disp8)
                    break;
                case 2:
                    if(rm == 4) // SIB MODE
                        decoded->size+=1;

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