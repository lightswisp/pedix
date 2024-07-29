#pragma once

typedef unsigned char uchar8_t;

enum Types {
  INSTR_ZERO = 1,
  INSTR_MODRM = 2,
  INSTR_OTHER = 3,
};

#define MODE_32 32
#define MODE_64 64

#define SET_BREAKPOINT asm volatile("int3");
#define MAX_OPERAND_STR_LEN 100 
#define MAX_MNEMONIC_STR_LEN 17
#define MAX_PREFIXES 4
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

#define PREFIX_LOCK 0xF0            // lock prefix
#define PREFIX_REPNE_Z 0xF2         // repne/repnz prefix
#define PREFIX_REP_E_Z 0xF3         // rep or repe/repz prefix
#define PREFIX_CS 0x2E              // cs segment override
#define PREFIX_SS 0x36              // ss segment override
#define PREFIX_DS 0x3E              // ds segment override
#define PREFIX_ES 0x26              // es segment override
#define PREFIX_FS 0x64              // fs segment override
#define PREFIX_GS 0x65              // gs segment override
#define PREFIX_BNT 0x2E             // branch not taken
#define PREFIX_BT 0x3E              // branch taken
#define PREFIX_OPSIZE_OVERRIDE 0x66 // operand-size override prefix
#define PREFIX_ASZ_OVERRIDE 0x67    // address-size override prefix
