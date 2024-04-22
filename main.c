#include <stdio.h>
#include "decoder.h"    


int main(void){
    //unsigned char instruction[] = {0x0F, 0x05};
    //unsigned char instruction[] = {0x66, 0x0F, 0x3A, 0x09, 0x01};
    //unsigned char instruction[] = {0x45, 0x00};
    // unsigned char instruction[] = { 0x55, 0x89, 0x25, 0x00, 0x00, 0x00, 0x00, 0xB8, 0x13, 0x00, 0x00, 0x00, 0xC9, 0xC3 };
    unsigned char instruction[] = {0x00, 0x05};
    Dinstruction* decoded = init_instruction();
    unsigned int mode = 32;
    
    puts("1");
    printf("result: %d\n", decode(instruction, decoded, mode));

    dump(decoded);

    free_instrucion(decoded);
    return 0;
}