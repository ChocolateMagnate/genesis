Here you can find the file system of this folder.   
# Compiler.h
It is used in order to implement the techniques from the compilation theory. It includes:
* lexical analysis;
* parsing;
* semantic analysis;
* optimisation;
* executable code generation.   
# Genesis.h
This header file is used to implement the underlying Genesis-specific features and the way how they are reflected in the final executable. It is supposed to run alongside *Compiler.h* to implement:
* library linking;
* user definitions;
* Genesis Query Reduction and Genesis Step Acceleration;
* type conversion and coercion;
* built-in math engine, etc. 
# Startup.cpp
This is the entry point of the app that folds everything in one process and produces the executable file. Its primarily focus is the main function that orchestrates the process of compilation. 
