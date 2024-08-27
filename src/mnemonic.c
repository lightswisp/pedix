#include <pedix/mnemonic.h>
#include <string.h>

void pedix_set_mnemonic(decoded_instruction_t *decoded) {
  strcat(decoded->text, decoded->instruction->mnemonic);
}

