/* MIT License (C) Genesis Contributors
 * This file is the central roadmap for the whole compiler that 
 * binds all components together as a Command Line Interface tool.*/
#include <iostream>
#include <fstream>
#include <string>
#include "Front-end/Genesis.cc"
//#include "Front-end/Parsing.cc"
#include "Middle-end/Medium.cc"
#include "Middle-end/Optimisations.cc"
//#include "Back-end/Platforms.hpp"
using namespace std;
namespace Compiler::CommandLineInterface {
    /// @brief Binds all compilation stages and produces Genesis executable out of the source code.
    void compile(string input, string output){}

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