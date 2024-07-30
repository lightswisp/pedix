#include "../src/headers/decoder.h"
#include "../src/headers/operand.h"
#include "../src/headers/mnemonic.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

/* some colors for output */
#define GREEN "\033[0;32m"
#define NC "\033[0m"
#define TEXT_IDENTICAL(d, s)((strcmp(d,s) == 0))
#define FORMAT_INSTRUCTION(d, m, o)(sprintf(d, "%.24s %.24s", m, o))

/* test template */
#define PREPARE_TEST(n, itext)                                                 \
  assert(("Decode   test " #n && decode(decoded, instruction##n) == true));    \
  assert(                                                                      \
      ("Mnemonic test " #n && set_mnemonic(decoded, decoded->op1) == true));   \
  assert(                                                                      \
      ("Operands test " #n && set_operands(decoded, decoded->op1) == true));   \
  FORMAT_INSTRUCTION(temp, decoded->mnemonic.str, decoded->operands.str);      \
  printf("temp: %s\n", temp); \
  assert(("Instruction text test " #n && TEXT_IDENTICAL(temp, itext)));        \
  print_bytes(decoded);                                                        \
  print_instruction(decoded);                                                  \
  zero_instruction(decoded);

/*add WORD PTR[ecx+esi*1],cx */
uchar8_t instruction1[] = {0x66, 0x01, 0x0C, 0x31}; 

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
    printf("0x%02X ", decoded->buffer.bytes[i]);
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
  PREPARE_TEST(1, "add WORD PTR [ecx+esi*1],cx");
  PREPARE_TEST(2, "add DWORD PTR [edx],eax");
  PREPARE_TEST(3, "mov DWORD PTR [eax+0x50],0x11111111");
  PREPARE_TEST(4, "mov DWORD PTR [ecx+edx*2+0x50],0x11111111");
  
  puts(GREEN"All tests are passed!"NC);
  return 0;
}
