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

    // Get Functions - Public
public:
    int getHexInstruction() const;
    unsigned int getAddress() const;


    // Virtual Write & Print Functions
    virtual void writeToFile(std::string filePath) const;
    virtual void writeToTerminal() const;

private:
    int hexInstruction;
    unsigned int address;

};


#endif
