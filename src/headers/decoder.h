#pragma once
#include "defines.h"
#include <stdbool.h>
#include <stdlib.h>

#define HAS_STATUS(s, x) ((s & x) > 0)
typedef enum {
  STATUS_VEX = 1 << 0,
  STATUS_REX = 1 << 1,
  STATUS_PREFIX = 1 << 2,
  STATUS_OPCODE_EXTENSION = 1 << 3,
  STATUS_IMMEDIATE_OPERAND = 1 << 4,
  STATUS_REL_OFFSET_OPERAND = 1 << 5,
  STATUS_DIRECT_ADDR_OPERAND = 1 << 6,
  STATUS_EXTENDED = 1 << 7,
  STATUS_OPSIZE_OVERRIDE = 1 << 8,
} Status;

typedef struct {
  unsigned int prefix[MAX_PREFIXES];
  size_t size;
} Prefix;

typedef struct {
  char str[MAX_MNEMONIC_STR_LEN];
} Mnemonic;

typedef struct {
  unsigned int field;
  unsigned int mod : 2;
  unsigned int reg : 3;
  unsigned int rm : 3;
} Modrm;

typedef struct {
  unsigned int field;
  unsigned int w : 1;
  unsigned int r : 1;
  unsigned int x : 1;
  unsigned int b : 1;
} Rex;

typedef struct {
  unsigned int field;
  unsigned int scale : 2;
  unsigned int index : 3;
  unsigned int base : 3;
} Sib;

typedef struct {
  size_t size;
  unsigned char bytes[MAX_INSTR_SIZE];
} Buffer;

typedef struct {
  size_t size;
  char str[MAX_OPERAND_STR_LEN];
} Operand;

typedef struct {
  Status status;           // instruction status
  Buffer buffer;           // instruction raw bytes
  Mnemonic mnemonic;       // mnemonic
  Operand operands;        // operands
  unsigned int mode;       // 32-bit or 64-bit
  unsigned int instr_type; // zero/other/modrm

  Prefix prefixes;            // prefixes
  Rex rex;                    // rex field
  unsigned char op1;          // op1 is the primary opcode
  unsigned char op2;          // op2 is the secondary opcode
  Modrm modrm;                // modrm field
  Sib sib;                    // sib field
  unsigned long displacement; // disp field
  unsigned long imm;          // immediate operand
  unsigned long rel;          // relative addr operand
  unsigned long dir;          // direct addr operand
  size_t operand_capacity;    // amount of operands per instruction
} Dinstruction;

Dinstruction *init_instruction();             // allocates memory for the struct
void free_instrucion(Dinstruction *decoded);  // frees the memory
void zero_instruction(Dinstruction *decoded); // zeroes the struct
void set_instruction_operand(Dinstruction *decoded, size_t op_size);
bool decode(Dinstruction *decoded,
            unsigned char *instruction); // general decode func
bool decode32(Dinstruction *decoded,
              unsigned char *instruction); // 32bit specific
bool decode64(Dinstruction *decoded,
              unsigned char *instruction); // 64bit specific
