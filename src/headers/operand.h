#include "decoder.h"

/* ib or imm8 */
#define OPERAND_BYTE "0x%02x"
/* iw ic iv or imm16 */
#define OPERAND_WORD "0x%04x"
/* iv id or imm32 */
#define OPERAND_DWORD "0x%08x"
/* ap 32/48 bit pointer */
#define OPERAND_48 "0x%lx"
/* when register addressing (mod field = 3) */
#define REG_TO_REG "%s,%s"

#define MEM_TO_REG "%s,%s"

#define REG_TO_MEM "%s,%s" 

#define SINGLE_OPERAND "%s"

#define REGISTER "%s"

#define SCALE "%d"

#define INDIRECT_OP_8_ADDRESSING "BYTE PTR [" REGISTER "]"
#define INDIRECT_OP_16_ADDRESSING "WORD PTR [" REGISTER "]"
#define INDIRECT_OP_32_ADDRESSING "DWORD PTR [" REGISTER "]"

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

bool set_operands(Dinstruction *decoded, uchar8_t instruction);
bool set_operands32(Dinstruction *decoded, uchar8_t instruction);
bool set_operands64(Dinstruction *decoded, uchar8_t instruction);

/* 8-bit registers */
static const char *modrm_reg8[] = {"al", "cl", "dl", "bl", "ah", "ch", "dh", "bh"};
/* 16-bit registers */
static const char *modrm_reg16[] = {"ax", "cx", "dx", "bx", "sp", "bp", "si", "di"};
/* 32-bit registers */
static const char *modrm_reg32[] = {"eax", "ecx", "edx", "ebx",
                              "esp", "ebp", "esi", "edi"};
/* 64-bit registers */
static const char *modrm_reg64[] = {"rax", "rcx", "rdx", "rbx",
                              "rsp", "rbp", "rsi", "rdi"};

/* instr_zero with 32-bit operands map */ 
static const char *z_instr_op32[] = {[0x06] = "es",
                               [0x07] = "es",
                               [0x0e] = "cs",
                               [0x16] = "ss",
                               [0x17] = "ss",
                               [0x1e] = "ds",
                               [0x1f] = "ds",
                               [0x26] = "",
                               [0x27] = "",
                               [0x2e] = "",
                               [0x2f] = "",
                               [0x36] = "",
                               [0x37] = "",
                               [0x3e] = "",
                               [0x3f] = "",
                               [0x40] = "eax",
                               [0x41] = "ecx",
                               [0x42] = "edx",
                               [0x43] = "ebx",
                               [0x44] = "esp",
                               [0x45] = "ebp",
                               [0x46] = "esi",
                               [0x47] = "edi",
                               [0x48] = "eax",
                               [0x49] = "ecx",
                               [0x4a] = "edx",
                               [0x4b] = "ebx",
                               [0x4c] = "esp",
                               [0x4d] = "ebp",
                               [0x4e] = "esi",
                               [0x4f] = "edi",
                               [0x50] = "eax",
                               [0x51] = "ecx",
                               [0x52] = "edx",
                               [0x53] = "ebx",
                               [0x54] = "esp",
                               [0x55] = "ebp",
                               [0x56] = "esi",
                               [0x57] = "edi",
                               [0x58] = "eax",
                               [0x59] = "ecx",
                               [0x5a] = "edx",
                               [0x5b] = "ebx",
                               [0x5c] = "esp",
                               [0x5d] = "ebp",
                               [0x5e] = "esi",
                               [0x5f] = "edi",
                               [0x60] = "",
                               [0x61] = "",
                               [0x64] = "",
                               [0x65] = "",
                               [0x66] = "",
                               [0x67] = "",
                               [0x6c] = "BYTE PTR es:[edi],dx",
                               [0x6d] = "DWORD PTR es:[edi],dx",
                               [0x6e] = "dx,BYTE PTR ds:[esi]",
                               [0x6f] = "dx,DWORD PTR ds:[esi]",
                               [0x90] = "",
                               [0x91] = "ecx,eax",
                               [0x92] = "edx,eax",
                               [0x93] = "ebx,eax",
                               [0x94] = "esp,eax",
                               [0x95] = "ebp,eax",
                               [0x96] = "esi,eax",
                               [0x97] = "edi,eax",
                               [0x98] = "",
                               [0x99] = "",
                               [0x9b] = "",
                               [0x9c] = "",
                               [0x9d] = "",
                               [0x9e] = "",
                               [0x9f] = "",
                               [0xa4] = "BYTE PTR es:[edi],BYTE PTR ds:[esi]",
                               [0xa5] = "DWORD PTR es:[edi],DWORD PTR ds:[esi]",
                               [0xa6] = "BYTE PTR ds:[esi],BYTE PTR es:[edi]",
                               [0xa7] = "DWORD PTR ds:[esi],DWORD PTR es:[edi]",
                               [0xaa] = "BYTE PTR es:[edi],al",
                               [0xab] = "DWORD PTR es:[edi],eax",
                               [0xac] = "al,BYTE PTR ds:[esi]",
                               [0xad] = "eax,DWORD PTR ds:[esi]",
                               [0xae] = "al,BYTE PTR es:[edi]",
                               [0xaf] = "eax,DWORD PTR es:[edi]",
                               [0xc3] = "",
                               [0xc9] = "",
                               [0xcb] = "",
                               [0xcc] = "",
                               [0xce] = "",
                               [0xcf] = "",
                               [0xec] = "al,dx",
                               [0xed] = "eax,dx",
                               [0xee] = "dx,al",
                               [0xef] = "dx,eax",
                               [0xf0] = "",
                               [0xf2] = "",
                               [0xf3] = "",
                               [0xf4] = "",
                               [0xf5] = "",
                               [0xf8] = "",
                               [0xf9] = "",
                               [0xfa] = "",
                               [0xfb] = "",
                               [0xfc] = "",
                               [0xfd] = ""};

