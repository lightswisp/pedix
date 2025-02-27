/*
 * Copyright (c) 2024 lightswisp
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/

#pragma once
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

// at the moment, vgf2p8affineinvqb at 17 bytes is the longest mnemonic in intel's docs
#define MAX_MNEMONIC_LEN 17  
#define MAX_OPERANDS     4

typedef enum{
  FIELD_VOID               = 0,
  FIELD_MOD_RM             = 1,
  FIELD_MULTIPLEXED_MOD_RM = 2
} field_type_t;

typedef struct{
  field_type_t type;
  uint8_t value;
} field_t;


typedef enum{
  OPERAND_VOID              = 0, 
  OPERAND_IMM_8             = 1,
  OPERAND_IMM_16            = 2,
  OPERAND_IMM_32            = 3,
  OPERAND_IMM_16_32         = 4,
  OPERAND_R_ALL             = 5,
  OPERAND_RM_ALL            = 6,
  OPERAND_R_8               = 7,
  OPERAND_R_16              = 8,
  OPERAND_R_32              = 9,
  OPERAND_R_16_32           = 10, 
  OPERAND_RM_8              = 11,
  OPERAND_RM_16             = 12,
  OPERAND_RM_32             = 13,
  OPERAND_RM_16_32          = 14,

  OPERAND_REG_AL            = 15,
  OPERAND_REG_CL            = 16,
  OPERAND_REG_DL            = 17,
  OPERAND_REG_BL            = 18,
  OPERAND_REG_AH            = 19,
  OPERAND_REG_CH            = 20,
  OPERAND_REG_DH            = 21,
  OPERAND_REG_BH            = 22,
  OPERAND_REG_AX            = 23,
  OPERAND_REG_CX            = 24,
  OPERAND_REG_DX            = 25,
  OPERAND_REG_BX            = 26,
  OPERAND_REG_SP            = 27,
  OPERAND_REG_BP            = 28,
  OPERAND_REG_SI            = 29,
  OPERAND_REG_DI            = 30,
  OPERAND_REG_EAX           = 31,
  OPERAND_REG_ECX           = 32,
  OPERAND_REG_EDX           = 33,
  OPERAND_REG_EBX           = 34,
  OPERAND_REG_ESP           = 35,
  OPERAND_REG_EBP           = 36,
  OPERAND_REG_ESI           = 37,
  OPERAND_REG_EDI           = 38,
  OPERAND_REG_RAX           = 39,
  OPERAND_REG_RCX           = 40,
  OPERAND_REG_RDX           = 41,
  OPERAND_REG_RBX           = 42,
  OPERAND_REG_RSP           = 43,
  OPERAND_REG_RBP           = 44,
  OPERAND_REG_RSI           = 45,
  OPERAND_REG_RDI           = 46,

  OPERAND_SEG_ALL           = 47,
  OPERAND_SEG_ES            = 48,
  OPERAND_SEG_SS            = 49,
  OPERAND_SEG_DS            = 50,
  OPERAND_SEG_CS            = 51,
  OPERAND_SEG_FS            = 52,
  OPERAND_SEG_GS            = 53,

  OPERAND_M_ALL             = 54,
  OPERAND_M_8               = 55,
  OPERAND_M_16              = 56,
  OPERAND_M_32              = 57,
  OPERAND_M_64              = 58,
  OPERAND_M_80              = 59,
  OPERAND_M_128             = 60,
  OPERAND_M_512             = 61,
  OPERAND_M_16_32           = 62,

  OPERAND_M_16_AMP_32       = 63,
  OPERAND_M_16_AMP_16       = 64,
  OPERAND_M_32_AMP_32       = 65,
  OPERAND_M_16_AMP_64       = 66,
  OPERAND_M_16_32_AMP_16_32 = 67,

  OPERAND_MOFFS_8           = 68,
  OPERAND_MOFFS_16          = 69,
  OPERAND_MOFFS_32          = 70,
  OPERAND_MOFFS_64          = 71,
  OPERAND_MOFFS_16_32       = 72,

  OPERAND_REL_8             = 73,
  OPERAND_REL_16            = 74,
  OPERAND_REL_32            = 75,
  OPERAND_REL_16_32         = 76,

  OPERAND_PTR_16            = 77,
  OPERAND_PTR_32            = 78,
  OPERAND_PTR_16_32         = 79,

  OPERAND_M_PTR_16          = 80,
  OPERAND_M_PTR_32          = 81,
  OPERAND_M_PTR_64          = 82,
  OPERAND_M_PTR_16_32       = 83,

  OPERAND_ONE               = 84, 
  OPERAND_REG_ST            = 85,
  OPERAND_REG_STI           = 86,
  OPERAND_REG_ST1           = 87, 
  OPERAND_REG_ST2           = 88,
  OPERAND_REG_STI_M32       = 89,

  OPERAND_XMM               = 90,
  OPERAND_XMM_0             = 91,
  OPERAND_XMM_M_32          = 92,
  OPERAND_XMM_M_64          = 93,
  OPERAND_XMM_M_128         = 94,

  OPERAND_REG_CRN           = 95, 
  OPERAND_REG_DRN           = 96,

  OPERAND_MM                = 97,
  OPERAND_MM_M_64           = 98,
  R_PLUS_16_32              = 99,
  R_PLUS_8                  = 100,
} __operand_t;

typedef enum {
  PREFIX_VOID            = 0x00,
  PREFIX_LOCK            = 0xF0,
  PREFIX_REPNE_Z         = 0xF2,
  PREFIX_REP_E_Z         = 0xF3,
  PREFIX_CS              = 0x2E,
  PREFIX_SS              = 0x36,
  PREFIX_DS              = 0x3E,
  PREFIX_ES              = 0x26,
  PREFIX_FS              = 0x64,
  PREFIX_GS              = 0x65,
  PREFIX_BNT             = 0x2E,
  PREFIX_BT              = 0x3E,
  PREFIX_OPSIZE_OVERRIDE = 0x66,
  PREFIX_ASZ_OVERRIDE    = 0x67
} __prefix_t;

typedef struct {
  bool extended_opcode; // false if not 0x0f
  const char mnemonic[MAX_MNEMONIC_LEN]; // text representation of the mnemonic
  field_t opcode_field; 

  struct {
    size_t size; 
    __operand_t operand[MAX_OPERANDS];
  } operands;

  __prefix_t prefix;
  uint8_t primary_opcode;
  short secondary_opcode; // -1 if there is no secondary opcode
} instruction_t;

typedef struct{
  size_t size;
  instruction_t* instructions;
} instruction_container_t;
