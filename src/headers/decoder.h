#pragma once
#include "defines.h"
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
  bool has_vex;
  bool has_rex;
  bool has_prefix;
  bool has_opcode_extension;
  bool has_immediate_operand;
  bool has_rel_offset_operand;
  bool has_direct_addr_operand;
  bool extended;
  bool opsize_override;
} Status;

typedef struct {
  unsigned int prefix[4];
  size_t size;
} Prefix;

typedef struct {
  char str[100];
  size_t cur_size;
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
  size_t operand;
  unsigned int size;
} Operand;

typedef struct {
  Status status;           // instruction status
  Buffer buffer;           // instruction raw bytes
  Mnemonic mnemonic;       // this one is not implemented yet!
  unsigned int mode;       // 32-bit or 64-bit
  unsigned int instr_type; // zero/other/modrm

  Prefix prefixes;            // prefixes
  Rex rex;                    // rex field
  unsigned char op1;          // op1 is the primary opcode
  unsigned char op2;          // op2 is the secondary opcode
  Modrm modrm;                // modrm field
  Sib sib;                    // sib field
  unsigned long displacement; // disp field
  Operand operand1;           // first operand
  Operand operand2;           // second operand
  Operand operand3;           // third operand
  Operand operand4;           // fourth operand
} Dinstruction;

Dinstruction *init_instruction();             // allocates memory for the struct
void dump(Dinstruction *decoded);             // dumps struct fields to stdout
void free_instrucion(Dinstruction *decoded);  // frees the memory
void zero_instruction(Dinstruction *decoded); // zeroes the struct
bool decode(Dinstruction *decoded,
            unsigned char *instruction); // general decode func
bool decode32(Dinstruction *decoded,
              unsigned char *instruction); // 32bit specific
bool decode64(Dinstruction *decoded,
              unsigned char *instruction); // 64bit specific
