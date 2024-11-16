#include <string.h>
#include <assert.h>
#include <pedix/iutils.h>
#include <pedix/tables/tabledef.h>
#ifdef DEBUG 
  #include <stdio.h>
#endif

#define HAS_IMMEDIATE(operand)                                                 \
  (operand == OPERAND_IMM_8 || operand == OPERAND_IMM_16 ||                    \
   operand == OPERAND_IMM_32 || operand == OPERAND_IMM_16_32)

#define HAS_RELATIVE(operand)                                                  \
  (operand == OPERAND_REL_8 || operand == OPERAND_REL_16 ||                    \
   operand == OPERAND_REL_32 || operand == OPERAND_REL_16_32)

#define HAS_MOFFS(operand) (operand == OPERAND_MOFFS_32)

#define HAS_STI(operand) (operand == OPERAND_REG_STI)

/*
 * check if instruction has any prefixes
 */
bool pedix_instr_has_prefix(uint8_t opcode) {
  switch (opcode) {
  case PREFIX_LOCK:
  case PREFIX_REPNE_Z:
  case PREFIX_REP_E_Z:
  case PREFIX_CS:
  case PREFIX_DS:
  case PREFIX_SS:
  case PREFIX_ES:
  case PREFIX_FS:
  case PREFIX_GS:
  case PREFIX_OPSIZE_OVERRIDE:
  case PREFIX_ASZ_OVERRIDE:

    return true;

  default:
    return false;
  }
}

/* 
 * check if instruction has extended opcode
 * if returns true, then the instruction size is at least 2 bytes long
 */
bool pedix_instr_has_extended_opcode(uint8_t opcode) {
  if (opcode == 0x0F)
    return true;
  return false;
}

size_t pedix_get_vex_size(uint8_t vex_byte) {
  switch (vex_byte) {
  case 0xC5:
    return WORD_LEN;
  case 0xC4:
    return THREE_BYTE_LEN;
  case 0x8F:
    return THREE_BYTE_LEN;
  }
  return 0;
}

bool pedix_instr_has_specific_prefix(decoded_instruction_t *decoded, uint8_t prefix){
  for (size_t i = 0; i < decoded->prefixes.size; i++) 
    if (decoded->prefixes.prefix[i] == prefix) return true;
  return false;
}

bool pedix_instr_has_sib(decoded_instruction_t *decoded) {
 /* |mod|rm|  
  *  00 100 sib            mode                     
  *  01 100 sib  +  disp8  mode
  *  10 100 sib  +  disp32 mode
  */
  if(decoded->address_size == WORD_LEN)
    /* there is no sib in real mode */
    return false;
 
  if  (decoded->modrm.rm  == 4 &&
      (decoded->modrm.mod == 0 || decoded->modrm.mod == 1 ||
       decoded->modrm.mod == 2))
    return true;
  return false;
}

bool pedix_instr_has_displacement(decoded_instruction_t *decoded){
  if (decoded->address_size == WORD_LEN) {
    // 16-bit mode
    switch (decoded->modrm.mod) {
    case 0:
      if (decoded->modrm.rm == 6)
        return true;
      break;
    case 1:
    case 2:
      return true;
    }
    return false;
  } else {
    // 32/64-bit modes
    switch (decoded->modrm.mod) {
    case 0:
      if (decoded->modrm.rm == 4) {
        uint8_t base = decoded->sib.base & 0x07;
        if (base == 5)
          return true;
      } else if (decoded->modrm.rm == 5)
        return true;
      break;
    case 1:
    case 2:
      return true;
    }
    return false;
  }
}

/*
 * in situations where instruction container consists of more then one instruction,
 * this function is used to find the best match in a for loop
 * matching criterias are: prefix, primary opcode, secondary opcode and operand field.
 * if there is no match, we decrease the temp_score by one
 * if there is a match, we increase the temp_score by one
 * if there is an exact hit, we return the instruction pointer immediately.
 */ 
