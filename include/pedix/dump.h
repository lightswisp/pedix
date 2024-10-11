#include "iutils.h"
#include "decoder.h"
#include "tables/tabledef.h"

void pedix_dump_instruction(instruction_t *decoded);     
void pedix_dump_memory(uint8_t* addr, size_t size);
void pedix_print_instruction(decoded_instruction_t *decoded, uint64_t offset);  
