#include <stdbool.h>

#include "decoder.h"

bool set_mnemonic(Dinstruction *decoded, unsigned char instruction);
void set_operands(Dinstruction *decoded);
void set_immediate(Dinstruction *decoded);

static char *extd_ext_11b_66[0x100][0x08] = {
    [0x71] = {"", "", "vpsrlw", "", "vpsraw", "", "vpsllw", ""},
    [0x72] = {"", "", "vpsrld", "", "vpsrad", "", "vpslld", ""},
    [0x73] = {"", "", "vpsrlq", "vpsrldq", "", "", "vpsllq", "vpslldq"}};

static char *extd_ext_11b_f3[0x100][0x08] = {
    [0xC7] = {"", "", "", "", "", "", "", "rdpid"},
    [0xAE] = {"rdfsbase", "rdgsbase", "wrfsbase", "wrgsbase"}};

static char *extd_ext_11b_rm[0x08][0x08] = {
    [0x00] = {"", "vmcall", "vmlaunch", "vmresume", "vmxoff"},
    [0x01] = {"monitor", "mwait", "clac", "stac", "encls"},
    [0x07] = {"swapgs", "rdtscp"}};

static char *extd_ext_11b[0x100][0x08] = {
    [0x00] = {"sldt", "str", "lldt", "ltr", "verr", "verw"},
    [0x01] = {"", "", "", "", "smsw", "", "lmsw", "invlpg"},
    [0xBA] = {"", "", "", "", "bt", "bts", "btr", "btc"},
    [0xC7] = {"", "", "", "", "", "", "rdrand", "rdseed"},
    [0xB9] = {"ud1", "ud1", "ud1", "ud1", "ud1", "ud1", "ud1", "ud1"},
    [0x71] = {"", "", "psrlw", "", "psraw", "", "psllw"},
    [0x72] = {"", "", "psrld", "", "psrad", "", "pslld"},
    [0x73] = {"", "", "psrlq", "", "", "", "psllq"},
    [0xAE] = {"", "", "", "", "", "lfence", "mfence", "sfence"},
    [0x18] = {"nop", "nop", "nop", "nop", "nop", "nop", "nop", "nop"}};

static char *extd_ext_mem_66[0x100][0x08] = {
    [0xC7] = {"", "", "", "", "", "", "vmclear"}};

static char *extd_ext_mem_f3[0x100][0x08] = {
    [0xC7] = {"", "", "", "", "", "", "vmxon"}};

static char *extd_ext_mem[0x100][0x08] = {
    [0x00] = {"sldt", "str", "lldt", "ltr", "verr", "verw"},
    [0x01] = {"sgdt", "sidt", "lgdt", "lidt", "smsw", "", "lmsw", "invlpg"},
    [0xBA] = {"", "", "", "", "bt", "bts", "btr", "btc"},
    [0xC7] = {"", "cmpxch8b", "", "", "", "", "vmptrld", "vmptrst"},
    [0xB9] = {"ud1", "ud1", "ud1", "ud1", "ud1", "ud1", "ud1", "ud1"},
    [0xAE] = {"fxsave", "fxrstor", "ldmxcsr", "stmxcsr", "xsave", "xrstor",
              "xsaveopt", "clflush"},
    [0x18] = {"prefetch", "prefetch", "prefetch", "prefetch", "nop", "nop",
              "nop", "nop"}};

static char *extd[0x100] = { // 0x0f
    "",     "",       "lar",  "lsl",    "", "syscall",
    "clts", "sysret", "invd", "wbindv", "", "ud2"};

