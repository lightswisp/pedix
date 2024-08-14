#pragma once

typedef unsigned char uchar8_t;
#define MODE_32 32 
#define MODE_64 64

#define SET_BREAKPOINT asm volatile("int3");
#define MAX_OPERAND_STR_LEN 50 
#define MAX_PREFIXES 4
#define MAX_TEXT_LEN 100
#define MAX_INSTR_SIZE 0x0F
#define BYTE_LEN                                                                \
  0x01 // operand type b (byte, regardless of operand-size attribute)
#define THREE_BYTE_LEN 0x03 // 24-bit
#define WORD_LEN                                                                \
  0x02 // operand type w (word, regardless of operand-size attribute)
#define DOUBLEWORD_LEN                                                          \
  0x04 // operand type v (word or doubleword, depending on operand-size
       // attribute)
#define ADDR_48_LEN                                                             \
  0x06 // operand type p (32-bit or 48-bit pointer, depending on operand-size
       // attribute)
#define QUADWORD_LEN 0x08 // 64-bit

