#pragma once

#include <stdbool.h>

typedef struct{
    char str[100];
    size_t cur_size;
} Mnemonic;

typedef struct {
    size_t size;
    bool has_rex;
    bool has_prefix;
    bool extended;
    unsigned int prefixes[2];
    unsigned char op1; // op1 is the primary opcode (it might be a little bit confusting, but it's not the first opcode)
    unsigned char op2; // op2 is the secondary opcode
    unsigned int mod;
    unsigned int reg_src;
    unsigned int reg_dst;
    unsigned int instr_type;
    Mnemonic* mnemonic; // this one is not implemented yet!
} Dinstruction;

Dinstruction* init_instruction();               // allocates memory for the struct
void dump(Dinstruction* decoded);               // dumps struct fields to stdout
void free_instrucion(Dinstruction* decoded);    // frees the memory
void zero_instruction(Dinstruction* decoded);   // zeroes the struct
bool decode(Dinstruction* decoded, unsigned char* insruction, unsigned int mode);   //general decode func
bool decode32(Dinstruction* decoded, unsigned char* insruction); // 32bit specific 
bool decode64(Dinstruction* decoded, unsigned char* insruction); // 64bit specific
