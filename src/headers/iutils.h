#pragma once

#include "decoder.h"
#include <stdbool.h>

/* modrm helpers */
#define MODRM_MOD(field) ((field & 0xC0) >> 6)
#define MODRM_REG(field) ((field & 0x38) >> 3)
#define MODRM_RM(field)  ((field & 0x07))

bool instr_has_immediate_operand(Dinstruction *decoded);
bool instr_has_rel_offset_operand(Dinstruction *decoded);
bool instr_has_direct_addr_operand(Dinstruction *decoded);
bool instr_has_prefix(uchar8_t opcode);
bool instr_has_specific_prefix(Dinstruction *decoded, uint8_t prefix);
bool instr_has_extended_opcode(uchar8_t opcode);
bool instr_has_sib(Dinstruction *decoded);
bool instr_has_displacement(Dinstruction *decoded);
void set_sib(Dinstruction *decoded, uchar8_t *i_ptr);
void set_modrm(Dinstruction *decoded, uchar8_t *i_ptr); 
void set_displacement(Dinstruction *decoded);
uint64_t set_immediate_operand_if_present(Dinstruction *decoded, uchar8_t* instruction);
uint64_t set_relative_offset_operand_if_present(Dinstruction *decoded, uchar8_t* instruction);
uint64_t set_direct_address_operand_if_present(Dinstruction *decoded, uchar8_t* instruction);
void set_direct_address(Dinstruction *decoded, uchar8_t* instruction);
void set_relative_address(Dinstruction *decoded, uchar8_t* instruction);

Instruction *find_best_match(InstructionContainer container, Dinstruction *decoded, uchar8_t *i_ptr);
size_t get_vex_size(uchar8_t vex_byte);
