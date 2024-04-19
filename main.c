#include <stdio.h>
#include "decoder.h"    


int main(void){
    unsigned char instruction[] = {0x0F, 0x05};
    //unsigned char instruction[] = {0x66, 0x0F, 0x3A, 0x09, 0x01};
    //unsigned char instruction[] = {0x45, 0x00};
    Dinstruction* decoded = init_instruction();
    unsigned int mode = 32;
    

    printf("result: %d\n", decode(instruction, decoded, mode));

    dump(decoded);

    free_instrucion(decoded);
    return 0;
}