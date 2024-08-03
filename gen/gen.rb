require "csv"

# some instructions cannot make use of the reg portion of the modr/m byte. 
# many of these instructions are "multiplexed" using this field, where a single opcode can refer to multiple instructions, and the reg field determines the instruction. 
# in opcode listings, these are specified by following the opcode with a slash (/) and a digit 0-7

# np => no prefix 

# flags 
module Flags 
  FLAGS_VOID                    = 0 << 0;
  FLAGS_MODRM                   = 1 << 0;
  FLAGS_CODE_OFFSET             = 1 << 1;
  FLAGS_IMMEDIATE               = 1 << 2;
  FLAGS_MODRM_REG_MULTIPLEXING  = 1 << 3;
  FLAGS_ST_FPU                  = 1 << 4;
  FLAGS_NO_MODIFIERS            = 1 << 5;
end

# prefix bytes
module Prefixes
  PREFIX_LOCK            = 0xF0            
  PREFIX_REPNE_Z         = 0xF2         
  PREFIX_REP_E_Z         = 0xF3         
  PREFIX_CS              = 0x2E              
  PREFIX_SS              = 0x36              
  PREFIX_DS              = 0x3E              
  PREFIX_ES              = 0x26              
  PREFIX_FS              = 0x64              
  PREFIX_GS              = 0x65              
  PREFIX_BNT             = 0x2E             
  PREFIX_BT              = 0x3E              
  PREFIX_OPSIZE_OVERRIDE = 0x66 
  PREFIX_ASZ_OVERRIDE    = 0x67    
end

PREFIXES = [Prefixes::PREFIX_LOCK,          
            Prefixes::PREFIX_REPNE_Z, 
            Prefixes::PREFIX_REP_E_Z,       
            Prefixes::PREFIX_CS,            
            Prefixes::PREFIX_SS,            
            Prefixes::PREFIX_DS,            
            Prefixes::PREFIX_ES,            
            Prefixes::PREFIX_FS,            
            Prefixes::PREFIX_GS,            
            Prefixes::PREFIX_BNT,           
            Prefixes::PREFIX_BT,            
            Prefixes::PREFIX_OPSIZE_OVERRIDE,
            Prefixes::PREFIX_ASZ_OVERRIDE] 

IMMEDIATES_MAP = {
  "imm8" => "IMM8",
  "imm16" => "IMM16",
  "imm32" => "IMM32",
  "imm64" => "IMM64",
}

SEGMENT_REGISTERS_MAP = {
  "ES" => "ES",
  "FS" => "FS",
  "GS" => "GS",
  "SS" => "SS",
  "DS" => "DS",
  "CS" => "CS"
}

REGISTERS_MAP = {
  "AL"  => "AL",
  "CL"  => "CL",
  "DL"  =>"DL",
  "BL"  => "BL",
  "AH"  =>"AH",
  "CH"  =>"CH",
  "DH"  =>"DH",
  "BH"  => "BH",
  "SPL" => "SPL",
  "BPL" => "BPL",
  "AX"  =>"AX",
  "CX"  =>"CX",
  "DX"  =>"DX",
  "BX"  =>"BX",
  "SP"  =>"SP",
  "BP"  =>"BP",
  "SI"  =>"SI",
  "DI"  =>"DI",
  "SIL" => "SIL",
  "DIL" => "DIL",
  "EAX" => "EAX",
  "ECX" =>"ECX",
  "EDX" =>"EDX",
  "EBX" =>"EBX",
  "ESP" =>"ESP",
  "EBP" =>"EBP",
  "ESI" =>"ESI",
  "EDI" => "EDI",
  "RAX" =>"RAX",
  "RCX" =>"RCX",
  "RDX" =>"RDX",
  "RBX" =>"RBX",
  "RSP" =>"RSP",
  "RBP" =>"RBP",
  "RSI" =>"RSI",
  "RDI" => "RDI",
}

MULTIPLEXED_MODRM_MAP = {

}

MODRM_MAP = {
  "ModRM:reg" => {
    "r8" => "MODRM_REG8",
    "r16" => "MODRM_REG16",
    "r32" => "MODRM_REG32"
  },

  "ModRM:r/m" => {
    "r/m8" => "MODRM_RM8",
    "r/m16" => "MODRM_RM16",
    "r/m32" => "MODRM_RM32"
  }
}

OPERANDS_MAP = {}.merge(REGISTERS_MAP)
                 .merge(IMMEDIATES_MAP)
                 .merge(MODRM_MAP)
                 .merge(SEGMENT_REGISTERS_MAP)
                 .merge(MULTIPLEXED_MODRM_MAP)

