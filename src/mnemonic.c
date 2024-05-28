#include <string.h>
#include "mnemonic.h"

void set_mnemonic(Dinstruction* decoded, unsigned char instruction){
    if(decoded->status.extended){
    		if(decoded->status.has_opcode_extension){
    			// extended and has extension
    			char* ex_m = m_extd_ex_table[instruction][decoded->modrm.reg];
    			memcpy(decoded->mnemonic.str, ex_m, strlen(ex_m));
    		}
    		else{
    			// just extended
	        char* extd_m = ex_m_table[instruction];
	        memcpy(decoded->mnemonic.str, extd_m, strlen(extd_m));
        }
    }
    else{
    		if(decoded->status.has_opcode_extension){
    			// has extension
    			char* ex_m = m_ex_table[instruction][decoded->modrm.reg];
    			memcpy(decoded->mnemonic.str, ex_m, strlen(ex_m));
    		}
    		else{
    			// regular opcode
	        char* m = m_table[instruction];
	        memcpy(decoded->mnemonic.str, m, strlen(m));
        }
    }
}

void set_operands(Dinstruction* decoded){
    // todo
}

void set_immediate(Dinstruction* decoded){
    // todo
}
