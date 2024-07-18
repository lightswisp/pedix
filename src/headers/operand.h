#include "decoder.h"

bool set_operands(Dinstruction *decoded, unsigned char instruction);
bool set_operands32(Dinstruction *decoded, unsigned char instruction);
bool set_operands64(Dinstruction *decoded, unsigned char instruction);

static char *modrm_reg8[] = {"al", "cl", "dl", "bl", "ah", "ch", "dh", "bh"};
static char *modrm_reg16[] = {"ax", "cx", "dx", "bx", "sp", "bp", "si", "di"};
static char *modrm_reg32[] = {"eax", "ecx", "edx", "ebx",
                              "esp", "ebp", "esi", "edi"};
static char *modrm_reg64[] = {"rax", "rcx", "rdx", "rbx",
                              "rsp", "rbp", "rsi", "rdi"};

static char *z_instr_op32[] = {[0x06] = "es",
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

static char *z_instr_op16[] = {[0x06] = "es",
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

static char *o_instr_op32[] = {
    [0x04] = "al",  [0x05] = "eax", [0x0c] = "al",  [0x0d] = "eax",
    [0x14] = "al",  [0x15] = "eax", [0x1c] = "al",  [0x1d] = "eax",
    [0x24] = "al",  [0x25] = "eax", [0x2c] = "al",  [0x2d] = "eax",
    [0x34] = "al",  [0x35] = "eax", [0x3c] = "al",  [0x3d] = "eax",
    [0x68] = "",    [0x6a] = "",    [0x70] = "",    [0x71] = "",
    [0x72] = "",    [0x73] = "",    [0x74] = "",    [0x75] = "",
    [0x76] = "",    [0x77] = "",    [0x78] = "",    [0x79] = "",
    [0x7a] = "",    [0x7b] = "",    [0x7c] = "",    [0x7d] = "",
    [0x7e] = "",    [0x7f] = "",    [0x9a] = "",    [0xa0] = "al",
    [0xa1] = "eax", [0xa2] = "al",  [0xa3] = "eax", [0xa8] = "al",
    [0xa9] = "eax", [0xb0] = "al",  [0xb1] = "cl",  [0xb2] = "dl",
    [0xb3] = "bl",  [0xb4] = "ah",  [0xb5] = "ch",  [0xb6] = "dh",
    [0xb7] = "bh",  [0xb8] = "eax", [0xb9] = "ecx", [0xba] = "edx",
    [0xbb] = "ebx", [0xbc] = "esp", [0xbd] = "ebp", [0xbe] = "esi",
    [0xbf] = "edi", [0xc2] = "",    [0xca] = "",    [0xcd] = "",
    [0xd4] = "",    [0xd5] = "",    [0xe0] = "",    [0xe1] = "",
    [0xe2] = "",    [0xe3] = "",    [0xe4] = "al",  [0xe5] = "eax",
    [0xe6] = "al",  [0xe7] = "eax", [0xe8] = "",    [0xe9] = "",
    [0xea] = "",    [0xeb] = ""};

static char *o_instr_op16[] = {
    [0x04] = "al", [0x05] = "ax", [0x0c] = "al", [0x0d] = "ax", [0x14] = "al",
    [0x15] = "ax", [0x1c] = "al", [0x1d] = "ax", [0x24] = "al", [0x25] = "ax",
    [0x2c] = "al", [0x2d] = "ax", [0x34] = "al", [0x35] = "ax", [0x3c] = "al",
    [0x3d] = "ax", [0x68] = "",   [0x6a] = "",   [0x70] = "",   [0x71] = "",
    [0x72] = "",   [0x73] = "",   [0x74] = "",   [0x75] = "",   [0x76] = "",
    [0x77] = "",   [0x78] = "",   [0x79] = "",   [0x7a] = "",   [0x7b] = "",
    [0x7c] = "",   [0x7d] = "",   [0x7e] = "",   [0x7f] = "",   [0x9a] = "",
    [0xa0] = "al", [0xa1] = "ax", [0xa2] = "al", [0xa3] = "ax", [0xa8] = "al",
    [0xa9] = "ax", [0xb0] = "al", [0xb1] = "cl", [0xb2] = "dl", [0xb3] = "bl",
    [0xb4] = "ah", [0xb5] = "ch", [0xb6] = "dh", [0xb7] = "bh", [0xb8] = "ax",
    [0xb9] = "cx", [0xba] = "dx", [0xbb] = "bx", [0xbc] = "sp", [0xbd] = "bp",
    [0xbe] = "si", [0xbf] = "di", [0xc2] = "",   [0xca] = "",   [0xcd] = "",
    [0xd4] = "",   [0xd5] = "",   [0xe0] = "",   [0xe1] = "",   [0xe2] = "",
    [0xe3] = "",   [0xe4] = "al", [0xe5] = "ax", [0xe6] = "al", [0xe7] = "ax",
    [0xe8] = "",   [0xe9] = "",   [0xea] = "",   [0xeb] = ""};