/* instr_zero with 16-bit operands map */ 
static const char *z_instr_op16[] = {[0x06] = "es",
                               [0x07] = "es",
                               [0x0e] = "cs",
                               [0x16] = "ss",
                               [0x17] = "ss",
                               [0x1e] = "ds",
                               [0x1f] = "ds",
                               [0x26] = "",
                               [0x27] = "",
                               [0x2e] = "",
                               [0x2f] = "",
                               [0x36] = "",
                               [0x37] = "",
                               [0x3e] = "",
                               [0x3f] = "",
                               [0x40] = "ax",
                               [0x41] = "cx",
                               [0x42] = "dx",
                               [0x43] = "bx",
                               [0x44] = "sp",
                               [0x45] = "bp",
                               [0x46] = "si",
                               [0x47] = "di",
                               [0x48] = "ax",
                               [0x49] = "cx",
                               [0x4a] = "dx",
                               [0x4b] = "bx",
                               [0x4c] = "sp",
                               [0x4d] = "bp",
                               [0x4e] = "si",
                               [0x4f] = "di",
                               [0x50] = "ax",
                               [0x51] = "cx",
                               [0x52] = "dx",
                               [0x53] = "bx",
                               [0x54] = "sp",
                               [0x55] = "bp",
                               [0x56] = "si",
                               [0x57] = "di",
                               [0x58] = "ax",
                               [0x59] = "cx",
                               [0x5a] = "dx",
                               [0x5b] = "bx",
                               [0x5c] = "sp",
                               [0x5d] = "bp",
                               [0x5e] = "si",
                               [0x5f] = "di",
                               [0x60] = "",
                               [0x61] = "",
                               [0x64] = "",
                               [0x65] = "",
                               [0x66] = "",
                               [0x67] = "",
                               [0x6c] = "BYTE PTR es:[edi],dx",
                               [0x6d] = "WORD PTR es:[edi],dx",
                               [0x6e] = "dx,BYTE PTR ds:[esi]",
                               [0x6f] = "dx,WORD PTR ds:[esi]",
                               [0x90] = "",
                               [0x91] = "cx,ax",
                               [0x92] = "dx,ax",
                               [0x93] = "bx,ax",
                               [0x94] = "sp,ax",
                               [0x95] = "bp,ax",
                               [0x96] = "si,ax",
                               [0x97] = "di,ax",
                               [0x98] = "",
                               [0x99] = "",
                               [0x9b] = "",
                               [0x9c] = "",
                               [0x9d] = "",
                               [0x9e] = "",
                               [0x9f] = "",
                               [0xa4] = "BYTE PTR es:[edi],BYTE PTR ds:[esi]",
                               [0xa5] = "WORD PTR es:[edi],WORD PTR ds:[esi]",
                               [0xa6] = "BYTE PTR ds:[esi],BYTE PTR es:[edi]",
                               [0xa7] = "WORD PTR ds:[esi],WORD PTR es:[edi]",
                               [0xaa] = "BYTE PTR es:[edi],al",
                               [0xab] = "WORD PTR es:[edi],ax",
                               [0xac] = "al,BYTE PTR ds:[esi]",
                               [0xad] = "ax,WORD PTR ds:[esi]",
                               [0xae] = "al,BYTE PTR es:[edi]",
                               [0xaf] = "ax,WORD PTR es:[edi]",
                               [0xc3] = "",
                               [0xc9] = "",
                               [0xcb] = "",
                               [0xcc] = "",
                               [0xce] = "",
                               [0xcf] = "",
                               [0xec] = "al,dx",
                               [0xed] = "ax,dx",
                               [0xee] = "dx,al",
                               [0xef] = "dx,ax",
                               [0xf0] = "",
                               [0xf2] = "",
                               [0xf3] = "",
                               [0xf4] = "",
                               [0xf5] = "",
                               [0xf8] = "",
                               [0xf9] = "",
                               [0xfa] = "",
                               [0xfb] = "",
                               [0xfc] = "",
                               [0xfd] = ""};

