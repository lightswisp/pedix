#include <stdbool.h>

#define MAX_INSTR_SZ 15
#define MAX_PREFIX 2

#define BYTE_SZ 1       // OPERAND TYPE b (Byte, regardless of operand-size attribute)
#define WORD_SZ 2       // OPERAND TYPE w (Word, regardless of operand-size attribute)
#define DOUBLEWORD_SZ 4 // OPERAND TYPE v (Word or doubleword, depending on operand-size attribute)
#define ADDR_48_SZ  6   // OPERAND TYPE p (32-bit or 48-bit pointer, depending on operand-size attribute)

enum Prefixes{
    LOCK            = 0xF0,     //LOCK prefix 
    REPNE_Z         = 0xF2,     //REPNE/REPNZ prefix 
    REP_E_Z         = 0xF3,     //REP or REPE/REPZ prefix 
    CS              = 0x2E,     //CS segment override
    SS              = 0x36,     //SS segment override
    DS              = 0x3E,     //DS segment override
    ES              = 0x26,     //ES segment override
    FS              = 0x64,     //FS segment override
    GS              = 0x65,     //GS segment override
    BNT             = 0x2E,     //Branch not taken
    BT              = 0x3E,     //Branch taken 
    OPSZ_OVERRIDE   = 0x66,     //Operand-size override prefix 
    ASZ_OVERRIDE    = 0x67      //Address-size override prefix 
};

enum Registers{
    AL   = 0,   AX   = 0,   EAX  = 0,   RAX = 0,  ST0  = 0,  MMX0  = 0,  XMM0  = 0, YMM0 = 0, ES_R = 0,
    CL   = 1,   CX   = 1,   ECX  = 1,   RCX = 1,  ST1  = 1,  MMX1  = 1,  XMM1  = 1, YMM1 = 1, CS_R = 1,
    DL   = 2,   DX   = 2,   EDX  = 2,   RDX = 2,  ST2  = 2,  MMX2  = 2,  XMM2  = 2, YMM2 = 2, SS_R = 2,
    BL   = 3,   BX   = 3,   EBX  = 3,   RBX = 3,  ST3  = 3,  MMX3  = 3,  XMM3  = 3, YMM3 = 3, DS_R = 3,
    AH   = 4,   SP   = 4,   ESP  = 4,   RSP = 4,  ST4  = 4,  MMX4  = 4,  XMM4  = 4, YMM4 = 4, FS_R = 4,
    CH   = 5,   BP   = 5,   EBP  = 5,   RBP = 5,  ST5  = 5,  MMX5  = 5,  XMM5  = 5, YMM5 = 5, GS_R = 5,
    DH   = 6,   SI   = 6,   ESI  = 6,   RSI = 6,  ST6  = 6,  MMX6  = 6,  XMM6  = 6, YMM6 = 6,
    BH   = 7,   DI   = 7,   EDI  = 7,   RDI = 7,  ST7  = 7,  MMX7  = 7,  XMM7  = 7, YMM7 = 7,
    R8L  = 8,   R8W  = 8,   R8D  = 8,   R8  = 8,  MMX0_2 = 8,  XMM8  = 8,  YMM8  = 8, 	
    R9L  = 9,	R9W  = 9,   R9D  = 9,   R9  = 9,  MMX1_2 = 9,  XMM9  = 9,  YMM9  = 9,
    R10L = 10, 	R10W = 10,  R10D = 10,  R10 = 10, MMX2_2 = 10, XMM10 = 10, YMM10 = 10,
    R11L = 11, 	R11W = 11,  R11D = 11,  R11 = 11, MMX3_2 = 11, XMM11 = 11, YMM11 = 11,
    R12L = 12, 	R12W = 12,  R12D = 12,  R12 = 12, MMX4_2 = 12, XMM12 = 12, YMM12 = 12,
    R13L = 13, 	R13W = 13,  R13D = 13,  R13 = 13, MMX5_2 = 13, XMM13 = 13, YMM13 = 13,
    R14L = 14,	R14W = 14,  R14D = 14,  R14 = 14, MMX6_2 = 14, XMM14 = 14, YMM14 = 14,
    R15L = 15, 	R15W = 15,  R15D = 15,  R15 = 15, MMX7_2 = 15, XMM15 = 15, YMM15 = 15,
};



typedef struct {
    size_t size;
    bool has_prefix;
    bool extended;
    unsigned int prefixes[2];
    unsigned char op1; // op1 is the primary opcode (it might be a little bit confusting, but it's not the first opcode)
    unsigned char op2; // op2 is the secondary opcode
    char mnemonic[100]; // this one is not implemented yet!
} Dinstruction;

Dinstruction* init_instruction();               // allocates memory for the struct
void dump(Dinstruction* decoded);               // dumps struct fields to stdout
void free_instrucion(Dinstruction* decoded);    // frees the memory
bool decode(unsigned char* insruction, Dinstruction* decoded, unsigned int mode);   //general decode func
bool decode32(unsigned char* insruction, Dinstruction* decoded, unsigned int mode); // 32bit specific 
bool decode64(unsigned char* insruction, Dinstruction* decoded, unsigned int mode); // 64bit specific
bool instr_has_prefix(unsigned char instruction);           // checks if the instruction has prefixes (4 bytes max)
bool instr_has_extended_opcode(unsigned char instruction);  // checks if the instruction has 2-byte opcode
bool instr_has_zero_operands(unsigned char opcode); // if instruction has no operands
bool instr_has_immediate_operand(unsigned char opcode);
bool instr_has_rel_offset_operand(unsigned char opcode);
bool instr_has_direct_addr_operand(unsigned char opcode);
bool instr_has_modrm(unsigned char opcode);
unsigned int get_immediate_operand_size(unsigned char opcode);
unsigned int get_rel_offset_operand_size(unsigned char opcode);