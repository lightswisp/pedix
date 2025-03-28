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

#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <pedix/mnemonic.h>
#include <pedix/iutils.h>
#include <pedix/decoder.h>
#include <pedix/operand.h>
#include <pedix/tables/tables.h>

#define eat_bytes(i, n) do{\
  i += n;                  \
}while(0)

#define SET_BUFFER(decoded, i_ptr, len)                                        \
  memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, len);            \
  decoded->buffer.size += len;

#define MANDATORY_PREFIX_CHECK(decoded)                                        \
  if (decoded->instruction->prefix != PREFIX_VOID)                             \
    assert("mandatory prefix is missing" &&                                    \
           pedix_instr_has_specific_prefix(decoded,                            \
                                           decoded->instruction->prefix));

decoded_instruction_t*
pedix_init_instruction(void) {
  decoded_instruction_t *decoded = (decoded_instruction_t *)calloc(1, sizeof(decoded_instruction_t));
  assert("calloc failed" && decoded != NULL);
  return decoded;
}

void 
pedix_zero_instruction(decoded_instruction_t *decoded) {
  // save the mode in order to restore it after zeroing the struct
  uint8_t mode = decoded->mode;
  memset(decoded, 0, sizeof(decoded_instruction_t));
  pedix_set_mode(decoded, mode);
}

void 
pedix_set_mode(decoded_instruction_t *decoded, uint8_t mode){
  switch(mode){
    case 32: 
      decoded->mode = mode; 
      decoded->address_size = DOUBLEWORD_LEN; 
      decoded->operand_size = DOUBLEWORD_LEN;
      break;
    case 64: 
      assert(!"64-bit mode is not yet implemented!");
      break;
    default: 
      assert(!"illegal mode selected");
      break;
  }
}

void 
pedix_free_instrucion(decoded_instruction_t *decoded) { 
  free(decoded); 
}

