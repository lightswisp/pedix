#include <stdbool.h>

enum Types{
    INSTR_ZERO  = 1,
    INSTR_MODRM = 2,
    INSTR_OTHER = 3,
};

bool instr_has_prefix(unsigned char instruction);           // checks if the instruction has prefixes (4 bytes max)
bool instr_has_extended_opcode(unsigned char instruction);  // checks if the instruction has 2-byte opcode
bool instr_zero(unsigned char opcode); // if instruction has no operands
bool instr_modrm(unsigned char opcode);
bool instr_other(unsigned char opcode);
bool instr_has_rel_offset_operand(unsigned char opcode);
bool instr_has_immediate_operand(unsigned char opcode);
bool instr_has_direct_addr_operand(unsigned char opcode);
bool instr_has_modrm(unsigned char opcode);
unsigned int get_immediate_operand_size(unsigned char opcode);
unsigned int get_rel_offset_operand_size(unsigned char opcode);
unsigned int get_direct_addr_operand_size(unsigned char opcode);