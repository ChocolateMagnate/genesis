Here you can find the file system of this folder.   
# Back-end.cpp
This file compiles the source directly into Assembly and then is assembled into the executable machine code. At the end, it writes a new file that can be executed by the hardware.
# Front-end.cpp
It is used in order to implement code analysis and generates the representation of the meaning conveyed in the input code. It includes lexical, syntax and semantic analysis. 
# Genesis.cpp
This header file is used to implement the underlying Genesis-specific features and the way how they are reflected in the final executable. It is supposed to run alongside *Front-end.cpp* to implement:
* library linking;
* user definitions;
* Genesis Query Reduction and Genesis Step Acceleration;
* type conversion and coercion;
* built-in math engine, etc. 
# Startup.cpp
This is the entry point of the app that folds everything in one process and produces the executable file. Its primarily focus is the main function that orchestrates the process of compilation. 
