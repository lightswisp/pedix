#pragma once

#include "decoder.h"

bool set_operands(Dinstruction *decoded, uchar8_t instruction);

/* ib or imm8 */
#define OPERAND_BYTE "0x%02x"
/* iw ic iv or imm16 */
#define OPERAND_WORD "0x%04x"
/* iv id or imm32 */
#define OPERAND_DWORD "0x%08x"
/* ap 32/48 bit pointer */
#define OPERAND_48 "0x%lx"
/* when register addressing (mod field = 3) */
#define REG_TO_REG "%.24s,%.24s"

#define MEM_TO_REG "%.24s,%.24s"

#define REG_TO_MEM "%.24s,%.24s" 

#define SINGLE_OPERAND "%s"

#define REGISTER "%s"

#define SCALE "%d"

#define INDIRECT_OP_8_ADDRESSING "BYTE PTR [" REGISTER "]"
#define INDIRECT_OP_16_ADDRESSING "WORD PTR [" REGISTER "]"
#define INDIRECT_OP_32_ADDRESSING "DWORD PTR [" REGISTER "]"

#define SIB_FOUR_BYTE_OP_8_NO_DISP_ADDRESSING                                  \
  "BYTE PTR[" REGISTER "+" REGISTER "*" SCALE "]"
#define SIB_FOUR_BYTE_OP_16_NO_DISP_ADDRESSING                                 \
  "WORD PTR[" REGISTER "+" REGISTER "*" SCALE "]"
#define SIB_FOUR_BYTE_OP_32_NO_DISP_ADDRESSING                                 \
  "DWORD PTR[" REGISTER "+" REGISTER "*" SCALE "]"

#define SIB_FOUR_BYTE_DISP_OP_8_NO_REG_ADDRESSING                              \
  "BYTE PTR [" REGISTER "*" SCALE "+" OPERAND_DWORD "]"
#define SIB_FOUR_BYTE_DISP_OP_16_NO_REG_ADDRESSING                             \
  "WORD PTR [" REGISTER "*" SCALE "+" OPERAND_DWORD "]"
#define SIB_FOUR_BYTE_DISP_OP_32_NO_REG_ADDRESSING                             \
  "DWORD PTR [" REGISTER "*" SCALE "+" OPERAND_DWORD "]"

#define ONE_BYTE_DISP_OP_8_ADDRESSING "BYTE PTR [" REGISTER "+" OPERAND_BYTE "]"

#define ONE_BYTE_DISP_OP_16_ADDRESSING                                         \
  "WORD PTR [" REGISTER "+" OPERAND_BYTE "]"

#define ONE_BYTE_DISP_OP_32_ADDRESSING                                         \
  "DWORD PTR [" REGISTER "+" OPERAND_BYTE "]"

#define SIB_ONE_BYTE_DISP_OP_8_ADDRESSING                                      \
  "BYTE PTR [" REGISTER "+" REGISTER "*" SCALE "+" OPERAND_BYTE "]"

#define SIB_ONE_BYTE_DISP_OP_16_ADDRESSING                                     \
  "WORD PTR [" REGISTER "+" REGISTER "*" SCALE "+" OPERAND_BYTE "]"

#define SIB_ONE_BYTE_DISP_OP_32_ADDRESSING                                     \
  "DWORD PTR [" REGISTER "+" REGISTER "*" SCALE "+" OPERAND_BYTE "]"

#define FOUR_BYTE_DISP_OP_8_ADDRESSING                                         \
  "BYTE PTR [" REGISTER "+" OPERAND_DWORD "]"

#define FOUR_BYTE_DISP_OP_16_ADDRESSING                                        \
  "WORD PTR [" REGISTER "+" OPERAND_DWORD "]"

#define FOUR_BYTE_DISP_OP_32_ADDRESSING                                        \
  "DWORD PTR [" REGISTER "+" OPERAND_DWORD "]"

#define SIB_FOUR_BYTE_DISP_OP_8_ADDRESSING                                     \
  "BYTE PTR [" REGISTER "+" REGISTER "*" SCALE "+" OPERAND_DWORD "]"

#define SIB_FOUR_BYTE_DISP_OP_16_ADDRESSING                                    \
  "WORD PTR [" REGISTER "+" REGISTER "*" SCALE "+" OPERAND_DWORD "]"

#define SIB_FOUR_BYTE_DISP_OP_32_ADDRESSING                                    \
  "DWORD PTR [" REGISTER "+" REGISTER "*" SCALE "+" OPERAND_DWORD "]"

