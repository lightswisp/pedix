#include <pedix/decoder.h>
#include <pedix/dump.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

/* some colors for output */
#define GREEN "\033[0;32m"
#define NC "\033[0m"
#define TEXT_IDENTICAL(d, s)((strcmp(d,s) == 0))

/* test template */
#define PREPARE_TEST(n, itext)                                                 \
  pedix_decode(decoded, instruction##n);                                       \
  assert(                                                                      \
      ("instruction text test " #n && TEXT_IDENTICAL(decoded->text, itext)));  \
  pedix_zero_instruction(decoded);

/*add WORD PTR[ecx+esi*1],cx */
uint8_t instruction1[] = {0x66, 0x01, 0x0C, 0x31}; 

/* add DWORD PTR[edx], eax */
uint8_t instruction2[] = {0x01, 0x02};       

/* mov DWORD PTR [eax+0x50],0x11111111 */
uint8_t instruction3[] = {
    0xC7, 0x40, 0x50, 0x11,
    0x11, 0x11, 0x11}; 

/* mov DWORD PTR [ecx+edx*2+0x50],0x11111111 */
uint8_t instruction4[] = {0xC7, 0x44, 0x51, 0x50, 0x11, 0x11, 0x11, 0x11};       

int main(){
  /* init */
  decoded_instruction_t *decoded = pedix_init_instruction();
  decoded->mode = MODE_32;

  /* tests */
  PREPARE_TEST(1, "add WORD PTR [ecx+esi*1],cx");
  PREPARE_TEST(2, "add DWORD PTR [edx],eax");
  PREPARE_TEST(3, "mov DWORD PTR [eax+0x50],0x11111111");
  PREPARE_TEST(4, "mov DWORD PTR [ecx+edx*2+0x50],0x11111111");
  
  puts(GREEN"All tests are passed!"NC);
  return 0;
}