static void 
pedix_decode32(decoded_instruction_t *decoded, uint8_t *instruction) {
  while (pedix_instr_has_prefix(*instruction)) {
    decoded->prefixes.prefix[decoded->prefixes.size] = *instruction;
    switch(*instruction){
      case PREFIX_LOCK:            strcat(decoded->text, "lock ");       break;
      case PREFIX_CS:              strcpy(decoded->segment_text, "cs:"); break;
      case PREFIX_SS:              strcpy(decoded->segment_text, "ss:"); break;
      case PREFIX_DS:              strcpy(decoded->segment_text, "ds:"); break;
      case PREFIX_ES:              strcpy(decoded->segment_text, "es:"); break;
      case PREFIX_FS:              strcpy(decoded->segment_text, "fs:"); break;
      case PREFIX_GS:              strcpy(decoded->segment_text, "gs:"); break;
      case PREFIX_OPSIZE_OVERRIDE: decoded->operand_size = WORD_LEN;                break;
      case PREFIX_ASZ_OVERRIDE:    decoded->address_size = WORD_LEN;                break;
    }

    SET_BUFFER(decoded, instruction, BYTE_LEN);
    decoded->prefixes.size = decoded->buffer.size;
    eat_bytes(instruction, 1);
  }

  if (pedix_instr_has_extended_opcode(*instruction)) {
    // 0x0f (two byte opcode is gonna be decoded here)
    SET_BUFFER(decoded, instruction, WORD_LEN);
    eat_bytes(instruction, 1);
    
    instruction_container_t container = extended_table_32[*instruction];
    assert("non-zero instruction container" && container.size != 0);

    if (container.size == 1) {
      eat_bytes(instruction, 1);
      decoded->instruction = &container.instructions[0];
      MANDATORY_PREFIX_CHECK(decoded);
      if(decoded->instruction->secondary_opcode != NOT_FOUND){
        SET_BUFFER(decoded, instruction, BYTE_LEN); 
        eat_bytes(instruction, 1);
      }
    } else {
      // find the best match
      instruction_t* best_match_instruction = pedix_find_best_match(container, decoded, instruction);
      assert("can't find instruction" && best_match_instruction != NULL);
      eat_bytes(instruction, 1);
      decoded->instruction = best_match_instruction;
      if(decoded->instruction->secondary_opcode != NOT_FOUND){
        SET_BUFFER(decoded, instruction, BYTE_LEN); 
        eat_bytes(instruction, 1);
      }
    }

  } else { 
    // one byte opcode is gonna be here
    SET_BUFFER(decoded, instruction, BYTE_LEN);

    instruction_container_t container = regular_table_32[*instruction];
    assert("non-zero instruction container" && container.size != 0);

    if (container.size == 1) {
      eat_bytes(instruction, 1);
      decoded->instruction = &container.instructions[0];
      MANDATORY_PREFIX_CHECK(decoded);
      if(decoded->instruction->secondary_opcode != NOT_FOUND){
        SET_BUFFER(decoded, instruction, BYTE_LEN); 
        eat_bytes(instruction, 1);
      }
    } else {
      // find the best match
      instruction_t *best_match_instruction = pedix_find_best_match(container, decoded, instruction);
      assert("can't find instruction" && best_match_instruction != NULL);

      eat_bytes(instruction, 1);

      decoded->instruction = best_match_instruction;
      if(decoded->instruction->secondary_opcode != NOT_FOUND){
        SET_BUFFER(decoded, instruction, BYTE_LEN); 
        eat_bytes(instruction, 1);
      }
    }
  }

  if (decoded->instruction->opcode_field.type == FIELD_MOD_RM ||
      decoded->instruction->opcode_field.type == FIELD_MULTIPLEXED_MOD_RM) {
    // if it has modrm
    pedix_set_modrm(decoded, instruction);
    SET_BUFFER(decoded, instruction, BYTE_LEN);
    eat_bytes(instruction, 1);
    // it can have sib byte only and only when modrm is present
    if (pedix_instr_has_sib(decoded)) {
      pedix_set_sib(decoded, instruction);
      SET_BUFFER(decoded, instruction, decoded->sib.size);
      eat_bytes(instruction, 1);
    }
    // sib byte must be parsed first, and only after that we are free to check for displacement 
    if(pedix_instr_has_displacement(decoded)){
      pedix_set_displacement(decoded);
      SET_BUFFER(decoded, instruction, decoded->displacement.size);
      memcpy(&decoded->displacement.field, instruction, decoded->displacement.size); 
      eat_bytes(instruction, decoded->displacement.size);
    }
  }

  // set mnemonic
  pedix_set_mnemonic(decoded);
  // set operands if we have at least one operand 
  if (decoded->instruction->operands.size > 0) {
    pedix_set_operands(decoded, instruction); 
    pedix_merge_operands(decoded);
  }
}