class Instruction 
  attr_accessor :instruction, :opcode, :valid_64, 
                :valid_32, :valid_16, :feature_flags, 
                :operand1, :operand2, :operand3, 
                :operand4, :no_prefix, :prefixes

  @@count = 0
  def initialize(row)
      @instruction    = row[0] 
      @opcode         = row[1] 
      @valid_64       = row[2] 
      @valid_32       = row[3] 
      @valid_16       = row[4] 
      @feature_flags  = row[5] 
      @operand1       = row[6] 
      @operand2       = row[7] 
      @operand3       = row[8] 
      @operand4       = row[9] 
      @no_prefix      = false
      @prefixes       = []
      @flags          = Flags::FLAGS_VOID 


      @@count         += 1
  end

  def count()
    return @@count
  end

  def set_operand(n, v)
    instance_variable_set("@operand#{n}", v)
  end

  def get_operand(n)
    instance_variable_get("@operand#{n}")
  end

  def set_flags()
    case @opcode 
      when /\/r/
        # modrm
        @flags |= Flags::FLAGS_MODRM 
      when /\/\d/
        #  digit between 0 and 7 indicates that the modr/m byte of the instruction uses only the r/m (register or memory) operand. 
        #  the reg field contains the digit that provides an extension to the instruction's opcode.
        #digit = @opcode.scan(/\/\d/).first.delete("/")
        @flags |= Flags::FLAGS_MODRM_REG_MULTIPLEXING
      when /ib/, /iw/, /id/, /io/
        # immediate 
        @flags |= Flags::FLAGS_IMMEDIATE
      when /c./
        # code offset
        @flags |= Flags::FLAGS_CODE_OFFSET
      when /\+i/
        # number used in floating-point instructions when one of the operands is st(i) from the fpu register stack.
        @flags |= Flags::FLAGS_ST_FPU 
      else 
        @flags |= Flags::FLAGS_NO_MODIFIERS
    end
  end

  def has_flags(flags)
   return ((@flags & flags) > 0) 
  end

  def generate_operand(el, existing_operand)
    # for debugging
    printf("searching for %s\n", el)
    if has_flags(Flags::FLAGS_MODRM)
      # modrm
      if existing_operand.include?("ModRM:reg")
        return OPERANDS_MAP["ModRM:reg"][el]
      elsif existing_operand.include?("ModRM:r/m")
        return OPERANDS_MAP["ModRM:r/m"][el]
      else 
        # ???????
        return nil
      end

    elsif has_flags(Flags::FLAGS_MODRM_REG_MULTIPLEXING)

    else 
      return OPERANDS_MAP[el]
    end
  end
end

csv = CSV.read("x86.csv")
instructions = []

csv.each do |row|
  # removing sse,avx,etc (for now!)
 if row[5].nil? || row[5].empty?
    instructions << Instruction.new(row)
  end
end

# replace rexes with appropriate bytes

instructions.map! do |instruction| 

  # REX => 0x40 to 0x4f
  # REX.W => 0x48 to 0x4f
  # REX.R => 0x44 to 0x4f
  
  case instruction.opcode 
  when /REX\.W/
   (0x48..0x4f).to_a.map do |prefix|
     temp_instr = Instruction.new([instruction.instruction, 
                                  instruction.opcode.sub(/REX\.W\s\+|REX\.W/, prefix.to_s(16).upcase),
                                  instruction.valid_64, 
                                  instruction.valid_32, 
                                  instruction.valid_16, 
                                  instruction.feature_flags,
                                  instruction.operand1,
                                  instruction.operand2,
                                  instruction.operand3,
                                  instruction.operand4])
   end
  when /REX\.R/
   (0x44..0x4f).to_a.map do |prefix| 
     temp_instr = Instruction.new([instruction.instruction, 
                                  instruction.opcode.sub(/REX\.R\s\+|REX\.R/, prefix.to_s(16).upcase),
                                  instruction.valid_64, 
                                  instruction.valid_32, 
                                  instruction.valid_16, 
                                  instruction.feature_flags,
                                  instruction.operand1,
                                  instruction.operand2,
                                  instruction.operand3,
                                  instruction.operand4])
   end
  when /REX/
   (0x40..0x4f).to_a.map do |prefix|
     temp_instr = Instruction.new([instruction.instruction, 
                                  instruction.opcode.sub(/REX\s\+|REX/, prefix.to_s(16).upcase),
                                  instruction.valid_64, 
                                  instruction.valid_32, 
                                  instruction.valid_16, 
                                  instruction.feature_flags,
                                  instruction.operand1,
                                  instruction.operand2,
                                  instruction.operand3,
                                  instruction.operand4])
   end
  else
    instruction
  end 
end.flatten!


# delete NP (No prefix)

instructions.each do |instruction| 
  if instruction.opcode.include?("NP")
    instruction.opcode.sub!("NP ", "")
    instruction.no_prefix = true
  end
