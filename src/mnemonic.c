#include <string.h>
#include "mnemonic.h"

bool set_mnemonic(Dinstruction* decoded, unsigned char instruction){
    if(decoded->status.extended){
    		if(decoded->status.has_opcode_extension){
    			// extended and has extension (extended_opcode_with_extensions_table)
				if(decoded->modrm.mod == 0x03){ // register addressing
					switch(decoded->prefixes.prefix[0]){
						case 0x66:
							// handle extended with extension + mod 11B and 0x66 prefix
							char* m_66 = extd_ext_11b_66[instruction][decoded->modrm.reg];
							memcpy(decoded->mnemonic.str, m_66, strlen(m_66));
							return true;
						case 0xF3:
							// handle extended with extension + mod 11B and 0xF3 prefix
							char* m_f3 = extd_ext_11b_f3[instruction][decoded->modrm.reg];
							memcpy(decoded->mnemonic.str, m_f3, strlen(m_f3));
							return true;
					}

					// no prefix here (but with modrm.mod == 11B)
					if(instruction == 0x01){
						// vmcall, vmlaunch ...
						char* m = extd_ext_11b_rm[decoded->modrm.reg][decoded->modrm.rm];
						memcpy(decoded->mnemonic.str, m, strlen(m));
						return true;
					}
					else{
						char* m = extd_ext_11b[instruction][decoded->modrm.reg];
						memcpy(decoded->mnemonic.str, m, strlen(m));
						return true;
					}
				}
				else{ //memory addressing
					switch(decoded->prefixes.prefix[0]){
						case 0x66:
							// handle extended with extension + mod mem and 0x66 prefix
							char* m_66 = extd_ext_mem_66[instruction][decoded->modrm.reg];
							memcpy(decoded->mnemonic.str, m_66, strlen(m_66));
							return true;
						case 0xF3:
							// handle extended with extension + mod mem and 0xF3 prefix
							char* m_f3 = extd_ext_mem_f3[instruction][decoded->modrm.reg];
							memcpy(decoded->mnemonic.str, m_f3, strlen(m_f3));
							return true;
					}

					// no prefix here (but with modrm.mod == mem)
					char* m = extd_ext_mem[instruction][decoded->modrm.reg];
					memcpy(decoded->mnemonic.str, m, strlen(m));
					return true;
				}

    		}
    		else{
				// just extended (extended_opcode_table)
				char* extd_m = extd[instruction];
				memcpy(decoded->mnemonic.str, extd_m, strlen(extd_m));
				return true;
        	}
    }
    else{
    		if(decoded->status.has_opcode_extension){
    			// has extension (regular_opcode_with_extensions_table)
				if(decoded->modrm.mod == 0x03){ // register addressing
					char* m = reg_ext_11b[instruction][decoded->modrm.reg];
					memcpy(decoded->mnemonic.str, m, strlen(m));
					return true;
				}
				else{  //memory addressing
					char* m = reg_ext_mem[instruction][decoded->modrm.reg];
					memcpy(decoded->mnemonic.str, m, strlen(m));
					return true;
				}

    		}
    		else{
    			// regular opcode (regular_opcode_table)
				char* m = reg[instruction];
				memcpy(decoded->mnemonic.str, m, strlen(m));
				return true;
        	}
    }
	return false;
}

void set_operands(Dinstruction* decoded){
    // todo
}

void set_immediate(Dinstruction* decoded){
    // todo
}
