#include <pedix/dump.h>
#include <stdio.h>

void pedix_dump_instruction(instruction_t *instruction) {
  printf("#<Instruction:%p\n", (void*)instruction);
  printf("  extended_opcode=%d\n", instruction->extended_opcode);
  printf("  mnemonic=%s\n", instruction->mnemonic);
  printf("  opcode_field=<type=%d, value=%d>\n", instruction->opcode_field.type,
         instruction->opcode_field.value);
  printf("  operands={%d, %d, %d, %d},\n", instruction->operands.operand[0],
                                           instruction->operands.operand[1], 
                                           instruction->operands.operand[2],
                                           instruction->operands.operand[3]);
  printf("  prefix=%d\n", instruction->prefix);
  printf("  primary_opcode=%d\n", instruction->primary_opcode);
  printf("  secondary_opcode=%d>\n", instruction->secondary_opcode);
}

static char *pedix_get_bytes(decoded_instruction_t *decoded){
  char *temp = calloc(MAX_INSTR_SIZE*3+1, 1);
  for(uint8_t i = 0; i < decoded->buffer.size; i++)
    sprintf(temp+3*i, "%.2x ", decoded->buffer.bytes[i]);
  return temp;
}

void pedix_print_instruction(decoded_instruction_t *decoded, uint64_t offset) {
  char *bytes = pedix_get_bytes(decoded); 
#if defined(__x86_64__) 
  printf("%08lx: %25s\t%s\n", offset, bytes, decoded->text);
#endif
#if defined(__i386__)
  printf("%08llx: %25s\t%s\n", offset, bytes, decoded->text);
#endif
  free(bytes);
}
