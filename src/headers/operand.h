#pragma once
#include "decoder.h"

void pedix_set_operands(Dinstruction *decoded);
void pedix_merge_operands(Dinstruction *decoded);

extern const char *modrm_reg8[]; 
extern const char *modrm_reg16[];
extern const char *modrm_reg32[];

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

#define SINGLE_OPERAND "%s"

#define REGISTER "%s"

#define SCALE "%d"

#define INDIRECT_ADDRESSING_OP8 "BYTE PTR [" REGISTER "]"
#define INDIRECT_ADDRESSING_OP16 "WORD PTR [" REGISTER "]"
#define INDIRECT_ADDRESSING_OP32 "DWORD PTR [" REGISTER "]"

#define SIB_FOUR_BYTE_NO_DISP_ADDRESSING_OP8                                  \
  "BYTE PTR [" REGISTER "+" REGISTER "*" SCALE "]"
#define SIB_FOUR_BYTE_NO_DISP_ADDRESSING_OP16                                 \
  "WORD PTR [" REGISTER "+" REGISTER "*" SCALE "]"
#define SIB_FOUR_BYTE_NO_DISP_ADDRESSING_OP32                                 \
  "DWORD PTR [" REGISTER "+" REGISTER "*" SCALE "]"

#define SIB_FOUR_BYTE_DISP_NO_REG_ADDRESSING_OP8                              \
  "BYTE PTR [" REGISTER "*" SCALE "+" OPERAND_DWORD "]"
#define SIB_FOUR_BYTE_DISP_NO_REG_ADDRESSING_OP16                             \
  "WORD PTR [" REGISTER "*" SCALE "+" OPERAND_DWORD "]"
#define SIB_FOUR_BYTE_DISP_NO_REG_ADDRESSING_OP32                             \
  "DWORD PTR [" REGISTER "*" SCALE "+" OPERAND_DWORD "]"

#define ONE_BYTE_DISP_ADDRESSING_OP8 "BYTE PTR [" REGISTER "+" OPERAND_BYTE "]"

#define ONE_BYTE_DISP_ADDRESSING_OP16                                         \
  "WORD PTR [" REGISTER "+" OPERAND_BYTE "]"

#define ONE_BYTE_DISP_ADDRESSING_OP32                                         \
  "DWORD PTR [" REGISTER "+" OPERAND_BYTE "]"

#define SIB_ONE_BYTE_DISP_ADDRESSING_OP8                                      \
  "BYTE PTR [" REGISTER "+" REGISTER "*" SCALE "+" OPERAND_BYTE "]"

#define SIB_ONE_BYTE_DISP_ADDRESSING_OP16                                     \
  "WORD PTR [" REGISTER "+" REGISTER "*" SCALE "+" OPERAND_BYTE "]"

#define SIB_ONE_BYTE_DISP_ADDRESSING_OP32                                     \
  "DWORD PTR [" REGISTER "+" REGISTER "*" SCALE "+" OPERAND_BYTE "]"

#define FOUR_BYTE_DISP_ADDRESSING_OP8                                         \
  "BYTE PTR [" REGISTER "+" OPERAND_DWORD "]"

#define FOUR_BYTE_DISP_ADDRESSING_OP16                                        \
  "WORD PTR [" REGISTER "+" OPERAND_DWORD "]"

#define FOUR_BYTE_DISP_ADDRESSING_OP32                                        \
  "DWORD PTR [" REGISTER "+" OPERAND_DWORD "]"

#define SIB_FOUR_BYTE_DISP_ADDRESSING_OP8                                     \
  "BYTE PTR [" REGISTER "+" REGISTER "*" SCALE "+" OPERAND_DWORD "]"

#define SIB_FOUR_BYTE_DISP_ADDRESSING_OP16                                    \
  "WORD PTR [" REGISTER "+" REGISTER "*" SCALE "+" OPERAND_DWORD "]"

#define SIB_FOUR_BYTE_DISP_ADDRESSING_OP32                                    \
  "DWORD PTR [" REGISTER "+" REGISTER "*" SCALE "+" OPERAND_DWORD "]"

