/* MIT License (C) Genesis Contributors
 * This file contains the source code for the process of compilation
 * Genesis programming language broken down into the following components:
 * tokenisation, parsing, semantic analysis. */
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>


struct Lexeme {
    //This is the struct that represents encapsulated tokens:
    string lexeme; //the text,
    char type[5];  //the type of lexeme: identifier, number, string, an operator, keyword, etc.
};

//This class is used to represent relations among the tokens as a hierarchical model.   
class SourceSchema {
    public:
        SourceSchema *parent;
        list<SourceSchema*> children;
        Lexeme *lexeme;
        SourceSchema(SourceSchema *parent, Lexeme *lexeme) {
            this->parent = parent;
            this->lexeme = lexeme;
        }
        void addChild(SourceSchema *child) {
            children.push_back(child);
        }
        void Show(int depth) {
            for (int i = 0; i < depth; i++) {
                cout << "  ";
            }
            cout << lexeme->lexeme << endl;
            for (SourceSchema *child : children) {
                child->Show(depth + 1);
            }
        }
};

list<string> splitByKeywords(string input, list<string> keywords) {
    //Splits the input string into the list of keywords.
    list<string> output;

}
map<string, string> generateTokens(char source[]) {
    //This function tokenises the source code into a list of lexemes.
    map<string, string> tokens;
    //Algebraic Operators:
    tokens["Add"]      = "+";
    tokens["Subtract"] = "-";
    tokens["Multiply"] = "*";
    tokens["Divide"]   = "/";
    tokens["Assign"]   = "=";
    tokens["Modulo"]   = "%";
    //Boolean Operators:
    tokens["Equals"]     = "==";
    tokens["Not equals"] = "!=";
    tokens["Less"]       = "<";
    tokens["Not more"]   = "<=";
    tokens["More"]       = ">";
    tokens["Not less"]   = ">=";
    //Equation Operators:
    tokens["Add to"]        = "+=";
    tokens["Subtract from"] = "-=";
    tokens["Multiply by"]   = "*=";
    tokens["Divide by"]     = "/=";
    tokens["Modulo by"]     = "%=";
    tokens["Strict assign"] = ":=";
    //Special symbols:
    tokens["Round opening"]  = "(";
    tokens["Round closing"]  = ")";
    tokens["Curly opening"]  = "{";
    tokens["Curly closing"]  = "}";
    tokens["Square opening"] = "[";
    tokens["Square closing"] = "]";
    tokens["Colon"]          = ":";
    tokens["Semocolon"]      = ";";
    tokens["Dot"]            = ".";
    tokens["Comma"]          = ",";
    tokens["Backslash"]      = "\\";

    return tokens;
}

