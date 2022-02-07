// Class for Storing and Manipulating Hex Instructions into Assembly
//
// Author: Brian Horner
// Edit History:
// 2/6/2022 Initial Version
// 2/6/2022 Added Constructor, data members, get, set and virtual functions

#ifndef InstructionSet_H
#define InstructionSet_H


class InstructionSet {

public:

    // Constructor
    InstructionSet(int hexInstruction, unsigned int currentAddress){
        //Might cause a problem with conversion?
        this->address = currentAddress;
        this-> hexInstruction = hexInstruction;
    };
    // Destructor
    ~InstructionSet();

    // Set Functions - Private
private:
    void setHexInstruction(int Instruction);
    void setAddress(unsigned int address);
    void setOpCode (unsigned int code);
    void setMemory1 (unsigned int mem1);
    void setMemory2 (unsigned int mem2);
    void setFormat (char formatChar);

    // Get Functions - Public
public:
    int getHexInstruction() const;
    unsigned int getAddress() const;
    unsigned int getOpCode() const;
    unsigned int getMemory1() const;
    unsigned int getMemory2() const;
    char getFormat() const;

    // Virtual Write & Print Functions
    virtual void writeToFile(std::string filePath) const;
    virtual void writeToTerminal() const;

private:
    int hexInstruction;
    unsigned int address;
    unsigned int OpCode{};
    unsigned int memory1{};
    unsigned int memory2{};
    char format{};
};


#endif
