#include <stdint.h>
#include <stdbool.h>

#define MAX_MNEMONIC_LEN 50

typedef enum{
  FIELD_VOID               = 0,
  FIELD_MOD_RM             = 1,
  FIELD_MULTIPLEXED_MOD_RM = 2
} FieldType;

typedef struct{
  FieldType type;
  uint8_t value;
} Field;

typedef enum{
  OPERAND_VOID              = 0, 
  OPERAND_IMM_8             = 1,
  OPERAND_IMM_16            = 2,
  OPERAND_IMM_32            = 3,
  OPERAND_IMM_16_32         = 4,
  OPERAND_R_ALL             = 5,
  OPERAND_RM_ALL            = 6,
  OPERAND_R_8               = 7,
  OPERAND_R_16              = 8,
  OPERAND_R_32              = 9,
  OPERAND_R_16_32           = 10, 
  OPERAND_RM_8              = 11,
  OPERAND_RM_16             = 12,
  OPERAND_RM_32             = 13,
  OPERAND_RM_16_32          = 14,

  OPERAND_REG_AL            = 15,
  OPERAND_REG_CL            = 16,
  OPERAND_REG_DL            = 17,
  OPERAND_REG_BL            = 18,
  OPERAND_REG_AH            = 19,
  OPERAND_REG_CH            = 20,
  OPERAND_REG_DH            = 21,
  OPERAND_REG_BH            = 22,
  OPERAND_REG_AX            = 23,
  OPERAND_REG_CX            = 24,
  OPERAND_REG_DX            = 25,
  OPERAND_REG_BX            = 26,
  OPERAND_REG_SP            = 27,
  OPERAND_REG_BP            = 28,
  OPERAND_REG_SI            = 29,
  OPERAND_REG_DI            = 30,
  OPERAND_REG_EAX           = 31,
  OPERAND_REG_ECX           = 32,
  OPERAND_REG_EDX           = 33,
  OPERAND_REG_EBX           = 34,
  OPERAND_REG_ESP           = 35,
  OPERAND_REG_EBP           = 36,
  OPERAND_REG_ESI           = 37,
  OPERAND_REG_EDI           = 38,
  OPERAND_REG_RAX           = 39,
  OPERAND_REG_RCX           = 40,
  OPERAND_REG_RDX           = 41,
  OPERAND_REG_RBX           = 42,
  OPERAND_REG_RSP           = 43,
  OPERAND_REG_RBP           = 44,
  OPERAND_REG_RSI           = 45,
  OPERAND_REG_RDI           = 46,

  OPERAND_SEG_ALL           = 47,
  OPERAND_SEG_ES            = 48,
  OPERAND_SEG_SS            = 49,
  OPERAND_SEG_DS            = 50,
  OPERAND_SEG_CS            = 51,
  OPERAND_SEG_FS            = 52,
  OPERAND_SEG_GS            = 53,

  OPERAND_M_ALL             = 54,
  OPERAND_M_8               = 55,
  OPERAND_M_16              = 56,
  OPERAND_M_32              = 57,
  OPERAND_M_64              = 58,
  OPERAND_M_128             = 59,
  OPERAND_M_512             = 60,
  OPERAND_M_16_32           = 61,

  OPERAND_M_16_AMP_32       = 62,
  OPERAND_M_16_AMP_16       = 63,
  OPERAND_M_32_AMP_32       = 64,
  OPERAND_M_16_AMP_64       = 65,
  OPERAND_M_16_32_AMP_16_32 = 66,

  OPERAND_MOFFS_8           = 67,
  OPERAND_MOFFS_16          = 68,
  OPERAND_MOFFS_32          = 69,
  OPERAND_MOFFS_64          = 70,
  OPERAND_MOFFS_16_32       = 71,

  OPERAND_REL_8             = 72,
  OPERAND_REL_16            = 73,
  OPERAND_REL_32            = 74,
  OPERAND_REL_16_32         = 75,

  OPERAND_PTR_16            = 76,
  OPERAND_PTR_32            = 77,
  OPERAND_PTR_16_32         = 78,

  OPERAND_M_PTR_16          = 79,
  OPERAND_M_PTR_32          = 80,
  OPERAND_M_PTR_64          = 81,
  OPERAND_M_PTR_16_32       = 82,

  OPERAND_ONE               = 83, 
  OPERAND_REG_ST            = 84,
  OPERAND_REG_STI           = 85,
  OPERAND_REG_ST1           = 86, 
  OPERAND_REG_ST2           = 87,
  OPERAND_REG_STI_M32       = 88,

  OPERAND_XMM               = 89,
  OPERAND_XMM_0             = 90,
  OPERAND_XMM_M_32          = 91,
  OPERAND_XMM_M_64          = 92,
  OPERAND_XMM_M_128         = 93,

  OPERAND_REG_CRN           = 94, 
  OPERAND_REG_DRN           = 95,

  OPERAND_MM                = 96,
  OPERAND_MM_M_64           = 97,
} Operand;

typedef enum {
  PREFIX_VOID            = 0x00,
  PREFIX_LOCK            = 0xF0,
  PREFIX_REPNE_Z         = 0xF2,
  PREFIX_REP_E_Z         = 0xF3,
  PREFIX_CS              = 0x2E,
  PREFIX_SS              = 0x36,
  PREFIX_DS              = 0x3E,
  PREFIX_ES              = 0x26,
  PREFIX_FS              = 0x64,
  PREFIX_GS              = 0x65,
  PREFIX_BNT             = 0x2E,
  PREFIX_BT              = 0x3E,
  PREFIX_OPSIZE_OVERRIDE = 0x66,
  PREFIX_ASZ_OVERRIDE    = 0x67
} Prefix;

typedef struct {
  bool extended_opcode; // false if not 0x0f
  const char mnemonic[MAX_MNEMONIC_LEN]; // text representation of the mnemonic
  Field opcode_field; 
  Operand operand1;
  Operand operand2;
  Operand operand3;
  Operand operand4;
  Prefix  prefix;
  uint8_t primary_opcode;
  int secondary_opcode;
} Instruction;
