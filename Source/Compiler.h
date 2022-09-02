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


/// @brief The hierarchical tree model of the operators. 
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

/// @brief Generates the standard lexemes used in the language.
/// @return The map of standard operators to their codes with the array of the keywords.
auto generateTokens() {
    //This function tokenises the source code 
    //into a list of predefined lexemes.
    map<string, string> operators;
    //Algebraic Operators:
    operators["+"]  = "Add";
    operators["-"]  = "Subtract";
    operators["*"]  = "Multiply";
    operators["/"]  = "Divide";
    operators["="]  = "Assign";
    operators["%"]  = "Modulo";
    operators["^"]  = "Power";
    operators["\\"] = "Root";
    //Boolean Operators:
    operators["=="] = "Equals";
    operators["!" ] = "Not";
    operators["!="] = "Not equals";
    operators["<"]  = "Less";
    operators["<="] = "Not more";
    operators[">"]  = "More";
    operators[">="] = "Not less";
    //Equation Operators:
    operators["+="] = "Add to";
    operators["-="] = "Subtract from";
    operators["*="] = "Multiply by";
    operators["/="] = "Divide by";
    operators["%="] = "Modulo by";
    operators[":="] = "Strict assign";
    //Special symbols:
    operators[")"]  = "Round opening";
    operators[")"]  = "Round closing";
    operators["{"]  = "Curly opening";
    operators["}"]  = "Curly closing";
    operators["["]  = "Square opening";
    operators["]"]  = "Square closing";
    operators[":"]  = "Colon";
    operators[";"]  = "Semicolon";
    operators["."]  = "Dot";
    operators[","]  = "Comma";

    return operators;
}
/// @brief (0/4) Generates the list of the keywords used in Genesis.
/// @return The array of the keywords.
auto generateKeywords(){
    const string keywords[] = {"if", "else", "as", "for", "while", "break", "return",
                "class", "do", "private", "protected", "public", "static",  "delete", 
                "import", "this", "and", "or", "not", "true", "false", "void", "with",
                "extends", "interface", "export", "readonly", "go", "in", "out"};
    return keywords;
}

/// @brief (1/4) Removes the the characters to be ignored (comments) from the source code.
/// @return The formatted string with only meaningful content.
list<string> cleanseComments(string source) {

}


/// @brief (2/4) Divides the source code into the sequence of sliced lexemes ready to be parsed.
/// @return The list of individual lexemes.
list<string> splitIntoComponents(string input) {
    //Splits the input string into the components
    //that can be parsed as individual operators.
    const map<string, string> operators = generateTokens();
    const string *keywords = generateKeywords();
    //Step 1. Cleanse the comments.

}

/// @brief (3/4) Parses the tokens into specified lexemes by mathing operators, keywords and identifiers.
/// @return The sequence of configured lexemes.
list<Lexeme> tokenise(string source) {
    //This function tokenises the source code into a list of lexemes.
    list<Lexeme> lexemes; //Below is only the reference to the primary operators.
    const map<string, string> operators = generateTokens();
    const string *keywords = generateKeywords();
    return lexemes;
}

/// @brief (4/4) Parses the lexemes into the hierarchical tree model of the operators.
/// @return The statement pattern as an integer.
int parseIntoPattern(list<Lexeme> lexemes) {
    int pattern{}; //The initial pattern of the code.

    return pattern;
};
