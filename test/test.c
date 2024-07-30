#include "../src/headers/decoder.h"
#include "../src/headers/operand.h"
#include <stdio.h>
#include <assert.h>

/* some colors for output */
#define GREEN "\033[0;32m"
#define NC "\033[0m"
#define TEXT_IDENTICAL(d, s)((strcmp(d,s) == 0))
#define FORMAT_INSTRUCTION(d, m, o)(sprintf(d, "%s %s", m, o))

/* test template */
#define PREPARE_TEST(n, itext)                                                 \
  assert(("Decode   test " #n, decode(decoded, instruction1) == true));        \
  assert(("Mnemonic test " #n, set_mnemonic(decoded, decoded->op1) == true));  \
  assert(("Operands test " #n, set_operands(decoded, decoded->op1) == true));  \
  FORMAT_INSTRUCTION(temp, decoded->mnemonic.str, decoded->operands.str);      \
  assert(("Instruction text test " #n,                                         \
          TEXT_IDENTICAL(temp, "add WORD PTR[ecx+esi*1],cx")));                \
  print_bytes(decoded);                                                        \
  print_instruction(decoded);                                                  \
  zero_instruction(decoded);
 
/*add WORD PTR[ecx+esi*1],cx */
uchar8_t instruction1[] = {0x66, 0x01, 0x0C}; 

/* add DWORD PTR[edx], eax */
uchar8_t instruction2[] = {0x01, 0x02};       

/* mov DWORD PTR [eax+0x50],0x11111111 */
uchar8_t instruction3[] = {
    0xC7, 0x40, 0x50, 0x11,
    0x11, 0x11, 0x11}; 

/* mov DWORD PTR [ecx+edx*2+0x50],0x11111111 */
uchar8_t instruction4[] = {0xC7, 0x44, 0x51, 0x50, 0x11, 0x11, 0x11, 0x11};       

void print_bytes(Dinstruction *decoded){
  for (size_t i = 0; i < decoded->buffer.size; i++) {
    printf("%02x ", decoded->buffer.bytes[i]);
  }
}

void print_instruction(Dinstruction *decoded) {
  if (decoded->operands.capacity == 0)
    printf("%s\n", decoded->mnemonic.str);
  else
    printf("%s %s\n", decoded->mnemonic.str, decoded->operands.str);
}

int main(){
  /* init */
  Dinstruction *decoded = init_instruction();
  decoded->mode = MODE_32;
  char temp[50];


  /* tests */
  assert(("Decode   test 1", decode(decoded, instruction1) == true));
  assert(("Mnemonic test 1", set_mnemonic(decoded, decoded->op1) == true));
  assert(("Operands test 1", set_operands(decoded, decoded->op1) == true));

  FORMAT_INSTRUCTION(temp, decoded->mnemonic.str, decoded->operands.str);
  printf("%s\n", temp);
  assert(("Instruction text test 1", TEXT_IDENTICAL(temp, "add WORD PTR[ecx+esi*1],cx") ));
  print_bytes(decoded);
  print_instruction(decoded);
  zero_instruction(decoded);
  
  puts(GREEN"All tests are passed!"NC);
  return 0;
}
