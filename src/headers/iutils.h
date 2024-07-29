#pragma once

#include "decoder.h"
#include <stdbool.h>

bool instr_has_secondary_opcode(uchar8_t opcode);
bool instr_has_vex(uchar8_t opcode);
bool instr_has_rex(uchar8_t opcode);
bool instr_has_prefix(uchar8_t opcode); 
bool instr_has_extended_opcode(uchar8_t opcode); 
bool instr_has_opcode_extension(Dinstruction *decoded);
bool instr_has_valid_extension(Dinstruction *decoded);
bool instr_has_sib(Dinstruction *decoded);
bool instr_has_displacement(Dinstruction *decoded);

bool instr_has_rel_offset_operand(Dinstruction *decoded);
bool instr_has_immediate_operand(Dinstruction *decoded);
bool instr_has_direct_addr_operand(Dinstruction *decoded);

void set_operand_capacity(Dinstruction *decoded);
void set_operand_size(Dinstruction *decoded);
void set_sib(Dinstruction *decoded, uchar8_t *i_ptr);
void set_displacement(Dinstruction *decoded);

size_t get_opcode_extension_operand_size(Dinstruction *decoded);
size_t get_vex_size(uchar8_t vex_byte);

