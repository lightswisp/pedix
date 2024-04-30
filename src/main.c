#include <stdio.h>
#include "decoder.h"    


int main(void){
    unsigned char instruction[] = { 0xB8, 0x00, 0xF9, 0x5F, 0x1F, 0xBA, 0x00, 0x00, 0x00, 0x00, 0xB9, 0x1B, 0x00, 0x00, 0x00, 0x0F, 0x30 } ;
    //unsigned char instruction[] = {0x66, 0x0F, 0x3A, 0x09, 0x01};
    //unsigned char instruction[] = {0x45, 0x00};
    // unsigned char instruction[] = { 0x55, 0x89, 0x25, 0x00, 0x00, 0x00, 0x00, 0xB8, 0x13, 0x00, 0x00, 0x00, 0xC9, 0xC3 };
    //unsigned char instruction[] = { 0x62, 0x80, 0x40, 0x30, 0x20, 0x10, 0x01, 0x00, 0xD8, 0x80, 0x12, 0x12, 0x12, 0x12   } ;
    Dinstruction* decoded = init_instruction();
    unsigned int mode = 32;
    
    int offset = 0;
    int instructions = 0;
    while(instructions < 5){
        int r = decode(instruction + offset, decoded, mode);
        if(r == 0){
            break;
        }
        dump(decoded);
        offset+=decoded->size;
        instructions++;
        zero_instruction(decoded);
    }
    // printf("result: %d\n", decode(instruction, decoded, mode));
    // dump(decoded);

    free_instrucion(decoded);
    return 0;
}