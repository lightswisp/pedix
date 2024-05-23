#include "decoder.h"
#include <stdio.h>

int main(void){
    //unsigned char instruction[] = { 0xB8, 0x00, 0x00, 0x00, 0x00, 0xBA, 0xFF, 0xFF, 0xFF, 0xFF, 0x89, 0xD0, 0x48, 0x50, 0x59, 0xF7, 0xD8, 0xC1, 0xF8, 0x03, 0x0F, 0x31, 0x48, 0x48, 0x0F, 0x6F, 0x04, 0x08, 0x48, 0x0F, 0x18, 0x00, 0x66, 0x0F, 0x6F, 0xC2, 0x66, 0x0F, 0x6F, 0x18, 0x48, 0x0F, 0x18, 0x08, 0x66, 0x0F, 0x28, 0x40, 0x08 };


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

                //{0x0F, 0x2f, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00}
    // unsigned char instruction[] = { 0x55, 
    //                                 0x89, 0x25, 0x00, 0x00, 0x00, 0x00, 
    //                                 0xB8, 0x13, 0x00, 0x00, 0x00, 
    //                                 0xC9, 
    //                                 0xC3, 
    //                                 0x0F, 0x00, 0x90, 0x14, 0x13, 0x12, 0x11, 
    //                                 0x0F, 0x02, 0x08,
    //                                 0x00, 0x01,
    //                                 0x0F, 0x05,
    //                                 0x0F, 0x0D, 0x00,
    //                                 0x0F, 0x10, 0x89, 0x20, 0x10, 0x00, 0x00,
    //                                 0x0F, 0x19, 0x89, 0x20, 0x10, 0x11, 0x22,
    //                                 0x0F, 0x23, 0x22,
    //                                 0x66, 0x0F, 0x3A, 0x08, 0x12, 0xff,
    //                                 0x0F, 0x42, 0x00,
    //                                 0x0F, 0x01, 0xC1,                                  
    //                                 0x0F, 0x70, 0x44, 0x43, 0x10, 0x10, 
    //                                 0x00, 0x84, 0x4F, 0x40, 0x30, 0x20, 0x10,
    //                                 0xD0, 0x44, 0xC1, 0x10
    // };

    
    unsigned char instruction[] = { 0x4b, 0xC7, 0xC0, 0x40, 0x30, 0x20, 0x10 } ;
    Dinstruction* decoded = init_instruction();
    unsigned int mode = 64;
    
    int offset = 0;
    int instructions = 0;
    while(instructions < 1){
        int r = decode(decoded, instruction + offset, mode);
        if(r == 0){
            printf("Error has occured while decoding!\n");
            dump(decoded);
            break;
        }
        dump(decoded);
        printf("%s\n\n", decoded->mnemonic.str);
        offset += decoded->buffer.size;
        instructions++;
        zero_instruction(decoded);
    }
    // printf("result: %d\n", decode(instruction, decoded, mode));
    // dump(decoded);

    free_instrucion(decoded);
    return 0;
}