/* instr_other with 32-bit operands map */
static const char *o_instr_op32[] = {[0x04] = "al," OPERAND_BYTE,
                               [0x05] = "eax," OPERAND_DWORD,
                               [0x0c] = "al," OPERAND_BYTE,
                               [0x0d] = "eax," OPERAND_DWORD,
                               [0x14] = "al," OPERAND_BYTE,
                               [0x15] = "eax," OPERAND_DWORD,
                               [0x1c] = "al," OPERAND_BYTE,
                               [0x1d] = "eax," OPERAND_DWORD,
                               [0x24] = "al," OPERAND_BYTE,
                               [0x25] = "eax," OPERAND_DWORD,
                               [0x2c] = "al," OPERAND_BYTE,
                               [0x2d] = "eax," OPERAND_DWORD,
                               [0x34] = "al," OPERAND_BYTE,
                               [0x35] = "eax," OPERAND_DWORD,
                               [0x3c] = "al," OPERAND_BYTE,
                               [0x3d] = "eax," OPERAND_DWORD,
                               [0x68] = OPERAND_DWORD,
                               [0x6a] = OPERAND_BYTE,
                               [0x70] = OPERAND_BYTE,
                               [0x71] = OPERAND_BYTE,
                               [0x72] = OPERAND_BYTE,
                               [0x73] = OPERAND_BYTE,
                               [0x74] = OPERAND_BYTE,
                               [0x75] = OPERAND_BYTE,
                               [0x76] = OPERAND_BYTE,
                               [0x77] = OPERAND_BYTE,
                               [0x78] = OPERAND_BYTE,
                               [0x79] = OPERAND_BYTE,
                               [0x7a] = OPERAND_BYTE,
                               [0x7b] = OPERAND_BYTE,
                               [0x7c] = OPERAND_BYTE,
                               [0x7d] = OPERAND_BYTE,
                               [0x7e] = OPERAND_BYTE,
                               [0x7f] = OPERAND_BYTE,
                               [0x9a] = OPERAND_WORD ":" OPERAND_DWORD,
                               [0xa0] = "al,ds:" OPERAND_BYTE,
                               [0xa1] = "eax,ds:" OPERAND_BYTE,
                               [0xa2] = "ds:" OPERAND_BYTE ",al",
                               [0xa3] = "ds:" OPERAND_BYTE ",eax",
                               [0xa8] = "al," OPERAND_BYTE,
                               [0xa9] = "eax," OPERAND_DWORD,
                               [0xb1] = "cl," OPERAND_BYTE,
                               [0xb2] = "dl," OPERAND_BYTE,
                               [0xb3] = "bl," OPERAND_BYTE,
                               [0xb4] = "ah," OPERAND_BYTE,
                               [0xb5] = "ch," OPERAND_BYTE,
                               [0xb6] = "dh," OPERAND_BYTE,
                               [0xb7] = "bh," OPERAND_BYTE,
                               [0xb8] = "eax," OPERAND_DWORD,
                               [0xb9] = "ecx," OPERAND_DWORD,
                               [0xba] = "edx," OPERAND_DWORD,
                               [0xbb] = "ebx," OPERAND_DWORD,
                               [0xbc] = "esp," OPERAND_DWORD,
                               [0xbd] = "ebp," OPERAND_DWORD,
                               [0xbe] = "esi," OPERAND_DWORD,
                               [0xbf] = "edi," OPERAND_DWORD,
                               [0xc2] = OPERAND_WORD,
                               [0xca] = OPERAND_WORD,
                               [0xcd] = OPERAND_BYTE,
                               [0xd4] = OPERAND_BYTE,
                               [0xd5] = OPERAND_BYTE,
                               [0xe0] = OPERAND_BYTE,
                               [0xe1] = OPERAND_BYTE,
                               [0xe2] = OPERAND_BYTE,
                               [0xe3] = OPERAND_BYTE,
                               [0xe4] = "al," OPERAND_BYTE,
                               [0xe5] = "eax," OPERAND_BYTE,
                               [0xe6] = OPERAND_BYTE ",al",
                               [0xe7] = OPERAND_BYTE ",eax",
                               [0xe8] = OPERAND_DWORD,
                               [0xe9] = OPERAND_DWORD,
                               [0xea] = OPERAND_WORD ":" OPERAND_DWORD,
                               [0xeb] = OPERAND_BYTE};


