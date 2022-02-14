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
#include "IFormat.h"


std::bitset<6> CalcOpCode(int64_t originalHex); //Calculates OP Code
char CalcInstructionFormat(int64_t OriginalHex); // Calcs the instruction format



int64_t OPCODES[11] = {0x032BA020, 0x8CE90014, 0x12A90003, 0x022DA822,
                     0xADB30020, 0x02697824, 0xAE8FFFF4, 0x018C6020,
                     0x02A4A825, 0x158FFFF7, 0x8ECDFFF0};

int main() {

    unsigned int currentMem{0x9A040};

    int OPCodeSize = sizeof(OPCODES)/sizeof(OPCODES[0]);
    for(int i{0}; i < OPCodeSize; i++){
        int64_t currentCode = OPCODES[i];
        if (CalcInstructionFormat(currentCode) == 'R'){
            RFormat (OPCODES[i], currentMem);
        }else{
            IFormat(OPCODES[i], currentMem);
        }
        currentMem = currentMem +4;
    }
}


// Start of checks
char CalcInstructionFormat(int64_t OriginalHex){
    // Calcs the instruction format
    std::bitset<6> OpCode = CalcOpCode(OriginalHex);
    if (OpCode == 0){
        return 'R';
    }else{
        return 'I';
    }
}



std::bitset<6> CalcOpCode(int64_t originalHex){
    // Calculates the OP Code
    unsigned int OpCodeMask = 0b111111<<26;
    unsigned int OpCode = OpCodeMask & originalHex;
    return std::bitset<6>(OpCode >> 26);
}