static char *reg_ext_11b[0x100][0x08] = {
    [0x80] = {"add", "or", "adc", "sbb", "and", "sub", "xor", "cmp"},
    [0x81] = {"add", "or", "adc", "sbb", "and", "sub", "xor", "cmp"},
    [0x82] = {"add", "or", "adc", "sbb", "and", "sub", "xor", "cmp"},
    [0x83] = {"add", "or", "adc", "sbb", "and", "sub", "xor", "cmp"},
    [0x8F] = {"pop"},
    [0xC0] = {"rol", "ror", "rcl", "rcr", "shl", "shr", "shl", "sar"},
    [0xC1] = {"rol", "ror", "rcl", "rcr", "shl", "shr", "shl", "sar"},
    [0xD0] = {"rol", "ror", "rcl", "rcr", "shl", "shr", "shl", "sar"},
    [0xD1] = {"rol", "ror", "rcl", "rcr", "shl", "shr", "shl", "sar"},
    [0xD2] = {"rol", "ror", "rcl", "rcr", "shl", "shr", "shl", "sar"},
    [0xD3] = {"rol", "ror", "rcl", "rcr", "shl", "shr", "shl", "sar"},
    [0xF6] = {"test", "", "not", "neg", "mul", "imul", "div", "idiv"},
    [0xF7] = {"test", "", "not", "neg", "mul", "imul", "div", "idiv"},
    [0xFE] = {"inc", "dec"},
    [0xFF] = {"inc", "dec", "call", "call", "jmp", "jmp", "push"},
    [0xC6] = {"mov", "", "", "", "", "", "xabort"},
    [0xC7] = {"mov", "", "", "", "", "", "xbegin"},
};

static char *reg_ext_mem[0x100][0x08] = {
    [0x80] = {"add", "or", "adc", "sbb", "and", "sub", "xor", "cmp"},
    [0x81] = {"add", "or", "adc", "sbb", "and", "sub", "xor", "cmp"},
    [0x82] = {"add", "or", "adc", "sbb", "and", "sub", "xor", "cmp"},
    [0x83] = {"add", "or", "adc", "sbb", "and", "sub", "xor", "cmp"},
    [0x8F] = {"pop"},
    [0xC0] = {"rol", "ror", "rcl", "rcr", "shl", "shr", "shl", "sar"},
    [0xC1] = {"rol", "ror", "rcl", "rcr", "shl", "shr", "shl", "sar"},
    [0xD0] = {"rol", "ror", "rcl", "rcr", "shl", "shr", "shl", "sar"},
    [0xD1] = {"rol", "ror", "rcl", "rcr", "shl", "shr", "shl", "sar"},
    [0xD2] = {"rol", "ror", "rcl", "rcr", "shl", "shr", "shl", "sar"},
    [0xD3] = {"rol", "ror", "rcl", "rcr", "shl", "shr", "shl", "sar"},
    [0xF6] = {"test", "", "not", "neg", "mul", "imul", "div", "idiv"},
    [0xF7] = {"test", "", "not", "neg", "mul", "imul", "div", "idiv"},
    [0xFE] = {"inc", "dec"},
    [0xFF] = {"inc", "dec", "call", "call", "jmp", "jmp", "push"},
    [0xC6] = {"mov", "", "", "", "", "", ""},
    [0xC7] = {"mov", "", "", "", "", "", ""},
};

// mod/rm extension via reg (Table A-6. Opcode Extensions for One- and Two-byte
// Opcodes by Group Number)
static char *m_ex_table[0x100][0x08] = {
    [0x80] = {"add", "or", "adc", "sbb", "and", "sub", "xor", "cmp"},
    [0x81] = {"add", "or", "adc", "sbb", "and", "sub", "xor", "cmp"},
    [0x82] = {"add", "or", "adc", "sbb", "and", "sub", "xor", "cmp"},
    [0x83] = {"add", "or", "adc", "sbb", "and", "sub", "xor", "cmp"},
    [0x8F] = {"pop"},
    [0xC0] = {"rol", "ror", "rcl", "rcr", "shl", "shr", "shl", "sar"},
    [0xC1] = {"rol", "ror", "rcl", "rcr", "shl", "shr", "shl", "sar"},
    [0xC6] = {"mov", "", "", "", "", "", "xabort"},
    [0xC7] = {"mov", "", "", "", "", "", "xbegin"},
    [0xD0] = {"rol", "ror", "rcl", "rcr", "shl", "shr", "shl", "sar"},
    [0xD1] = {"rol", "ror", "rcl", "rcr", "shl", "shr", "shl", "sar"},
    [0xD2] = {"rol", "ror", "rcl", "rcr", "shl", "shr", "shl", "sar"},
    [0xD3] = {"rol", "ror", "rcl", "rcr", "shl", "shr", "shl", "sar"},
    [0xF6] = {"test", "", "not", "neg", "mul", "imul", "div", "idiv"},
    [0xF7] = {"test", "", "not", "neg", "mul", "imul", "div", "idiv"},
    [0xFE] = {"inc", "dec"},
    [0xFF] = {"inc", "dec", "call", "call", "jmp", "jmp", "push"}};

