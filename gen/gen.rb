require "nokogiri"

module Operands
  VOID              = 0;
  IMM_8             = 1;
  IMM_16            = 2;
  IMM_32            = 3;
  IMM_16_32         = 4;
  R_ALL             = 5;
  RM_ALL            = 6;
  R_8               = 7;
  R_16              = 8;
  R_32              = 9;
  R_16_32           = 10;
  RM_8              = 11;
  RM_16             = 12;
  RM_32             = 13;
  RM_16_32          = 14;

  REG_AL            = 15;
  REG_CL            = 16;
  REG_DL            = 17;
  REG_BL            = 18;
  REG_AH            = 19;
  REG_CH            = 20;
  REG_DH            = 21;
  REG_BH            = 22;
  REG_AX            = 23;
  REG_CX            = 24;
  REG_DX            = 25;
  REG_BX            = 26;
  REG_SP            = 27;
  REG_BP            = 28;
  REG_SI            = 29;
  REG_DI            = 30;
  REG_EAX           = 31;
  REG_ECX           = 32;
  REG_EDX           = 33;
  REG_EBX           = 34;
  REG_ESP           = 35;
  REG_EBP           = 36;
  REG_ESI           = 37;
  REG_EDI           = 38;
  REG_RAX           = 39;
  REG_RCX           = 40;
  REG_RDX           = 41;
  REG_RBX           = 42;
  REG_RSP           = 43;
  REG_RBP           = 44;
  REG_RSI           = 45;
  REG_RDI           = 46;
  
  SEG_ALL           = 47;
  SEG_ES            = 48;
  SEG_SS            = 49;
  SEG_DS            = 50;
  SEG_CS            = 51;
  SEG_FS            = 52;
  SEG_GS            = 53;

  M_ALL             = 54;
  M_8               = 55;
  M_16              = 56;
  M_32              = 57;
  M_64              = 58;
  M_128             = 59;
  M_512             = 60;
  M_16_32           = 61;

  M_16_AMP_32       = 62;
  M_16_AMP_16       = 63;
  M_32_AMP_32       = 64;
  M_16_AMP_64       = 65;
  M_16_32_AMP_16_32 = 66;

  MOFFS_8           = 67;
  MOFFS_16          = 68;
  MOFFS_32          = 69;
  MOFFS_64          = 70;
  MOFFS_16_32       = 71;

  REL_8             = 72;
  REL_16            = 73;
  REL_32            = 74;
  REL_16_32         = 75;

  PTR_16            = 76;
  PTR_32            = 77;
  PTR_16_32         = 78;

  M_PTR_16          = 79;
  M_PTR_32          = 80;
  M_PTR_64          = 81;
  M_PTR_16_32       = 82;

  ONE               = 83; # literally "1"
  REG_ST            = 84; # literally "st" string (top element of fpu register stack)
  REG_STI           = 85; # the i's from the top of the fpu register stack
  REG_ST1           = 86; # st(1)
  REG_ST2           = 87;
  REG_STI_M32       = 88;

  XMM               = 89;
  XMM_0             = 90;
  XMM_M_32          = 91;
  XMM_M_64          = 92;
  XMM_M_128         = 93;

  REG_CRN           = 94; # Control registers
  REG_DRN           = 95; # Debug registers

  MM                = 96;
  MM_M_64           = 97;
end

SEGMENTS_MAP = {
  "es" => Operands::SEG_ES,
  "ss" => Operands::SEG_SS,
  "ds" => Operands::SEG_DS,
  "cs" => Operands::SEG_CS,
  "fs" => Operands::SEG_FS,
  "gs" => Operands::SEG_GS,
  "sreg" => Operands::SEG_ALL
}

REGISTERS_MAP = {
  "al"  => Operands::REG_AL, 
  "cl"  => Operands::REG_CL, 
  "dl"  => Operands::REG_DL, 
  "bl"  => Operands::REG_BL, 
  "ah"  => Operands::REG_AH, 
  "ch"  => Operands::REG_CH, 
  "dh"  => Operands::REG_DH, 
  "bh"  => Operands::REG_BH, 
  "ax"  => Operands::REG_AX, 
  "cx"  => Operands::REG_CX, 
  "dx"  => Operands::REG_DX, 
  "bx"  => Operands::REG_BX, 
  "sp"  => Operands::REG_SP, 
  "bp"  => Operands::REG_BP, 
  "si"  => Operands::REG_SI, 
  "di"  => Operands::REG_DI, 
  "eax" => Operands::REG_EAX,  
  "ecx" => Operands::REG_ECX,
  "edx" => Operands::REG_EDX,
  "ebx" => Operands::REG_EBX,
  "esp" => Operands::REG_ESP,
  "ebp" => Operands::REG_EBP,
  "esi" => Operands::REG_ESI,
  "edi" => Operands::REG_EDI,
  "rax" => Operands::REG_RAX,
  "rcx" => Operands::REG_RCX,
  "rdx" => Operands::REG_RDX,
  "rbx" => Operands::REG_RBX,
  "rsp" => Operands::REG_RSP,
  "rbp" => Operands::REG_RBP,
  "rsi" => Operands::REG_RSI,
  "rdi" => Operands::REG_RDI,
  "crn" => Operands::REG_CRN,
  "drn" => Operands::REG_DRN,
}

NUM_MAP = {
  "1" => Operands::ONE
}

IMMEDIATES_MAP = {
  "imm8"      => Operands::IMM_8,
  "imm16"     => Operands::IMM_16,
  "imm16/32"  => Operands::IMM_16_32,
}

