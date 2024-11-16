/*
 * Copyright (c) 2024 lightswisp
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/

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
bool pedix_instr_has_prefix(uint8_t opcode);
bool pedix_instr_has_specific_prefix(decoded_instruction_t *decoded, uint8_t prefix);
bool pedix_instr_has_extended_opcode(uint8_t opcode);
bool pedix_instr_has_sib(decoded_instruction_t *decoded);
bool pedix_instr_has_displacement(decoded_instruction_t *decoded);
void pedix_set_direct_address(decoded_instruction_t *decoded, uint8_t* instruction);
void pedix_set_relative_address(decoded_instruction_t *decoded, uint8_t* instruction);
void pedix_set_sib(decoded_instruction_t *decoded, uint8_t *i_ptr);
void pedix_set_modrm(decoded_instruction_t *decoded, uint8_t *i_ptr); 
void pedix_set_displacement(decoded_instruction_t *decoded);
size_t pedix_get_vex_size(uint8_t vex_byte);
instruction_t *pedix_find_best_match(instruction_container_t container, decoded_instruction_t *decoded, uint8_t *i_ptr);
