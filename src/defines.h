#pragma once

#define MAX_INSTR_SIZE        0x0F
#define BYTE_SZ               0x01        // OPERAND TYPE b (Byte, regardless of operand-size attribute)
#define THREE_BYTE_SZ         0x03        // 24 bit
#define WORD_SZ               0x02        // OPERAND TYPE w (Word, regardless of operand-size attribute)
#define DOUBLEWORD_SZ         0x04        // OPERAND TYPE v (Word or doubleword, depending on operand-size attribute)
#define ADDR_48_SZ            0x06        // OPERAND TYPE p (32-bit or 48-bit pointer, depending on operand-size attribute)

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