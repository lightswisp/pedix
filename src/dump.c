/*
 * Copyright (c) 2024 lightswisp
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/

#include <pedix/dump.h>
#include <stdio.h>

void 
pedix_dump_instruction(instruction_t *instruction) {
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
  printf("  primary_opcode=%x\n", instruction->primary_opcode);
  printf("  secondary_opcode=%d>\n", instruction->secondary_opcode);
}

void 
pedix_dump_memory(uint8_t* addr, size_t size){
  printf("=================== memory dump ===================\n");
  for(size_t i = 0; i < size; i++){
    if(i % 4 == 0)
      putchar('\n');
    printf("0x%02X ", *(addr++));
  }
  printf("\n\n===================================================\n\n");
}

static char*
pedix_get_bytes(decoded_instruction_t *decoded){
  char *temp = calloc(MAX_INSTR_SIZE*3+1, 1);
  for(uint8_t i = 0; i < decoded->buffer.size; i++)
    sprintf(temp+3*i, "%.2x ", decoded->buffer.bytes[i]);
  return temp;
}

void 
pedix_print_instruction(decoded_instruction_t *decoded, uint64_t offset) {
  char *bytes = pedix_get_bytes(decoded); 
#if defined(__x86_64__) 
  printf("%08lx: %25s\t%s\n", offset, bytes, decoded->text);
#endif
#if defined(__i386__)
  printf("%08llx: %25s\t%s\n", offset, bytes, decoded->text);
#endif
  free(bytes);
}
