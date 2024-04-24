#include <stdio.h>
#include "decoder.h"    


int main(void){
    //unsigned char instruction[] = {0x0F, 0x05};
    //unsigned char instruction[] = {0x66, 0x0F, 0x3A, 0x09, 0x01};
    //unsigned char instruction[] = {0x45, 0x00};
    // unsigned char instruction[] = { 0x55, 0x89, 0x25, 0x00, 0x00, 0x00, 0x00, 0xB8, 0x13, 0x00, 0x00, 0x00, 0xC9, 0xC3 };
    unsigned char instruction[] = { 0x55, 0x89, 0xE5, 0x83, 0xEC, 0x20, 0xC9, 0xC3 } ;
    Dinstruction* decoded = init_instruction();
    unsigned int mode = 32;
    
    int offset = 0;
    while(true){
        int r = decode(instruction + offset, decoded, mode);
        if(r == 0){
            break;
        }
        dump(decoded);
        offset+=decoded->size;
        zero_instruction(decoded);
    }
    // printf("result: %d\n", decode(instruction, decoded, mode));
    // dump(decoded);

    free_instrucion(decoded);
    return 0;
}