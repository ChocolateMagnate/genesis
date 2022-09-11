/* MIT License (C) Genesis Contributors
 * This file contains different useful data structures,
 * algorithms and utilities used in the compilation process.*/
#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

constexpr unsigned int str2int(const char* str, int h = 0) {
    return !str[h] ? 5381 : (str2int(str, h+1)*33) ^ str[h];
}

/// @brief The basic type that represents the lexeme as its value and type.
enum PlatformSpecifier{
    WebAssembly, ARMLinux, x64Linux, ARMWindows, x64Windows, ARMmacOS, x64macOS
};
class MachineCode{
    string Opcode;
    string Operands[4];
    PlatformSpecifier Platform;
    public:
        MachineCode(PlatformSpecifier platform){
            this->Platform = platform;
        }
        string* getOpcode(){
            return &Opcode;
        }
        auto getOperands(){
            return &Operands;
        }
};
