#include "headers/dump.h"
/*
 * dumps all needed information about instruction
 */
void dump(Dinstruction *decoded) {
  printf("========================================\n");

  printf("instruction mode: %d\n", decoded->mode);
  printf("instruction size: %lu\n", decoded->buffer.size);
  printf("has_prefix: %d\n", HAS_STATUS(decoded->status, STATUS_PREFIX));
  printf("0x0f extended: %d\n", HAS_STATUS(decoded->status, STATUS_EXTENDED));

  if (decoded->instr_type) {
    switch (decoded->instr_type) {
    case INSTR_ZERO:
      printf("type: zero\n");
      break;
    case INSTR_MODRM:
      printf("type: mod/rm\n");
      break;
    case INSTR_OTHER:
      printf("type: other\n");
      break;
    }
  }

  if (HAS_STATUS(decoded->status, STATUS_PREFIX)) {
    for (size_t i = 0; i < decoded->prefixes.size; i++) {
      printf("instruction prefix %zu: 0x%02X\n", i,
             decoded->prefixes.prefix[i]);
    }
  }

  printf("instruction opcode 1: 0x%02X\n", decoded->op1);
  printf("instruction opcode 2: 0x%02X\n", decoded->op2);
  printf("instruction dir: %lld\n", decoded->dir);
  printf("instruction operand capacity: %zu\n", decoded->operands.capacity);
  printf("raw bytes: ");
  for (size_t i = 0; i < decoded->buffer.size; i++) {
    printf("%02x ", decoded->buffer.bytes[i]);
  }
  putchar('\n');
  printf("========================================\n\n");
}

/*
 * prints to stdout 
 */
void print_instruction(Dinstruction *decoded) {
  if (decoded->operands.capacity == 0)
    printf("%s\n", decoded->mnemonic.str);
  else
    printf("%s %s\n", decoded->mnemonic.str, decoded->operands.str);
}
