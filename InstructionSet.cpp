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

// --- Constructor ---
InstructionSet::InstructionSet(int hexInstruction,
                               unsigned int currentAddress) {
    //Might cause a problem with conversion?
    this->address = currentAddress;
    this->hexInstruction = hexInstruction;
}

// --- Get Functions ---
unsigned int InstructionSet::getAddress() const {return address;}
int InstructionSet::getHexInstruction() const {return hexInstruction;}

// --- Set Functions ---
void InstructionSet::setHexInstruction(int Instruction) {
    // Needs implementation
}

void InstructionSet::setAddress(unsigned int address) {
    // Needs implementation
}

// --- Virtual Functions ---
void InstructionSet::writeToTerminal() const {
    std::cout << address << " ";
}

void InstructionSet::writeToFile(std::string filePath) const {
    // Needs implementation
}
// --- Destructor ---
InstructionSet::~InstructionSet() {}