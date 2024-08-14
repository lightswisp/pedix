#include "headers/decoder.h"
#include "headers/dump.h"
#include <stdio.h>

#define INSTRUCTION_LIMIT 14 

int main(void) {
  // todo: add valid prefix check
  // ex: 66 0f 74 04 00 -> is a valid instruction, while f3 0f 74 04 00 is not
  uint64_t offset, instructions;
  //uchar8_t instruction[] = {0xBA, 0x11, 0x11, 0x22, 0x33, 0x66, 0x69, 0x00, 0x00, 0x00,0x00, 0x04, 0x55, 0x11, 0x11, 0x11, 0x11};
  uchar8_t instruction[] = {0xE8, 0xA4, 0x00, 0x00, 0x00, 0x81, 0xC2, 0x0F, 0x2F, 0x00, 0x00, 0x55, 0x89, 0xE5, 0x53, 0x8D, 0x8A, 0x1C, 0x00, 0x00, 0x00, 0x8D, 0x82, 0x1C, 0x00, 0x00, 0x00, 0x83, 0xEC, 0x04, 0x29, 0xC8, 0x89, 0xC3, 0xC1, 0xE8, 0x1F, 0xC1, 0xFB, 0x02, 0x01, 0xD8, 0xD1, 0xF8};
  Dinstruction *decoded = init_instruction();
  decoded->mode = MODE_32;

  /* curr offset */
  offset = 0;
  /* instruction counter */
  instructions = 0;

  while (instructions < INSTRUCTION_LIMIT) {
    decode(decoded, instruction + offset);

#ifdef DEBUG
    dump_instruction(decoded->instruction);
#endif
    /* if everything went well */
    print_instruction(decoded, offset);
    /* eat bytes */
    offset += decoded->buffer.size;
    /* go to the next instruction */
    instructions++;
    /* zero the struct */
    zero_instruction(decoded);
  }

  free_instrucion(decoded);
  return 0;
}

