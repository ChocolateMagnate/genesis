/* MIT License (C) Genesis Contributors
 * This file contains the final stage of compilation of the 
 * Genesis source code and produces Artificial Thought Conveyer
 * that can be executed directly by the hardware. It takes the 
 * pre-processed source and harnesses the power of C++ to build
 * the executable. For previous stages, look at Source/Compiler.h*/
#include <iostream>
#include <string>

unsigned int registers[16]; // The 16 CPU registers
/// @brief Finds the register that can be used for assignment. 
/// @return The available register.
int getAvailableRegister(){
    for (auto index = 0; index < 16; index++){
        if (index == 7) continue;
        if (registers[index] == 0){
            registers[index] = 1;
            return index;
        }
    }
}
/// @brief Moves the value into the register.
/// @return The Assembly MOV statement.
std::string move(std::string value){
    int registerIndex = getAvailableRegister();
    std::string registerName = "R" + std::to_string(registerIndex);
    std::string result = "MOV " + registerName + ", " + value;
    return result;
}
/// @brief Saves given value into the random access memory.
/// @return The Assembly PUSH statement.
std::string push(std::string value){
    return "PUSH " + value;
}
/// @brief Fetches the temporarily saved value from RAM into the register.
/// @return The Assembly POP statement.
std::string pop(int registerIndex){
    return "POP R" + std::to_string(registerIndex);
}
/// @brief Adds two values and stores the result in the register.
/// @return The Assembly ADD statement.
std::string add(std::string value1, std::string value2){
    int registerIndex = getAvailableRegister();
    std::string registerName = "R" + std::to_string(registerIndex);
    std::string result = "ADD " + registerName + ", #" + value1 + ", #" + value2;
    return result;
}
/// @brief Subtracts two values and stores the result in the register.
/// @return The Assembly SUB statement.
std::string sub(std::string value1, std::string value2){
    int registerIndex = getAvailableRegister();
    std::string registerName = "R" + std::to_string(registerIndex);
    std::string result = "SUB " + registerName + ", #" + value1 + ", #" + value2;
    return result;
}
/// @brief Multipllies two values and stores the result in the register.
/// @return The Assembly MUL statement.
std::string multiply(std::string value1, std::string value2){
    int registerIndex = getAvailableRegister();
    std::string registerName = "R" + std::to_string(registerIndex);
    std::string result = "MUL " + registerName + ", #" + value1 + ", #" + value2;
    return result;
}
/// @brief Divides the two operands and stores the result in the register.
/// @return The Assembly DIV statement.
std::string divide(std::string value1, std::string value2){
    int registerIndex = getAvailableRegister();
    std::string registerName = "R" + std::to_string(registerIndex);
    std::string result = "DIV " + registerName + ", #" + value1 + ", #" + value2;
    return result;
}
/// @brief Loads the value from the address into the register, similarly to how pointers work.
/// @return The Assembly LEA statement.
std::string load(int address){
    int registerIndex = getAvailableRegister();
    std::string registerName = "R" + std::to_string(registerIndex);
    std::string result = "LEA #" + std::to_string(address); + ", #" + registerName;
    return result;
}
/// @brief Bitwise shifts into right the register by the given number of bits.
/// Results into multiplication.
/// @return The Assembly SHR statement.
std::string shiftRight(std::string value){
    int registerIndex = getAvailableRegister();
    std::string registerName = "R" + std::to_string(registerIndex);
    std::string result = "SHR " + registerName + ", #" + value;
    return result;
}
/// @brief Bitwise shifts the register into left by the given number of bits.
/// Results into division.
/// @return The Assembly SHL statement.
std::string shiftLeft(std::string value){
    int registerIndex = getAvailableRegister();
    std::string registerName = "R" + std::to_string(registerIndex);
    std::string result = "SHL " + registerName + ", #" + value;
    return result;
}
/// @brief Moves the execution flow to the speicified label.
/// @return The Assembly JMP statement.
std::string jump(std::string label){
    return "JMP " + label;
}
/// @brief Evaluates the condition by substracting the first value from the second and 
/// saves the reuslt in the register.
/// @return The Assembly CMP statement.
std::string compare(int register1, int register2){
    int registerIndex = getAvailableRegister();
    std::string registerName = "R" + std::to_string(registerIndex);
    return "CMP R" + std::to_string(register1) + ", R" + std::to_string(register2);
}
/// @brief Generates a new label body.
/// @return The Assembly new label instruction.
std::string label(std::string name){
    return name + ":";
}
/// @brief Halts the program though the R7 register.
/// @return The Assembly halting instruction.
std::string quit(){
    //R7 is system-preserved register that halts the program 
    return "MOV R7, #1"; //if you push 1 into it.
}