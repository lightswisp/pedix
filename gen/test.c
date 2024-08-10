#include <stdio.h>
#include "tables.h"

void dump_instruction(const Instruction *instruction){
  printf("#<Instruction:%08x\n", &instruction);
  printf("  extended_opcode=%d\n", instruction->extended_opcode);
  printf("  mnemonic=%s\n", instruction->mnemonic);
  printf("  opcode_field=<type=%d, value=%d>\n", instruction->opcode_field.type, instruction->opcode_field.value);
  printf("  operand1=%d\n", instruction->operand1);
  printf("  operand2=%d\n", instruction->operand2);
  printf("  operand3=%d\n", instruction->operand3);
  printf("  operand4=%d\n", instruction->operand4);
  printf("  prefix=%d\n", instruction->prefix);
  printf("  primary_opcode=%d\n", instruction->primary_opcode);
  printf("  secondary_opcode=%d>\n", instruction->secondary_opcode);
}

int main(void){
  dump_instruction(&extended_table_32[0]);
  return 0;
}
