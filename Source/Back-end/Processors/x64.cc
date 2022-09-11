/* MIT License (C) Genesis Contributors
 * This file translates the optimised Genesis Mediator
 * Assembly syntax tree into x64 native executable file 
 * ready to be shipped. This architecture is commonly 
 * used in supercomputers and mobile devices.*/
#include <iostream>
#include <string>
#include "./Exports.cc"
using namespace std;
/* x64 is a 64-bit stack-based processor architecture 
 * that uses complex instruction set computing (CISC)
 * to enable wider, easier and more robust compilation.
 * Complex commands take multiple CPU cycles to execute,
 * which removes some freedom from compiler designer 
 * compared to ARM. It's widely used in supercomputers and PCs.*/

unsigned int generalRegisters[15];   //For the designing purposes,
unsigned int indexRegisters  [4] ;  //the registers are described as arrays
unsigned int instructionPointer  ; //instead of maps of their names.
unsigned int segmentRegisters[4] ;
unsigned int flag;
string adjustAfterAddition(){}

// Data movement

MachineCode mov(int registerIndex, unsigned int value, MachineCode* print = nullptr){
    auto instruction =  "MOV R" + to_string(registerIndex) + ", " + to_string(value);
    return MachineCode(ARMWindows);
}

string push(){}

string pop(){}
// Arithmetic operations

// Comparison

// Conditional set

// Conditional movement

// Procedure calls