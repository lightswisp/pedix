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

csv.each{|row|
  # removing sse,avx,etc (for now!)
  if row[5].nil? || row[5].empty?
    instructions << Instruction.new(row)
  end
}


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
instructions.each.with_index{|instruction, i|
  if instruction.opcode.include?("+i")
    to_find = instruction.opcode.sub("+i", "").split(" ")
    to_find[-1] = (to_find[-1].to_i(16)+1).to_s(16).upcase
    to_find = to_find.join(" ")

    instructions.delete_if{|row_to_find| row_to_find.opcode == to_find}
  end
}

# remove prefixes and set them as required attributes.
# because when we will parse the instruction inside our c code, 
# all prefix bytes that were eaten are supposed to be checked 
# according to this required attribute.

instructions.each{|instruction|
  first_byte = instruction.opcode.split(" ")
  next if first_byte.size < 2
  first_byte = first_byte.first.to_i(16)
  if PREFIXES.include?(first_byte) 
    instruction.prefixes << first_byte 
    instruction.opcode = instruction.opcode[3..-1]
  end
}

pp instructions

# fix operands
# use Operand class to set :operand1, :operand2, ...

#instructions.filter! do |instruction|
#  ((instruction.operand1.nil?   ||
#  instruction.operand1.empty?   ||
#  instruction.operand1 == "NA") &&
#  instruction.instruction.include?(" ") 
#  )
#end 


