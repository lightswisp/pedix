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
} prefix_t;

typedef struct {
  size_t size;
  uint8_t field;
  uint8_t mod : 2;
  uint8_t reg : 3;
  uint8_t rm : 3;
} modrm_t;

typedef struct {
  uint8_t field;
  uint8_t w : 1;
  uint8_t r : 1;
  uint8_t x : 1;
  uint8_t b : 1;
} rex_t;

typedef struct {
  size_t size;
  uint8_t field;
  uint8_t scale : 2;
  uint8_t index : 3;
  uint8_t base : 3;
} sib_t;

typedef struct{
  size_t size;
  uint64_t field; 
} displacement_t;

typedef struct {
  size_t size;
  uint8_t bytes[MAX_INSTR_SIZE];
} buffer_t;

typedef struct {
  buffer_t buffer;           
  char text[MAX_TEXT_LEN];       
  uint8_t mode;            
  prefix_t prefixes; 
  rex_t rex;         
  modrm_t modrm;    
  sib_t sib;      
  displacement_t displacement;   

  // should be either empty, or contain fs:, gs:, cs:, ss:, ds: you get it ;)
  char segment_text[MAX_SEGMENT_TEXT_LEN];
  char operands[MAX_OPERANDS][MAX_OPERAND_STR_LEN];

  union {
    uint64_t imm;
    uint64_t rel;
    uint64_t dir;
  };
  instruction_t* instruction;
  uint64_t base_address;
} decoded_instruction_t;

decoded_instruction_t *pedix_init_instruction(void);
void pedix_free_instrucion(decoded_instruction_t *decoded);  
void pedix_zero_instruction(decoded_instruction_t *decoded); 
void pedix_decode(decoded_instruction_t *decoded, uint8_t *instruction);
