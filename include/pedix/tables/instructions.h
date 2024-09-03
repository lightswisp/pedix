/* (instructions.h) auto generated using gen.rb 
 * time: 2024-09-02 05:18:29 -0400
 */

#pragma once
#include <stdbool.h>
#include <stdint.h>
#include "tabledef.h"

instruction_t REGULAR_ADD_0[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "add",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {11,7,0,0}},
   .prefix = 0,
   .primary_opcode = 0,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_ADD_1[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "add",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {14,10,0,0}},
   .prefix = 0,
   .primary_opcode = 1,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_ADD_2[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "add",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {7,11,0,0}},
   .prefix = 0,
   .primary_opcode = 2,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_ADD_3[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "add",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,14,0,0}},
   .prefix = 0,
   .primary_opcode = 3,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_ADD_4[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "add",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {15,1,0,0}},
   .prefix = 0,
   .primary_opcode = 4,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_ADD_5[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "add",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {31,4,0,0}},
   .prefix = 0,
   .primary_opcode = 5,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_PUSH_6[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "push",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {48,0,0,0}},
   .prefix = 0,
   .primary_opcode = 6,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_POP_7[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "pop",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {48,0,0,0}},
   .prefix = 0,
   .primary_opcode = 7,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_OR_8[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "or",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {11,7,0,0}},
   .prefix = 0,
   .primary_opcode = 8,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_OR_9[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "or",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {14,10,0,0}},
   .prefix = 0,
   .primary_opcode = 9,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_OR_10[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "or",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {7,11,0,0}},
   .prefix = 0,
   .primary_opcode = 10,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_OR_11[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "or",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,14,0,0}},
   .prefix = 0,
   .primary_opcode = 11,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_OR_12[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "or",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {15,1,0,0}},
   .prefix = 0,
   .primary_opcode = 12,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_OR_13[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "or",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {31,4,0,0}},
   .prefix = 0,
   .primary_opcode = 13,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_PUSH_14[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "push",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {51,0,0,0}},
   .prefix = 0,
   .primary_opcode = 14,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_ADC_16[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "adc",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {11,7,0,0}},
   .prefix = 0,
   .primary_opcode = 16,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_ADC_17[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "adc",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {14,10,0,0}},
   .prefix = 0,
   .primary_opcode = 17,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_ADC_18[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "adc",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {7,11,0,0}},
   .prefix = 0,
   .primary_opcode = 18,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_ADC_19[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "adc",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,14,0,0}},
   .prefix = 0,
   .primary_opcode = 19,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_ADC_20[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "adc",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {15,1,0,0}},
   .prefix = 0,
   .primary_opcode = 20,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_ADC_21[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "adc",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {31,4,0,0}},
   .prefix = 0,
   .primary_opcode = 21,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_PUSH_22[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "push",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {49,0,0,0}},
   .prefix = 0,
   .primary_opcode = 22,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_POP_23[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "pop",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {49,0,0,0}},
   .prefix = 0,
   .primary_opcode = 23,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_SBB_24[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "sbb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {11,7,0,0}},
   .prefix = 0,
   .primary_opcode = 24,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_SBB_25[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "sbb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {14,10,0,0}},
   .prefix = 0,
   .primary_opcode = 25,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_SBB_26[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "sbb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {7,11,0,0}},
   .prefix = 0,
   .primary_opcode = 26,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_SBB_27[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "sbb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,14,0,0}},
   .prefix = 0,
   .primary_opcode = 27,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_SBB_28[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "sbb",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {15,1,0,0}},
   .prefix = 0,
   .primary_opcode = 28,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_SBB_29[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "sbb",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {31,4,0,0}},
   .prefix = 0,
   .primary_opcode = 29,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_PUSH_30[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "push",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {50,0,0,0}},
   .prefix = 0,
   .primary_opcode = 30,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_POP_31[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "pop",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {50,0,0,0}},
   .prefix = 0,
   .primary_opcode = 31,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_AND_32[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "and",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {11,7,0,0}},
   .prefix = 0,
   .primary_opcode = 32,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_AND_33[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "and",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {14,10,0,0}},
   .prefix = 0,
   .primary_opcode = 33,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_AND_34[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "and",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {7,11,0,0}},
   .prefix = 0,
   .primary_opcode = 34,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_AND_35[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "and",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,14,0,0}},
   .prefix = 0,
   .primary_opcode = 35,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_AND_36[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "and",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {15,1,0,0}},
   .prefix = 0,
   .primary_opcode = 36,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_AND_37[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "and",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {31,4,0,0}},
   .prefix = 0,
   .primary_opcode = 37,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_DAA_39[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "daa",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 39,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_SUB_40[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "sub",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {11,7,0,0}},
   .prefix = 0,
   .primary_opcode = 40,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_SUB_41[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "sub",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {14,10,0,0}},
   .prefix = 0,
   .primary_opcode = 41,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_SUB_42[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "sub",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {7,11,0,0}},
   .prefix = 0,
   .primary_opcode = 42,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_SUB_43[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "sub",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,14,0,0}},
   .prefix = 0,
   .primary_opcode = 43,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_SUB_44[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "sub",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {15,1,0,0}},
   .prefix = 0,
   .primary_opcode = 44,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_SUB_45[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "sub",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {31,4,0,0}},
   .prefix = 0,
   .primary_opcode = 45,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_DAS_47[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "das",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 47,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_XOR_48[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "xor",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {11,7,0,0}},
   .prefix = 0,
   .primary_opcode = 48,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_XOR_49[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "xor",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {14,10,0,0}},
   .prefix = 0,
   .primary_opcode = 49,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_XOR_50[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "xor",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {7,11,0,0}},
   .prefix = 0,
   .primary_opcode = 50,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_XOR_51[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "xor",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,14,0,0}},
   .prefix = 0,
   .primary_opcode = 51,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_XOR_52[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "xor",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {15,1,0,0}},
   .prefix = 0,
   .primary_opcode = 52,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_XOR_53[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "xor",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {31,4,0,0}},
   .prefix = 0,
   .primary_opcode = 53,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_AAA_55[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "aaa",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 55,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_CMP_56[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "cmp",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {11,7,0,0}},
   .prefix = 0,
   .primary_opcode = 56,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_CMP_57[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "cmp",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {14,10,0,0}},
   .prefix = 0,
   .primary_opcode = 57,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_CMP_58[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "cmp",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {7,11,0,0}},
   .prefix = 0,
   .primary_opcode = 58,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_CMP_59[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "cmp",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,14,0,0}},
   .prefix = 0,
   .primary_opcode = 59,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_CMP_60[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "cmp",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {15,1,0,0}},
   .prefix = 0,
   .primary_opcode = 60,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_CMP_61[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "cmp",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {31,4,0,0}},
   .prefix = 0,
   .primary_opcode = 61,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_AAS_63[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "aas",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 63,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_INC_64[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "inc",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {98,0,0,0}},
   .prefix = 0,
   .primary_opcode = 64,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_INC_65[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "inc",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {98,0,0,0}},
   .prefix = 0,
   .primary_opcode = 65,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_INC_66[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "inc",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {98,0,0,0}},
   .prefix = 0,
   .primary_opcode = 66,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_INC_67[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "inc",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {98,0,0,0}},
   .prefix = 0,
   .primary_opcode = 67,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_INC_68[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "inc",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {98,0,0,0}},
   .prefix = 0,
   .primary_opcode = 68,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_INC_69[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "inc",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {98,0,0,0}},
   .prefix = 0,
   .primary_opcode = 69,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_INC_70[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "inc",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {98,0,0,0}},
   .prefix = 0,
   .primary_opcode = 70,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_INC_71[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "inc",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {98,0,0,0}},
   .prefix = 0,
   .primary_opcode = 71,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_DEC_72[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "dec",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {98,0,0,0}},
   .prefix = 0,
   .primary_opcode = 72,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_DEC_73[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "dec",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {98,0,0,0}},
   .prefix = 0,
   .primary_opcode = 73,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_PUSH_80[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "push",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {98,0,0,0}},
   .prefix = 0,
   .primary_opcode = 80,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_PUSH_81[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "push",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {98,0,0,0}},
   .prefix = 0,
   .primary_opcode = 81,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_PUSH_82[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "push",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {98,0,0,0}},
   .prefix = 0,
   .primary_opcode = 82,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_PUSH_83[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "push",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {98,0,0,0}},
   .prefix = 0,
   .primary_opcode = 83,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_PUSH_84[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "push",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {98,0,0,0}},
   .prefix = 0,
   .primary_opcode = 84,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_PUSH_85[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "push",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {98,0,0,0}},
   .prefix = 0,
   .primary_opcode = 85,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_PUSH_86[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "push",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {98,0,0,0}},
   .prefix = 0,
   .primary_opcode = 86,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_PUSH_87[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "push",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {98,0,0,0}},
   .prefix = 0,
   .primary_opcode = 87,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_POP_88[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "pop",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {98,0,0,0}},
   .prefix = 0,
   .primary_opcode = 88,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_POP_89[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "pop",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {98,0,0,0}},
   .prefix = 0,
   .primary_opcode = 89,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_POP_90[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "pop",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {98,0,0,0}},
   .prefix = 0,
   .primary_opcode = 90,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_POP_91[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "pop",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {98,0,0,0}},
   .prefix = 0,
   .primary_opcode = 91,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_POP_92[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "pop",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {98,0,0,0}},
   .prefix = 0,
   .primary_opcode = 92,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_POP_93[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "pop",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {98,0,0,0}},
   .prefix = 0,
   .primary_opcode = 93,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_POP_94[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "pop",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {98,0,0,0}},
   .prefix = 0,
   .primary_opcode = 94,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_POP_95[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "pop",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {98,0,0,0}},
   .prefix = 0,
   .primary_opcode = 95,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_PUSHAD_96[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "pushad",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 96,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_POPAD_97[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "popad",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 97,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_BOUND_98[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "bound",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,66,0,0}},
   .prefix = 0,
   .primary_opcode = 98,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_ARPL_99[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "arpl",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {12,8,0,0}},
   .prefix = 0,
   .primary_opcode = 99,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_PUSH_104[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "push",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {4,0,0,0}},
   .prefix = 0,
   .primary_opcode = 104,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_IMUL_105[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "imul",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {10,14,4,0}},
   .prefix = 0,
   .primary_opcode = 105,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_PUSH_106[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "push",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {1,0,0,0}},
   .prefix = 0,
   .primary_opcode = 106,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_IMUL_107[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "imul",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {10,14,1,0}},
   .prefix = 0,
   .primary_opcode = 107,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_INS_108[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "ins",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {0,25,0,0}},
   .prefix = 0,
   .primary_opcode = 108,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_INS_109[2] = {
  {
   .extended_opcode = false,
   .mnemonic = "ins",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {56,25,0,0}},
   .prefix = 0,
   .primary_opcode = 109,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "ins",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {61,25,0,0}},
   .prefix = 0,
   .primary_opcode = 109,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_OUTS_110[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "outs",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {25,0,0,0}},
   .prefix = 0,
   .primary_opcode = 110,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_OUTS_111[2] = {
  {
   .extended_opcode = false,
   .mnemonic = "outs",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {25,56,0,0}},
   .prefix = 0,
   .primary_opcode = 111,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "outs",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {25,61,0,0}},
   .prefix = 0,
   .primary_opcode = 111,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_JO_112[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "jo",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {72,0,0,0}},
   .prefix = 0,
   .primary_opcode = 112,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_JNO_113[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "jno",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {72,0,0,0}},
   .prefix = 0,
   .primary_opcode = 113,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_JB_114[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "jb",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {72,0,0,0}},
   .prefix = 0,
   .primary_opcode = 114,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_JNB_115[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "jnb",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {72,0,0,0}},
   .prefix = 0,
   .primary_opcode = 115,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_JZ_116[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "jz",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {72,0,0,0}},
   .prefix = 0,
   .primary_opcode = 116,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_JNZ_117[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "jnz",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {72,0,0,0}},
   .prefix = 0,
   .primary_opcode = 117,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_JBE_118[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "jbe",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {72,0,0,0}},
   .prefix = 0,
   .primary_opcode = 118,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_JNBE_119[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "jnbe",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {72,0,0,0}},
   .prefix = 0,
   .primary_opcode = 119,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_JS_120[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "js",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {72,0,0,0}},
   .prefix = 0,
   .primary_opcode = 120,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_JNS_121[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "jns",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {72,0,0,0}},
   .prefix = 0,
   .primary_opcode = 121,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_JP_122[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "jp",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {72,0,0,0}},
   .prefix = 0,
   .primary_opcode = 122,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_JNP_123[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "jnp",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {72,0,0,0}},
   .prefix = 0,
   .primary_opcode = 123,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_JL_124[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "jl",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {72,0,0,0}},
   .prefix = 0,
   .primary_opcode = 124,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_JNL_125[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "jnl",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {72,0,0,0}},
   .prefix = 0,
   .primary_opcode = 125,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_JLE_126[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "jle",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {72,0,0,0}},
   .prefix = 0,
   .primary_opcode = 126,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_JNLE_127[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "jnle",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {72,0,0,0}},
   .prefix = 0,
   .primary_opcode = 127,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_ADD_128[8] = {
  {
   .extended_opcode = false,
   .mnemonic = "add",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 2, .operand = {11,1,0,0}},
   .prefix = 0,
   .primary_opcode = 128,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "or",
   .opcode_field = {.type = 2, .value = 1 },
   .operands = {.size = 2, .operand = {11,1,0,0}},
   .prefix = 0,
   .primary_opcode = 128,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "adc",
   .opcode_field = {.type = 2, .value = 2 },
   .operands = {.size = 2, .operand = {11,1,0,0}},
   .prefix = 0,
   .primary_opcode = 128,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "sbb",
   .opcode_field = {.type = 2, .value = 3 },
   .operands = {.size = 2, .operand = {11,1,0,0}},
   .prefix = 0,
   .primary_opcode = 128,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "and",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 2, .operand = {11,1,0,0}},
   .prefix = 0,
   .primary_opcode = 128,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "sub",
   .opcode_field = {.type = 2, .value = 5 },
   .operands = {.size = 2, .operand = {11,1,0,0}},
   .prefix = 0,
   .primary_opcode = 128,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "xor",
   .opcode_field = {.type = 2, .value = 6 },
   .operands = {.size = 2, .operand = {11,1,0,0}},
   .prefix = 0,
   .primary_opcode = 128,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "cmp",
   .opcode_field = {.type = 2, .value = 7 },
   .operands = {.size = 2, .operand = {11,1,0,0}},
   .prefix = 0,
   .primary_opcode = 128,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_ADD_129[8] = {
  {
   .extended_opcode = false,
   .mnemonic = "add",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 2, .operand = {14,4,0,0}},
   .prefix = 0,
   .primary_opcode = 129,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "or",
   .opcode_field = {.type = 2, .value = 1 },
   .operands = {.size = 2, .operand = {14,4,0,0}},
   .prefix = 0,
   .primary_opcode = 129,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "adc",
   .opcode_field = {.type = 2, .value = 2 },
   .operands = {.size = 2, .operand = {14,4,0,0}},
   .prefix = 0,
   .primary_opcode = 129,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "sbb",
   .opcode_field = {.type = 2, .value = 3 },
   .operands = {.size = 2, .operand = {14,4,0,0}},
   .prefix = 0,
   .primary_opcode = 129,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "and",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 2, .operand = {14,4,0,0}},
   .prefix = 0,
   .primary_opcode = 129,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "sub",
   .opcode_field = {.type = 2, .value = 5 },
   .operands = {.size = 2, .operand = {14,4,0,0}},
   .prefix = 0,
   .primary_opcode = 129,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "xor",
   .opcode_field = {.type = 2, .value = 6 },
   .operands = {.size = 2, .operand = {14,4,0,0}},
   .prefix = 0,
   .primary_opcode = 129,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "cmp",
   .opcode_field = {.type = 2, .value = 7 },
   .operands = {.size = 2, .operand = {14,4,0,0}},
   .prefix = 0,
   .primary_opcode = 129,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_ADD_130[8] = {
  {
   .extended_opcode = false,
   .mnemonic = "add",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 2, .operand = {11,1,0,0}},
   .prefix = 0,
   .primary_opcode = 130,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "or",
   .opcode_field = {.type = 2, .value = 1 },
   .operands = {.size = 2, .operand = {11,1,0,0}},
   .prefix = 0,
   .primary_opcode = 130,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "adc",
   .opcode_field = {.type = 2, .value = 2 },
   .operands = {.size = 2, .operand = {11,1,0,0}},
   .prefix = 0,
   .primary_opcode = 130,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "sbb",
   .opcode_field = {.type = 2, .value = 3 },
   .operands = {.size = 2, .operand = {11,1,0,0}},
   .prefix = 0,
   .primary_opcode = 130,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "and",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 2, .operand = {11,1,0,0}},
   .prefix = 0,
   .primary_opcode = 130,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "sub",
   .opcode_field = {.type = 2, .value = 5 },
   .operands = {.size = 2, .operand = {11,1,0,0}},
   .prefix = 0,
   .primary_opcode = 130,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "xor",
   .opcode_field = {.type = 2, .value = 6 },
   .operands = {.size = 2, .operand = {11,1,0,0}},
   .prefix = 0,
   .primary_opcode = 130,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "cmp",
   .opcode_field = {.type = 2, .value = 7 },
   .operands = {.size = 2, .operand = {11,1,0,0}},
   .prefix = 0,
   .primary_opcode = 130,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_ADD_131[8] = {
  {
   .extended_opcode = false,
   .mnemonic = "add",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 2, .operand = {14,1,0,0}},
   .prefix = 0,
   .primary_opcode = 131,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "or",
   .opcode_field = {.type = 2, .value = 1 },
   .operands = {.size = 2, .operand = {14,1,0,0}},
   .prefix = 0,
   .primary_opcode = 131,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "adc",
   .opcode_field = {.type = 2, .value = 2 },
   .operands = {.size = 2, .operand = {14,1,0,0}},
   .prefix = 0,
   .primary_opcode = 131,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "sbb",
   .opcode_field = {.type = 2, .value = 3 },
   .operands = {.size = 2, .operand = {14,1,0,0}},
   .prefix = 0,
   .primary_opcode = 131,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "and",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 2, .operand = {14,1,0,0}},
   .prefix = 0,
   .primary_opcode = 131,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "sub",
   .opcode_field = {.type = 2, .value = 5 },
   .operands = {.size = 2, .operand = {14,1,0,0}},
   .prefix = 0,
   .primary_opcode = 131,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "xor",
   .opcode_field = {.type = 2, .value = 6 },
   .operands = {.size = 2, .operand = {14,1,0,0}},
   .prefix = 0,
   .primary_opcode = 131,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "cmp",
   .opcode_field = {.type = 2, .value = 7 },
   .operands = {.size = 2, .operand = {14,1,0,0}},
   .prefix = 0,
   .primary_opcode = 131,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_TEST_132[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "test",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {11,7,0,0}},
   .prefix = 0,
   .primary_opcode = 132,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_TEST_133[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "test",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {14,10,0,0}},
   .prefix = 0,
   .primary_opcode = 133,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_XCHG_134[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "xchg",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {7,11,0,0}},
   .prefix = 0,
   .primary_opcode = 134,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_XCHG_135[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "xchg",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,14,0,0}},
   .prefix = 0,
   .primary_opcode = 135,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_MOV_136[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "mov",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {11,7,0,0}},
   .prefix = 0,
   .primary_opcode = 136,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_MOV_137[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "mov",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {14,10,0,0}},
   .prefix = 0,
   .primary_opcode = 137,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_MOV_138[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "mov",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {7,11,0,0}},
   .prefix = 0,
   .primary_opcode = 138,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_MOV_139[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "mov",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,14,0,0}},
   .prefix = 0,
   .primary_opcode = 139,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_MOV_140[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "mov",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {56,47,0,0}},
   .prefix = 0,
   .primary_opcode = 140,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_LEA_141[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "lea",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,54,0,0}},
   .prefix = 0,
   .primary_opcode = 141,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_MOV_142[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "mov",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {47,12,0,0}},
   .prefix = 0,
   .primary_opcode = 142,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_POP_143[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "pop",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 1, .operand = {14,0,0,0}},
   .prefix = 0,
   .primary_opcode = 143,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_NOP_144[2] = {
  {
   .extended_opcode = false,
   .mnemonic = "nop",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 144,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "pause",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 243,
   .primary_opcode = 144,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_XCHG_145[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "xchg",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {98,31,0,0}},
   .prefix = 0,
   .primary_opcode = 145,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_XCHG_146[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "xchg",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {98,31,0,0}},
   .prefix = 0,
   .primary_opcode = 146,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_XCHG_147[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "xchg",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {98,31,0,0}},
   .prefix = 0,
   .primary_opcode = 147,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_XCHG_148[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "xchg",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {98,31,0,0}},
   .prefix = 0,
   .primary_opcode = 148,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_XCHG_149[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "xchg",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {98,31,0,0}},
   .prefix = 0,
   .primary_opcode = 149,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_XCHG_150[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "xchg",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {98,31,0,0}},
   .prefix = 0,
   .primary_opcode = 150,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_XCHG_151[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "xchg",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {98,31,0,0}},
   .prefix = 0,
   .primary_opcode = 151,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_CBW_152[2] = {
  {
   .extended_opcode = false,
   .mnemonic = "cbw",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {23,15,0,0}},
   .prefix = 0,
   .primary_opcode = 152,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "cwde",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 152,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_CDQ_153[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "cdq",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 153,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_CALLF_154[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "callf",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {78,0,0,0}},
   .prefix = 0,
   .primary_opcode = 154,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_FWAIT_155[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "fwait",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 155,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_PUSHFD_156[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "pushfd",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 156,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_POPFD_157[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "popfd",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 157,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_SAHF_158[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "sahf",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 158,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_LAHF_159[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "lahf",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 159,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_MOV_160[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "mov",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {15,69,0,0}},
   .prefix = 0,
   .primary_opcode = 160,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_MOV_161[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "mov",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {31,69,0,0}},
   .prefix = 0,
   .primary_opcode = 161,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_MOV_162[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "mov",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {69,15,0,0}},
   .prefix = 0,
   .primary_opcode = 162,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_MOV_163[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "mov",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {69,31,0,0}},
   .prefix = 0,
   .primary_opcode = 163,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_MOVS_164[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "movs",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 164,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_MOVS_165[2] = {
  {
   .extended_opcode = false,
   .mnemonic = "movs",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {56,56,0,0}},
   .prefix = 0,
   .primary_opcode = 165,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "movs",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {61,61,0,0}},
   .prefix = 0,
   .primary_opcode = 165,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_CMPS_166[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "cmps",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 166,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_CMPS_167[2] = {
  {
   .extended_opcode = false,
   .mnemonic = "cmps",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {56,56,0,0}},
   .prefix = 0,
   .primary_opcode = 167,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "cmps",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {61,61,0,0}},
   .prefix = 0,
   .primary_opcode = 167,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_TEST_168[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "test",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {15,1,0,0}},
   .prefix = 0,
   .primary_opcode = 168,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_TEST_169[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "test",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {31,4,0,0}},
   .prefix = 0,
   .primary_opcode = 169,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_STOS_170[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "stos",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 170,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_STOS_171[2] = {
  {
   .extended_opcode = false,
   .mnemonic = "stos",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {56,23,0,0}},
   .prefix = 0,
   .primary_opcode = 171,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "stos",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {61,31,0,0}},
   .prefix = 0,
   .primary_opcode = 171,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_LODS_172[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "lods",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {15,0,0,0}},
   .prefix = 0,
   .primary_opcode = 172,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_LODS_173[2] = {
  {
   .extended_opcode = false,
   .mnemonic = "lods",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {23,56,0,0}},
   .prefix = 0,
   .primary_opcode = 173,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "lods",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {31,61,0,0}},
   .prefix = 0,
   .primary_opcode = 173,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_SCAS_174[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "scas",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 174,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_SCAS_175[2] = {
  {
   .extended_opcode = false,
   .mnemonic = "scas",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {56,23,0,0}},
   .prefix = 0,
   .primary_opcode = 175,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "scas",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {61,31,0,0}},
   .prefix = 0,
   .primary_opcode = 175,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_MOV_176[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "mov",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {99,1,0,0}},
   .prefix = 0,
   .primary_opcode = 176,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_MOV_177[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "mov",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {99,1,0,0}},
   .prefix = 0,
   .primary_opcode = 177,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_MOV_178[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "mov",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {99,1,0,0}},
   .prefix = 0,
   .primary_opcode = 178,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_MOV_179[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "mov",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {99,1,0,0}},
   .prefix = 0,
   .primary_opcode = 179,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_MOV_180[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "mov",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {99,1,0,0}},
   .prefix = 0,
   .primary_opcode = 180,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_MOV_181[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "mov",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {99,1,0,0}},
   .prefix = 0,
   .primary_opcode = 181,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_MOV_182[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "mov",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {99,1,0,0}},
   .prefix = 0,
   .primary_opcode = 182,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_MOV_183[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "mov",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {99,1,0,0}},
   .prefix = 0,
   .primary_opcode = 183,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_MOV_184[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "mov",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {98,4,0,0}},
   .prefix = 0,
   .primary_opcode = 184,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_MOV_185[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "mov",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {98,4,0,0}},
   .prefix = 0,
   .primary_opcode = 185,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_MOV_186[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "mov",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {98,4,0,0}},
   .prefix = 0,
   .primary_opcode = 186,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_MOV_187[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "mov",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {98,4,0,0}},
   .prefix = 0,
   .primary_opcode = 187,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_MOV_188[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "mov",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {98,4,0,0}},
   .prefix = 0,
   .primary_opcode = 188,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_MOV_189[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "mov",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {98,4,0,0}},
   .prefix = 0,
   .primary_opcode = 189,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_MOV_190[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "mov",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {98,4,0,0}},
   .prefix = 0,
   .primary_opcode = 190,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_MOV_191[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "mov",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {98,4,0,0}},
   .prefix = 0,
   .primary_opcode = 191,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_ROL_192[8] = {
  {
   .extended_opcode = false,
   .mnemonic = "rol",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 2, .operand = {11,1,0,0}},
   .prefix = 0,
   .primary_opcode = 192,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "ror",
   .opcode_field = {.type = 2, .value = 1 },
   .operands = {.size = 2, .operand = {11,1,0,0}},
   .prefix = 0,
   .primary_opcode = 192,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "rcl",
   .opcode_field = {.type = 2, .value = 2 },
   .operands = {.size = 2, .operand = {11,1,0,0}},
   .prefix = 0,
   .primary_opcode = 192,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "rcr",
   .opcode_field = {.type = 2, .value = 3 },
   .operands = {.size = 2, .operand = {11,1,0,0}},
   .prefix = 0,
   .primary_opcode = 192,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "shl",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 2, .operand = {11,1,0,0}},
   .prefix = 0,
   .primary_opcode = 192,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "shr",
   .opcode_field = {.type = 2, .value = 5 },
   .operands = {.size = 2, .operand = {11,1,0,0}},
   .prefix = 0,
   .primary_opcode = 192,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "sal",
   .opcode_field = {.type = 2, .value = 6 },
   .operands = {.size = 2, .operand = {11,1,0,0}},
   .prefix = 0,
   .primary_opcode = 192,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "sar",
   .opcode_field = {.type = 2, .value = 7 },
   .operands = {.size = 2, .operand = {11,1,0,0}},
   .prefix = 0,
   .primary_opcode = 192,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_ROL_193[8] = {
  {
   .extended_opcode = false,
   .mnemonic = "rol",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 2, .operand = {14,1,0,0}},
   .prefix = 0,
   .primary_opcode = 193,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "ror",
   .opcode_field = {.type = 2, .value = 1 },
   .operands = {.size = 2, .operand = {14,1,0,0}},
   .prefix = 0,
   .primary_opcode = 193,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "rcl",
   .opcode_field = {.type = 2, .value = 2 },
   .operands = {.size = 2, .operand = {14,1,0,0}},
   .prefix = 0,
   .primary_opcode = 193,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "rcr",
   .opcode_field = {.type = 2, .value = 3 },
   .operands = {.size = 2, .operand = {14,1,0,0}},
   .prefix = 0,
   .primary_opcode = 193,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "shl",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 2, .operand = {14,1,0,0}},
   .prefix = 0,
   .primary_opcode = 193,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "shr",
   .opcode_field = {.type = 2, .value = 5 },
   .operands = {.size = 2, .operand = {14,1,0,0}},
   .prefix = 0,
   .primary_opcode = 193,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "sal",
   .opcode_field = {.type = 2, .value = 6 },
   .operands = {.size = 2, .operand = {14,1,0,0}},
   .prefix = 0,
   .primary_opcode = 193,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "sar",
   .opcode_field = {.type = 2, .value = 7 },
   .operands = {.size = 2, .operand = {14,1,0,0}},
   .prefix = 0,
   .primary_opcode = 193,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_RETN_194[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "retn",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {2,0,0,0}},
   .prefix = 0,
   .primary_opcode = 194,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_RETN_195[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "retn",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 195,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_LES_196[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "les",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,82,0,0}},
   .prefix = 0,
   .primary_opcode = 196,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_LDS_197[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "lds",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,82,0,0}},
   .prefix = 0,
   .primary_opcode = 197,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_MOV_198[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "mov",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 2, .operand = {11,1,0,0}},
   .prefix = 0,
   .primary_opcode = 198,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_MOV_199[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "mov",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 2, .operand = {14,4,0,0}},
   .prefix = 0,
   .primary_opcode = 199,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_ENTER_200[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "enter",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {2,1,0,0}},
   .prefix = 0,
   .primary_opcode = 200,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_LEAVE_201[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "leave",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 201,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_RETF_202[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "retf",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {2,0,0,0}},
   .prefix = 0,
   .primary_opcode = 202,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_RETF_203[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "retf",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 203,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_INT3_204[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "int3",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 204,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_INT_205[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "int",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {1,0,0,0}},
   .prefix = 0,
   .primary_opcode = 205,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_INTO_206[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "into",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 206,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_IRETD_207[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "iretd",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 207,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_ROL_208[8] = {
  {
   .extended_opcode = false,
   .mnemonic = "rol",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 2, .operand = {11,83,0,0}},
   .prefix = 0,
   .primary_opcode = 208,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "ror",
   .opcode_field = {.type = 2, .value = 1 },
   .operands = {.size = 2, .operand = {11,83,0,0}},
   .prefix = 0,
   .primary_opcode = 208,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "rcl",
   .opcode_field = {.type = 2, .value = 2 },
   .operands = {.size = 2, .operand = {11,83,0,0}},
   .prefix = 0,
   .primary_opcode = 208,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "rcr",
   .opcode_field = {.type = 2, .value = 3 },
   .operands = {.size = 2, .operand = {11,83,0,0}},
   .prefix = 0,
   .primary_opcode = 208,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "shl",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 2, .operand = {11,83,0,0}},
   .prefix = 0,
   .primary_opcode = 208,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "shr",
   .opcode_field = {.type = 2, .value = 5 },
   .operands = {.size = 2, .operand = {11,83,0,0}},
   .prefix = 0,
   .primary_opcode = 208,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "sal",
   .opcode_field = {.type = 2, .value = 6 },
   .operands = {.size = 2, .operand = {11,83,0,0}},
   .prefix = 0,
   .primary_opcode = 208,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "sar",
   .opcode_field = {.type = 2, .value = 7 },
   .operands = {.size = 2, .operand = {11,83,0,0}},
   .prefix = 0,
   .primary_opcode = 208,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_ROL_209[8] = {
  {
   .extended_opcode = false,
   .mnemonic = "rol",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 2, .operand = {14,83,0,0}},
   .prefix = 0,
   .primary_opcode = 209,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "ror",
   .opcode_field = {.type = 2, .value = 1 },
   .operands = {.size = 2, .operand = {14,83,0,0}},
   .prefix = 0,
   .primary_opcode = 209,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "rcl",
   .opcode_field = {.type = 2, .value = 2 },
   .operands = {.size = 2, .operand = {14,83,0,0}},
   .prefix = 0,
   .primary_opcode = 209,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "rcr",
   .opcode_field = {.type = 2, .value = 3 },
   .operands = {.size = 2, .operand = {14,83,0,0}},
   .prefix = 0,
   .primary_opcode = 209,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "shl",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 2, .operand = {14,83,0,0}},
   .prefix = 0,
   .primary_opcode = 209,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "shr",
   .opcode_field = {.type = 2, .value = 5 },
   .operands = {.size = 2, .operand = {14,83,0,0}},
   .prefix = 0,
   .primary_opcode = 209,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "sal",
   .opcode_field = {.type = 2, .value = 6 },
   .operands = {.size = 2, .operand = {14,83,0,0}},
   .prefix = 0,
   .primary_opcode = 209,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "sar",
   .opcode_field = {.type = 2, .value = 7 },
   .operands = {.size = 2, .operand = {14,83,0,0}},
   .prefix = 0,
   .primary_opcode = 209,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_ROL_210[8] = {
  {
   .extended_opcode = false,
   .mnemonic = "rol",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 2, .operand = {11,16,0,0}},
   .prefix = 0,
   .primary_opcode = 210,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "ror",
   .opcode_field = {.type = 2, .value = 1 },
   .operands = {.size = 2, .operand = {11,16,0,0}},
   .prefix = 0,
   .primary_opcode = 210,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "rcl",
   .opcode_field = {.type = 2, .value = 2 },
   .operands = {.size = 2, .operand = {11,16,0,0}},
   .prefix = 0,
   .primary_opcode = 210,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "rcr",
   .opcode_field = {.type = 2, .value = 3 },
   .operands = {.size = 2, .operand = {11,16,0,0}},
   .prefix = 0,
   .primary_opcode = 210,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "shl",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 2, .operand = {11,16,0,0}},
   .prefix = 0,
   .primary_opcode = 210,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "shr",
   .opcode_field = {.type = 2, .value = 5 },
   .operands = {.size = 2, .operand = {11,16,0,0}},
   .prefix = 0,
   .primary_opcode = 210,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "sal",
   .opcode_field = {.type = 2, .value = 6 },
   .operands = {.size = 2, .operand = {11,16,0,0}},
   .prefix = 0,
   .primary_opcode = 210,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "sar",
   .opcode_field = {.type = 2, .value = 7 },
   .operands = {.size = 2, .operand = {11,16,0,0}},
   .prefix = 0,
   .primary_opcode = 210,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_ROL_211[8] = {
  {
   .extended_opcode = false,
   .mnemonic = "rol",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 2, .operand = {14,16,0,0}},
   .prefix = 0,
   .primary_opcode = 211,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "ror",
   .opcode_field = {.type = 2, .value = 1 },
   .operands = {.size = 2, .operand = {14,16,0,0}},
   .prefix = 0,
   .primary_opcode = 211,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "rcl",
   .opcode_field = {.type = 2, .value = 2 },
   .operands = {.size = 2, .operand = {14,16,0,0}},
   .prefix = 0,
   .primary_opcode = 211,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "rcr",
   .opcode_field = {.type = 2, .value = 3 },
   .operands = {.size = 2, .operand = {14,16,0,0}},
   .prefix = 0,
   .primary_opcode = 211,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "shl",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 2, .operand = {14,16,0,0}},
   .prefix = 0,
   .primary_opcode = 211,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "shr",
   .opcode_field = {.type = 2, .value = 5 },
   .operands = {.size = 2, .operand = {14,16,0,0}},
   .prefix = 0,
   .primary_opcode = 211,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "sal",
   .opcode_field = {.type = 2, .value = 6 },
   .operands = {.size = 2, .operand = {14,16,0,0}},
   .prefix = 0,
   .primary_opcode = 211,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "sar",
   .opcode_field = {.type = 2, .value = 7 },
   .operands = {.size = 2, .operand = {14,16,0,0}},
   .prefix = 0,
   .primary_opcode = 211,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_AMX_212[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "amx",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {1,0,0,0}},
   .prefix = 0,
   .primary_opcode = 212,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_ADX_213[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "adx",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {1,0,0,0}},
   .prefix = 0,
   .primary_opcode = 213,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_SALC_214[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "salc",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 214,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_XLAT_215[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "xlat",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 215,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_FADD_216[8] = {
  {
   .extended_opcode = false,
   .mnemonic = "fadd",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 2, .operand = {84,57,0,0}},
   .prefix = 0,
   .primary_opcode = 216,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fmul",
   .opcode_field = {.type = 2, .value = 1 },
   .operands = {.size = 2, .operand = {84,57,0,0}},
   .prefix = 0,
   .primary_opcode = 216,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fcom",
   .opcode_field = {.type = 2, .value = 2 },
   .operands = {.size = 2, .operand = {84,57,0,0}},
   .prefix = 0,
   .primary_opcode = 216,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fcomp",
   .opcode_field = {.type = 2, .value = 3 },
   .operands = {.size = 2, .operand = {84,57,0,0}},
   .prefix = 0,
   .primary_opcode = 216,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fsub",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 2, .operand = {84,57,0,0}},
   .prefix = 0,
   .primary_opcode = 216,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fsubr",
   .opcode_field = {.type = 2, .value = 5 },
   .operands = {.size = 2, .operand = {84,57,0,0}},
   .prefix = 0,
   .primary_opcode = 216,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fdiv",
   .opcode_field = {.type = 2, .value = 6 },
   .operands = {.size = 2, .operand = {84,57,0,0}},
   .prefix = 0,
   .primary_opcode = 216,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fdivr",
   .opcode_field = {.type = 2, .value = 7 },
   .operands = {.size = 2, .operand = {84,57,0,0}},
   .prefix = 0,
   .primary_opcode = 216,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_FLD_217[39] = {
  {
   .extended_opcode = false,
   .mnemonic = "fld",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 2, .operand = {84,88,0,0}},
   .prefix = 0,
   .primary_opcode = 217,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fxch",
   .opcode_field = {.type = 2, .value = 1 },
   .operands = {.size = 2, .operand = {84,85,0,0}},
   .prefix = 0,
   .primary_opcode = 217,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fst",
   .opcode_field = {.type = 2, .value = 2 },
   .operands = {.size = 2, .operand = {57,84,0,0}},
   .prefix = 0,
   .primary_opcode = 217,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fnop",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 217,
   .secondary_opcode = 208,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fstp",
   .opcode_field = {.type = 2, .value = 3 },
   .operands = {.size = 2, .operand = {57,84,0,0}},
   .prefix = 0,
   .primary_opcode = 217,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fstp1",
   .opcode_field = {.type = 2, .value = 3 },
   .operands = {.size = 2, .operand = {85,84,0,0}},
   .prefix = 0,
   .primary_opcode = 217,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fldenv",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 1, .operand = {57,0,0,0}},
   .prefix = 0,
   .primary_opcode = 217,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fchs",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {84,0,0,0}},
   .prefix = 0,
   .primary_opcode = 217,
   .secondary_opcode = 224,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fabs",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {84,0,0,0}},
   .prefix = 0,
   .primary_opcode = 217,
   .secondary_opcode = 225,
  },
  {
   .extended_opcode = false,
   .mnemonic = "ftst",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {84,0,0,0}},
   .prefix = 0,
   .primary_opcode = 217,
   .secondary_opcode = 228,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fxam",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {84,0,0,0}},
   .prefix = 0,
   .primary_opcode = 217,
   .secondary_opcode = 229,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fldcw",
   .opcode_field = {.type = 2, .value = 5 },
   .operands = {.size = 1, .operand = {56,0,0,0}},
   .prefix = 0,
   .primary_opcode = 217,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fld1",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {84,0,0,0}},
   .prefix = 0,
   .primary_opcode = 217,
   .secondary_opcode = 232,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fldl2t",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {84,0,0,0}},
   .prefix = 0,
   .primary_opcode = 217,
   .secondary_opcode = 233,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fldl2e",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {84,0,0,0}},
   .prefix = 0,
   .primary_opcode = 217,
   .secondary_opcode = 234,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fldpi",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {84,0,0,0}},
   .prefix = 0,
   .primary_opcode = 217,
   .secondary_opcode = 235,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fldlg2",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {84,0,0,0}},
   .prefix = 0,
   .primary_opcode = 217,
   .secondary_opcode = 236,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fldln2",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {84,0,0,0}},
   .prefix = 0,
   .primary_opcode = 217,
   .secondary_opcode = 237,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fldz",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 217,
   .secondary_opcode = 238,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fnstenv",
   .opcode_field = {.type = 2, .value = 6 },
   .operands = {.size = 1, .operand = {57,0,0,0}},
   .prefix = 0,
   .primary_opcode = 217,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fstenv",
   .opcode_field = {.type = 2, .value = 6 },
   .operands = {.size = 1, .operand = {57,0,0,0}},
   .prefix = 155,
   .primary_opcode = 217,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "f2xm1",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {84,0,0,0}},
   .prefix = 0,
   .primary_opcode = 217,
   .secondary_opcode = 240,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fyl2x",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {86,84,0,0}},
   .prefix = 0,
   .primary_opcode = 217,
   .secondary_opcode = 241,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fptan",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {84,0,0,0}},
   .prefix = 0,
   .primary_opcode = 217,
   .secondary_opcode = 242,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fpatan",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {86,84,0,0}},
   .prefix = 0,
   .primary_opcode = 217,
   .secondary_opcode = 243,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fxtract",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {84,0,0,0}},
   .prefix = 0,
   .primary_opcode = 217,
   .secondary_opcode = 244,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fprem1",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {84,86,0,0}},
   .prefix = 0,
   .primary_opcode = 217,
   .secondary_opcode = 245,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fdecstp",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 217,
   .secondary_opcode = 246,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fincstp",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 217,
   .secondary_opcode = 247,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fnstcw",
   .opcode_field = {.type = 2, .value = 7 },
   .operands = {.size = 1, .operand = {56,0,0,0}},
   .prefix = 0,
   .primary_opcode = 217,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fstcw",
   .opcode_field = {.type = 2, .value = 7 },
   .operands = {.size = 1, .operand = {56,0,0,0}},
   .prefix = 155,
   .primary_opcode = 217,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fprem",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {84,86,0,0}},
   .prefix = 0,
   .primary_opcode = 217,
   .secondary_opcode = 248,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fyl2xp1",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {86,84,0,0}},
   .prefix = 0,
   .primary_opcode = 217,
   .secondary_opcode = 249,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fsqrt",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {84,0,0,0}},
   .prefix = 0,
   .primary_opcode = 217,
   .secondary_opcode = 250,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fsincos",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {84,0,0,0}},
   .prefix = 0,
   .primary_opcode = 217,
   .secondary_opcode = 251,
  },
  {
   .extended_opcode = false,
   .mnemonic = "frndint",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {84,0,0,0}},
   .prefix = 0,
   .primary_opcode = 217,
   .secondary_opcode = 252,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fscale",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {84,86,0,0}},
   .prefix = 0,
   .primary_opcode = 217,
   .secondary_opcode = 253,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fsin",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {84,0,0,0}},
   .prefix = 0,
   .primary_opcode = 217,
   .secondary_opcode = 254,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fcos",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {84,0,0,0}},
   .prefix = 0,
   .primary_opcode = 217,
   .secondary_opcode = 255,
  },
};

instruction_t REGULAR_FIADD_218[13] = {
  {
   .extended_opcode = false,
   .mnemonic = "fiadd",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 2, .operand = {84,57,0,0}},
   .prefix = 0,
   .primary_opcode = 218,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fcmovb",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 2, .operand = {84,85,0,0}},
   .prefix = 0,
   .primary_opcode = 218,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fimul",
   .opcode_field = {.type = 2, .value = 1 },
   .operands = {.size = 2, .operand = {84,57,0,0}},
   .prefix = 0,
   .primary_opcode = 218,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fcmove",
   .opcode_field = {.type = 2, .value = 1 },
   .operands = {.size = 2, .operand = {84,85,0,0}},
   .prefix = 0,
   .primary_opcode = 218,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "ficom",
   .opcode_field = {.type = 2, .value = 2 },
   .operands = {.size = 2, .operand = {84,57,0,0}},
   .prefix = 0,
   .primary_opcode = 218,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fcmovbe",
   .opcode_field = {.type = 2, .value = 2 },
   .operands = {.size = 2, .operand = {84,85,0,0}},
   .prefix = 0,
   .primary_opcode = 218,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "ficomp",
   .opcode_field = {.type = 2, .value = 3 },
   .operands = {.size = 2, .operand = {84,57,0,0}},
   .prefix = 0,
   .primary_opcode = 218,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fcmovu",
   .opcode_field = {.type = 2, .value = 3 },
   .operands = {.size = 2, .operand = {84,85,0,0}},
   .prefix = 0,
   .primary_opcode = 218,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fisub",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 2, .operand = {84,57,0,0}},
   .prefix = 0,
   .primary_opcode = 218,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fisubr",
   .opcode_field = {.type = 2, .value = 5 },
   .operands = {.size = 2, .operand = {84,57,0,0}},
   .prefix = 0,
   .primary_opcode = 218,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fucompp",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 218,
   .secondary_opcode = 233,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fidiv",
   .opcode_field = {.type = 2, .value = 6 },
   .operands = {.size = 2, .operand = {84,57,0,0}},
   .prefix = 0,
   .primary_opcode = 218,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fidivr",
   .opcode_field = {.type = 2, .value = 7 },
   .operands = {.size = 2, .operand = {84,57,0,0}},
   .prefix = 0,
   .primary_opcode = 218,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_FILD_219[19] = {
  {
   .extended_opcode = false,
   .mnemonic = "fild",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 2, .operand = {84,57,0,0}},
   .prefix = 0,
   .primary_opcode = 219,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fcmovnb",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 2, .operand = {84,85,0,0}},
   .prefix = 0,
   .primary_opcode = 219,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fisttp",
   .opcode_field = {.type = 2, .value = 1 },
   .operands = {.size = 2, .operand = {57,84,0,0}},
   .prefix = 0,
   .primary_opcode = 219,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fcmovne",
   .opcode_field = {.type = 2, .value = 1 },
   .operands = {.size = 2, .operand = {84,85,0,0}},
   .prefix = 0,
   .primary_opcode = 219,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fist",
   .opcode_field = {.type = 2, .value = 2 },
   .operands = {.size = 2, .operand = {57,84,0,0}},
   .prefix = 0,
   .primary_opcode = 219,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fcmovnbe",
   .opcode_field = {.type = 2, .value = 2 },
   .operands = {.size = 2, .operand = {84,85,0,0}},
   .prefix = 0,
   .primary_opcode = 219,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fistp",
   .opcode_field = {.type = 2, .value = 3 },
   .operands = {.size = 2, .operand = {57,84,0,0}},
   .prefix = 0,
   .primary_opcode = 219,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fcmovnu",
   .opcode_field = {.type = 2, .value = 3 },
   .operands = {.size = 2, .operand = {84,85,0,0}},
   .prefix = 0,
   .primary_opcode = 219,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fneni nop",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 219,
   .secondary_opcode = 224,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fndisi nop",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 219,
   .secondary_opcode = 225,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fnclex",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 219,
   .secondary_opcode = 226,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fclex",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 155,
   .primary_opcode = 219,
   .secondary_opcode = 226,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fninit",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 219,
   .secondary_opcode = 227,
  },
  {
   .extended_opcode = false,
   .mnemonic = "finit",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 155,
   .primary_opcode = 219,
   .secondary_opcode = 227,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fnsetpm nop",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 219,
   .secondary_opcode = 228,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fld",
   .opcode_field = {.type = 2, .value = 5 },
   .operands = {.size = 2, .operand = {84,57,0,0}},
   .prefix = 0,
   .primary_opcode = 219,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fucomi",
   .opcode_field = {.type = 2, .value = 5 },
   .operands = {.size = 2, .operand = {84,85,0,0}},
   .prefix = 0,
   .primary_opcode = 219,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fcomi",
   .opcode_field = {.type = 2, .value = 6 },
   .operands = {.size = 2, .operand = {84,85,0,0}},
   .prefix = 0,
   .primary_opcode = 219,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fstp",
   .opcode_field = {.type = 2, .value = 7 },
   .operands = {.size = 2, .operand = {57,84,0,0}},
   .prefix = 0,
   .primary_opcode = 219,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_FADD_220[16] = {
  {
   .extended_opcode = false,
   .mnemonic = "fadd",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 2, .operand = {84,57,0,0}},
   .prefix = 0,
   .primary_opcode = 220,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fadd",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 2, .operand = {85,84,0,0}},
   .prefix = 0,
   .primary_opcode = 220,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fmul",
   .opcode_field = {.type = 2, .value = 1 },
   .operands = {.size = 2, .operand = {84,57,0,0}},
   .prefix = 0,
   .primary_opcode = 220,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fmul",
   .opcode_field = {.type = 2, .value = 1 },
   .operands = {.size = 2, .operand = {85,84,0,0}},
   .prefix = 0,
   .primary_opcode = 220,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fcom",
   .opcode_field = {.type = 2, .value = 2 },
   .operands = {.size = 2, .operand = {84,57,0,0}},
   .prefix = 0,
   .primary_opcode = 220,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fcom2",
   .opcode_field = {.type = 2, .value = 2 },
   .operands = {.size = 2, .operand = {84,85,0,0}},
   .prefix = 0,
   .primary_opcode = 220,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fcomp",
   .opcode_field = {.type = 2, .value = 3 },
   .operands = {.size = 2, .operand = {84,57,0,0}},
   .prefix = 0,
   .primary_opcode = 220,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fcomp3",
   .opcode_field = {.type = 2, .value = 3 },
   .operands = {.size = 2, .operand = {84,85,0,0}},
   .prefix = 0,
   .primary_opcode = 220,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fsub",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 2, .operand = {84,57,0,0}},
   .prefix = 0,
   .primary_opcode = 220,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fsubr",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 2, .operand = {85,84,0,0}},
   .prefix = 0,
   .primary_opcode = 220,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fsubr",
   .opcode_field = {.type = 2, .value = 5 },
   .operands = {.size = 2, .operand = {84,57,0,0}},
   .prefix = 0,
   .primary_opcode = 220,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fsub",
   .opcode_field = {.type = 2, .value = 5 },
   .operands = {.size = 2, .operand = {85,84,0,0}},
   .prefix = 0,
   .primary_opcode = 220,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fdiv",
   .opcode_field = {.type = 2, .value = 6 },
   .operands = {.size = 2, .operand = {84,57,0,0}},
   .prefix = 0,
   .primary_opcode = 220,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fdivr",
   .opcode_field = {.type = 2, .value = 6 },
   .operands = {.size = 2, .operand = {85,84,0,0}},
   .prefix = 0,
   .primary_opcode = 220,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fdivr",
   .opcode_field = {.type = 2, .value = 7 },
   .operands = {.size = 2, .operand = {84,57,0,0}},
   .prefix = 0,
   .primary_opcode = 220,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fdiv",
   .opcode_field = {.type = 2, .value = 7 },
   .operands = {.size = 2, .operand = {85,84,0,0}},
   .prefix = 0,
   .primary_opcode = 220,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_FLD_221[15] = {
  {
   .extended_opcode = false,
   .mnemonic = "fld",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 2, .operand = {84,57,0,0}},
   .prefix = 0,
   .primary_opcode = 221,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "ffree",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 1, .operand = {85,0,0,0}},
   .prefix = 0,
   .primary_opcode = 221,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fisttp",
   .opcode_field = {.type = 2, .value = 1 },
   .operands = {.size = 2, .operand = {57,84,0,0}},
   .prefix = 0,
   .primary_opcode = 221,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fxch4",
   .opcode_field = {.type = 2, .value = 1 },
   .operands = {.size = 2, .operand = {84,85,0,0}},
   .prefix = 0,
   .primary_opcode = 221,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fst",
   .opcode_field = {.type = 2, .value = 2 },
   .operands = {.size = 2, .operand = {57,84,0,0}},
   .prefix = 0,
   .primary_opcode = 221,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fst",
   .opcode_field = {.type = 2, .value = 2 },
   .operands = {.size = 2, .operand = {84,85,0,0}},
   .prefix = 0,
   .primary_opcode = 221,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fstp",
   .opcode_field = {.type = 2, .value = 3 },
   .operands = {.size = 2, .operand = {57,84,0,0}},
   .prefix = 0,
   .primary_opcode = 221,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fstp",
   .opcode_field = {.type = 2, .value = 3 },
   .operands = {.size = 2, .operand = {84,85,0,0}},
   .prefix = 0,
   .primary_opcode = 221,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "frstor",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 3, .operand = {84,86,87,0}},
   .prefix = 0,
   .primary_opcode = 221,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fucom",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 2, .operand = {84,85,0,0}},
   .prefix = 0,
   .primary_opcode = 221,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fucomp",
   .opcode_field = {.type = 2, .value = 5 },
   .operands = {.size = 2, .operand = {84,85,0,0}},
   .prefix = 0,
   .primary_opcode = 221,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fnsave",
   .opcode_field = {.type = 2, .value = 6 },
   .operands = {.size = 3, .operand = {57,84,86,0}},
   .prefix = 0,
   .primary_opcode = 221,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fsave",
   .opcode_field = {.type = 2, .value = 6 },
   .operands = {.size = 3, .operand = {57,84,86,0}},
   .prefix = 155,
   .primary_opcode = 221,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fnstsw",
   .opcode_field = {.type = 2, .value = 7 },
   .operands = {.size = 1, .operand = {56,0,0,0}},
   .prefix = 0,
   .primary_opcode = 221,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fstsw",
   .opcode_field = {.type = 2, .value = 7 },
   .operands = {.size = 1, .operand = {56,0,0,0}},
   .prefix = 155,
   .primary_opcode = 221,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_FIADD_222[16] = {
  {
   .extended_opcode = false,
   .mnemonic = "fiadd",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 2, .operand = {84,57,0,0}},
   .prefix = 0,
   .primary_opcode = 222,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "faddp",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 2, .operand = {85,84,0,0}},
   .prefix = 0,
   .primary_opcode = 222,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fimul",
   .opcode_field = {.type = 2, .value = 1 },
   .operands = {.size = 2, .operand = {84,57,0,0}},
   .prefix = 0,
   .primary_opcode = 222,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fmulp",
   .opcode_field = {.type = 2, .value = 1 },
   .operands = {.size = 2, .operand = {85,84,0,0}},
   .prefix = 0,
   .primary_opcode = 222,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "ficom",
   .opcode_field = {.type = 2, .value = 2 },
   .operands = {.size = 2, .operand = {84,57,0,0}},
   .prefix = 0,
   .primary_opcode = 222,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fcomp5",
   .opcode_field = {.type = 2, .value = 2 },
   .operands = {.size = 2, .operand = {84,85,0,0}},
   .prefix = 0,
   .primary_opcode = 222,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "ficomp",
   .opcode_field = {.type = 2, .value = 3 },
   .operands = {.size = 2, .operand = {84,57,0,0}},
   .prefix = 0,
   .primary_opcode = 222,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fcompp",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {84,86,0,0}},
   .prefix = 0,
   .primary_opcode = 222,
   .secondary_opcode = 217,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fisub",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 2, .operand = {84,57,0,0}},
   .prefix = 0,
   .primary_opcode = 222,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fsubrp",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 2, .operand = {85,84,0,0}},
   .prefix = 0,
   .primary_opcode = 222,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fisubr",
   .opcode_field = {.type = 2, .value = 5 },
   .operands = {.size = 2, .operand = {84,57,0,0}},
   .prefix = 0,
   .primary_opcode = 222,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fsubp",
   .opcode_field = {.type = 2, .value = 5 },
   .operands = {.size = 2, .operand = {85,84,0,0}},
   .prefix = 0,
   .primary_opcode = 222,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fidiv",
   .opcode_field = {.type = 2, .value = 6 },
   .operands = {.size = 2, .operand = {84,57,0,0}},
   .prefix = 0,
   .primary_opcode = 222,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fdivrp",
   .opcode_field = {.type = 2, .value = 6 },
   .operands = {.size = 2, .operand = {85,84,0,0}},
   .prefix = 0,
   .primary_opcode = 222,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fidivr",
   .opcode_field = {.type = 2, .value = 7 },
   .operands = {.size = 2, .operand = {84,57,0,0}},
   .prefix = 0,
   .primary_opcode = 222,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fdivp",
   .opcode_field = {.type = 2, .value = 7 },
   .operands = {.size = 2, .operand = {85,84,0,0}},
   .prefix = 0,
   .primary_opcode = 222,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_FILD_223[16] = {
  {
   .extended_opcode = false,
   .mnemonic = "fild",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 2, .operand = {84,57,0,0}},
   .prefix = 0,
   .primary_opcode = 223,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "ffreep",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 1, .operand = {85,0,0,0}},
   .prefix = 0,
   .primary_opcode = 223,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fisttp",
   .opcode_field = {.type = 2, .value = 1 },
   .operands = {.size = 2, .operand = {57,84,0,0}},
   .prefix = 0,
   .primary_opcode = 223,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fxch7",
   .opcode_field = {.type = 2, .value = 1 },
   .operands = {.size = 2, .operand = {84,85,0,0}},
   .prefix = 0,
   .primary_opcode = 223,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fist",
   .opcode_field = {.type = 2, .value = 2 },
   .operands = {.size = 2, .operand = {57,84,0,0}},
   .prefix = 0,
   .primary_opcode = 223,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fstp8",
   .opcode_field = {.type = 2, .value = 2 },
   .operands = {.size = 2, .operand = {85,84,0,0}},
   .prefix = 0,
   .primary_opcode = 223,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fistp",
   .opcode_field = {.type = 2, .value = 3 },
   .operands = {.size = 2, .operand = {57,84,0,0}},
   .prefix = 0,
   .primary_opcode = 223,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fstp9",
   .opcode_field = {.type = 2, .value = 3 },
   .operands = {.size = 2, .operand = {85,84,0,0}},
   .prefix = 0,
   .primary_opcode = 223,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fbld",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 2, .operand = {84,57,0,0}},
   .prefix = 0,
   .primary_opcode = 223,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fnstsw",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {23,0,0,0}},
   .prefix = 0,
   .primary_opcode = 223,
   .secondary_opcode = 224,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fstsw",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 1, .operand = {23,0,0,0}},
   .prefix = 155,
   .primary_opcode = 223,
   .secondary_opcode = 224,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fild",
   .opcode_field = {.type = 2, .value = 5 },
   .operands = {.size = 2, .operand = {84,57,0,0}},
   .prefix = 0,
   .primary_opcode = 223,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fucomip",
   .opcode_field = {.type = 2, .value = 5 },
   .operands = {.size = 2, .operand = {84,85,0,0}},
   .prefix = 0,
   .primary_opcode = 223,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fbstp",
   .opcode_field = {.type = 2, .value = 6 },
   .operands = {.size = 2, .operand = {57,84,0,0}},
   .prefix = 0,
   .primary_opcode = 223,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fcomip",
   .opcode_field = {.type = 2, .value = 6 },
   .operands = {.size = 2, .operand = {84,85,0,0}},
   .prefix = 0,
   .primary_opcode = 223,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "fistp",
   .opcode_field = {.type = 2, .value = 7 },
   .operands = {.size = 2, .operand = {57,84,0,0}},
   .prefix = 0,
   .primary_opcode = 223,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_LOOPNZ_224[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "loopnz",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {32,72,0,0}},
   .prefix = 0,
   .primary_opcode = 224,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_LOOPZ_225[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "loopz",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {32,72,0,0}},
   .prefix = 0,
   .primary_opcode = 225,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_LOOP_226[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "loop",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {32,72,0,0}},
   .prefix = 0,
   .primary_opcode = 226,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_JCXZ_227[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "jcxz",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {72,24,0,0}},
   .prefix = 0,
   .primary_opcode = 227,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_IN_228[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "in",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {15,1,0,0}},
   .prefix = 0,
   .primary_opcode = 228,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_IN_229[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "in",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {31,1,0,0}},
   .prefix = 0,
   .primary_opcode = 229,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_OUT_230[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "out",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {1,15,0,0}},
   .prefix = 0,
   .primary_opcode = 230,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_OUT_231[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "out",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {1,31,0,0}},
   .prefix = 0,
   .primary_opcode = 231,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_CALL_232[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "call",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {75,0,0,0}},
   .prefix = 0,
   .primary_opcode = 232,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_JMP_233[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "jmp",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {75,0,0,0}},
   .prefix = 0,
   .primary_opcode = 233,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_JMPF_234[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "jmpf",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {78,0,0,0}},
   .prefix = 0,
   .primary_opcode = 234,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_JMP_235[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "jmp",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {72,0,0,0}},
   .prefix = 0,
   .primary_opcode = 235,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_IN_236[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "in",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {15,25,0,0}},
   .prefix = 0,
   .primary_opcode = 236,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_IN_237[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "in",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {31,25,0,0}},
   .prefix = 0,
   .primary_opcode = 237,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_OUT_238[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "out",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {25,15,0,0}},
   .prefix = 0,
   .primary_opcode = 238,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_OUT_239[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "out",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 2, .operand = {25,31,0,0}},
   .prefix = 0,
   .primary_opcode = 239,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_INT1_241[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "int1",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 241,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_HLT_244[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "hlt",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 244,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_CMC_245[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "cmc",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 245,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_TEST_246[8] = {
  {
   .extended_opcode = false,
   .mnemonic = "test",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 2, .operand = {11,1,0,0}},
   .prefix = 0,
   .primary_opcode = 246,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "test",
   .opcode_field = {.type = 2, .value = 1 },
   .operands = {.size = 2, .operand = {11,1,0,0}},
   .prefix = 0,
   .primary_opcode = 246,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "not",
   .opcode_field = {.type = 2, .value = 2 },
   .operands = {.size = 1, .operand = {11,0,0,0}},
   .prefix = 0,
   .primary_opcode = 246,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "neg",
   .opcode_field = {.type = 2, .value = 3 },
   .operands = {.size = 1, .operand = {11,0,0,0}},
   .prefix = 0,
   .primary_opcode = 246,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "mul",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 3, .operand = {23,15,11,0}},
   .prefix = 0,
   .primary_opcode = 246,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "imul",
   .opcode_field = {.type = 2, .value = 5 },
   .operands = {.size = 3, .operand = {23,15,11,0}},
   .prefix = 0,
   .primary_opcode = 246,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "div",
   .opcode_field = {.type = 2, .value = 6 },
   .operands = {.size = 4, .operand = {15,19,23,11}},
   .prefix = 0,
   .primary_opcode = 246,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "idiv",
   .opcode_field = {.type = 2, .value = 7 },
   .operands = {.size = 4, .operand = {15,19,23,11}},
   .prefix = 0,
   .primary_opcode = 246,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_TEST_247[8] = {
  {
   .extended_opcode = false,
   .mnemonic = "test",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 2, .operand = {14,4,0,0}},
   .prefix = 0,
   .primary_opcode = 247,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "test",
   .opcode_field = {.type = 2, .value = 1 },
   .operands = {.size = 2, .operand = {14,4,0,0}},
   .prefix = 0,
   .primary_opcode = 247,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "not",
   .opcode_field = {.type = 2, .value = 2 },
   .operands = {.size = 1, .operand = {14,0,0,0}},
   .prefix = 0,
   .primary_opcode = 247,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "neg",
   .opcode_field = {.type = 2, .value = 3 },
   .operands = {.size = 1, .operand = {14,0,0,0}},
   .prefix = 0,
   .primary_opcode = 247,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "mul",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 3, .operand = {33,31,14,0}},
   .prefix = 0,
   .primary_opcode = 247,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "imul",
   .opcode_field = {.type = 2, .value = 5 },
   .operands = {.size = 3, .operand = {33,31,14,0}},
   .prefix = 0,
   .primary_opcode = 247,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "div",
   .opcode_field = {.type = 2, .value = 6 },
   .operands = {.size = 3, .operand = {33,31,14,0}},
   .prefix = 0,
   .primary_opcode = 247,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "idiv",
   .opcode_field = {.type = 2, .value = 7 },
   .operands = {.size = 3, .operand = {33,31,14,0}},
   .prefix = 0,
   .primary_opcode = 247,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_CLC_248[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "clc",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 248,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_STC_249[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "stc",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 249,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_CLI_250[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "cli",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 250,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_STI_251[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "sti",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 251,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_CLD_252[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "cld",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 252,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_STD_253[1] = {
  {
   .extended_opcode = false,
   .mnemonic = "std",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 253,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_INC_254[2] = {
  {
   .extended_opcode = false,
   .mnemonic = "inc",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 1, .operand = {11,0,0,0}},
   .prefix = 0,
   .primary_opcode = 254,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "dec",
   .opcode_field = {.type = 2, .value = 1 },
   .operands = {.size = 1, .operand = {11,0,0,0}},
   .prefix = 0,
   .primary_opcode = 254,
   .secondary_opcode = -1,
  },
};

instruction_t REGULAR_INC_255[7] = {
  {
   .extended_opcode = false,
   .mnemonic = "inc",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 1, .operand = {14,0,0,0}},
   .prefix = 0,
   .primary_opcode = 255,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "dec",
   .opcode_field = {.type = 2, .value = 1 },
   .operands = {.size = 1, .operand = {14,0,0,0}},
   .prefix = 0,
   .primary_opcode = 255,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "call",
   .opcode_field = {.type = 2, .value = 2 },
   .operands = {.size = 1, .operand = {14,0,0,0}},
   .prefix = 0,
   .primary_opcode = 255,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "callf",
   .opcode_field = {.type = 2, .value = 3 },
   .operands = {.size = 1, .operand = {82,0,0,0}},
   .prefix = 0,
   .primary_opcode = 255,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "jmp",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 1, .operand = {14,0,0,0}},
   .prefix = 0,
   .primary_opcode = 255,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "jmpf",
   .opcode_field = {.type = 2, .value = 5 },
   .operands = {.size = 1, .operand = {82,0,0,0}},
   .prefix = 0,
   .primary_opcode = 255,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = false,
   .mnemonic = "push",
   .opcode_field = {.type = 2, .value = 6 },
   .operands = {.size = 1, .operand = {14,0,0,0}},
   .prefix = 0,
   .primary_opcode = 255,
   .secondary_opcode = -1,
  },
};

// regular end 
instruction_t EXTENDED_SLDT_0[6] = {
  {
   .extended_opcode = true,
   .mnemonic = "sldt",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 1, .operand = {14,0,0,0}},
   .prefix = 0,
   .primary_opcode = 0,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "str",
   .opcode_field = {.type = 2, .value = 1 },
   .operands = {.size = 1, .operand = {14,0,0,0}},
   .prefix = 0,
   .primary_opcode = 0,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "lldt",
   .opcode_field = {.type = 2, .value = 2 },
   .operands = {.size = 1, .operand = {12,0,0,0}},
   .prefix = 0,
   .primary_opcode = 0,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "ltr",
   .opcode_field = {.type = 2, .value = 3 },
   .operands = {.size = 1, .operand = {12,0,0,0}},
   .prefix = 0,
   .primary_opcode = 0,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "verr",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 1, .operand = {12,0,0,0}},
   .prefix = 0,
   .primary_opcode = 0,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "verw",
   .opcode_field = {.type = 2, .value = 5 },
   .operands = {.size = 1, .operand = {12,0,0,0}},
   .prefix = 0,
   .primary_opcode = 0,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_SGDT_1[16] = {
  {
   .extended_opcode = true,
   .mnemonic = "sgdt",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 1, .operand = {54,0,0,0}},
   .prefix = 0,
   .primary_opcode = 1,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "vmcall",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 1,
   .secondary_opcode = 193,
  },
  {
   .extended_opcode = true,
   .mnemonic = "vmlaunch",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 1,
   .secondary_opcode = 194,
  },
  {
   .extended_opcode = true,
   .mnemonic = "vmresume",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 1,
   .secondary_opcode = 195,
  },
  {
   .extended_opcode = true,
   .mnemonic = "vmxoff",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 1,
   .secondary_opcode = 196,
  },
  {
   .extended_opcode = true,
   .mnemonic = "sidt",
   .opcode_field = {.type = 2, .value = 1 },
   .operands = {.size = 1, .operand = {54,0,0,0}},
   .prefix = 0,
   .primary_opcode = 1,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "monitor",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 1,
   .secondary_opcode = 200,
  },
  {
   .extended_opcode = true,
   .mnemonic = "mwait",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 1,
   .secondary_opcode = 201,
  },
  {
   .extended_opcode = true,
   .mnemonic = "lgdt",
   .opcode_field = {.type = 2, .value = 2 },
   .operands = {.size = 1, .operand = {54,0,0,0}},
   .prefix = 0,
   .primary_opcode = 1,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "xgetbv",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 1,
   .secondary_opcode = 208,
  },
  {
   .extended_opcode = true,
   .mnemonic = "xsetbv",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 1,
   .secondary_opcode = 209,
  },
  {
   .extended_opcode = true,
   .mnemonic = "lidt",
   .opcode_field = {.type = 2, .value = 3 },
   .operands = {.size = 1, .operand = {54,0,0,0}},
   .prefix = 0,
   .primary_opcode = 1,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "smsw",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 1, .operand = {12,0,0,0}},
   .prefix = 0,
   .primary_opcode = 1,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "lmsw",
   .opcode_field = {.type = 2, .value = 6 },
   .operands = {.size = 1, .operand = {12,0,0,0}},
   .prefix = 0,
   .primary_opcode = 1,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "invlpg",
   .opcode_field = {.type = 2, .value = 7 },
   .operands = {.size = 1, .operand = {54,0,0,0}},
   .prefix = 0,
   .primary_opcode = 1,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "rdtscp",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 1,
   .secondary_opcode = 249,
  },
};

instruction_t EXTENDED_LAR_2[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "lar",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,14,0,0}},
   .prefix = 0,
   .primary_opcode = 2,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_LSL_3[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "lsl",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,14,0,0}},
   .prefix = 0,
   .primary_opcode = 3,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_SYSCALL_5[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "syscall",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 5,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_CLTS_6[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "clts",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 6,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_INVD_8[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "invd",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 8,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_WBINVD_9[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "wbinvd",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 9,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_UD2_11[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "ud2",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 11,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_NOP_13[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "nop",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {14,0,0,0}},
   .prefix = 0,
   .primary_opcode = 13,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_MOVUPS_16[4] = {
  {
   .extended_opcode = true,
   .mnemonic = "movups",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 0,
   .primary_opcode = 16,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "movss",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,91,0,0}},
   .prefix = 243,
   .primary_opcode = 16,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "movupd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 16,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "movsd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,92,0,0}},
   .prefix = 242,
   .primary_opcode = 16,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_MOVUPS_17[4] = {
  {
   .extended_opcode = true,
   .mnemonic = "movups",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {93,89,0,0}},
   .prefix = 0,
   .primary_opcode = 17,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "movss",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {91,89,0,0}},
   .prefix = 243,
   .primary_opcode = 17,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "movupd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {93,89,0,0}},
   .prefix = 102,
   .primary_opcode = 17,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "movsd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {92,89,0,0}},
   .prefix = 242,
   .primary_opcode = 17,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_MOVHLPS_18[5] = {
  {
   .extended_opcode = true,
   .mnemonic = "movhlps",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,89,0,0}},
   .prefix = 0,
   .primary_opcode = 18,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "movlps",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,58,0,0}},
   .prefix = 0,
   .primary_opcode = 18,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "movlpd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,58,0,0}},
   .prefix = 102,
   .primary_opcode = 18,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "movddup",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,92,0,0}},
   .prefix = 242,
   .primary_opcode = 18,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "movsldup",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,92,0,0}},
   .prefix = 243,
   .primary_opcode = 18,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_MOVLPS_19[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "movlps",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {58,89,0,0}},
   .prefix = 0,
   .primary_opcode = 19,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "movlpd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {58,89,0,0}},
   .prefix = 102,
   .primary_opcode = 19,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_UNPCKLPS_20[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "unpcklps",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,92,0,0}},
   .prefix = 0,
   .primary_opcode = 20,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "unpcklpd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 20,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_UNPCKHPS_21[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "unpckhps",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,92,0,0}},
   .prefix = 0,
   .primary_opcode = 21,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "unpckhpd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 21,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_MOVLHPS_22[4] = {
  {
   .extended_opcode = true,
   .mnemonic = "movlhps",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,89,0,0}},
   .prefix = 0,
   .primary_opcode = 22,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "movhps",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,58,0,0}},
   .prefix = 0,
   .primary_opcode = 22,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "movhpd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,58,0,0}},
   .prefix = 102,
   .primary_opcode = 22,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "movshdup",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,92,0,0}},
   .prefix = 243,
   .primary_opcode = 22,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_MOVHPS_23[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "movhps",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {58,89,0,0}},
   .prefix = 0,
   .primary_opcode = 23,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "movhpd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {58,89,0,0}},
   .prefix = 102,
   .primary_opcode = 23,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PREFETCHNTA_24[8] = {
  {
   .extended_opcode = true,
   .mnemonic = "prefetchnta",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 1, .operand = {55,0,0,0}},
   .prefix = 0,
   .primary_opcode = 24,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "prefetcht0",
   .opcode_field = {.type = 2, .value = 1 },
   .operands = {.size = 1, .operand = {55,0,0,0}},
   .prefix = 0,
   .primary_opcode = 24,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "prefetcht1",
   .opcode_field = {.type = 2, .value = 2 },
   .operands = {.size = 1, .operand = {55,0,0,0}},
   .prefix = 0,
   .primary_opcode = 24,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "prefetcht2",
   .opcode_field = {.type = 2, .value = 3 },
   .operands = {.size = 1, .operand = {55,0,0,0}},
   .prefix = 0,
   .primary_opcode = 24,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "hint_nop",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 1, .operand = {14,0,0,0}},
   .prefix = 0,
   .primary_opcode = 24,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "hint_nop",
   .opcode_field = {.type = 2, .value = 5 },
   .operands = {.size = 1, .operand = {14,0,0,0}},
   .prefix = 0,
   .primary_opcode = 24,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "hint_nop",
   .opcode_field = {.type = 2, .value = 6 },
   .operands = {.size = 1, .operand = {14,0,0,0}},
   .prefix = 0,
   .primary_opcode = 24,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "hint_nop",
   .opcode_field = {.type = 2, .value = 7 },
   .operands = {.size = 1, .operand = {14,0,0,0}},
   .prefix = 0,
   .primary_opcode = 24,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_ENDBR32_30[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "endbr32",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 243,
   .primary_opcode = 30,
   .secondary_opcode = 251,
  },
  {
   .extended_opcode = true,
   .mnemonic = "hint_nop",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {14,0,0,0}},
   .prefix = 0,
   .primary_opcode = 30,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_HINT_NOP_25[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "hint_nop",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {14,0,0,0}},
   .prefix = 0,
   .primary_opcode = 25,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_HINT_NOP_26[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "hint_nop",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {14,0,0,0}},
   .prefix = 0,
   .primary_opcode = 26,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_HINT_NOP_27[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "hint_nop",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {14,0,0,0}},
   .prefix = 0,
   .primary_opcode = 27,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_HINT_NOP_28[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "hint_nop",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {14,0,0,0}},
   .prefix = 0,
   .primary_opcode = 28,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_HINT_NOP_29[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "hint_nop",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {14,0,0,0}},
   .prefix = 0,
   .primary_opcode = 29,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_NOP_31[8] = {
  {
   .extended_opcode = true,
   .mnemonic = "nop",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 1, .operand = {14,0,0,0}},
   .prefix = 0,
   .primary_opcode = 31,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "hint_nop",
   .opcode_field = {.type = 2, .value = 1 },
   .operands = {.size = 1, .operand = {14,0,0,0}},
   .prefix = 0,
   .primary_opcode = 31,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "hint_nop",
   .opcode_field = {.type = 2, .value = 2 },
   .operands = {.size = 1, .operand = {14,0,0,0}},
   .prefix = 0,
   .primary_opcode = 31,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "hint_nop",
   .opcode_field = {.type = 2, .value = 3 },
   .operands = {.size = 1, .operand = {14,0,0,0}},
   .prefix = 0,
   .primary_opcode = 31,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "hint_nop",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 1, .operand = {14,0,0,0}},
   .prefix = 0,
   .primary_opcode = 31,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "hint_nop",
   .opcode_field = {.type = 2, .value = 5 },
   .operands = {.size = 1, .operand = {14,0,0,0}},
   .prefix = 0,
   .primary_opcode = 31,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "hint_nop",
   .opcode_field = {.type = 2, .value = 6 },
   .operands = {.size = 1, .operand = {14,0,0,0}},
   .prefix = 0,
   .primary_opcode = 31,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "hint_nop",
   .opcode_field = {.type = 2, .value = 7 },
   .operands = {.size = 1, .operand = {14,0,0,0}},
   .prefix = 0,
   .primary_opcode = 31,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_MOV_32[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "mov",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {9,94,0,0}},
   .prefix = 0,
   .primary_opcode = 32,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "mov",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {9,94,0,0}},
   .prefix = 0,
   .primary_opcode = 32,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_MOV_33[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "mov",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {9,95,0,0}},
   .prefix = 0,
   .primary_opcode = 33,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "mov",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {9,95,0,0}},
   .prefix = 0,
   .primary_opcode = 33,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_MOV_34[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "mov",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {94,9,0,0}},
   .prefix = 0,
   .primary_opcode = 34,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "mov",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {94,9,0,0}},
   .prefix = 0,
   .primary_opcode = 34,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_MOV_35[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "mov",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {95,9,0,0}},
   .prefix = 0,
   .primary_opcode = 35,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "mov",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {95,9,0,0}},
   .prefix = 0,
   .primary_opcode = 35,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_MOVAPS_40[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "movaps",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 0,
   .primary_opcode = 40,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "movapd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 40,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_MOVAPS_41[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "movaps",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {93,89,0,0}},
   .prefix = 0,
   .primary_opcode = 41,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "movapd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {93,89,0,0}},
   .prefix = 102,
   .primary_opcode = 41,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_CVTPI2PS_42[4] = {
  {
   .extended_opcode = true,
   .mnemonic = "cvtpi2ps",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,97,0,0}},
   .prefix = 0,
   .primary_opcode = 42,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "cvtsi2ss",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,13,0,0}},
   .prefix = 243,
   .primary_opcode = 42,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "cvtpi2pd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,97,0,0}},
   .prefix = 102,
   .primary_opcode = 42,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "cvtsi2sd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,13,0,0}},
   .prefix = 242,
   .primary_opcode = 42,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_MOVNTPS_43[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "movntps",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {59,89,0,0}},
   .prefix = 0,
   .primary_opcode = 43,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "movntpd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {59,89,0,0}},
   .prefix = 102,
   .primary_opcode = 43,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_CVTTPS2PI_44[4] = {
  {
   .extended_opcode = true,
   .mnemonic = "cvttps2pi",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,92,0,0}},
   .prefix = 0,
   .primary_opcode = 44,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "cvttss2si",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {9,91,0,0}},
   .prefix = 243,
   .primary_opcode = 44,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "cvttpd2pi",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,93,0,0}},
   .prefix = 102,
   .primary_opcode = 44,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "cvttsd2si",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {9,92,0,0}},
   .prefix = 242,
   .primary_opcode = 44,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_CVTPS2PI_45[4] = {
  {
   .extended_opcode = true,
   .mnemonic = "cvtps2pi",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,92,0,0}},
   .prefix = 0,
   .primary_opcode = 45,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "cvtss2si",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {9,91,0,0}},
   .prefix = 243,
   .primary_opcode = 45,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "cvtpd2pi",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,93,0,0}},
   .prefix = 102,
   .primary_opcode = 45,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "cvtsd2si",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {9,92,0,0}},
   .prefix = 242,
   .primary_opcode = 45,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_UCOMISS_46[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "ucomiss",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,91,0,0}},
   .prefix = 0,
   .primary_opcode = 46,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "ucomisd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,92,0,0}},
   .prefix = 102,
   .primary_opcode = 46,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_COMISS_47[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "comiss",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,91,0,0}},
   .prefix = 0,
   .primary_opcode = 47,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "comisd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,92,0,0}},
   .prefix = 102,
   .primary_opcode = 47,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_WRMSR_48[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "wrmsr",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 48,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_RDTSC_49[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "rdtsc",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 49,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_RDMSR_50[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "rdmsr",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 50,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_RDPMC_51[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "rdpmc",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 51,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_SYSENTER_52[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "sysenter",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 52,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_SYSEXIT_53[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "sysexit",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 53,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_GETSEC_55[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "getsec",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 55,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PSHUFB_56[67] = {
  {
   .extended_opcode = true,
   .mnemonic = "pshufb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 56,
   .secondary_opcode = 0,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pshufb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 0,
  },
  {
   .extended_opcode = true,
   .mnemonic = "phaddw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 56,
   .secondary_opcode = 1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "phaddw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "phaddd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 56,
   .secondary_opcode = 2,
  },
  {
   .extended_opcode = true,
   .mnemonic = "phaddd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 2,
  },
  {
   .extended_opcode = true,
   .mnemonic = "phaddsw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 56,
   .secondary_opcode = 3,
  },
  {
   .extended_opcode = true,
   .mnemonic = "phaddsw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 3,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pmaddubsw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 56,
   .secondary_opcode = 4,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pmaddubsw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 4,
  },
  {
   .extended_opcode = true,
   .mnemonic = "phsubw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 56,
   .secondary_opcode = 5,
  },
  {
   .extended_opcode = true,
   .mnemonic = "phsubw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 5,
  },
  {
   .extended_opcode = true,
   .mnemonic = "phsubd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 56,
   .secondary_opcode = 6,
  },
  {
   .extended_opcode = true,
   .mnemonic = "phsubd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 6,
  },
  {
   .extended_opcode = true,
   .mnemonic = "phsubsw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 56,
   .secondary_opcode = 7,
  },
  {
   .extended_opcode = true,
   .mnemonic = "phsubsw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 7,
  },
  {
   .extended_opcode = true,
   .mnemonic = "psignb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 56,
   .secondary_opcode = 8,
  },
  {
   .extended_opcode = true,
   .mnemonic = "psignb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 8,
  },
  {
   .extended_opcode = true,
   .mnemonic = "psignw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 56,
   .secondary_opcode = 9,
  },
  {
   .extended_opcode = true,
   .mnemonic = "psignw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 9,
  },
  {
   .extended_opcode = true,
   .mnemonic = "psignd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 56,
   .secondary_opcode = 10,
  },
  {
   .extended_opcode = true,
   .mnemonic = "psignd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 10,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pmulhrsw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 56,
   .secondary_opcode = 11,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pmulhrsw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 11,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pblendvb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {89,93,90,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 16,
  },
  {
   .extended_opcode = true,
   .mnemonic = "blendvps",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {89,93,90,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 20,
  },
  {
   .extended_opcode = true,
   .mnemonic = "blendvpd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {89,93,90,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 21,
  },
  {
   .extended_opcode = true,
   .mnemonic = "ptest",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 23,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pabsb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 56,
   .secondary_opcode = 28,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pabsb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 28,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pabsw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 56,
   .secondary_opcode = 29,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pabsw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 29,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pabsd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 56,
   .secondary_opcode = 30,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pabsd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 30,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pmovsxbw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,58,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 32,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pmovsxbd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,57,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 33,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pmovsxbq",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,56,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 34,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pmovsxwd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,58,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 35,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pmovsxwq",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,57,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 36,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pmovsxdq",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,58,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 37,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pmuldq",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 40,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pcmpeqq",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 41,
  },
  {
   .extended_opcode = true,
   .mnemonic = "movntdqa",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,59,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 42,
  },
  {
   .extended_opcode = true,
   .mnemonic = "packusdw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 43,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pmovzxbw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,58,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 48,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pmovzxbd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,57,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 49,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pmovzxbq",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,56,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 50,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pmovzxwd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,58,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 51,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pmovzxwq",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,57,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 52,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pmovzxdq",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,58,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 53,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pcmpgtq",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 55,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pminsb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 56,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pminsd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 57,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pminuw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 58,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pminud",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 59,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pmaxsb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 60,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pmaxsd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 61,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pmaxuw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 62,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pmaxud",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 63,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pmulld",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 64,
  },
  {
   .extended_opcode = true,
   .mnemonic = "phminposuw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 65,
  },
  {
   .extended_opcode = true,
   .mnemonic = "invept",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {9,59,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 128,
  },
  {
   .extended_opcode = true,
   .mnemonic = "invvpid",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {9,59,0,0}},
   .prefix = 102,
   .primary_opcode = 56,
   .secondary_opcode = 129,
  },
  {
   .extended_opcode = true,
   .mnemonic = "movbe",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,61,0,0}},
   .prefix = 0,
   .primary_opcode = 56,
   .secondary_opcode = 240,
  },
  {
   .extended_opcode = true,
   .mnemonic = "crc32",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {9,11,0,0}},
   .prefix = 242,
   .primary_opcode = 56,
   .secondary_opcode = 240,
  },
  {
   .extended_opcode = true,
   .mnemonic = "movbe",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {61,10,0,0}},
   .prefix = 0,
   .primary_opcode = 56,
   .secondary_opcode = 241,
  },
  {
   .extended_opcode = true,
   .mnemonic = "crc32",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {9,14,0,0}},
   .prefix = 242,
   .primary_opcode = 56,
   .secondary_opcode = 241,
  },
};

instruction_t EXTENDED_ROUNDPS_58[23] = {
  {
   .extended_opcode = true,
   .mnemonic = "roundps",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {89,93,1,0}},
   .prefix = 102,
   .primary_opcode = 58,
   .secondary_opcode = 8,
  },
  {
   .extended_opcode = true,
   .mnemonic = "roundpd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {89,93,1,0}},
   .prefix = 102,
   .primary_opcode = 58,
   .secondary_opcode = 9,
  },
  {
   .extended_opcode = true,
   .mnemonic = "roundss",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {89,91,1,0}},
   .prefix = 102,
   .primary_opcode = 58,
   .secondary_opcode = 10,
  },
  {
   .extended_opcode = true,
   .mnemonic = "roundsd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {89,92,1,0}},
   .prefix = 102,
   .primary_opcode = 58,
   .secondary_opcode = 11,
  },
  {
   .extended_opcode = true,
   .mnemonic = "blendps",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {89,93,1,0}},
   .prefix = 102,
   .primary_opcode = 58,
   .secondary_opcode = 12,
  },
  {
   .extended_opcode = true,
   .mnemonic = "blendpd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {89,93,1,0}},
   .prefix = 102,
   .primary_opcode = 58,
   .secondary_opcode = 13,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pblendw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {89,93,1,0}},
   .prefix = 102,
   .primary_opcode = 58,
   .secondary_opcode = 14,
  },
  {
   .extended_opcode = true,
   .mnemonic = "palignr",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 58,
   .secondary_opcode = 15,
  },
  {
   .extended_opcode = true,
   .mnemonic = "palignr",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 58,
   .secondary_opcode = 15,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pextrb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {55,89,1,0}},
   .prefix = 102,
   .primary_opcode = 58,
   .secondary_opcode = 20,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pextrw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {56,89,1,0}},
   .prefix = 102,
   .primary_opcode = 58,
   .secondary_opcode = 21,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pextrd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {13,89,1,0}},
   .prefix = 102,
   .primary_opcode = 58,
   .secondary_opcode = 22,
  },
  {
   .extended_opcode = true,
   .mnemonic = "extractps",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {13,89,1,0}},
   .prefix = 102,
   .primary_opcode = 58,
   .secondary_opcode = 23,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pinsrb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {89,55,1,0}},
   .prefix = 102,
   .primary_opcode = 58,
   .secondary_opcode = 32,
  },
  {
   .extended_opcode = true,
   .mnemonic = "insertps",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {89,57,1,0}},
   .prefix = 102,
   .primary_opcode = 58,
   .secondary_opcode = 33,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pinsrd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {89,13,1,0}},
   .prefix = 102,
   .primary_opcode = 58,
   .secondary_opcode = 34,
  },
  {
   .extended_opcode = true,
   .mnemonic = "dpps",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 58,
   .secondary_opcode = 64,
  },
  {
   .extended_opcode = true,
   .mnemonic = "dppd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 58,
   .secondary_opcode = 65,
  },
  {
   .extended_opcode = true,
   .mnemonic = "mpsadbw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {89,93,1,0}},
   .prefix = 102,
   .primary_opcode = 58,
   .secondary_opcode = 66,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pcmpestrm",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {89,93,1,0}},
   .prefix = 102,
   .primary_opcode = 58,
   .secondary_opcode = 96,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pcmpestri",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {89,93,1,0}},
   .prefix = 102,
   .primary_opcode = 58,
   .secondary_opcode = 97,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pcmpistrm",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {89,93,1,0}},
   .prefix = 102,
   .primary_opcode = 58,
   .secondary_opcode = 98,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pcmpistri",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {89,93,1,0}},
   .prefix = 102,
   .primary_opcode = 58,
   .secondary_opcode = 99,
  },
};

