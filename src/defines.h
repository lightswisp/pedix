#define MAX_INSTR_SZ 15
#define MAX_PREFIX 2

#define BYTE_SZ 1       // OPERAND TYPE b (Byte, regardless of operand-size attribute)
#define WORD_SZ 2       // OPERAND TYPE w (Word, regardless of operand-size attribute)
#define DOUBLEWORD_SZ 4 // OPERAND TYPE v (Word or doubleword, depending on operand-size attribute)
#define ADDR_48_SZ  6   // OPERAND TYPE p (32-bit or 48-bit pointer, depending on operand-size attribute)

#define PREFIX_LOCK           0xF0     //LOCK prefix 
#define PREFIX_REPNE_Z        0xF2     //REPNE/REPNZ prefix 
#define PREFIX_REP_E_Z        0xF3     //REP or REPE/REPZ prefix 
#define PREFIX_CS             0x2E     //CS segment override
#define PREFIX_SS             0x36     //SS segment override
#define PREFIX_DS             0x3E     //DS segment override
#define PREFIX_ES             0x26     //ES segment override
#define PREFIX_FS             0x64     //FS segment override
#define PREFIX_GS             0x65     //GS segment override
#define PREFIX_BNT            0x2E     //Branch not taken
#define PREFIX_BT             0x3E     //Branch taken 
#define PREFIX_OPSZ_OVERRIDE  0x66     //Operand-size override prefix 
#define PREFIX_ASZ_OVERRIDE   0x67      //Address-size override prefix 

// REGISTERS
#define AL 0
#define AX 0
#define EAX 0
#define RAX 0
#define ST0 0
#define MMX0 0
#define XMM0 0
#define YMM0 0
#define ES_R 0
#define CL 1
#define CX 1
#define ECX 1
#define RCX 1
#define ST1 1
#define MMX1 1
#define XMM1 1
#define YMM1 1
#define CS_R 1
#define DL 2
#define DX 2
#define EDX 2
#define RDX 2
#define ST2 2
#define MMX2 2
#define XMM2 2
#define YMM2 2
#define SS_R 2
#define BL 3
#define BX 3
#define EBX 3
#define RBX 3
#define ST3 3
#define MMX3 3
#define XMM3 3
#define YMM3 3
#define DS_R 3
#define AH 4
#define SP 4
#define ESP 4
#define RSP 4
#define ST4 4
#define MMX4 4
#define XMM4 4
#define YMM4 4
#define FS_R 4
#define CH 5
#define BP 5
#define EBP 5
#define RBP 5
#define ST5 5
#define MMX5 5
#define XMM5 5
#define YMM5 5
#define GS_R 5
#define DH 6
#define SI 6
#define ESI 6
#define RSI 6
#define ST6 6
#define MMX6 6
#define XMM6 6
#define YMM6 6
#define BH 7
#define DI 7
#define EDI 7
#define RDI 7
#define ST7 7
#define MMX7 7
#define XMM7 7
#define YMM7 7
#define R8L 8
#define R8W 8
#define R8D 8
#define R8 8
#define MMX0_2 8
#define XMM8 8
#define YMM8 8
#define R9L 9
#define R9W 9
#define R9D 9
#define R9 9
#define MMX1_2 9
#define XMM9 9
#define YMM9 9
#define R10L 10
#define R10W 10
#define R10D 10
#define R10 10
#define MMX2_2 10
#define XMM10 10
#define YMM10 10
#define R11L 11
#define R11W 11
#define R11D 11
#define R11 11
#define MMX3_2 11
#define XMM11 11
#define YMM11 11
#define R12L 12
#define R12W 12
#define R12D 12
#define R12 12
#define MMX4_2 12
#define XMM12 12
#define YMM12 12
#define R13L 13
#define R13W 13
#define R13D 13
#define R13 13
#define MMX5_2 13
#define XMM13 13
#define YMM13 13
#define R14L 14
#define R14W 14
#define R14D 14
#define R14 14
#define MMX6_2 14
#define XMM14 14
#define YMM14 14
#define R15L 15
#define R15W 15
#define R15D 15
#define R15 15
#define MMX7_2 15
#define XMM15 15
#define YMM15 15