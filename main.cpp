// CS472 Project 1 - MIPS Disassembler
//
// Author: Brian Horner
// Edit History:
// 2/5/2022 - Initial Version and Establishing Git Repo
// 2/5/2022 -

// Standard Library Includes
#include <iostream>
#include <bitset>
#include <map>

// User Built Includes
#include "InstructionSet.h"
#include "RFormat.h"
//#include "MIPSInstructionMaps.h"

std::bitset<6> CalcOpCode(int originalHex); //Calculates OP Code
unsigned int CalcRFormat(int OriginalHex); //Calculates R Format Instruction
char CalcInstructionFormat(int OriginalHex); // Calcs the instruction format

unsigned int startMem{0x9A040};

int main() {


 int test2 = 0x022DA822;

    std::cout << CalcOpCode(test2)<<std::endl;
    CalcRFormat(test2);
    std::cout << CalcInstructionFormat(test2);
    return 0;
    RFormat test1;
}


// Start of checks
char CalcInstructionFormat(int OriginalHex){
    // Calcs the instruction format
    std::bitset<6> OpCode = CalcOpCode(OriginalHex);
    if (OpCode == 0){
        return 'R';
    }else{
        return 'I';
    }
}



std::bitset<6> CalcOpCode(int originalHex){
    // Calculates the OP Code
    unsigned int OpCodeMask = 0b111111<<26;
    unsigned int OpCode = OpCodeMask & originalHex;
    return std::bitset<6>(OpCode >> 26);

}

// If Op Code equals 000000 go here
unsigned int CalcRFormat(int OriginalHex){
    //Calculates the R format instructions
    unsigned int MemMask = 0b11111;
    unsigned int FuncMask = 0b111111;
    int MaskShift{26};
    for(unsigned int i{0}; i<5; i++){
        MaskShift-=5;
        if (i < 3){
            std::cout << i << std::endl;
            std::cout << (std::bitset<5>(((MemMask<<MaskShift) & OriginalHex)
            >>MaskShift))
            <<std::endl;
        }else if (i>3){
            MaskShift-=1;
            std::cout << i <<std::endl;
            std::cout << (std::bitset<6>(((FuncMask<<MaskShift)&OriginalHex)
            >>MaskShift))<<std::endl;
        }
    }
}

