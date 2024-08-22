#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include "defines.h"
#include "tables/tabledef.h"

typedef struct {
  size_t size;
  uint8_t prefix[MAX_PREFIXES];
} Prefix;

typedef struct {
  size_t size;
  uint8_t field;
  uint8_t mod : 2;
  uint8_t reg : 3;
  uint8_t rm : 3;
} Modrm;

typedef struct {
  uint8_t field;
  uint8_t w : 1;
  uint8_t r : 1;
  uint8_t x : 1;
  uint8_t b : 1;
} Rex;

typedef struct {
  size_t size;
  uint8_t field;
  uint8_t scale : 2;
  uint8_t index : 3;
  uint8_t base : 3;
} Sib;

typedef struct{
  size_t size;
  uint64_t field; 
} Displacement;

typedef struct {
  size_t size;
  uchar8_t bytes[MAX_INSTR_SIZE];
} Buffer;

typedef struct {
  Buffer buffer;           
  char text[MAX_TEXT_LEN];       
  uint8_t mode;            
  Prefix prefixes; 
  Rex rex;         
  Modrm modrm;    
  Sib sib;      
  Displacement displacement;   

  char operands[MAX_OPERANDS][MAX_OPERAND_STR_LEN];

  union {
    uint64_t imm;
    uint64_t rel;
    uint64_t dir;
  };
  Instruction* instruction;
  uint64_t base_address;
} Dinstruction;

Dinstruction *pedix_init_instruction();
void pedix_free_instrucion(Dinstruction *decoded);  
void pedix_zero_instruction(Dinstruction *decoded); 
void pedix_decode(Dinstruction *decoded, uchar8_t *instruction);
