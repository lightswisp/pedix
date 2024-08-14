#include "headers/mnemonic.h"
#include <string.h>

void set_mnemonic(Dinstruction *decoded) {
  strcpy(decoded->text, decoded->instruction->mnemonic);
}

