/* MIT License (C) Genesis Contributors
 * This file is the central roadmap for the whole compiler that 
 * binds all components together. For more detailed description 
 * take a look at Source/Compiler.h. For the compiler implementation,
 * see Source/Genesis.h for the inner language's features parsing.*/
#include <iostream>
#include <fstream>
#include <string>
#include <Compiler.h>
#include <Genesis.h>
using namespace std;

int main(){
    string statement;
    ifstream source("Samples/code.gen");
    if (source.is_open()){
        getline(source, statement);
        cout << "Source code: " << statement << endl;
        cout << "Formatted code: " << endl << cleanseComments(statement) << endl;
        source.close();
    }
    return 0;
}