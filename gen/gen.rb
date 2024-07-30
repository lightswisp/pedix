require "csv"

csv = CSV.read("test.csv")

csv.each do |row|
  instruction, opcode = row
end


