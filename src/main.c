#include "headers/decoder.h"
#include "headers/dump.h"
#include "headers/mnemonic.h"
#include "headers/operand.h"
#include <stdio.h>

#define INSTRUCTION_LIMIT 1 

int main(void) {
  uint8_t offset, instructions, result;
  //uchar8_t instruction[] = {0xBA, 0x11, 0x11, 0x22, 0x33, 0x66, 0x69, 0x00, 0x00, 0x00,0x00, 0x04, 0x55, 0x11, 0x11, 0x11, 0x11};
  uchar8_t instruction[] = {0xC7, 0xC0, 0x50, 0x11, 0x11, 0x11};
  Dinstruction *decoded = init_instruction();
  decoded->mode = MODE_32;

  /* curr offset */
  offset = 0;
  /* instruction counter */
  instructions = 0;

  while (instructions < INSTRUCTION_LIMIT) {
    result = decode(decoded, instruction + offset);
    if (!result)
      goto decode_error;

    dump_instruction(decoded);
    if(!set_mnemonic(decoded, decoded->op1))
      goto mnemonic_error;

    if(!set_operands(decoded, decoded->op1))
      goto operands_error;

    /* if everything went well */
    print_instruction(decoded);
    /* eat bytes */
    offset += decoded->buffer.size;
    /* go to the next instruction */
    instructions++;
    /* zero the struct */
    zero_instruction(decoded);
  }

cleanup:
  free_instrucion(decoded);
  return 0;

decode_error:
  fprintf(stderr, "error has occured while decoding!\n");
  goto cleanup;

mnemonic_error:
  fprintf(stderr, "error has occured while setting mnemonic!\n");
  goto cleanup;

operands_error:
  fprintf(stderr, "error has occured while setting operands!\n");
  goto cleanup;
}

