require "csv"

# some instructions cannot make use of the reg portion of the modr/m byte. 
# many of these instructions are "multiplexed" using this field, where a single opcode can refer to multiple instructions, and the reg field determines the instruction. 
# in opcode listings, these are specified by following the opcode with a slash (/) and a digit 0-7

# np => no prefix 

# prefix bytes
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

PREFIXES = [PREFIX_LOCK,          
            PREFIX_REPNE_Z, 
            PREFIX_REP_E_Z,       
            PREFIX_CS,            
            PREFIX_SS,            
            PREFIX_DS,            
            PREFIX_ES,            
            PREFIX_FS,            
            PREFIX_GS,            
            PREFIX_BNT,           
            PREFIX_BT,            
            PREFIX_OPSIZE_OVERRIDE,
            PREFIX_ASZ_OVERRIDE] 

OPERAND_MAP = {
  "imm8" => "IMM8",
  "imm16" => "IMM16",
  "imm32" => "IMM32",
  "imm64" => "IMM64",
  "al"  => "al",
  "cl"  => "cl",
  "dl"  =>"dl",
  "bl"  => "bl",
  "ah"  =>"ah",
  "ch"  =>"ch",
  "dh"  =>"dh",
  "bh"  => "bh",
  "spl" => "spl",
  "bpl" => "bpl",
  "ax"  =>"ax",
  "cx"  =>"cx",
  "dx"  =>"dx",
  "bx"  =>"bx",
  "sp"  =>"sp",
  "bp"  =>"bp",
  "si"  =>"si",
  "di"  =>"di",
  "sil" => "sil",
  "dil" => "dil",
  "eax" => "eax",
  "ecx" =>"ecx",
  "edx" =>"edx",
  "ebx" =>"ebx",
  "esp" =>"esp",
  "ebp" =>"ebp",
  "esi" =>"esi",
  "edi" => "edi",
  "rax" =>"rax",
  "rcx" =>"rcx",
  "rdx" =>"rdx",
  "rbx" =>"rbx",
  "rsp" =>"rsp",
  "rbp" =>"rbp",
  "rsi" =>"rsi",
  "rdi" => "rdi",
  "r/m8" => "MODRM_RM8",
  "r/m16" => "MODRM_RM16",
  "r/m32" => "MODRM_RM32",
  "r/m64" => "MODRM_RM64",
  "r8b" =>"r8b",
  "r8w" =>"r8w",
  "r8d" =>"r8d",
  "r8" =>"r8",
  "r9b" =>"r9b",
  "r9w" =>"r9w",
  "r9d" =>"r9d",
  "r9" =>"r9",
  "r10b" =>"r10b",
  "r10w" =>"r10w",
  "r10d" =>"r10d",
  "r10" =>"r10",
  "r11b" =>"r11b",
  "r11w" =>"r11w",
  "r11d" =>"r11d",
  "r11" =>"r11",
  "r12b" =>"r12b",
  "r12w" =>"r12w",
  "r12d" =>"r12d",
  "r12" =>"r12",
  "r13b" =>"r13b",
  "r13w" =>"r13w",
  "r13d" =>"r13d",
  "r13" =>"r13",
  "r14b" =>"r14b",
  "r14w" =>"r14w",
  "r14d" =>"r14d",
  "r14" =>"r14",
  "r15b" =>"r15b",
  "r15w" =>"r15w",
  "r15d" =>"r15d",
  "r15" =>"r15",
  "r16" => "r16",  # One of the word general-purpose registers: AX, CX, DX, BX, SP, BP, SI, DI
  "r32" => "r32",  # One of the doubleword general-purpose registers: EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI
  "r64" => "r64",  # One of the quadword general-purpose registers: RAX, RBX, RCX, RDX, RDI, RSI, RBP, RSP, R8–R15
}



















class Instruction 
  attr_accessor :instruction, :opcode, :valid_64, :valid_32, :valid_16, :feature_flags, :operand1, :operand2, :operand3, :operand4, :no_prefix, :prefixes

  @@count = 0
  def initialize(row)
      @instruction = row[0] 
      @opcode = row[1] 
      @valid_64 = row[2] 
      @valid_32 = row[3] 
      @valid_16 = row[4] 
      @feature_flags = row[5] 
      @operand1 = row[6] 
      @operand2 = row[7] 
      @operand3 = row[8] 
      @operand4 = row[9] 
      @no_prefix = false
      @prefixes  = []

      @@count += 1
  end

  def count()
    return @@count
  end
  def set_operand(n, v)
    instance_variable_set("@operand#{n}", v)
  end
end

class Operand 
  # set once again all of the operands according to the instruction and opcode flags 
  def initialize(instruction, opcode) 
    @instruction = instruction 
    @opcode = opcode
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
  if PREFIXES.include?(first_byte) 
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


# downcase em 
instructions.each do |instruction|
  instruction.instruction.downcase! 
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
          operand = OPERAND_MAP[el]
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
          instruction.set_operand(i+1, OPERAND_MAP[el])
        end
      else 
        instruction.operand1 = portion
      end
#      case portion 
#        when /imm/
#          if splitted_portion.size > 1
#            # more then one operand
#            splitted_portion.each.with_index do |el, i|
#              instruction.set_operand(i+1, OPERAND_MAP[el])
#            end
#          else 
#            instruction.operand1 = portion
#          end 
#          pp instruction
#        when /r8/
#        else 
#          # for debugging
#          printf("splitted_portion: %s\n", splitted_portion)
#          printf("splitted_instruction: %s\n", splitted_instruction)
#          printf("unhandled portion: %s\n", portion)
#          puts
#          pp(instruction)
#          exit(false)
#      end
    end
  end
end

pp instructions 


# group_by 
# in the end!