instruction_t EXTENDED_CMOVO_64[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "cmovo",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,14,0,0}},
   .prefix = 0,
   .primary_opcode = 64,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_CMOVNO_65[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "cmovno",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,14,0,0}},
   .prefix = 0,
   .primary_opcode = 65,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_CMOVB_66[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "cmovb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,14,0,0}},
   .prefix = 0,
   .primary_opcode = 66,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_CMOVNB_67[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "cmovnb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,14,0,0}},
   .prefix = 0,
   .primary_opcode = 67,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_CMOVZ_68[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "cmovz",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,14,0,0}},
   .prefix = 0,
   .primary_opcode = 68,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_CMOVNZ_69[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "cmovnz",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,14,0,0}},
   .prefix = 0,
   .primary_opcode = 69,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_CMOVBE_70[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "cmovbe",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,14,0,0}},
   .prefix = 0,
   .primary_opcode = 70,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_CMOVNBE_71[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "cmovnbe",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,14,0,0}},
   .prefix = 0,
   .primary_opcode = 71,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_CMOVS_72[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "cmovs",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,14,0,0}},
   .prefix = 0,
   .primary_opcode = 72,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_CMOVNS_73[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "cmovns",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,14,0,0}},
   .prefix = 0,
   .primary_opcode = 73,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_CMOVP_74[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "cmovp",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,14,0,0}},
   .prefix = 0,
   .primary_opcode = 74,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_CMOVNP_75[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "cmovnp",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,14,0,0}},
   .prefix = 0,
   .primary_opcode = 75,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_CMOVL_76[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "cmovl",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,14,0,0}},
   .prefix = 0,
   .primary_opcode = 76,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_CMOVNL_77[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "cmovnl",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,14,0,0}},
   .prefix = 0,
   .primary_opcode = 77,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_CMOVLE_78[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "cmovle",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,14,0,0}},
   .prefix = 0,
   .primary_opcode = 78,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_CMOVNLE_79[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "cmovnle",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,14,0,0}},
   .prefix = 0,
   .primary_opcode = 79,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_MOVMSKPS_80[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "movmskps",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {9,89,0,0}},
   .prefix = 0,
   .primary_opcode = 80,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "movmskpd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {9,89,0,0}},
   .prefix = 102,
   .primary_opcode = 80,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_SQRTPS_81[4] = {
  {
   .extended_opcode = true,
   .mnemonic = "sqrtps",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 0,
   .primary_opcode = 81,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "sqrtss",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,91,0,0}},
   .prefix = 243,
   .primary_opcode = 81,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "sqrtpd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 81,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "sqrtsd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,92,0,0}},
   .prefix = 242,
   .primary_opcode = 81,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_RSQRTPS_82[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "rsqrtps",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 0,
   .primary_opcode = 82,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "rsqrtss",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,91,0,0}},
   .prefix = 243,
   .primary_opcode = 82,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_RCPPS_83[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "rcpps",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 0,
   .primary_opcode = 83,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "rcpss",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,91,0,0}},
   .prefix = 243,
   .primary_opcode = 83,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_ANDPS_84[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "andps",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 0,
   .primary_opcode = 84,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "andpd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 84,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_ANDNPS_85[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "andnps",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 0,
   .primary_opcode = 85,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "andnpd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 85,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_ORPS_86[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "orps",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 0,
   .primary_opcode = 86,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "orpd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 86,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_XORPS_87[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "xorps",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 0,
   .primary_opcode = 87,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "xorpd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 87,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_ADDPS_88[4] = {
  {
   .extended_opcode = true,
   .mnemonic = "addps",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 0,
   .primary_opcode = 88,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "addss",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,91,0,0}},
   .prefix = 243,
   .primary_opcode = 88,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "addpd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 88,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "addsd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,92,0,0}},
   .prefix = 242,
   .primary_opcode = 88,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_MULPS_89[4] = {
  {
   .extended_opcode = true,
   .mnemonic = "mulps",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 0,
   .primary_opcode = 89,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "mulss",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,91,0,0}},
   .prefix = 243,
   .primary_opcode = 89,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "mulpd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 89,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "mulsd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,92,0,0}},
   .prefix = 242,
   .primary_opcode = 89,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_CVTPS2PD_90[4] = {
  {
   .extended_opcode = true,
   .mnemonic = "cvtps2pd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 0,
   .primary_opcode = 90,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "cvtpd2ps",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 90,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "cvtss2sd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,91,0,0}},
   .prefix = 243,
   .primary_opcode = 90,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "cvtsd2ss",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,92,0,0}},
   .prefix = 242,
   .primary_opcode = 90,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_CVTDQ2PS_91[3] = {
  {
   .extended_opcode = true,
   .mnemonic = "cvtdq2ps",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 0,
   .primary_opcode = 91,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "cvtps2dq",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 91,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "cvttps2dq",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 243,
   .primary_opcode = 91,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_SUBPS_92[4] = {
  {
   .extended_opcode = true,
   .mnemonic = "subps",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 0,
   .primary_opcode = 92,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "subss",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,91,0,0}},
   .prefix = 243,
   .primary_opcode = 92,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "subpd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 92,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "subsd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,92,0,0}},
   .prefix = 242,
   .primary_opcode = 92,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_MINPS_93[4] = {
  {
   .extended_opcode = true,
   .mnemonic = "minps",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 0,
   .primary_opcode = 93,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "minss",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,91,0,0}},
   .prefix = 243,
   .primary_opcode = 93,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "minpd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 93,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "minsd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,92,0,0}},
   .prefix = 242,
   .primary_opcode = 93,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_DIVPS_94[4] = {
  {
   .extended_opcode = true,
   .mnemonic = "divps",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 0,
   .primary_opcode = 94,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "divss",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,91,0,0}},
   .prefix = 243,
   .primary_opcode = 94,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "divpd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 94,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "divsd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,92,0,0}},
   .prefix = 242,
   .primary_opcode = 94,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_MAXPS_95[4] = {
  {
   .extended_opcode = true,
   .mnemonic = "maxps",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 0,
   .primary_opcode = 95,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "maxss",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,91,0,0}},
   .prefix = 243,
   .primary_opcode = 95,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "maxpd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 95,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "maxsd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,92,0,0}},
   .prefix = 242,
   .primary_opcode = 95,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PUNPCKLBW_96[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "punpcklbw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 96,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "punpcklbw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 96,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PUNPCKLWD_97[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "punpcklwd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 97,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "punpcklwd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 97,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PUNPCKLDQ_98[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "punpckldq",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 98,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "punpckldq",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 98,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PACKSSWB_99[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "packsswb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 99,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "packsswb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 99,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PCMPGTB_100[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "pcmpgtb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 100,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pcmpgtb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 100,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PCMPGTW_101[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "pcmpgtw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 101,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pcmpgtw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 101,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PCMPGTD_102[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "pcmpgtd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 102,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pcmpgtd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 102,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PACKUSWB_103[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "packuswb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 103,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "packuswb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 103,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PUNPCKHBW_104[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "punpckhbw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 104,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "punpckhbw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 104,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PUNPCKHWD_105[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "punpckhwd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 105,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "punpckhwd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 105,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PUNPCKHDQ_106[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "punpckhdq",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 106,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "punpckhdq",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 106,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PACKSSDW_107[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "packssdw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 107,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "packssdw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 107,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PUNPCKLQDQ_108[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "punpcklqdq",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 108,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PUNPCKHQDQ_109[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "punpckhqdq",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 109,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_MOVD_110[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "movd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,13,0,0}},
   .prefix = 0,
   .primary_opcode = 110,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "movd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,13,0,0}},
   .prefix = 102,
   .primary_opcode = 110,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_MOVQ_111[3] = {
  {
   .extended_opcode = true,
   .mnemonic = "movq",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 111,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "movdqa",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 111,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "movdqu",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 243,
   .primary_opcode = 111,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PSHUFW_112[4] = {
  {
   .extended_opcode = true,
   .mnemonic = "pshufw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {96,97,1,0}},
   .prefix = 0,
   .primary_opcode = 112,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pshuflw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {89,93,1,0}},
   .prefix = 242,
   .primary_opcode = 112,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pshufhw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {89,93,1,0}},
   .prefix = 243,
   .primary_opcode = 112,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pshufd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {89,93,1,0}},
   .prefix = 102,
   .primary_opcode = 112,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PSRLW_113[6] = {
  {
   .extended_opcode = true,
   .mnemonic = "psrlw",
   .opcode_field = {.type = 2, .value = 2 },
   .operands = {.size = 2, .operand = {96,1,0,0}},
   .prefix = 0,
   .primary_opcode = 113,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "psrlw",
   .opcode_field = {.type = 2, .value = 2 },
   .operands = {.size = 2, .operand = {89,1,0,0}},
   .prefix = 102,
   .primary_opcode = 113,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "psraw",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 2, .operand = {96,1,0,0}},
   .prefix = 0,
   .primary_opcode = 113,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "psraw",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 2, .operand = {89,1,0,0}},
   .prefix = 102,
   .primary_opcode = 113,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "psllw",
   .opcode_field = {.type = 2, .value = 6 },
   .operands = {.size = 2, .operand = {96,1,0,0}},
   .prefix = 0,
   .primary_opcode = 113,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "psllw",
   .opcode_field = {.type = 2, .value = 6 },
   .operands = {.size = 2, .operand = {89,1,0,0}},
   .prefix = 102,
   .primary_opcode = 113,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PSRLD_114[6] = {
  {
   .extended_opcode = true,
   .mnemonic = "psrld",
   .opcode_field = {.type = 2, .value = 2 },
   .operands = {.size = 2, .operand = {96,1,0,0}},
   .prefix = 0,
   .primary_opcode = 114,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "psrld",
   .opcode_field = {.type = 2, .value = 2 },
   .operands = {.size = 2, .operand = {89,1,0,0}},
   .prefix = 102,
   .primary_opcode = 114,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "psrad",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 2, .operand = {96,1,0,0}},
   .prefix = 0,
   .primary_opcode = 114,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "psrad",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 2, .operand = {89,1,0,0}},
   .prefix = 102,
   .primary_opcode = 114,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pslld",
   .opcode_field = {.type = 2, .value = 6 },
   .operands = {.size = 2, .operand = {96,1,0,0}},
   .prefix = 0,
   .primary_opcode = 114,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pslld",
   .opcode_field = {.type = 2, .value = 6 },
   .operands = {.size = 2, .operand = {89,1,0,0}},
   .prefix = 102,
   .primary_opcode = 114,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PSRLQ_115[6] = {
  {
   .extended_opcode = true,
   .mnemonic = "psrlq",
   .opcode_field = {.type = 2, .value = 2 },
   .operands = {.size = 2, .operand = {96,1,0,0}},
   .prefix = 0,
   .primary_opcode = 115,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "psrlq",
   .opcode_field = {.type = 2, .value = 2 },
   .operands = {.size = 2, .operand = {89,1,0,0}},
   .prefix = 102,
   .primary_opcode = 115,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "psrldq",
   .opcode_field = {.type = 2, .value = 3 },
   .operands = {.size = 2, .operand = {89,1,0,0}},
   .prefix = 102,
   .primary_opcode = 115,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "psllq",
   .opcode_field = {.type = 2, .value = 6 },
   .operands = {.size = 2, .operand = {96,1,0,0}},
   .prefix = 0,
   .primary_opcode = 115,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "psllq",
   .opcode_field = {.type = 2, .value = 6 },
   .operands = {.size = 2, .operand = {89,1,0,0}},
   .prefix = 102,
   .primary_opcode = 115,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pslldq",
   .opcode_field = {.type = 2, .value = 7 },
   .operands = {.size = 2, .operand = {89,1,0,0}},
   .prefix = 102,
   .primary_opcode = 115,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PCMPEQB_116[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "pcmpeqb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 116,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pcmpeqb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 116,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PCMPEQW_117[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "pcmpeqw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 117,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pcmpeqw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 117,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PCMPEQD_118[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "pcmpeqd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 118,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pcmpeqd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 118,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_EMMS_119[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "emms",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 119,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_VMREAD_120[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "vmread",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {13,9,0,0}},
   .prefix = 0,
   .primary_opcode = 120,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_VMWRITE_121[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "vmwrite",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {9,13,0,0}},
   .prefix = 0,
   .primary_opcode = 121,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_HADDPD_124[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "haddpd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 124,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "haddps",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 242,
   .primary_opcode = 124,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_HSUBPD_125[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "hsubpd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 125,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "hsubps",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 242,
   .primary_opcode = 125,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_MOVD_126[3] = {
  {
   .extended_opcode = true,
   .mnemonic = "movd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {13,96,0,0}},
   .prefix = 0,
   .primary_opcode = 126,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "movd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {13,89,0,0}},
   .prefix = 102,
   .primary_opcode = 126,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "movq",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,92,0,0}},
   .prefix = 243,
   .primary_opcode = 126,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_MOVQ_127[3] = {
  {
   .extended_opcode = true,
   .mnemonic = "movq",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {97,96,0,0}},
   .prefix = 0,
   .primary_opcode = 127,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "movdqa",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {93,89,0,0}},
   .prefix = 102,
   .primary_opcode = 127,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "movdqu",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {93,89,0,0}},
   .prefix = 243,
   .primary_opcode = 127,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_JO_128[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "jo",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {75,0,0,0}},
   .prefix = 0,
   .primary_opcode = 128,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_JNO_129[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "jno",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {75,0,0,0}},
   .prefix = 0,
   .primary_opcode = 129,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_JB_130[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "jb",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {75,0,0,0}},
   .prefix = 0,
   .primary_opcode = 130,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_JNB_131[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "jnb",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {75,0,0,0}},
   .prefix = 0,
   .primary_opcode = 131,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_JZ_132[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "jz",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {75,0,0,0}},
   .prefix = 0,
   .primary_opcode = 132,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_JNZ_133[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "jnz",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {75,0,0,0}},
   .prefix = 0,
   .primary_opcode = 133,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_JBE_134[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "jbe",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {75,0,0,0}},
   .prefix = 0,
   .primary_opcode = 134,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_JNBE_135[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "jnbe",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {75,0,0,0}},
   .prefix = 0,
   .primary_opcode = 135,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_JS_136[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "js",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {75,0,0,0}},
   .prefix = 0,
   .primary_opcode = 136,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_JNS_137[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "jns",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {75,0,0,0}},
   .prefix = 0,
   .primary_opcode = 137,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_JP_138[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "jp",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {75,0,0,0}},
   .prefix = 0,
   .primary_opcode = 138,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_JNP_139[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "jnp",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {75,0,0,0}},
   .prefix = 0,
   .primary_opcode = 139,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_JL_140[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "jl",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {75,0,0,0}},
   .prefix = 0,
   .primary_opcode = 140,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_JNL_141[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "jnl",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {75,0,0,0}},
   .prefix = 0,
   .primary_opcode = 141,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_JLE_142[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "jle",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {75,0,0,0}},
   .prefix = 0,
   .primary_opcode = 142,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_JNLE_143[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "jnle",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {75,0,0,0}},
   .prefix = 0,
   .primary_opcode = 143,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_SETO_144[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "seto",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 1, .operand = {11,0,0,0}},
   .prefix = 0,
   .primary_opcode = 144,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_SETNO_145[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "setno",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 1, .operand = {11,0,0,0}},
   .prefix = 0,
   .primary_opcode = 145,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_SETB_146[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "setb",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 1, .operand = {11,0,0,0}},
   .prefix = 0,
   .primary_opcode = 146,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_SETNB_147[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "setnb",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 1, .operand = {11,0,0,0}},
   .prefix = 0,
   .primary_opcode = 147,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_SETZ_148[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "setz",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 1, .operand = {11,0,0,0}},
   .prefix = 0,
   .primary_opcode = 148,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_SETNZ_149[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "setnz",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 1, .operand = {11,0,0,0}},
   .prefix = 0,
   .primary_opcode = 149,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_SETBE_150[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "setbe",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 1, .operand = {11,0,0,0}},
   .prefix = 0,
   .primary_opcode = 150,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_SETNBE_151[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "setnbe",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 1, .operand = {11,0,0,0}},
   .prefix = 0,
   .primary_opcode = 151,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_SETS_152[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "sets",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 1, .operand = {11,0,0,0}},
   .prefix = 0,
   .primary_opcode = 152,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_SETNS_153[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "setns",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 1, .operand = {11,0,0,0}},
   .prefix = 0,
   .primary_opcode = 153,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_SETP_154[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "setp",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 1, .operand = {11,0,0,0}},
   .prefix = 0,
   .primary_opcode = 154,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_SETNP_155[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "setnp",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 1, .operand = {11,0,0,0}},
   .prefix = 0,
   .primary_opcode = 155,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_SETL_156[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "setl",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 1, .operand = {11,0,0,0}},
   .prefix = 0,
   .primary_opcode = 156,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_SETNL_157[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "setnl",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 1, .operand = {11,0,0,0}},
   .prefix = 0,
   .primary_opcode = 157,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_SETLE_158[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "setle",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 1, .operand = {11,0,0,0}},
   .prefix = 0,
   .primary_opcode = 158,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_SETNLE_159[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "setnle",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 1, .operand = {11,0,0,0}},
   .prefix = 0,
   .primary_opcode = 159,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PUSH_160[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "push",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {52,0,0,0}},
   .prefix = 0,
   .primary_opcode = 160,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_POP_161[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "pop",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {52,0,0,0}},
   .prefix = 0,
   .primary_opcode = 161,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_CPUID_162[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "cpuid",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 162,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_BT_163[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "bt",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {14,10,0,0}},
   .prefix = 0,
   .primary_opcode = 163,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_SHLD_164[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "shld",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {14,10,1,0}},
   .prefix = 0,
   .primary_opcode = 164,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_SHLD_165[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "shld",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {14,10,16,0}},
   .prefix = 0,
   .primary_opcode = 165,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PUSH_168[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "push",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {53,0,0,0}},
   .prefix = 0,
   .primary_opcode = 168,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_POP_169[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "pop",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 1, .operand = {53,0,0,0}},
   .prefix = 0,
   .primary_opcode = 169,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_RSM_170[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "rsm",
   .opcode_field = {.type = 0, .value = 0 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 170,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_BTS_171[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "bts",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {14,10,0,0}},
   .prefix = 0,
   .primary_opcode = 171,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_SHRD_172[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "shrd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {14,10,1,0}},
   .prefix = 0,
   .primary_opcode = 172,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_SHRD_173[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "shrd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {14,10,16,0}},
   .prefix = 0,
   .primary_opcode = 173,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_FXSAVE_174[10] = {
  {
   .extended_opcode = true,
   .mnemonic = "fxsave",
   .opcode_field = {.type = 2, .value = 0 },
   .operands = {.size = 1, .operand = {60,0,0,0}},
   .prefix = 0,
   .primary_opcode = 174,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "fxrstor",
   .opcode_field = {.type = 2, .value = 1 },
   .operands = {.size = 1, .operand = {60,0,0,0}},
   .prefix = 0,
   .primary_opcode = 174,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "ldmxcsr",
   .opcode_field = {.type = 2, .value = 2 },
   .operands = {.size = 1, .operand = {57,0,0,0}},
   .prefix = 0,
   .primary_opcode = 174,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "stmxcsr",
   .opcode_field = {.type = 2, .value = 3 },
   .operands = {.size = 1, .operand = {57,0,0,0}},
   .prefix = 0,
   .primary_opcode = 174,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "xsave",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 1, .operand = {54,0,0,0}},
   .prefix = 0,
   .primary_opcode = 174,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "lfence",
   .opcode_field = {.type = 2, .value = 5 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 174,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "xrstor",
   .opcode_field = {.type = 2, .value = 5 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 174,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "mfence",
   .opcode_field = {.type = 2, .value = 6 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 174,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "sfence",
   .opcode_field = {.type = 2, .value = 7 },
   .operands = {.size = 0, .operand = {0,0,0,0}},
   .prefix = 0,
   .primary_opcode = 174,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "clflush",
   .opcode_field = {.type = 2, .value = 7 },
   .operands = {.size = 1, .operand = {55,0,0,0}},
   .prefix = 0,
   .primary_opcode = 174,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_IMUL_175[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "imul",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,14,0,0}},
   .prefix = 0,
   .primary_opcode = 175,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_CMPXCHG_176[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "cmpxchg",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {11,7,0,0}},
   .prefix = 0,
   .primary_opcode = 176,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_CMPXCHG_177[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "cmpxchg",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {14,10,0,0}},
   .prefix = 0,
   .primary_opcode = 177,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_LSS_178[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "lss",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,82,0,0}},
   .prefix = 0,
   .primary_opcode = 178,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_BTR_179[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "btr",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {14,10,0,0}},
   .prefix = 0,
   .primary_opcode = 179,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_LFS_180[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "lfs",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,82,0,0}},
   .prefix = 0,
   .primary_opcode = 180,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_LGS_181[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "lgs",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,82,0,0}},
   .prefix = 0,
   .primary_opcode = 181,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_MOVZX_182[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "movzx",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,11,0,0}},
   .prefix = 0,
   .primary_opcode = 182,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_MOVZX_183[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "movzx",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,12,0,0}},
   .prefix = 0,
   .primary_opcode = 183,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_POPCNT_184[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "popcnt",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,14,0,0}},
   .prefix = 243,
   .primary_opcode = 184,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_UD_185[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "ud",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {5,6,0,0}},
   .prefix = 0,
   .primary_opcode = 185,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_BT_186[4] = {
  {
   .extended_opcode = true,
   .mnemonic = "bt",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 2, .operand = {14,1,0,0}},
   .prefix = 0,
   .primary_opcode = 186,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "bts",
   .opcode_field = {.type = 2, .value = 5 },
   .operands = {.size = 2, .operand = {14,1,0,0}},
   .prefix = 0,
   .primary_opcode = 186,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "btr",
   .opcode_field = {.type = 2, .value = 6 },
   .operands = {.size = 2, .operand = {14,1,0,0}},
   .prefix = 0,
   .primary_opcode = 186,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "btc",
   .opcode_field = {.type = 2, .value = 7 },
   .operands = {.size = 2, .operand = {14,1,0,0}},
   .prefix = 0,
   .primary_opcode = 186,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_BTC_187[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "btc",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {14,10,0,0}},
   .prefix = 0,
   .primary_opcode = 187,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_BSF_188[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "bsf",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,14,0,0}},
   .prefix = 0,
   .primary_opcode = 188,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_BSR_189[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "bsr",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,14,0,0}},
   .prefix = 0,
   .primary_opcode = 189,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_MOVSX_190[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "movsx",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,11,0,0}},
   .prefix = 0,
   .primary_opcode = 190,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_MOVSX_191[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "movsx",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {10,12,0,0}},
   .prefix = 0,
   .primary_opcode = 191,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_XADD_192[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "xadd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {11,7,0,0}},
   .prefix = 0,
   .primary_opcode = 192,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_XADD_193[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "xadd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {14,10,0,0}},
   .prefix = 0,
   .primary_opcode = 193,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_CMPPS_194[4] = {
  {
   .extended_opcode = true,
   .mnemonic = "cmpps",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {89,93,1,0}},
   .prefix = 0,
   .primary_opcode = 194,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "cmpss",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {89,91,1,0}},
   .prefix = 243,
   .primary_opcode = 194,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "cmppd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {89,93,1,0}},
   .prefix = 102,
   .primary_opcode = 194,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "cmpsd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {89,92,1,0}},
   .prefix = 242,
   .primary_opcode = 194,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_MOVNTI_195[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "movnti",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {57,9,0,0}},
   .prefix = 0,
   .primary_opcode = 195,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PINSRW_196[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "pinsrw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {96,9,1,0}},
   .prefix = 0,
   .primary_opcode = 196,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pinsrw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {89,9,1,0}},
   .prefix = 102,
   .primary_opcode = 196,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PEXTRW_197[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "pextrw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {9,96,1,0}},
   .prefix = 0,
   .primary_opcode = 197,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pextrw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {9,89,1,0}},
   .prefix = 102,
   .primary_opcode = 197,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_SHUFPS_198[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "shufps",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {89,93,1,0}},
   .prefix = 0,
   .primary_opcode = 198,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "shufpd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {89,93,1,0}},
   .prefix = 102,
   .primary_opcode = 198,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_CMPXCHG8B_199[5] = {
  {
   .extended_opcode = true,
   .mnemonic = "cmpxchg8b",
   .opcode_field = {.type = 2, .value = 1 },
   .operands = {.size = 1, .operand = {58,0,0,0}},
   .prefix = 0,
   .primary_opcode = 199,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "vmptrld",
   .opcode_field = {.type = 2, .value = 6 },
   .operands = {.size = 1, .operand = {58,0,0,0}},
   .prefix = 0,
   .primary_opcode = 199,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "vmclear",
   .opcode_field = {.type = 2, .value = 6 },
   .operands = {.size = 1, .operand = {58,0,0,0}},
   .prefix = 102,
   .primary_opcode = 199,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "vmxon",
   .opcode_field = {.type = 2, .value = 6 },
   .operands = {.size = 1, .operand = {58,0,0,0}},
   .prefix = 243,
   .primary_opcode = 199,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "vmptrst",
   .opcode_field = {.type = 2, .value = 7 },
   .operands = {.size = 1, .operand = {58,0,0,0}},
   .prefix = 0,
   .primary_opcode = 199,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_BSWAP_200[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "bswap",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 1, .operand = {98,0,0,0}},
   .prefix = 0,
   .primary_opcode = 200,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_BSWAP_201[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "bswap",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 1, .operand = {98,0,0,0}},
   .prefix = 0,
   .primary_opcode = 201,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_BSWAP_202[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "bswap",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 1, .operand = {98,0,0,0}},
   .prefix = 0,
   .primary_opcode = 202,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_BSWAP_203[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "bswap",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 1, .operand = {98,0,0,0}},
   .prefix = 0,
   .primary_opcode = 203,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_BSWAP_204[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "bswap",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 1, .operand = {98,0,0,0}},
   .prefix = 0,
   .primary_opcode = 204,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_BSWAP_205[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "bswap",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 1, .operand = {98,0,0,0}},
   .prefix = 0,
   .primary_opcode = 205,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_BSWAP_206[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "bswap",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 1, .operand = {98,0,0,0}},
   .prefix = 0,
   .primary_opcode = 206,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_BSWAP_207[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "bswap",
   .opcode_field = {.type = 2, .value = 4 },
   .operands = {.size = 1, .operand = {98,0,0,0}},
   .prefix = 0,
   .primary_opcode = 207,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_ADDSUBPD_208[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "addsubpd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 208,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "addsubps",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 242,
   .primary_opcode = 208,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PSRLW_209[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "psrlw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 209,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "psrlw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 209,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PSRLD_210[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "psrld",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 210,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "psrld",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 210,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PSRLQ_211[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "psrlq",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 211,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "psrlq",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 211,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PADDQ_212[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "paddq",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 212,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "paddq",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 212,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PMULLW_213[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "pmullw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 213,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pmullw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 213,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_MOVQ_214[3] = {
  {
   .extended_opcode = true,
   .mnemonic = "movq",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {92,89,0,0}},
   .prefix = 102,
   .primary_opcode = 214,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "movq2dq",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,96,0,0}},
   .prefix = 243,
   .primary_opcode = 214,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "movdq2q",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,89,0,0}},
   .prefix = 242,
   .primary_opcode = 214,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PMOVMSKB_215[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "pmovmskb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {9,96,0,0}},
   .prefix = 0,
   .primary_opcode = 215,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pmovmskb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {9,89,0,0}},
   .prefix = 102,
   .primary_opcode = 215,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PSUBUSB_216[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "psubusb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 216,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "psubusb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 216,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PSUBUSW_217[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "psubusw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 217,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "psubusw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 217,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PMINUB_218[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "pminub",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 218,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pminub",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 218,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PAND_219[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "pand",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 219,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pand",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 219,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PADDUSB_220[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "paddusb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 220,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "paddusb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 220,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PADDUSW_221[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "paddusw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 221,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "paddusw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 221,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PMAXUB_222[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "pmaxub",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 222,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pmaxub",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 222,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PANDN_223[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "pandn",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 223,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pandn",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 223,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PAVGB_224[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "pavgb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 224,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pavgb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 224,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PSRAW_225[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "psraw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 225,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "psraw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 225,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PSRAD_226[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "psrad",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 226,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "psrad",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 226,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PAVGW_227[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "pavgw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 227,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pavgw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 227,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PMULHUW_228[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "pmulhuw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 228,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pmulhuw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 228,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PMULHW_229[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "pmulhw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 229,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pmulhw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 229,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_CVTPD2DQ_230[3] = {
  {
   .extended_opcode = true,
   .mnemonic = "cvtpd2dq",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 242,
   .primary_opcode = 230,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "cvttpd2dq",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 230,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "cvtdq2pd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 243,
   .primary_opcode = 230,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_MOVNTQ_231[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "movntq",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {58,96,0,0}},
   .prefix = 0,
   .primary_opcode = 231,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "movntdq",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {59,89,0,0}},
   .prefix = 102,
   .primary_opcode = 231,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PSUBSB_232[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "psubsb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 232,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "psubsb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 232,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PSUBSW_233[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "psubsw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 233,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "psubsw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 233,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PMINSW_234[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "pminsw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 234,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pminsw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 234,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_POR_235[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "por",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 235,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "por",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 235,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PADDSB_236[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "paddsb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 236,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "paddsb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 236,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PADDSW_237[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "paddsw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 237,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "paddsw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 237,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PMAXSW_238[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "pmaxsw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 238,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pmaxsw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 238,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PXOR_239[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "pxor",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 239,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pxor",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 239,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_LDDQU_240[1] = {
  {
   .extended_opcode = true,
   .mnemonic = "lddqu",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,59,0,0}},
   .prefix = 242,
   .primary_opcode = 240,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PSLLW_241[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "psllw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 241,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "psllw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 241,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PSLLD_242[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "pslld",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 242,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pslld",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 242,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PSLLQ_243[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "psllq",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 243,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "psllq",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 243,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PMULUDQ_244[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "pmuludq",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 244,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pmuludq",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 244,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PMADDWD_245[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "pmaddwd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 245,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "pmaddwd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 245,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PSADBW_246[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "psadbw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 246,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "psadbw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 246,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_MASKMOVQ_247[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "maskmovq",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {58,96,96,0}},
   .prefix = 0,
   .primary_opcode = 247,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "maskmovdqu",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 3, .operand = {59,89,89,0}},
   .prefix = 102,
   .primary_opcode = 247,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PSUBB_248[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "psubb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 248,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "psubb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 248,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PSUBW_249[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "psubw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 249,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "psubw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 249,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PSUBD_250[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "psubd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 250,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "psubd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 250,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PSUBQ_251[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "psubq",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 251,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "psubq",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 251,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PADDB_252[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "paddb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 252,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "paddb",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 252,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PADDW_253[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "paddw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 253,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "paddw",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 253,
   .secondary_opcode = -1,
  },
};

instruction_t EXTENDED_PADDD_254[2] = {
  {
   .extended_opcode = true,
   .mnemonic = "paddd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {96,97,0,0}},
   .prefix = 0,
   .primary_opcode = 254,
   .secondary_opcode = -1,
  },
  {
   .extended_opcode = true,
   .mnemonic = "paddd",
   .opcode_field = {.type = 1, .value = 0 },
   .operands = {.size = 2, .operand = {89,93,0,0}},
   .prefix = 102,
   .primary_opcode = 254,
   .secondary_opcode = -1,
  },
};

// extended end
