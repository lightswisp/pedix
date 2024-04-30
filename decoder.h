#include <stdbool.h>

enum Types{
    INSTR_ZERO  = 1,
    INSTR_MODRM = 2,
    INSTR_OTHER = 3,
};

typedef struct {
    size_t size;
    bool has_prefix;
    bool extended;
    unsigned int prefixes[2];
    unsigned char op1; // op1 is the primary opcode (it might be a little bit confusting, but it's not the first opcode)
    unsigned char op2; // op2 is the secondary opcode
    unsigned int mod;
    unsigned int reg_src;
    unsigned int reg_dst;
    unsigned int instr_type;
    char mnemonic[100]; // this one is not implemented yet!
} Dinstruction;

Dinstruction* init_instruction();               // allocates memory for the struct
void dump(Dinstruction* decoded);               // dumps struct fields to stdout
void free_instrucion(Dinstruction* decoded);    // frees the memory
void zero_instruction(Dinstruction* decoded);   // zeroes the struct
bool decode(unsigned char* insruction, Dinstruction* decoded, unsigned int mode);   //general decode func
bool decode32(unsigned char* insruction, Dinstruction* decoded, unsigned int mode); // 32bit specific 
bool decode64(unsigned char* insruction, Dinstruction* decoded, unsigned int mode); // 64bit specific
bool instr_has_prefix(unsigned char instruction);           // checks if the instruction has prefixes (4 bytes max)
bool instr_has_extended_opcode(unsigned char instruction);  // checks if the instruction has 2-byte opcode
bool instr_zero(unsigned char opcode); // if instruction has no operands
bool instr_modrm(unsigned char opcode);
bool instr_other(unsigned char opcode);
bool instr_has_rel_offset_operand(unsigned char opcode);
bool instr_has_direct_addr_operand(unsigned char opcode);
bool instr_has_modrm(unsigned char opcode);
unsigned int get_immediate_operand_size(unsigned char opcode);
unsigned int get_rel_offset_operand_size(unsigned char opcode);