#pragma once

#include "defines.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#define HAS_STATUS(s, x) ((s & x) > 0)

/* instruction bit flags */ 
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
  uint8_t prefix[MAX_PREFIXES];
  size_t size;
} Prefix;

typedef struct {
  char str[MAX_MNEMONIC_STR_LEN];
} Mnemonic;

typedef struct {
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
  uint8_t field;
  uint8_t scale : 2;
  uint8_t index : 3;
  uint8_t base : 3;
} Sib;

typedef struct {
  size_t size;
  uchar8_t bytes[MAX_INSTR_SIZE];
} Buffer;

typedef struct {
  size_t size;
  char str[MAX_OPERAND_STR_LEN];
} Operand;

typedef struct {
  /* instruction status */
  Status status;         
  /* instruction raw bytes */
  Buffer buffer;           
  /* mnemonic */
  Mnemonic mnemonic;       
  /* operands */
  Operand operands;        
  /* 32-bit or 64-bit */
  uint8_t mode;            
  /* zero/other/modrm */
  uint8_t instr_type;  
  /* amount of operands per instruction */
  size_t operand_capacity;

  /* prefixes */
  Prefix prefixes; 
  /* rex field */
  Rex rex;         
  /* op1 is the primary opcode */
  uchar8_t op1;    
  /* op2 is the secondary opcode */
  uchar8_t op2;    
  /* modrm field */
  Modrm modrm;    
  /* sib field */
  Sib sib;      
  /* displacement field */
  uint64_t disp;   
  /* immediate operand field */
  uint64_t imm;    
  /* relative address operand field */
  uint64_t rel;    
  /* direct address operand field */
  uint64_t dir;    
} Dinstruction;

/* allocates memory for the struct */
Dinstruction *init_instruction();
/* frees the memory */
void free_instrucion(Dinstruction *decoded);  
/* zeroes the struct */
void zero_instruction(Dinstruction *decoded); 
/* general decode func */
bool decode(Dinstruction *decoded, uchar8_t *instruction);
/* 32-bit specific */
bool decode32(Dinstruction *decoded, uchar8_t *instruction);
/* 64-bit specific */
bool decode64(Dinstruction *decoded, uchar8_t *instruction);
