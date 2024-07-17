#include "decoder.h"

bool set_operands(Dinstruction *decoded, unsigned char instruction);
bool set_operands32(Dinstruction *decoded, unsigned char instruction);
bool set_operands64(Dinstruction *decoded, unsigned char instruction);

static char * b8_reg [] = {"al", "cl", "dl", "bl", "ah", "ch", "dh", "bh"};
static char * b16_reg [] = {"ax", "cx", "dx", "bx", "sp", "bp", "si", "di"};
static char *
    b32_reg [] = {"eax", "ecx", "edx", "ebx", "esp", "ebp", "esi", "edi"};
static char *
    b64_reg [] = {"rax", "rcx", "rdx", "rbx", "rsp", "rbp", "rsi", "rdi"};
