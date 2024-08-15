#include "headers/mnemonic.h"
#include <string.h>

void pedix_set_mnemonic(Dinstruction *decoded) {
  strcpy(decoded->text, decoded->instruction->mnemonic);
}

