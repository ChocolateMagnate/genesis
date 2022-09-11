/* MIT License (C) Genesis Contributors
 * This file is responsible for end-compiling and
 * linking executables from Genesis Mediator Assembly 
 * into ARM-native processor instructions. */
#include <iostream>
#include <string>
using namespace std;
namespace Compiler::Processor::ARM {
    /* ARM is minimalistic register-based processor architecture
    * that utilises reduced instruction set computer (RISC) to
    * represent a verity of tasks. It's remarkably more performant
    * than Intel processors due to their lack of unnecessary instructions
    * and improving the pathways, while needing less energy and producing
    * significantly less heat. It is commonly used in mobile devices,
    * Internet of Things and wearables.*/
    unsigned int registers       [16];   // The 16 universal CPU registers
    bool unavailableRegisters    [16];  // The records of the taken registers
    unsigned int specialRegisters[16]; // The 16 system-reserved registers
    /// @brief Finds the register that can be used for assignment. 
    /// @return The available register.
    auto getAvailableRegister(){
        for (auto index = 0; index < 16; index++){
            if (index == 7) continue; //The 7th register is reserved for the system calls.
            if (registers[index] != unavailableRegisters[index]) {

                return index;
            }
        }
        return -1; //-1 means no register is available.
    }
    //      COMMON INSTRUCTIONS
    //      x64-specific instructions
    //      ARM-specific instructions

    /// @brief Moves the value into the register.
    /// @return The Assembly MOV statement.
    string move(string value){
        return "MOV R" + to_string(getAvailableRegister()) + ", #" + value;
    }
    /// @brief Saves given value into the random access memory.
    /// @return The Assembly PUSH statement.
    string push(string value){
        return "PUSH " + value;
    }
    /// @brief Fetches the temporarily saved value from RAM into the register.
    /// @return The Assembly POP statement.
    string pop(int registerIndex){
        return "POP R" + to_string(registerIndex);
    }
    /// @brief Adds two values and stores the result in the register.
    /// @return The Assembly ADD statement.
    string add(string value1, string value2){
        return "ADD R" + to_string(getAvailableRegister()) + ", #" + value1 + ", #" + value2;
    }
    /// @brief Subtracts two values and stores the result in the register.
    /// @return The Assembly SUB statement.
    string sub(string value1, string value2){
        return "SUB R" + to_string(getAvailableRegister()) + ", #" + value1 + ", #" + value2;
    }
    /// @brief Multiplies two values and stores the result in the register.
    /// @return The Assembly MUL statement.
    string multiply(string value1, string value2){
        return "MUL R" + to_string(getAvailableRegister()) + ", #" + value1 + ", #" + value2;
    }
    /// @brief Divides the two operands and stores the result in the register.
    /// @return The Assembly DIV statement.
    string divide(string value1, string value2){
        return "DIV R" + to_string(getAvailableRegister()) + ", #" + value1 + ", #" + value2;
    }
    /// @brief Loads the value from the address into the register, similarly to how pointers work.
    /// @return The Assembly LEA statement.
    string load(int address, int value){
        return "LEA #" + to_string(address); + ", #" + to_string(value);
    }
    /// @brief Bitwise shifts into right the register by the given number of bits.
    /// Results into multiplication.
    /// @return The Assembly SHR statement.
    string shiftRight(string value){
        return "SHR R" + to_string(getAvailableRegister()) + ", #" + value;
    }
    /// @brief Bitwise shifts the register into left by the given number of bits.
    /// Results into division.
    /// @return The Assembly SHL statement.
    string shiftLeft(string value){
        return "SHL R" + to_string(getAvailableRegister()) + ", #" + value;
    }
    /// @brief Moves the execution flow to the specified label.
    /// @return The Assembly JMP statement.
    string jump(string label){
        return "JMP " + label;
    }
    /// @brief Evaluates the condition by subtracting the first value from the second and 
    /// saves the result in the register.
    /// @return The Assembly CMP statement.
    string compare(int register1, int register2){
        return "CMP R" + to_string(register1) + ", R" + to_string(register2);
    }
    /// @brief Generates a new label body.
    /// @return The Assembly new label instruction.
    string label(string name){
        return name + ":";
    }
    /// @brief Halts the program though the R7 register.
    /// @return The Assembly halting instruction.
    string quit(){
        //R7 is system-preserved register that halts the program 
        return "MOV R7, #1"; //if you push 1 into it.
    }
};