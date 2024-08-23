#include <pedix/mnemonic.h>
#include <string.h>

void pedix_set_mnemonic(decoded_instruction_t *decoded) {
  strcpy(decoded->text, decoded->instruction->mnemonic);
}

