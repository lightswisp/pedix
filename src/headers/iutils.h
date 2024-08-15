#pragma once

#include "decoder.h"
#include <stdbool.h>

/* modrm helpers */
#define MODRM_MOD(field) ((field & 0xC0) >> 6)
#define MODRM_REG(field) ((field & 0x38) >> 3)
#define MODRM_RM(field)  ((field & 0x07))

/* sib helpers */
#define SIB_SCALE(field) ((field & 0xC0) >> 6)
#define SIB_INDEX(field) ((field & 0x38) >> 3)
#define SIB_BASE(field)  ((field & 0x07))

bool pedix_instr_has_immediate_operand(Dinstruction *decoded);
bool pedix_instr_has_rel_offset_operand(Dinstruction *decoded);
bool pedix_instr_has_direct_addr_operand(Dinstruction *decoded);
bool pedix_instr_has_prefix(uchar8_t opcode);
bool pedix_instr_has_specific_prefix(Dinstruction *decoded, uint8_t prefix);
bool pedix_instr_has_extended_opcode(uchar8_t opcode);
bool pedix_instr_has_sib(Dinstruction *decoded);
bool pedix_instr_has_displacement(Dinstruction *decoded);
void pedix_set_direct_address(Dinstruction *decoded, uchar8_t* instruction);
void pedix_set_relative_address(Dinstruction *decoded, uchar8_t* instruction);
void pedix_set_sib(Dinstruction *decoded, uchar8_t *i_ptr);
void pedix_set_modrm(Dinstruction *decoded, uchar8_t *i_ptr); 
void pedix_set_displacement(Dinstruction *decoded);
uint64_t pedix_set_immediate_operand_if_present(Dinstruction *decoded, uchar8_t* instruction);
uint64_t pedix_set_relative_offset_operand_if_present(Dinstruction *decoded, uchar8_t* instruction);
uint64_t pedix_set_direct_address_operand_if_present(Dinstruction *decoded, uchar8_t* instruction);

size_t pedix_get_vex_size(uchar8_t vex_byte);
Instruction *pedix_find_best_match(InstructionContainer container, Dinstruction *decoded, uchar8_t *i_ptr);
