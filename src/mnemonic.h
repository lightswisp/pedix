#include "decoder.h" 

void set_mnemonic(Dinstruction* decoded, unsigned char instruction);
void set_operands(Dinstruction* decoded);
void set_immediate(Dinstruction* decoded);

//mod/rm extension via reg (Table A-6. Opcode Extensions for One- and Two-byte Opcodes by Group Number)
static char* m_ex_table[0x100][0x08] = { 
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
		[0xFF] = {"inc", "dec", "call", "call", "jmp", "jmp", "push"}	
}; 

// extended (0x0f) extension table
static char* m_extd_ex_table[0x100][0x08] = {
		[0x00] = {"sldt", "str", "lldt", "ltr", "verr", "verw", "", ""},
		[0x01] = {"sgdt", "sidt", "lgdt", "lidt", "smsw", "", "lmsw", "invlpg"}, // -_- sorry
};

static char* m_table[] = { // regular
    "add",    "add",    "add",    "add", 
    "add",    "add",    "push",   "pop", 
    "or",     "or",     "or",     "or",  
    "or",     "or",     "push",   " ",
    "adc",    "adc",    "adc",    "adc",
    "adc",    "adc",    "push",   "pop",
    "sbb",    "sbb",    "sbb",    "sbb",
    "sbb",    "sbb",    "push",   "pop",
    "and",    "and",    "and",    "and",
    "and",    "and",    "es",     "daa",
    "sub",    "sub",    "sub",    "sub",
    "sub",    "sub",    "cs",     "das",
    "xor",    "xor",    "xor",    "xor",
    "xor",    "xor",    "ss",     "aaa",
    "cmp",    "cmp",    "cmp",    "cmp",
    "cmp",    "cmp",    "ds",     "aas",
    "inc",    "inc",    "inc",    "inc",
    "inc",    "inc",    "inc",    "inc",
    "dec",    "dec",    "dec",    "dec",
    "dec",    "dec",    "dec",    "dec",
    "push",   "push",   "push",   "push",
    "push",   "push",   "push",   "push",
    "pop",    "pop",    "pop",    "pop",
    "pop",    "pop",    "pop",    "pop",
    "pusha",  "popa",   "bound",  "arpl",
    "fs",     "gs",     "opsize", "adsize", 
    "push",   "imul",   "push",   "imul",
    "insb",   "insw",   "outsb",  "outsw",  
    "jo",     "jno",    "jb",     "jnb",    
    "jz",     "jnz",    "jbe",    "ja",     
    "js",     "jns",    "jp",     "jnp",    
    "jl",     "jnl",    "jle",    "jnle",   
    "add",    "add",    "sub",    "sub",    
    "test",   "test",   "xchg",   "xchg",   
    "mov",    "mov",    "mov",    "mov",    
    "mov",    "lea",    "mov",    "pop",    
    "nop",    "xchg",   "xchg",   "xchg",   
    "xchg",   "xchg",   "xchg",   "xchg",   
    "cbw",    "cwd",    "call",   "wait",   
    "pushf",  "popf",   "sahf",   "lahf",   
    "mov",    "mov",    "mov",    "mov",    
    "movsb",  "movsw",  "cmpsb",  "cmpsw",  
    "test",   "test",   "stosb",  "stosw",  
    "lodsb",  "lodsw",  "scasb",  "scasw",  
    "mov",    "mov",    "mov",    "mov",    
    "mov",    "mov",    "mov",    "mov",    
    "mov",    "mov",    "mov",    "mov",    
    "mov",    "mov",    "mov",    "mov",    
    " ",      " ",      "retn",   "retn",   
    "les",    "lds",    "mov",    "mov",    
    "enter",  "leave",  "retf",   "retf",   
    "int3",   "int",    "into",   "iret",   
    " ",      " ",      " ",      " ",      
    "aam",    "aad",    "salc",   "xlat",   
    "esc",    "esc",    "esc",    "esc",    
    "esc",    "esc",    "esc",    "esc",    
    "loopnz", "loopz",  "loop",   "jcxz",   
    "in",     "in",     "out",    "out",    
    "call",   "jmp",    "jmp",    "jmp",    
    "in",     "in",     "out",    "out",    
    "lock",   "int1",   "repne",  "rep",    
    "hlt",    "cmc",    " ",      " ",      
    "clc",    "stc",    "cli",    "sti",    
    "cld",    "std",    "inc/dec","inc/dec"
};

static char* ex_m_table[] = { // 0x0f 
	[0x8e] = "jle"
};
