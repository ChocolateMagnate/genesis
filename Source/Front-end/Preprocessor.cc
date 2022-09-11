/* MIT License (C) Genesis Contributors
 * This is the preprocessor, the starting point of the compiler
 * responsible for looking through the files and fetching the 
 * data needed for the further analysis. It notably searches
 * top-level declarations and hence enables developers to use
 * them before they were defined. */
#include <iostream>
#include <fstream>
#include <map>
#include "./Exports.cc"

namespace Compiler::Analysis::Preprocessor {
    /// @brief The preprocessor struct that represents the rows in the 
    /// dependency table: name of the library, its path and type.
    typedef struct DependencyRecord {
        string title; //The title of the dependency to be imported.
        string path; //The path where to look for the dependency.
        string version; //The version of the dependency.
        string type; //The type of the item: class, function, etc.
        //TODO: implement polymorphic parameter for functions and class member listings.

    } DependencyRecord;
    //The list of all external libraries and their resources.
    vector<string, DependencyRecord> libraries;
    /// @brief Establishes the dependencies and fetches their items with
    /// types, such as classes, functions, etc. for semantic analysis.
    /// @param source 
    void linkDependencies(string source){}
    //The ID table containing the identifiers and their types.
    map<string, TokenSort> identifiers;
    /// @brief Looks through the file and fetches the top-level 
    /// declarations such as classes, functions, and constants.
    /// @param source 
    void searchIdentifiers(string source) {}
};