FPU_MAP = {
  "m80dec" => Operands::M_32,
  "m16int" => Operands::M_32,
  "m94/108" => Operands::M_32,
  "m64int" => Operands::M_32,
  "m64real" => Operands::M_32,
  "m80real" => Operands::M_32,
  "m32int" => Operands::M_32,
  "m14/28" => Operands::M_32,
  "m32real" => Operands::M_32,
  "sti/m32real" => Operands::REG_STI_M32, 
  "st" => Operands::REG_ST,
  "sti" => Operands::REG_STI,
  "st1" => Operands::REG_ST1,
  "st2" => Operands::REG_ST2
}

MEMORY_MAP = {
  "m"            => Operands::M_ALL,
  "m8"           => Operands::M_8,
  "m16"          => Operands::M_16,
  "m32"          => Operands::M_32,
  "m64"          => Operands::M_64,
  "m512"         => Operands::M_512,
  "m16/32"       => Operands::M_16_32,
  "m16/32&16/32" => Operands::M_16_32_AMP_16_32,
  "m128"         => Operands::M_128
}

RELATIVE_MAP = {
  "rel8"     => Operands::REL_8,
  "rel16"    => Operands::REL_16,
  "rel32"    => Operands::REL_32,
  "rel16/32" => Operands::REL_16_32
}

FAR_POINTER_MAP = {
  "ptr16:16"    => Operands::PTR_16,
  "ptr16:32"    => Operands::PTR_32,
  "ptr16:16/32" => Operands::PTR_16_32
}

FAR_POINTER_MEMORY_MAP = {
  "m16:16"    => Operands::M_PTR_16,
  "m16:32"    => Operands::M_PTR_32,
  "m16:64"    => Operands::M_PTR_64,
  "m16:16/32" => Operands::M_PTR_16_32
}

MEMORY_OFFSET_MAP = {
  "moffs8"     => Operands::MOFFS_8,
  "moffs16"    => Operands::MOFFS_16,
  "moffs32"    => Operands::MOFFS_32,
  "moffs16/32" => Operands::MOFFS_16_32
}

XMM_MAP = {
  "xmm"      => Operands::XMM,
  "xmm0"     => Operands::XMM_0,
  "xmm/m128" => Operands::XMM_M_128,
  "xmm/m64"  => Operands::XMM_M_64,
  "xmm/m32"  => Operands::XMM_M_32
}

MM_MAP = {
  "mm" => Operands::MM,
  "mm/m64" => Operands::MM_M_64
}

MODRM_MAP = {
  "r"        => Operands::R_ALL,
  "r/m"      => Operands::RM_ALL,
  "r8"       => Operands::R_8,
  "r16"      => Operands::R_16,
  "r32"      => Operands::R_32,
  "r16/32"   => Operands::R_16_32,
  "r/m8"     => Operands::RM_8,
  "r/m16"    => Operands::RM_16,
  "r/m32"    => Operands::RM_32,
  "r/m16/32" => Operands::RM_16_32
}

OPERANDS_MAP = {}.merge(IMMEDIATES_MAP)
                 .merge(MODRM_MAP)
                 .merge(REGISTERS_MAP)
                 .merge(SEGMENTS_MAP)
                 .merge(MEMORY_MAP)
                 .merge(RELATIVE_MAP)
                 .merge(FAR_POINTER_MAP)
                 .merge(MEMORY_OFFSET_MAP)
                 .merge(FAR_POINTER_MEMORY_MAP)
                 .merge(NUM_MAP)
                 .merge(FPU_MAP)
                 .merge(XMM_MAP)
                 .merge(MM_MAP)

class Instruction 
  def initialize(row)
    @prefix = row[0].content.strip.empty?? nil : row[0].content.strip
    @extended_opcode = row[1].content.strip.empty?? false : true 
    @primary_opcode = row[2].content.strip 
    @secondary_opcode = row[3].content.strip 
    @opcode_field = row[4].content.strip 
    @mnemonic = row[10].content.strip.downcase 
    @operand1 = row[11].content.strip.downcase 
    @operand2 = row[12].content.strip.downcase 
    @operand3 = row[13].content.strip.downcase 
    @operand4 = row[14].content.strip.downcase 
  end

  def set_operand()
    4.times do |i|
      operand =  instance_variable_get("@operand#{i+1}")
      if operand.empty?
        instance_variable_set("@operand#{i+1}", Operands::VOID)
        next
      end

      operand_to_set = OPERANDS_MAP[operand]
      return false if operand_to_set.nil?
      
      instance_variable_set("@operand#{i+1}", operand_to_set)
    end  
    return true 
  end
  
end

parsed = Nokogiri::HTML.parse(File.read("coder32.html"))

tables = parsed.xpath("//table")

regular_opcodes = tables[0]
extended_opcodes = tables[1]

#regular part
regular_rows = regular_opcodes.css("tbody")
regular_instructions = []

regular_rows.each do |row|
  instruction = Instruction.new(row.children.css("td"))
  unless instruction.set_operand
    puts "[regular] unexpected operands!"
    pp instruction 
    exit(false)
  end
  regular_instructions << instruction 
end

# extended part
extended_rows = extended_opcodes.css("tbody")
extended_instructions = []

extended_rows.each do |row|
  instruction = Instruction.new(row.children.css("td"))
  unless instruction.set_operand 
    puts "[extended] unexpected operands!"
    pp instruction 
    exit(false)
  end
  pp instruction
  extended_instructions << instruction
end
