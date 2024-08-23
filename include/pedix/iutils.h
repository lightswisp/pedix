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

bool pedix_instr_has_immediate_operand(decoded_instruction_t *decoded);
bool pedix_instr_has_rel_offset_operand(decoded_instruction_t *decoded);
bool pedix_instr_has_direct_addr_operand(decoded_instruction_t *decoded);
bool pedix_instr_has_prefix(uchar8_t opcode);
bool pedix_instr_has_specific_prefix(decoded_instruction_t *decoded, uint8_t prefix);
bool pedix_instr_has_extended_opcode(uchar8_t opcode);
bool pedix_instr_has_sib(decoded_instruction_t *decoded);
bool pedix_instr_has_displacement(decoded_instruction_t *decoded);
void pedix_set_direct_address(decoded_instruction_t *decoded, uchar8_t* instruction);
void pedix_set_relative_address(decoded_instruction_t *decoded, uchar8_t* instruction);
void pedix_set_sib(decoded_instruction_t *decoded, uchar8_t *i_ptr);
void pedix_set_modrm(decoded_instruction_t *decoded, uchar8_t *i_ptr); 
void pedix_set_displacement(decoded_instruction_t *decoded);
uint64_t pedix_set_immediate_operand_if_present(decoded_instruction_t *decoded, uchar8_t* instruction);
uint64_t pedix_set_relative_offset_operand_if_present(decoded_instruction_t *decoded, uchar8_t* instruction);
uint64_t pedix_set_direct_address_operand_if_present(decoded_instruction_t *decoded, uchar8_t* instruction);

size_t pedix_get_vex_size(uchar8_t vex_byte);
instruction_t *pedix_find_best_match(instruction_container_t container, decoded_instruction_t *decoded, uchar8_t *i_ptr);
