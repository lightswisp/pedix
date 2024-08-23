#include <pedix/decoder.h>
#include <pedix/dump.h>
#include <stdio.h>

#define INSTRUCTION_LIMIT 1 

int main(void) {
  // todo: add valid prefix check
  // ex: 66 0f 74 04 00 -> is a valid instruction, while f3 0f 74 04 00 is not
  uint64_t offset, instructions;
  uchar8_t instruction[] = { 0x2E, 0x00, 0x0D, 0x10, 0x20, 0x30, 0x40};
  Dinstruction *decoded = pedix_init_instruction();
  decoded->mode = MODE_32;

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