// extended (0x0f) extension table
static char *m_extd_ex_table[0x100][0x08] = {
    [0x00] = {"sldt", "str", "lldt", "ltr", "verr", "verw", "", ""},
    [0x01] = {"sgdt", "sidt", "lgdt", "lidt", "smsw", "", "lmsw",
              "invlpg"}, // -_- sorry
    [0xBA] = {"", "", "", "", "bt", "bts", "btr", "btc"},
};

static char *reg[0x100] = { // regular
    "add",    "add",   "add",     "add",    "add",    "add",    "push",
    "pop",    "or",    "or",      "or",     "or",     "or",     "or",
    "push",   " ",     "adc",     "adc",    "adc",    "adc",    "adc",
    "adc",    "push",  "pop",     "sbb",    "sbb",    "sbb",    "sbb",
    "sbb",    "sbb",   "push",    "pop",    "and",    "and",    "and",
    "and",    "and",   "and",     "es",     "daa",    "sub",    "sub",
    "sub",    "sub",   "sub",     "sub",    "cs",     "das",    "xor",
    "xor",    "xor",   "xor",     "xor",    "xor",    "ss",     "aaa",
    "cmp",    "cmp",   "cmp",     "cmp",    "cmp",    "cmp",    "ds",
    "aas",    "inc",   "inc",     "inc",    "inc",    "inc",    "inc",
    "inc",    "inc",   "dec",     "dec",    "dec",    "dec",    "dec",
    "dec",    "dec",   "dec",     "push",   "push",   "push",   "push",
    "push",   "push",  "push",    "push",   "pop",    "pop",    "pop",
    "pop",    "pop",   "pop",     "pop",    "pop",    "pusha",  "popa",
    "bound",  "arpl",  "fs",      "gs",     "opsize", "adsize", "push",
    "imul",   "push",  "imul",    "insb",   "insw",   "outsb",  "outsw",
    "jo",     "jno",   "jb",      "jnb",    "jz",     "jnz",    "jbe",
    "ja",     "js",    "jns",     "jp",     "jnp",    "jl",     "jnl",
    "jle",    "jnle",  "add",     "add",    "sub",    "sub",    "test",
    "test",   "xchg",  "xchg",    "mov",    "mov",    "mov",    "mov",
    "mov",    "lea",   "mov",     "pop",    "nop",    "xchg",   "xchg",
    "xchg",   "xchg",  "xchg",    "xchg",   "xchg",   "cbw",    "cwd",
    "call",   "wait",  "pushf",   "popf",   "sahf",   "lahf",   "mov",
    "mov",    "mov",   "mov",     "movsb",  "movsw",  "cmpsb",  "cmpsw",
    "test",   "test",  "stosb",   "stosw",  "lodsb",  "lodsw",  "scasb",
    "scasw",  "mov",   "mov",     "mov",    "mov",    "mov",    "mov",
    "mov",    "mov",   "mov",     "mov",    "mov",    "mov",    "mov",
    "mov",    "mov",   "mov",     " ",      " ",      "retn",   "retn",
    "les",    "lds",   "mov",     "mov",    "enter",  "leave",  "retf",
    "retf",   "int3",  "int",     "into",   "iret",   " ",      " ",
    " ",      " ",     "aam",     "aad",    "salc",   "xlat",   "esc",
    "esc",    "esc",   "esc",     "esc",    "esc",    "esc",    "esc",
    "loopnz", "loopz", "loop",    "jcxz",   "in",     "in",     "out",
    "out",    "call",  "jmp",     "jmp",    "jmp",    "in",     "in",
    "out",    "out",   "lock",    "int1",   "repne",  "rep",    "hlt",
    "cmc",    " ",     " ",       "clc",    "stc",    "cli",    "sti",
    "cld",    "std",   "inc/dec", "inc/dec"};
