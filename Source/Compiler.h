/* MIT License (C) Genesis Contributors
 * This file contains the source code for the process of compilation of the
 * Genesis programming language broken down into the following components:
 * tokenisation, parsing, semantic analysis. For the language-specific 
 * feature parsing, take a look at the Source/Genesis.h*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>

/// @brief The basic type that represents the token as its value and type.
struct Lexeme {
    string lexeme;
    char type[5];  //The type of lexeme: identifier, number, string, an operator, keyword, etc.
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
/// @return The map of standard tokens to their codes.
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
    //Step 2. Split the input into the meaningful parts.
    //Step 3. Tokenise the parts.
    //Step 4. Generate the pattern tree.

}

list<Lexeme> tokenise(string input) {
    //This function tokenises the source code into a list of lexemes.
    list<Lexeme> lexemes; //Below is only the reference to the primary tokens.
    const map<string, string> tokens = generateTokens();
    
    return lexemes;
}

