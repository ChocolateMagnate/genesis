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
#include "./Exports.cc"
using namespace std;
enum TokenSort{
    Keyword, Number, String, Boolean, Identifier, Operator, Separator, Indentation, Unknown
};


/// @brief The basic type that represents the lexeme as its value and type.
typedef struct Lexeme {
    string content;
    TokenSort type;  //The type of lexeme: identifier, number, string, an operator, keyword, etc.
} Lexeme;


/// @brief Generates the standard lexemes used in the language.
/// @return The map of standard tokens to their codes with the array of the keywords.
auto generateTokens() {
    //This function tokenises the source code 
    //into a list of predefined lexemes.
    map<string, Lexeme> tokens;
    //Algebraic Operators:
    tokens["+"]  = {"Add", Operator};
    tokens["-"]  = {"Subtract", Operator};
    tokens["*"]  = {"Multiply", Operator};
    tokens["/"]  = {"Divide", Operator};
    tokens["="]  = {"Assign", Operator};
    tokens["%"]  = {"Modulo", Operator};
    tokens["^"]  = {"Power", Operator};
    tokens["\\"] = {"Root", Operator};
    //Boolean Operators:
    tokens["=="] = {"Equals", Operator};
    tokens["!" ] = {"Not", Operator};
    tokens["!="] = {"Not equals", Operator};
    tokens["<"]  = {"Less", Operator};
    tokens["<="] = {"Not more", Operator};
    tokens[">"]  = {"More", Operator};
    tokens[">="] = {"Not less", Operator};
    //Equation Operators:
    tokens["+="] = {"Add to", Operator};
    tokens["-="] = {"Subtract from", Operator};
    tokens["*="] = {"Multiply by", Operator};
    tokens["/="] = {"Divide by", Operator};
    tokens["%="] = {"Modulo by", Operator};
    tokens[":="] = {"Strict assign", Operator};
    //Special symbols:
    tokens[")"]  = {"Round opening", Separator};
    tokens[")"]  = {"Round closing", Separator};
    tokens["{"]  = {"Curly opening", Separator};
    tokens["}"]  = {"Curly closing", Separator};
    tokens["["]  = {"Square opening", Separator};
    tokens["]"]  = {"Square closing", Separator};
    tokens[";"]  = {"Semicolon", Separator};
    tokens[":"]  = {"Colon", Separator};
    tokens[","]  = {"Comma", Separator};
    tokens["."]  = {"Dot", Separator};

    return tokens;
}
/// @brief (0/4) Generates the list of the keywords used in Genesis.
/// @return The array of the keywords.
auto generateKeywords(){
    string keywords[] = {"if", "else", "as", "for", "while", "break", "return",
                "class", "do", "private", "protected", "public", "static",  "delete", 
                "import", "this", "and", "or", "not", "true", "false", "void", "with",
                "extends", "interface", "export", "readonly", "go", "in", "out"};
    return &keywords;
}
//Global lexemes:
const auto tokens = generateTokens();
const auto keywords = generateKeywords();

/// @brief (1/4) Removes the the characters to be ignored (comments) from the source code 
/// and flags if the multiline /* comment was closed.
/// @return The formatted string with only meaningful content.
tuple<string, bool> cleanseComments(string source, bool commentClosed = true) {
    //Section 1. Remove everything before the closing comment.
    if (!commentClosed){
        int commentEnd = source.find("*/");
        if (commentEnd == string::npos) {
            return {"", false};
        } else source = source.substr(commentEnd + 2, source.length() - commentEnd);
    }
    //Section 2. Remove one-line comment.
    int indexOfComments = source.find("//");
    if (indexOfComments != string::npos)
        source = source.substr(0, indexOfComments); //Remove the rest of the line if // is detected.
    //Section 3. Remove multiline comment.
    indexOfComments = source.find("/*");
    bool startFound = indexOfComments != string::npos; //string::npos is the end of the string.
    if (startFound) {
        //Remove the rest of the line if /* is found unless it's closed with */. 
        //Otherwise, remove until the end of the line and add unclosed comment flag.
        int indexOfCommentsEnd = source.find("*/");
        bool endFound = indexOfCommentsEnd != string::npos;
        if (endFound) {
            source = source.substr(0, indexOfComments) + source.substr(indexOfCommentsEnd + 2);
            commentClosed = !commentClosed;
        } else {
            source = source.substr(0, indexOfComments);
            commentClosed = false;
        }
        auto test = source.find("/*");
        if (test != string::npos) return cleanseComments(source);
    }
    return {source, commentClosed};
}

