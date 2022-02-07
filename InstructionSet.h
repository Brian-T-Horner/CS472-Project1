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

    // --- Constructor ---
    InstructionSet(int hexInstruction, unsigned int currentAddress);

    // --- Destructor ---
    ~InstructionSet();

    // --- Set Functions - Private ---
private:
    void setHexInstruction(int Instruction); // Needs implementation
    void setAddress(unsigned int address); // Needs implementation

    // --- Get Functions - Public ---
public:
    int getHexInstruction() const;
    unsigned int getAddress() const;


    // --- Virtual Write & Print Functions ---

    // Needs implementation or change to function on vector of instruction
    // classes?????
    virtual void writeToFile(std::string filePath) const;
    virtual void writeToTerminal() const;

    // --- Data Members ---
private:
    int hexInstruction;
    unsigned int address;

};


#endif
