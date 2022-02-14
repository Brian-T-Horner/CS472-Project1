// Parent Class Implementation for Storing and Manipulating Hex Instructions
// into Assembly
//
// Author: Brian Horner
// Edit History:
// 2/6/2022 Initial Version
// 2/6/2022

// Standard Library Includes
#include <iostream>

// User Built Includes
#include "InstructionSet.h"

// --- Constructors ---
InstructionSet::InstructionSet(int64_t hexInstruction,
                               unsigned int currentAddress) {
    //Might cause a problem with conversion?
    this->address = currentAddress;
    this->hexInstruction = hexInstruction;
}


// --- Get Functions ---
unsigned int InstructionSet::getAddress() const {return address;}
int64_t InstructionSet::getHexInstruction() const {return hexInstruction;}

// --- Set Functions ---
void InstructionSet::setHexInstruction(int64_t instruction) {
    // Needs implementation of checks
    this-> hexInstruction = instruction;
}

void InstructionSet::setAddress(unsigned int address) {
    // Needs implementation of checks
    this->address = address;
}

// --- Virtual Functions ---
void InstructionSet::writeToTerminal() const {
    std::cout << std::hex << std::uppercase<< address <<
    std::nouppercase<<std::dec<< " ";
}


// --- Destructor ---
InstructionSet::~InstructionSet() {}