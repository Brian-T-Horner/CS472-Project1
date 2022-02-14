// Class Implementation for Storing and Manipulating R Format Instructions
// Child Class of InstructionSet

// Author: Brian Horner
// Edit History:
// 2/6/2022 Initial Version
// 2/6/2022 Added specifications for constructor, destructor, get and sets
// 2/6/2022 Added specifications for calc funcs, virtual funcs, and data members

#ifndef RFormat_H
#define RFormat_H

// Standard Library Includes

// User Built Includes
#include "InstructionSet.h"


class RFormat:public InstructionSet{

public:
    // --- Constructor ---
    RFormat(unsigned int hexInstruction, unsigned int address);

    // --- Calc Instructions Funcs ---
    void calcOPCode();
    void calcInstructionSet();



    // --- Set Functions ---    DO I EVEN WANT THESE
//private:
//    void setMemory1(unsigned int mem1);
//    void setMemory2(unsigned int mem2);
//    void setDestReg(unsigned int destReg);
//    void setFuncCode(unsigned int funcCode);+


    // --- Get Functions ---
public:
    unsigned int getMemory1() const;
    unsigned int getMemory2() const;
    unsigned int getDestReg() const;
    unsigned int getFuncCode() const;

    // --- Virtual Print Function ---
    virtual void writeToTerminal() const override;

    // --- Destructor ---
    virtual ~RFormat();

    // --- Data Members ---
private:
    unsigned int OpCode{};
    unsigned int memory1{};
    unsigned int memory2{};
    unsigned int destReg{};
    unsigned int funcCode{};
    std::string writtenOpCode{};
    std::string writtenFuncCode{};

};

#endif
