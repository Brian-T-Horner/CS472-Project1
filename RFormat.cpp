// Class Implementation for Storing and Manipulating R Format Instructions
// Child Class of InstructionSet

// Author: Brian Horner
// Edit History:
// 2/6/2022 Initial Version

// Standard Library Includes
#include <iostream>
#include <bitset>

// User Built Includes
#include "RFormat.h"

// --- Constructor ---
RFormat::RFormat(int hexInstruction, unsigned int address): InstructionSet
(hexInstruction, address) {

    // Calc calcs here
}

// --- Calc Instructions Funcs ---
void RFormat::calcOPCode() {
    unsigned int OpCodeMask = 0b111111<<26;
    OpCode = (OpCodeMask & getHexInstruction())>>26;
}

void RFormat::calcInstructionSet() {
    unsigned int MemMask = 0b11111;
    unsigned int OpFuncMask = 0b111111;
    unsigned int MaskShift{26};
    for(unsigned int i{0}; i<=5; i++){
        MaskShift -=5;
        switch(i){
            case 0 :
                MaskShift -=1;
                this->OpCode = (((OpFuncMask<<MaskShift)&getHexInstruction())
                        >>MaskShift);
                MaskShift +=1;
                break;
            case 1:
                this->memory1 = ((MemMask<<MaskShift)&getHexInstruction())
                        >>MaskShift;
                break;
            case 2:
                this->memory2 = ((MemMask<<MaskShift)&getHexInstruction())
                        >>MaskShift;
                break;
            case 3:
                this->destReg = ((MemMask<<MaskShift)& getHexInstruction())
                        >>MaskShift;
                break;
            case 4:
                break;
            case 5:
                MaskShift -=1;
                this->funcCode = (((OpFuncMask<<MaskShift)&getHexInstruction())
                        >>MaskShift);
                MaskShift +=1;
                break;
            default:
                std::cout << "Error should not reach here." <<std::endl;
                break;
        }
    }
    std::cout << "OPCode " <<std::bitset<6>(this->OpCode) << ".\n";
    std::cout << "Mem1 " <<std::bitset<5>(this->memory1) << ".\n";
    std::cout << "Mem2 " <<std::bitset<5>(this->memory2) << ".\n";
    std::cout << "Dest Reg " <<std::bitset<5>(this->destReg) << ".\n";
    std::cout <<"funcCode " <<std::bitset<6>(this->funcCode) << ".\n";
}
// --- Set Functions ---

// --- Get Functions ---

// -- Virtual Write and Print Functions