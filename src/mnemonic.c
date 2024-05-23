#include <string.h>
#include "mnemonic.h"

void set_mnemonic(Dinstruction* decoded, unsigned char instruction){
    if(decoded->extended){
        char* ex_m = ex_m_table[instruction];
        memcpy(decoded->mnemonic.str, ex_m, strlen(ex_m));
    }
    else{
        char* m = m_table[instruction];
        memcpy(decoded->mnemonic.str, m, strlen(m));
    }
}

void set_operands(Dinstruction* decoded){
    // todo
}

void set_immediate(Dinstruction* decoded){
    // todo
}