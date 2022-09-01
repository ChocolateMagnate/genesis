/* MIT License (C) Genesis Contributors
 * This file contains the source code for the process of compilation
 * Genesis programming language broken down into the following components:
 * tokenisation, parsing, semantic analysis. */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    string statement;
    ifstream source("Samples/guess-number.gen");
    if (source.is_open()){
        cout << "File opened successfully" << endl;
        while (getline(source, statement)){
            cout << statement << endl;
        }
        source.close();
    }
    return 0;
}