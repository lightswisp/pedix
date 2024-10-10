#include <pedix/decoder.h>
#include <pedix/dump.h>
#include <stdio.h>

//#define INSTRUCTION_LIMIT 102 
#define INSTRUCTION_LIMIT 1 


int main(void) {
  // todo: add valid prefix check
  // ex: 66 0f 74 04 00 -> is a valid instruction, while f3 0f 74 04 00 is not
  uint64_t offset, instructions;
  uint8_t instruction[] = {  0xda, 0x08};
  decoded_instruction_t *decoded = pedix_init_instruction();
  pedix_set_mode(decoded, MODE_32);

  /* curr offset */
  offset = 0;
  /* instruction counter */
  instructions = 0;

  while (instructions < INSTRUCTION_LIMIT) {
   pedix_decode(decoded, instruction + offset);

#ifdef DEBUG
    pedix_dump_instruction(decoded->instruction);
#endif
    /* if everything went well */
    pedix_print_instruction(decoded, offset);
    /* eat bytes */
    offset += decoded->buffer.size;
    /* go to the next instruction */
    instructions++;
    /* zero the struct */
    pedix_zero_instruction(decoded);
  }

  pedix_free_instrucion(decoded);
  return 0;
}