instruction_t *pedix_find_best_match(instruction_container_t container, decoded_instruction_t *decoded, uint8_t *instruction){
  uint8_t max_score, max_i;

  for (size_t i = 0; i < container.size; i++) {
    field_type_t type    = container.instructions[i].opcode_field.type;
    __prefix_t prefix    = container.instructions[i].prefix;
    int secondary_opcode = container.instructions[i].secondary_opcode;
    uint8_t value        = container.instructions[i].opcode_field.value;
    uint8_t offset       = 1;
    int temp_score       = 0;
    
    switch (type) {
    case FIELD_VOID:
      if(prefix != PREFIX_VOID){
        // if it has prefix
        bool found_prefix = false;
        for(size_t i = 0; i < decoded->prefixes.size; i++){
          if(decoded->prefixes.prefix[i] == prefix){
            temp_score++; 
            found_prefix = true;
          }
        }
        if(!found_prefix)
          temp_score--;
      } 
      if (secondary_opcode != NOT_FOUND && secondary_opcode == instruction[1]) {
        // return immediately if it is an exact hit!
        return &container.instructions[i];
      }
      break;
    case FIELD_MOD_RM:
      if(prefix != PREFIX_VOID){
        bool found_prefix = false;
        // if it has prefix
        for(size_t i = 0; i < decoded->prefixes.size; i++){
          if(decoded->prefixes.prefix[i] == prefix){
            temp_score++;
            found_prefix = true;
          }
        }
        if(!found_prefix)
          temp_score--;
      }
      if (secondary_opcode != NOT_FOUND) {
        // if secondary opcode is matching, we increase the offset
        // in order to check modrm after
        // and we increase score as well
        if(secondary_opcode == instruction[offset]){
#ifdef DEBUG
          printf("%s hit!\n", container.instructions[i].mnemonic);
#endif
          offset++;
          temp_score++;
        }
        else 
          temp_score--;
      }

      break;
    case FIELD_MULTIPLEXED_MOD_RM:
      if (prefix != PREFIX_VOID) {
        // if it has prefix
        bool found_prefix = false;
        for (size_t i = 0; i < decoded->prefixes.size; i++) {
          if (decoded->prefixes.prefix[i] == prefix) {
            temp_score++;
            found_prefix = true;
          }
        }

        if (!found_prefix)
          temp_score--;
      }

      if (secondary_opcode != NOT_FOUND) {
        // if secondary opcode is matching, we increase the offset
        // in order to check modrm after
        // and we increase score as well
        if(secondary_opcode == instruction[offset]){
#ifdef DEBUG
          printf("%s hit!\n", container.instructions[i].mnemonic);
#endif
          offset++;
          temp_score++;
        }
        else 
          temp_score--;
      }

/*#ifdef DEBUG
      if (secondary_opcode != NOT_FOUND) {
        // remove the opcode field from the table please!
#if defined(__x86_64__) || defined(__i386__)
        SET_BREAKPOINT;
#endif
      }
#endif
*/
      if (MODRM_REG(instruction[offset]) == value)
        // if reg field matches
        temp_score++; 
      else 
        temp_score--;
      break;
    }
#ifdef DEBUG
    printf("%s scores %d\n", container.instructions[i].mnemonic, temp_score);
#endif

    if(temp_score > max_score){
      max_score = temp_score;
      max_i = i;
    }

  }
  return &container.instructions[max_i];
}

void pedix_set_modrm(decoded_instruction_t *decoded, uint8_t *instruction) {
  decoded->modrm.size = BYTE_LEN;
  decoded->modrm.field = *instruction;
  decoded->modrm.mod = MODRM_MOD(decoded->modrm.field); 
  decoded->modrm.reg = MODRM_REG(decoded->modrm.field); 
  decoded->modrm.rm  = MODRM_RM(decoded->modrm.field); 
}

void pedix_set_sib(decoded_instruction_t *decoded, uint8_t *instruction){
  decoded->sib.size  = BYTE_LEN;
  decoded->sib.field = *instruction;
  decoded->sib.scale = SIB_SCALE(decoded->sib.field); 
  decoded->sib.index = SIB_INDEX(decoded->sib.field);
  decoded->sib.base  = SIB_BASE(decoded->sib.field);; 
}

void pedix_set_displacement(decoded_instruction_t *decoded){
  size_t size = 0;
  if (decoded->address_size == WORD_LEN) {
    // 16-bit mode
    switch(decoded->modrm.mod){
      case 0: 
        size = WORD_LEN;
        break;
      case 1: 
        size = BYTE_LEN;
        break;
      case 2:
        size = WORD_LEN;
        break;
    }
  } else {
    // 32/64-bit modes
    switch (decoded->modrm.mod) {
    case 0:
      if (decoded->modrm.rm == 4) {
        uint8_t base = decoded->sib.base & 0x07;
        if (base == 5) 
          size = DOUBLEWORD_LEN; 
        break;
      } else if (decoded->modrm.rm == 5) {
        size = DOUBLEWORD_LEN; 
        break;
      }
      break;
    case 1:
      size = BYTE_LEN;
      break;
    case 2:
      if (decoded->address_size == WORD_LEN)
        size = WORD_LEN;
      else
        size = DOUBLEWORD_LEN;
      break;
    }
  }

  decoded->displacement.size = size;
}
