#pragma once
#include "defines.h"
#include <stdbool.h>

typedef struct{
    bool has_vex;
    bool has_rex;
    bool has_prefix;
    bool extended;
} Status;

typedef struct{
    char str[100];
    size_t cur_size;
} Mnemonic;

typedef struct{
    unsigned int field;
    unsigned int w : 1;
    unsigned int r : 1;
    unsigned int x : 1;
    unsigned int b : 1;
} Rex;

typedef struct{
    unsigned int field;
    unsigned int scale : 2;
    unsigned int index : 3;
    unsigned int base : 3;
} Sib;

typedef struct{
    size_t size;
    unsigned int bytes[MAX_INSTR_SIZE];
} Buffer;

typedef struct {
    Status status;
    Buffer buffer;
    Mnemonic mnemonic; // this one is not implemented yet!
    unsigned int instr_type;
    unsigned int reg_src;
    unsigned int reg_dst;

    unsigned int prefixes[2]; // prefixes 
    Rex rex;           // rex field
    unsigned char op1; // op1 is the primary opcode 
    unsigned char op2; // op2 is the secondary opcode
    unsigned int mod;  // modrm field
    Sib sib;           // sib field
    unsigned int displacement; // disp field
    unsigned int immediate;    // imm field
} Dinstruction;

Dinstruction* init_instruction();               // allocates memory for the struct
void dump(Dinstruction* decoded);               // dumps struct fields to stdout
void free_instrucion(Dinstruction* decoded);    // frees the memory
void zero_instruction(Dinstruction* decoded);   // zeroes the struct
bool decode(Dinstruction* decoded, unsigned char* instruction, unsigned int mode);   //general decode func
bool decode32(Dinstruction* decoded, unsigned char* instruction); // 32bit specific 
bool decode64(Dinstruction* decoded, unsigned char* instruction); // 64bit specific
