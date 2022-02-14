// Parent Class Specification for Storing and Manipulating Hex Instructions
// into Assembly
//
// Author: Brian Horner
// Edit History:
// 2/6/2022 Initial Version
// 2/6/2022 Added Constructor, data members, get, set and virtual functions

#ifndef InstructionSet_H
#define InstructionSet_H


class InstructionSet {

public:

    // --- Constructors ---
    InstructionSet(unsigned int hexInstruction, unsigned int currentAddress);


    // --- Destructor ---
    virtual ~InstructionSet();

private:
    // --- Set Functions - Private?? ---
    // Private? Needs implementation of checks
    void setHexInstruction(unsigned int Instruction);
    void setAddress(unsigned int address);

    // --- Get Functions - Public ---
public:
    unsigned int getHexInstruction() const;
    unsigned int getAddress() const;


    // --- Virtual Write Function ---
    virtual void writeToTerminal() const;

    // --- Data Members ---
private:
    unsigned int hexInstruction{};
    unsigned int address{};

};


#endif
