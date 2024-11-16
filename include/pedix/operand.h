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
#include "decoder.h"

void pedix_set_operands(decoded_instruction_t *decoded, uint8_t *instruction);
void pedix_merge_operands(decoded_instruction_t *decoded);

extern const char *modrm_reg8[]; 
extern const char *modrm_reg16[];
extern const char *modrm_reg32[];
extern const char *modrm_reg16_override[];
extern const char *st_reg[]; 

/* ib or imm8 */
#define OPERAND_BYTE "0x%02x"
/* iw ic iv or imm16 */
#define OPERAND_WORD "0x%04x"
/* iv id or imm32 */
#define OPERAND_DWORD "0x%08x"
/* ap 32/48 bit pointer */
#define OPERAND_48 "0x%012x"
/* when register addressing (mod field = 3) */
#define REG_TO_REG "%.24s,%.24s"
#define MEM_TO_REG "%.24s,%.24s"
#define REG_TO_MEM "%.24s,%.24s" 
#define SIGN "%c"
#define SINGLE_OPERAND "%s"
#define REGISTER "%s"
#define SCALE "%d"
#define SEGMENT "%s"
#define ADDR_PTR "%s"

#define FMT_MOFFS SEGMENT"["OPERAND_DWORD"]" 
#define FMT_TWO_BYTE_DISPLACEMENT_ASZ_OVERRIDE                                 \
  ADDR_PTR " " SEGMENT "[" REGISTER SIGN OPERAND_WORD "]"
#define FMT_ONE_BYTE_DISPLACEMENT_ASZ_OVERRIDE                                 \
  ADDR_PTR " " SEGMENT "[" REGISTER SIGN OPERAND_BYTE "]"
#define FMT_DISPLACEMENT_ONLY_MODE_ASZ_OVERRIDE                                \
  ADDR_PTR " " SEGMENT "[" OPERAND_WORD "]"

#define FMT_DISPLACEMENT_ONLY_MODE ADDR_PTR " " SEGMENT "[" OPERAND_DWORD "]"
#define FMT_INDIRECT_ADDRESSING_OP ADDR_PTR " " SEGMENT "[" REGISTER "]"
#define FMT_SIB_FOUR_BYTE_NO_DISP_ADDRESSING_OP                               \
  ADDR_PTR " " SEGMENT "[" REGISTER "+" REGISTER "*" SCALE "]"
#define FMT_SIB_FOUR_BYTE_DISP_NO_REG_ADDRESSING_OP                           \
  ADDR_PTR " " SEGMENT "[" REGISTER "*" SCALE SIGN OPERAND_DWORD "]"
#define FMT_ONE_BYTE_DISP_ADDRESSING_OP                                       \
  ADDR_PTR " " SEGMENT "[" REGISTER SIGN OPERAND_BYTE "]"
#define FMT_SIB_ONE_BYTE_DISP_ADDRESSING_OP                                   \
  ADDR_PTR " " SEGMENT "[" REGISTER "+" REGISTER "*" SCALE SIGN OPERAND_BYTE "]"
#define FMT_SIB_ONE_BYTE_DISP_NO_SCALE_ADDRESSING_OP                          \
  ADDR_PTR " " SEGMENT "[" REGISTER SIGN OPERAND_BYTE "]"
#define FMT_SIB_FOUR_BYTE_DISP_NO_SCALE_ADDRESSING_OP                         \
  ADDR_PTR " " SEGMENT "[" REGISTER SIGN OPERAND_DWORD "]"
#define FMT_SIB_FOUR_BYTE_NO_DISP_NO_SCALE_ADDRESSING_OP                      \
  ADDR_PTR " " SEGMENT "[" REGISTER "]"
#define FMT_FOUR_BYTE_DISP_ADDRESSING_OP                                      \
  ADDR_PTR " " SEGMENT "[" REGISTER SIGN OPERAND_DWORD "]"
#define FMT_SIB_FOUR_BYTE_DISP_ADDRESSING_OP                                  \
  ADDR_PTR " " SEGMENT "[" REGISTER "+" REGISTER "*" SCALE SIGN OPERAND_DWORD "]"
