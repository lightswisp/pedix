#pragma once

#include <stdbool.h>
#include "decoder.h"

enum Types{
    INSTR_ZERO  = 1,
    INSTR_MODRM = 2,
    INSTR_OTHER = 3,
};

bool instr_has_vex(unsigned char instruction);
bool instr_has_rex(unsigned char instruction);
bool instr_has_prefix(unsigned char instruction);           // checks if the instruction has prefixes (4 bytes max)
bool instr_has_extended_opcode(unsigned char instruction);  // checks if the instruction has 2-byte opcode
bool instr_has_opcode_extension(Dinstruction* decoded, unsigned char opcode);
bool instr_has_valid_extension(Dinstruction* decoded, unsigned char opcode);

bool instr_zero(Dinstruction* decoded,  unsigned char opcode); // if instruction has no operands
bool instr_modrm(Dinstruction* decoded, unsigned char opcode);
bool instr_other(Dinstruction* decoded, unsigned char opcode);

bool instr_has_rel_offset_operand(Dinstruction* decoded, unsigned char opcode);
bool instr_has_immediate_operand(Dinstruction* decoded, unsigned char opcode);
bool instr_has_direct_addr_operand(unsigned char opcode);
bool instr_has_modrm(unsigned char opcode);

size_t get_operand_size(Dinstruction* decoded, unsigned char opcode);
size_t get_modrm_size(Dinstruction* decoded, unsigned char* i_ptr);
size_t get_vex_size(unsigned char vex_byte);