end


# deleting duplicates that follow ST(i)

instructions.each.with_index do |instruction, i|
  if instruction.opcode.include?("+i")
    to_find = instruction.opcode.sub("+i", "").split(" ")
    to_find[-1] = (to_find[-1].to_i(16)+1).to_s(16).upcase
    to_find = to_find.join(" ")

    instructions.delete_if{|row_to_find| row_to_find.opcode == to_find}
  end
end

# expand all instructions with ST(i)

instructions.map! do |instruction|

  if instruction.opcode.include?("+i")
    (0..7).to_a.map do |i|
      to_find = instruction.opcode.sub("+i", "").split(" ")
      to_find[-1] = (to_find[-1].to_i(16)+i).to_s(16).upcase
      to_find = to_find.join(" ")
      Instruction.new([
        instruction.instruction.sub("i", i.to_s),
        to_find,
        instruction.valid_64,
        instruction.valid_32,
        instruction.valid_16,
        instruction.feature_flags,
        instruction.operand1,
        instruction.operand2,
        instruction.operand3,
        instruction.operand4
      ])
    end
  else 
    instruction
  end
end.flatten!

# expand all instructions with +rb, +rw, +rd, +ro

instructions.filter!{|i| i.opcode.include?("+r")} # remove after expanding PLS

#instructions.map! do |instruction|
#  if instruction.opcode.include?("+r")
#    
#    if instruction 
#  else 
#    instruction
#  end
#end

  pp instructions

return 

# remove prefixes and set them as required attributes.
# because when we will parse the instruction inside our c code, 
# all prefix bytes that were eaten are supposed to be checked 
# according to this required attribute.

instructions.each do |instruction|
  first_byte = instruction.opcode.split(" ")
  if first_byte.size < 2
    instructions.delete(instruction)
    next 
  end
  first_byte = first_byte.first.to_i(16)
  if PREFIXES.inc66 0f c8lude?(first_byte) 
    instruction.prefixes << first_byte 
    instruction.opcode = instruction.opcode[3..-1]
  end
end

# remove spaces between operands

instructions.each do |instruction|
  if(instruction.instruction.count(" ") > 1)
    dirty_portion = instruction.instruction.index(" ")+1
    instruction.instruction[dirty_portion..-1] = instruction.instruction[dirty_portion..-1].delete(" ")
  end
end


# sort them by first operand

instructions.sort_by!{|instruction|
  instruction.opcode.split(" ").first.to_i(16)
}

# set flags
instructions.each do |instruction|
  instruction.set_flags()
end

# fix operands
# use Operand class to set :operand1, :operand2, ...

instructions.each do |instruction|
  splitted_instruction = instruction.instruction.split(" ")
  if splitted_instruction.size > 1
    # just throw the mnemonic part away
    splitted_instruction.shift
    splitted_instruction.each do |portion|
      splitted_portion = portion.split(",")
      if splitted_portion.size > 1
        # more then one operand
        splitted_portion.each.with_index do |el, i|
          operand = instruction.generate_operand(
            el,
            instruction.get_operand(i+1)
          )
          if operand.nil? 
            # for debugging
            printf("we are at: %d/%d\n", instructions.index(instruction), instructions.size)
            printf("el: %s\n", el)
            printf("splitted_portion: %s\n", splitted_portion)
            printf("splitted_instruction: %s\n", splitted_instruction)
            printf("unhandled portion: %s\n", portion)
            puts
            pp(instruction)
            exit(false)
          end
          instruction.set_operand(i+1, operand)
          # remove operand
          instruction.instruction.sub!(el, "")
        end
        # remove comma
        instruction.instruction.sub!(",", "") 
        # remove spaces
        instruction.instruction.strip!
      else 
        operand = instruction.generate_operand(
          splitted_instruction.first,
          instruction.get_operand(1)
        )
        if operand.nil? 
          # for debugging
          printf("we are at: %d/%d\n", instructions.index(instruction), instructions.size)
          printf("splitted_portion: %s\n", splitted_portion)
          printf("splitted_instruction: %s\n", splitted_instruction)
          puts
          pp(instruction)
          exit(false)
        end
        instruction.operand1 = operand 
        # remove operand
        instruction.instruction.sub!(splitted_instruction.first, "")
        # remove spaces
        instruction.instruction.strip!
      end
        pp instruction
    end
  end
end


#return 
#
#
#instructions.filter! do |instruction|
#  instruction.opcode.include?("/r") && instruction.operand1.include?("r/m") && !instruction.instruction.include?("r/m")
#end
#puts instructions.size
#
#pp instructions 

# downcase em 
#instructions.each do |instruction|
#  instruction.instruction.downcase! 
#end

# group_by 
# in the end!
