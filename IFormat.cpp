// Class Implementation for Storing and Manipulating I Format Instructions
// Child Class of InstructionSet

// Author: Brian Horner
// Edit History:
// 2/13/2022 Initial Version
// 2/13/2022 Added calc, constructor and get funcs

// Standard Library Includes
#include <iostream>
#include <bitset>
#include <map>

// User Built Includes
#include "IFormat.h"

// Map for opcodes
std::map<unsigned int, std::string> OPCodeDict{
    {0b000000, "Error"},    {0b000010, "j"},
    {0b000011, "jal"},      {0b000100, "beq"},
    {0b000101, "bne"},      {0b000110, "blez"},
    {0b000111, "bgtz"},     {0b001000, "addi"},
    {0b001001, "addiu"},    {0b001010, "siti"},
    {0b001011, "sltiu"},    {0b001100, "andi"},
    {0b001101, "ori"},      {0b001110, "xori"},
    {0b001111, "lui"},      {0b100000, "lb"},
    {0b100001, "lh"},       {0b100010, "lwl"},
    {0b100011, "lw"},       {0b100100, "lbu"},
    {0b100101, "lhu"},      {0b100110, "lwr"},
    {0b101000, "sb"},       {0b101001, "sh"},
    {0b101010, "swl"},      {0b101011, "sw"},
    {0b101110, "swr"},      {0b101111, "cache"},
    {0b110000, "li"},       {0b110001, "lwc1"},
    {0b110010, "lwc2"},     {0b110011, "pref"},
    {0b110101, "idc1"},     {0b110110, "idc2"},
    {0b111000, "sc"},       {0b111001, "swc1"},
    {0b111010, "swc2"},     {0b111101, "sdc1"},
    {0b111110, "sdc2"},
    };

unsigned int branches[2] = {0b000100, 0b000101}; // 2 more????

// --- Constructor ---
IFormat::IFormat(int64_t hexInstruction, unsigned int address): InstructionSet
(hexInstruction, address) {

    calcOPCode();
    boolBranch();
    calcInstructionSet();
    if (this->branchYesOrNo){
        calcBranch();
    }
    writeToTerminal();
}

// --- Destructor ---
IFormat::~IFormat() {};

// --- Calc Instructions Funcs ---

void IFormat::calcOPCode() {
    unsigned int OpCodeMask = 0b111111<<26;
    this->OpCode = (OpCodeMask & getHexInstruction())>>26;
}

void IFormat::boolBranch() {
    if(this->OpCode == branches[0] || this->OpCode == branches[1]){
        branchYesOrNo = true;
    }
}

void IFormat::calcInstructionSet() {
        unsigned int MemMask = 0b11111;
        unsigned int FuncMask = 0b1111111111111111;
        unsigned int MaskShift{32};
        for(unsigned int i{0}; i<4; i++){
            switch(i){
                case 0 :
                    MaskShift -= 6;
                    break;
                case 1:
                    MaskShift -= 5;
                    this->memory1 = ((MemMask<<MaskShift)&getHexInstruction())
                            >>MaskShift;
                    break;
                case 2:
                    MaskShift -=5;
                    this->destReg = ((MemMask<<MaskShift)&getHexInstruction())
                            >>MaskShift;
                    break;
                case 3:
                    MaskShift -=16;
                    this->offset = ((MemMask<<MaskShift)& getHexInstruction())
                            >>MaskShift;
                    break;
                default:
                    std::cout << "Error should not reach here." <<std::endl;
                    break;
            }
        }
}

void IFormat::calcBranch() {
    unsigned int startBranchAddy = this->getAddress() + 4;
    signed short correctOffset = offset << 2;
    branchMemory = correctOffset + startBranchAddy;

//    std::cout << "Start Branch Addy " <<std::hex<<std::uppercase<<
//    startBranchAddy <<std::dec<<std::nouppercase
//    <<std::endl;
//    std::cout << "Original Offset " <<this->offset <<std::endl;
//    std::cout << "Correct Offset " <<correctOffset <<std::endl;
}


// --- Set Functions ---

// --- Get Functions ---
unsigned int IFormat::getOpCode() const {return this->OpCode;}
unsigned int IFormat::getMemory1() const {return this->memory1;}
unsigned int IFormat::getDestReg() const {return this->destReg;}
signed short IFormat::getOffset() const {return this->offset;}
unsigned int IFormat::getBranchMemory() const {return this->branchMemory;}

// --- Virtual Print Function ---
void IFormat::writeToTerminal() const {
    InstructionSet::writeToTerminal();
    if (this->branchYesOrNo){
        std::cout << OPCodeDict.at(this->OpCode) << " $" <<this->destReg <<
        ", $"<<this->memory1 << " address " <<std::hex<<std::uppercase <<
        branchMemory<< std::dec <<std::nouppercase<<
        std::endl;
    }else{
    std::cout << OPCodeDict.at(this->OpCode) << " $" <<this->destReg <<
    ", "<<this->offset << "($" <<this->memory1 << ")"<<std::endl;
}
}