/// @brief (2/4) Divides the source code into the sequence of sliced lexemes ready to be parsed.
/// @return The list of individual lexemes.
list<string> splitIntoComponents(string source) {
    //The order of priorities: strings, indentations, whitespaces.
    list<string> components;

    //Step 1. Extract the strings.
    int quotation = source.find('"'); //To pass a quotation mark in a string, use single ticks.
    if (quotation != string::npos){
        int endOfQuotation = source.find('"', quotation + 1);
        if (endOfQuotation == string::npos) throw "Error: Quotation mark is not closed.";
        else {
            components.push_back(source.substr(quotation, endOfQuotation - quotation + 1));
            source = source.substr(0, quotation) + source.substr(endOfQuotation, source.length());
        }
    }
    int test = source.find('"');
    if (test != string::npos) return splitIntoComponents(source);

    //Step 2. Extract the indentation.
    int start = 0;
    while (source[start] == '\t') {
        components.push_back("\t");
        source = source.substr(1, source.length());
    }

    //Step 3. Remove the remaining whitespaces.
    list<string> mergedLexemes;
    int indexOfWhitespace = source.find(' ');
    while (indexOfWhitespace != string::npos) {
        mergedLexemes.push_back(source.substr(0, indexOfWhitespace));
        mergedLexemes.push_back(source.substr(indexOfWhitespace + 1));
        indexOfWhitespace = source.find(' ');
    }
    delete &source;

    //Step 4. Extract the rest of the lexemes.
    for (auto lexeme : mergedLexemes) {
        char tokens[] = {'+', '-', '*', '/', '=', '%', '^', '\\', '!', '?',
            '<', '>', '&', '|', '(', ')', '{', '}', '[', ']', ';', ':', ',', '.'};
        for (char symbol : tokens){
            int indexOfToken = lexeme.find(symbol);
            if (indexOfToken != string::npos) {
                components.push_back(lexeme.substr(0, indexOfToken));
                components.push_back(lexeme.substr(indexOfToken + 1));
                components.push_back(lexeme.substr(indexOfToken + 1, lexeme.length()));
            }
        }
    }
    return components;
};

/// @brief (3/4) Parses the tokens into specified lexemes by matching tokens, keywords and identifiers.
/// @return The sequence of configured lexemes.
list<Lexeme> tokenise(list<string> components) {
    list<Lexeme> lexemes;
    //C++ treat text literals as const char*, therefore we cannot switch them with
    //std::string. In order to compare them, we need to convert string to const char*
    //with .c_str() method and convert it into an integer to make it comparable.
    for (string component: components){
        switch (str2int(component.c_str())){
            case str2int("if"): case str2int("else"): case str2int("as"): case str2int("for"): 
            case str2int("while"): case str2int("break"): case str2int("return"): case str2int("class"):
            case str2int("do"): case str2int("private"): case str2int("protected"): case str2int("public"):
            case str2int("static"): case str2int("delete"): case str2int("import"): case str2int("this"):
            case str2int("and"): case str2int("or"): case str2int("not"): case str2int("true"): case str2int("false"):
            case str2int("void"): case str2int("with"): case str2int("extends"): case str2int("interface"):
            case str2int("export"): case str2int("readonly"): case str2int("go"): case str2int("in"): case str2int("out"):
                lexemes.push_back({component, Keyword});
                break;
            case str2int("+"): case str2int("-"): case str2int("*"): case str2int("/"): case str2int("="):
            case str2int("%"): case str2int("^"): case str2int("\\"): case str2int("!"): case str2int("?"):
            case str2int("<"): case str2int(">"): case str2int("&"): case str2int("|"): 
                lexemes.push_back({component, Operator});
                break;
            case str2int("("): case str2int(")"): case str2int("{"): case str2int("}"): case str2int("["):
            case str2int("]"): case str2int(";"): case str2int(":"): case str2int(","): case str2int("."):
                lexemes.push_back({component, Separator});
                break;
            case str2int("\t"):
                lexemes.push_back({component, Indentation});
                break;
            default:
                lexemes.push_back({component, Identifier});
                break;
        }
    }
    return lexemes;
}

/// @brief (4/4) Parses the lexemes into the hierarchical tree model of the tokens.
/// @return The statement pattern as an integer.
auto parseIntoPattern(list<Lexeme> lexemes) {
    int pattern{}; //The initial pattern of the code.

    return pattern;
};
