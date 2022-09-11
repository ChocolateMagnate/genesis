/* MIT License (C) Genesis Contributors
 * This file contains different useful data structures,
 * algorithms and utilities used in the compilation process.*/
#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

constexpr unsigned int str2int(const char *str, int h = 0){
    return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}
enum TokenSort {
    Keyword, Number, String, Boolean, Identifier, Operator, Separator, Indentation, Unknown,
    Class, Function, Variable, Constant, Method, Property, Enum, Interface, Namespace
};
/// @brief The basic type that represents the lexeme as its value and type.
class Lexeme {
    string content;
    TokenSort type; // The type of lexeme: identifier, number, string, an operator, keyword, etc.
    public:
        Lexeme(std::string content, TokenSort type) {
            this->content = content;
            this->type = type;
        }
};
/// @brief Generates the standard lexemes used in the language.
/// @return The map of standard tokens to their codes with the array of the keywords.
auto generateTokens(){
    // This function tokenises the source code
    // into a list of predefined lexemes.
    map<string, Lexeme> tokens;
    tokens["+"]   = Lexeme("Add", Operator);
    tokens["-"]   = Lexeme("Subtract", Operator);
    tokens["*"]   = Lexeme("Multiply", Operator);
    tokens["/"]   = Lexeme("Divide", Operator);
    tokens["%"]   = Lexeme("Modulo", Operator);
    tokens["^"]   = Lexeme("Caret", Operator);
    tokens["\\"]  = Lexeme("Backslash", Operator);
    tokens["="]   = Lexeme("Assign", Operator);
    tokens["=="]  = Lexeme("Equal", Operator);
    tokens["!="]  = Lexeme("NotEqual", Operator);
    tokens["<"]   = Lexeme("LessThan", Operator);
    tokens[">"]   = Lexeme("GreaterThan", Operator);
    tokens["<="]  = Lexeme("LessThanOrEqual", Operator);
    tokens[">="]  = Lexeme("GreaterThanOrEqual", Operator);
    tokens["&&"]  = Lexeme("And", Operator);
    tokens["||"]  = Lexeme("Or", Operator);
    tokens["!"]   = Lexeme("Not", Operator);
    tokens["("]   = Lexeme("OpenParenthesis", Separator);
    tokens[")"]   = Lexeme("CloseParenthesis", Separator);
    tokens["["]   = Lexeme("OpenBracket", Separator);
    tokens["]"]   = Lexeme("CloseBracket", Separator);
    tokens["{"]   = Lexeme("OpenBrace", Separator);
    tokens["}"]   = Lexeme("CloseBrace", Separator);
    tokens[";"]   = Lexeme("Semicolon", Separator);
    tokens[","]   = Lexeme("Comma", Separator);
    tokens["."]   = Lexeme("Dot", Separator);
    tokens[".."]  = Lexeme("Range", Separator);
    tokens["..."] = Lexeme("RangeInclusive", Separator);
    tokens["::"]  = Lexeme("Scope", Separator);
    tokens["->"]  = Lexeme("Arrow", Operator);
    tokens["?"]   = Lexeme("QuestionMark", Separator);
    tokens["\t"]  = Lexeme("Tab", Indentation);

    return tokens;
}
/// @brief (0/3) Generates the list of the keywords used in Genesis.
/// @return The array of the keywords.
auto generateKeywords()
{
    const string keywords[] = {"if", "else", "as", "for", "while", "break", "return", "namespace",
                         "class", "do", "private", "protected", "public", "static", "delete",
                         "import", "this", "and", "or", "not", "true", "false", "void", "with",
                         "extends", "interface", "export", "readonly", "go", "in", "out"};
    return &keywords;
}
// Global lexemes:
const auto tokens = generateTokens();
const auto keywords = generateKeywords();
