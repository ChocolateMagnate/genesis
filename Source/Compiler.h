/* MIT License (C) Genesis Contributors
 * This file contains the source code for the process of compilation
 * Genesis programming language broken down into the following components:
 * tokenisation, parsing, semantic analysis. */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>


struct Lexeme {
    //This is the struct that represents encapsulated tokens:
    string lexeme; //the text,
    char type[5];  //the type of lexeme: identifier, number, string, an operator, keyword, etc.
};


/// @brief The hierarchical tree model of the tokens. 
class Block {
    public:
        Block *parent;
        list<Block*> children;
        Lexeme *lexeme;
        Block(Block *parent, Lexeme *lexeme) {
            this->parent = parent;
            this->lexeme = lexeme;
        }
        void addChild(Block *child) {
            children.push_back(child);
        }
        void Show(int depth) {
            for (int i = 0; i < depth; i++) {
                cout << "  ";
            }
            cout << lexeme->lexeme << endl;
            for (Block *child : children) {
                child->Show(depth + 1);
            }
        }
};

/// @brief Generates the standard tokens used in the language.
/// @return the list of standard tokens.
auto generateTokens() {
    //This function tokenises the source code 
    //into a list of predefined lexemes.
    map<string, string> tokens;
    //Algebraic Operators:
    tokens["+"]  = "Add";
    tokens["-"]  = "Subtract";
    tokens["*"]  = "Multiply";
    tokens["/"]  = "Divide";
    tokens["="]  = "Assign";
    tokens["%"]  = "Modulo";
    tokens["^"]  = "Power";
    tokens["\\"] = "Root";
    //Boolean Operators:
    tokens["=="] = "Equals";
    tokens["!="] = "NotEquals";
    tokens["<"]  = "Less";
    tokens["<="] = "Not more";
    tokens[">"]  = "More";
    tokens[">="] = "Not less";
    //Equation Operators:
    tokens["+="] = "Add to";
    tokens["-="] = "Subtract from";
    tokens["*="] = "Multiply by";
    tokens["/="] = "Divide by";
    tokens["%="] = "Modulo by";
    tokens[":="] = "Strict assign";
    //Special symbols:
    tokens[")"]  = "Round opening";
    tokens[")"]  = "Round closing";
    tokens["{"]  = "Curly opening";
    tokens["}"]  = "Curly closing";
    tokens["["]  = "Square opening";
    tokens["]"]  = "Square closing";
    tokens[":"]  = "Colon";
    tokens[";"]  = "Semicolon";
    tokens["."]  = "Dot";
    tokens[","]  = "Comma";

    return tokens;
}

list<string> splitIntoComponents(string input) {
    //Splits the input string into the components
    //that can be parsed as individual tokens.
    const auto tokens = generateTokens();
    Block primary = Block(NULL, NULL);
    //Step 1. Cleanse the comments.
    auto comments = input.find("//");
    if (comments == NULL) comments = input.find("/*");

}

list<Lexeme> tokenise(string input) {
    //This function tokenises the source code into a list of lexemes.
    list<Lexeme> lexemes; //Below is only the reference to the primary tokens.
    const map<string, string> tokens = generateTokens();
    
    return lexemes;
}