static void 
pedix_decode64(__attribute__((unused)) decoded_instruction_t *decoded,
               __attribute__((unused)) uint8_t *instruction) {
  assert(!"64-bit mode is not yet implemented");
  //     in 64-bit mode, instruction formats do not change. bits needed to
  //     define fields in the 64-bit context are provided by the
  // addition of rex prefixes.
  //  uint8_t *i_ptr = instruction;
  //
  //  while (instr_has_prefix(*i_ptr)) {
  //    decoded->status |= STATUS_PREFIX;
  //    if (*i_ptr == PREFIX_OPSIZE_OVERRIDE)
  //      decoded->status |= STATUS_OPSIZE_OVERRIDE;
  //
  //    decoded->prefixes.prefix[decoded->prefixes.size] = *i_ptr;
  //    memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, BYTE_LEN);
  //    decoded->buffer.size += BYTE_LEN;
  //    decoded->prefixes.size = decoded->buffer.size;
  //    POST_INC(i_ptr);
  //  }
  //
  //  if (instr_has_rex(*i_ptr)) {
  //    decoded->status |= STATUS_REX;
  //    memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, BYTE_LEN);
  //    decoded->buffer.size += BYTE_LEN;
  //    decoded->rex.field = *i_ptr;
  //    decoded->rex.w = (decoded->rex.field & 0x08) >> 3;
  //    decoded->rex.r = (decoded->rex.field & 0x04) >> 2;
  //    decoded->rex.x = (decoded->rex.field & 0x02) >> 1;
  //    decoded->rex.b = (decoded->rex.field & 0x01);
  //    POST_INC(i_ptr);
  //  }
  //
  //  if (instr_has_extended_opcode(*i_ptr)) {
  //    // 0x0f (two byte opcode is gonna be decoded here)
  //    decoded->status |= STATUS_EXTENDED;
  //    memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, BYTE_LEN);
  //    decoded->buffer.size += BYTE_LEN;
  //    POST_INC(i_ptr);
  //    if (instr_has_secondary_opcode(*i_ptr)) {
  //      // if it has secondary opcode
  //      decoded->op1 = *i_ptr;
  //      memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, BYTE_LEN);
  //      decoded->buffer.size += BYTE_LEN;
  //
  //      POST_INC(i_ptr);
  //      decoded->op2 = *i_ptr;
  //      memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, BYTE_LEN);
  //      decoded->buffer.size += BYTE_LEN;
  //
  //      POST_INC(i_ptr);
  //
  //      if (!decode_modrm(decoded, i_ptr))
  //        return false;
  //
  //      decoded->buffer.bytes[decoded->buffer.size] = *i_ptr;
  //      decoded->buffer.size += decoded->modrm.size;
  //      i_ptr += decoded->modrm.size;
  //
  //      if (instr_has_sib(decoded)) {
  //        decoded->status |= STATUS_SIB;
  //        set_sib(decoded, i_ptr);
  //        decoded->buffer.bytes[decoded->buffer.size] = *i_ptr;
  //        decoded->buffer.size += decoded->sib.size;
  //        /* sib field */
  //        i_ptr += decoded->sib.size;
  //      }
  //
  //      if (instr_has_displacement(decoded)) {
  //        decoded->status |= STATUS_DISP;
  //        set_displacement(decoded);
  //        memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr,
  //               decoded->displacement.size);
  //        memcpy(&decoded->displacement.field, i_ptr,
  //        decoded->displacement.size); decoded->buffer.size +=
  //        decoded->displacement.size;
  //        /* displacement field */
  //        i_ptr += decoded->displacement.size;
  //      }
  //
  //      if (instr_has_immediate_operand(decoded)) {
  //        set_operand_size(decoded);
  //        if (decoded->operands.size == 0)
  //          return false;
  //
  //        memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr,
  //               decoded->operands.size);
  //        memcpy(&decoded->imm, i_ptr, decoded->operands.size);
  //        decoded->buffer.size += decoded->operands.size;
  //      }
  //      set_operand_capacity(decoded);
  //
  //      return true;
  //    } else if (*i_ptr == 0x01) {
  //      decoded->op1 = *i_ptr;
  //      POST_INC(i_ptr);
  //      switch (*i_ptr) {
  //      case 0xC1:
  //      case 0xC2:
  //      case 0xC3:
  //      case 0xC4:
  //      case 0xC8:
  //      case 0xC9:
  //      case 0xD0:
  //      case 0xD1:
  //      case 0xF9:
  //        decoded->op2 = *i_ptr;
  //        memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr,
  //        WORD_LEN); decoded->buffer.size += WORD_LEN;
  //        set_operand_capacity(decoded);
  //        return true;
  //      default:
  //        return false;
  //      }
  //    } else {
  //      decoded->op1 = *i_ptr;
  //      memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, BYTE_LEN);
  //      decoded->buffer.size += BYTE_LEN;
  //
  //      if (decode_zero(decoded))
  //        return true;
  //
  //      if (decode_other(decoded)) {
  //        memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr,
  //        decoded->operands.size); decoded->buffer.size +=
  //        decoded->operands.size; set_operand_capacity(decoded); return true;
  //      }
  //
  //      if (decode_modrm(decoded, PRE_INC(i_ptr))) {
  //
  //        if (instr_has_opcode_extension(decoded) &&
  //            instr_has_valid_extension(decoded)) {
  //          decoded->status |= STATUS_OPCODE_EXTENSION;
  //          size_t op_size = get_opcode_extension_operand_size(decoded);
  //          memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr,
  //          op_size); decoded->buffer.size += op_size;
  //        }
  //
  //        decoded->buffer.bytes[decoded->buffer.size] = *i_ptr;
  //        decoded->buffer.size += decoded->modrm.size;
  //        i_ptr += decoded->modrm.size;
  //
  //        if (instr_has_sib(decoded)) {
  //          decoded->status |= STATUS_SIB;
  //          set_sib(decoded, i_ptr);
  //          decoded->buffer.bytes[decoded->buffer.size] = *i_ptr;
  //          decoded->buffer.size += decoded->sib.size;
  //          /* sib field */
  //          i_ptr += decoded->sib.size;
  //        }
  //
  //        if (instr_has_displacement(decoded)) {
  //          decoded->status |= STATUS_DISP;
  //          set_displacement(decoded);
  //          memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr,
  //                 decoded->displacement.size);
  //          memcpy(&decoded->displacement.field, i_ptr,
  //          decoded->displacement.size); decoded->buffer.size +=
  //          decoded->displacement.size;
  //          /* displacement field */
  //          i_ptr += decoded->displacement.size;
  //        }
  //
  //        if (instr_has_immediate_operand(decoded)) {
  //          set_operand_size(decoded);
  //          if (decoded->operands.size == 0)
  //            return false;
  //
  //          memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr,
  //                 decoded->operands.size);
  //          memcpy(&decoded->imm, i_ptr, decoded->operands.size);
  //          decoded->buffer.size += decoded->operands.size;
  //        }
  //        set_operand_capacity(decoded);
  //        return true;
  //      }
  //    }
  //    return false;
  //  }
  //
  //  if (instr_has_vex(*i_ptr)) {
  //    decoded->status |= STATUS_VEX;
  //    size_t vex_size = get_vex_size(*i_ptr);
  //    memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, vex_size);
  //    decoded->buffer.size += vex_size;
  //    POST_INC(i_ptr);
  //  }
  //
  //  decoded->op1 = *i_ptr;
  //  memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, BYTE_LEN);
  //  decoded->buffer.size += BYTE_LEN;
  //
  //  if (decode_zero(decoded))
  //    return true;
  //
  //  if (decode_other(decoded)) {
  //    memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr,
  //    decoded->operands.size); decoded->buffer.size += decoded->operands.size;
  //    set_operand_capacity(decoded);
  //    return true;
  //  }
  //
  //  if (decode_modrm(decoded, PRE_INC(i_ptr))) {
  //
  //    if (instr_has_opcode_extension(decoded) &&
  //        instr_has_valid_extension(decoded)) {
  //      decoded->status |= STATUS_OPCODE_EXTENSION;
  //      size_t op_size = get_opcode_extension_operand_size(decoded);
  //      memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, op_size);
  //      decoded->buffer.size += op_size;
  //    }
  //
  //    decoded->buffer.bytes[decoded->buffer.size] = *i_ptr;
  //    decoded->buffer.size += decoded->modrm.size;
  //    i_ptr += decoded->modrm.size;
  //
  //    if (instr_has_sib(decoded)) {
  //      decoded->status |= STATUS_SIB;
  //      set_sib(decoded, i_ptr);
  //      decoded->buffer.bytes[decoded->buffer.size] = *i_ptr;
  //      decoded->buffer.size += decoded->sib.size;
  //      /* sib field */
  //      i_ptr += decoded->sib.size;
  //    }
  //
  //    if (instr_has_displacement(decoded)) {
  //      decoded->status |= STATUS_DISP;
  //      set_displacement(decoded);
  //      memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr,
  //             decoded->displacement.size);
  //      memcpy(&decoded->displacement.field, i_ptr,
  //      decoded->displacement.size); decoded->buffer.size +=
  //      decoded->displacement.size;
  //      /* displacement field */
  //      i_ptr += decoded->displacement.size;
  //    }
  //
  //    if (instr_has_immediate_operand(decoded)) {
  //      set_operand_size(decoded);
  //      if (decoded->operands.size == 0)
  //        return false;
  //
  //      memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr,
  //             decoded->operands.size);
  //      memcpy(&decoded->imm, i_ptr, decoded->operands.size);
  //      decoded->buffer.size += decoded->operands.size;
  //    }
  //    set_operand_capacity(decoded);
  //    return true;
  //  }
  //
  //  return false;
}

void 
pedix_decode(decoded_instruction_t *decoded, uint8_t *instruction) {
  switch (decoded->mode) {
  case MODE_32:
    pedix_decode32(decoded, instruction);
    break;
  case MODE_64:
    pedix_decode64(decoded, instruction);
    break;
  default:
    assert(!"illegal mode selected");
  }
}
