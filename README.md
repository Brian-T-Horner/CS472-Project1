Boston University CS - 472 Project 2

MIPS Disasssembler written in C++

--- Project Requirments ---

Your project is to write a partial disassembler for MIPS instructions. That is, your input will be the 32-bit
machine instructions that a compiler or assembler produces. Your program then figures out what the
original source instructions were that created those 32-bit machine instructions and outputs them. The
possible source instructions that you must be able to disassemble are: add, sub, and, or, slt, lw, sw, beq,
bne. Ignore all other MIPS instructions.
The specific machine instructions that you will disassemble (one after another in this exact order) are:
0x032BA020, 0x8CE90014, 0x12A90003, 0x022DA822, 0xADB30020, 0x02697824, 0xAE8FFFF4,
0x018C6020, 0x02A4A825, 0x158FFFF7, 0x8ECDFFF0
That is, the above 32-bit instructions will be the input to your program. (Eight hex digits are 32 binary
bits.) Feel free to embed them in the program itself so you can avoid typing them in each time. Your
program will then analyze a 32-bit instruction and figure out what the opcode, register operands and other
fields in the instruction are and then print out the assembly language instruction that produced it. Assume
that the first instruction begins at address hex 9A040 and the rest follow right after that one. You must
output the address along with the instruction.
For example, if your program determines that the first 32-bit machine instruction above is the instruction lw
$10, 12 ($20) (it isn't, but if it were) then your output for that instruction would be:
9A040 lw $10, 12 ($20)
You'll then go on and do the next 32-bit instruction, specifying its address in hex (the address for an
instruction immediately following one at 9A040) and what instruction caused those 32-bits. The
instruction should show the correct syntax so that an assembler could correctly evaluate it (with the
exception of the branch instruction detailed below). Output the numerical registers (e.g., $7, $0) as opposed
to the symbolic descriptions (e.g., $s3, $t1
Show addresses in hex. All other values should be in decimal, which is what an assembler defaults to. For
any load or store instructions, show the offset value as a signed decimal number.


--- Notes ---

