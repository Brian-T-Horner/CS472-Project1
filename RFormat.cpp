// Class Implementation for Storing and Manipulating R Format Instructions
// Child Class of InstructionSet

// Author: Brian Horner
// Edit History:
// 2/6/2022 Initial Version
// 2/6/2022 Added Initial Methods
// 2/13/2022 Fixed Bitwise Shifts

// Standard Library Includes
#include <iostream>
#include <bitset>
#include <map>

// User Built Includes
#include "RFormat.h"

// Map for Function Codes
std::map<unsigned int, std::string> FuncCodeDict = {
        {0b000000, "sll"},      {0b000010, "srl"},
        {0b000011, "sra"},      {0b000100, "sllv"},
        {0b000110, "srlv"},     {0b000111, "srav"},
        {0b001000, "jr"},       {0b001001, "jalr"},
        {0b001010, "movz"},     {0b001011, "movn"},
        {0b001100, "syscall"},  {0b001101, "break"},
        {0b001111, "sync"},     {0b010000, "mfhi"},
        {0b010001, "mthi"},     {0b010010, "mflo"},
        {0b010011, "mtlo"},     {0b011000, "multi"},
        {0b011001, "multiu"},   {0b011010, "div"},
        {0b011011, "divu"},     {0b100000, "add"},
        {0b100001, "addu"},     {0b100010, "sub"},
        {0b100011, "subu"},     {0b100100, "and"},
        {0b100101, "or"},       {0b100110, "xor"},
        {0b100111, "nor"},      {0b101010, "slt"},
        {0b101011, "sltu"},     {0b110000, "tge"},
        {0b110001, "tgeu"},     {0b110010, "tlt"},
        {0b110011, "tltu"},     {0b110100, "teq"},
        {0b110110, "tne"},
        };


// --- Constructor ---
RFormat::RFormat(unsigned int hexInstruction, unsigned int address):
InstructionSet
(hexInstruction, address) {

    calcOPCode();
    calcInstructionSet();
    writeToTerminal();

}

// --- Destructor ---
RFormat::~RFormat() {};

// --- Calc Instructions Funcs ---
void RFormat::calcOPCode() {
    unsigned int OpCodeMask = 0b111111<<26;
    this->OpCode = (OpCodeMask & getHexInstruction())>>26;
}

void RFormat::calcInstructionSet() {
    unsigned int MemMask = 0b11111;
    unsigned int FuncMask = 0b111111;
    unsigned int MaskShift{32};
    for(unsigned int i{0}; i<=5; i++){
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
                this->memory2 = ((MemMask<<MaskShift)&getHexInstruction())
                        >>MaskShift;
                break;
            case 3:
                MaskShift -=5;
                this->destReg = ((MemMask<<MaskShift)& getHexInstruction())
                        >>MaskShift;
                break;
            case 4:
                MaskShift-=5;
                break;
            case 5:
                MaskShift -=6;
                this->funcCode = (((FuncMask<<MaskShift)&getHexInstruction())
                        >>MaskShift);
                break;
            default:
                std::cout << "Error should not reach here." <<std::endl;
                break;
        }
    }
//    std::cout << "OPCode " <<std::bitset<6>(this->OpCode) << ".\n";
//    std::cout << "Mem1 " <<std::bitset<5>(this->memory1) << ".\n";
//    std::cout << "Mem2 " <<std::bitset<5>(this->memory2) << ".\n";
//    std::cout << "Dest Reg " <<std::bitset<5>(this->destReg) << ".\n";
//    std::cout <<"funcCode " <<std::bitset<6>(this->funcCode) << ".\n";

}
// --- Set Functions ---


// --- Get Functions ---
// !! Need to make return in hex !!
unsigned int RFormat::getMemory1() const {return this->memory1;}
unsigned int RFormat::getMemory2() const {return this->memory2;}
unsigned int RFormat::getDestReg() const {return this->destReg;}
unsigned int RFormat::getFuncCode() const {return this->funcCode;}

// -- Virtual Write and Print Functions

void RFormat::writeToTerminal() const {
    InstructionSet::writeToTerminal();
    std::cout <<  FuncCodeDict.at(this->funcCode) <<" $" <<this->destReg <<
    ", $" <<this->memory1 << ", $" <<memory2 <<std::endl;
}