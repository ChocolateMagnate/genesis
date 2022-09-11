/* MIT License (C) Genesis Contributors
 * This file is the central roadmap for the whole compiler that 
 * binds all components together as a Command Line Interface tool.*/
#include <iostream>
#include <fstream>
#include <string>
#include "Front-end/Preprocessor.cc"
#include "Front-end/Tokeniser.cc"
#include "Front-end/Parser.cc"
#include "Middle-end/Genesis.cc"
#include "Middle-end/Medium.cc"
#include "Middle-end/Optimisations.cc"
#include "Back-end/Platforms.hpp"
using namespace std;
namespace Compiler::CommandLineInterface {
    /// @brief Binds all compilation stages and produces Genesis executable out of the source code.
    void compile(string input, string output){}
    
    /// @brief Reads through the file and verifies it does not contain any errors. 
    /// Prints the list of errors into standard output if found any.
    /// @return True if the file is valid, false otherwise.
    bool review(string source){}

    int main(string args[]){
        cout << "Genesis Compiler v0.0.1 (C) Genesis Contributors" << endl;
        if (args->length() == 1){
            cout << "Usage: genesis <input> <output>" << endl;
            return 0;
        }
        cout << "Usage: genesis <input> <output>" << endl;
        return 0;
    }
};