/* instr_other with 16-bit operands map */
static const char *o_instr_op16[] = {[0x04] = "al," OPERAND_BYTE,
                               [0x05] = "ax," OPERAND_WORD,
                               [0x0c] = "al," OPERAND_BYTE,
                               [0x0d] = "ax," OPERAND_WORD,
                               [0x14] = "al," OPERAND_BYTE,
                               [0x15] = "ax," OPERAND_WORD,
                               [0x1c] = "al," OPERAND_BYTE,
                               [0x1d] = "ax," OPERAND_WORD,
                               [0x24] = "al," OPERAND_BYTE,
                               [0x25] = "ax," OPERAND_WORD,
                               [0x2c] = "al," OPERAND_BYTE,
                               [0x2d] = "ax," OPERAND_WORD,
                               [0x34] = "al," OPERAND_BYTE,
                               [0x35] = "ax," OPERAND_WORD,
                               [0x3c] = "al," OPERAND_BYTE,
                               [0x3d] = "ax," OPERAND_WORD,
                               [0x68] = OPERAND_WORD,
                               [0x6a] = OPERAND_BYTE,
                               [0x70] = OPERAND_BYTE,
                               [0x71] = OPERAND_BYTE,
                               [0x72] = OPERAND_BYTE,
                               [0x73] = OPERAND_BYTE,
                               [0x74] = OPERAND_BYTE,
                               [0x75] = OPERAND_BYTE,
                               [0x76] = OPERAND_BYTE,
                               [0x77] = OPERAND_BYTE,
                               [0x78] = OPERAND_BYTE,
                               [0x79] = OPERAND_BYTE,
                               [0x7a] = OPERAND_BYTE,
                               [0x7b] = OPERAND_BYTE,
                               [0x7c] = OPERAND_BYTE,
                               [0x7d] = OPERAND_BYTE,
                               [0x7e] = OPERAND_BYTE,
                               [0x7f] = OPERAND_BYTE,
                               [0x9a] = OPERAND_WORD ":0x%hx",
                               [0xa0] = "al,ds:" OPERAND_DWORD,
                               [0xa1] = "ax,ds:" OPERAND_DWORD,
                               [0xa2] = "ds:" OPERAND_DWORD ",al",
                               [0xa3] = "ds:" OPERAND_DWORD ",ax",
                               [0xa8] = "al," OPERAND_BYTE,
                               [0xa9] = "ax," OPERAND_WORD,
                               [0xb1] = "cl," OPERAND_BYTE,
                               [0xb2] = "dl," OPERAND_BYTE,
                               [0xb3] = "bl," OPERAND_BYTE,
                               [0xb4] = "ah," OPERAND_BYTE,
                               [0xb5] = "ch," OPERAND_BYTE,
                               [0xb6] = "dh," OPERAND_BYTE,
                               [0xb7] = "bh," OPERAND_BYTE,
                               [0xb8] = "ax," OPERAND_WORD,
                               [0xb9] = "cx," OPERAND_WORD,
                               [0xba] = "dx," OPERAND_WORD,
                               [0xbb] = "bx," OPERAND_WORD,
                               [0xbc] = "sp," OPERAND_WORD,
                               [0xbd] = "bp," OPERAND_WORD,
                               [0xbe] = "si," OPERAND_WORD,
                               [0xbf] = "di," OPERAND_WORD,
                               [0xc2] = OPERAND_WORD,
                               [0xca] = OPERAND_WORD,
                               [0xcd] = OPERAND_BYTE,
                               [0xd4] = OPERAND_BYTE,
                               [0xd5] = OPERAND_BYTE,
                               [0xe0] = OPERAND_BYTE,
                               [0xe1] = OPERAND_BYTE,
                               [0xe2] = OPERAND_BYTE,
                               [0xe3] = OPERAND_BYTE,
                               [0xe4] = "al," OPERAND_BYTE,
                               [0xe5] = "ax," OPERAND_BYTE,
                               [0xe6] = OPERAND_BYTE ",al",
                               [0xe7] = OPERAND_BYTE ",ax",
                               [0xe8] = OPERAND_WORD,
                               [0xe9] = OPERAND_WORD,
                               [0xea] = OPERAND_WORD ":0x%hx",
                               [0xeb] = OPERAND_BYTE};
