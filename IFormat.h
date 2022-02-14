// Class Implementation for Storing and Manipulating I Format Instructions
// Child Class of InstructionSet

// Author: Brian Horner
// Edit History:
// 2/13/2022 Initial Version

#ifndef IFormat_H
#define IFormat_H

// Standard Library Includes

// User Built Includes
#include "InstructionSet.h"


class IFormat:public InstructionSet {
public:
    // --- Constructor ---
    IFormat(unsigned int hexInstruction, unsigned int address);

    // --- Calc Instructions Funcs ---
    void calcOPCode();
    void calcInstructionSet();
    void calcBranch();
    void boolBranch();


    // --- Set Functions ---


    // --- Get Functions ---
    unsigned int getOpCode() const;
    unsigned int getMemory1() const;
    unsigned int getDestReg() const;
    short getOffset() const;
    unsigned int getBranchMemory() const;

    // --- Virtual Print Function ---
    virtual void writeToTerminal() const override;

    // -- Destructor ---
    virtual ~IFormat();

   // --- Data Members ---
private:
    unsigned int OpCode{};
    unsigned int memory1{};
    unsigned int destReg{};
    signed short offset{};
    unsigned int branchMemory{};
    bool branchYesOrNo{};
};


#endif
