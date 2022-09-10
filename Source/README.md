Here you can find the file system of this folder. The source files that make up the compiler are divided into 3 stages with their own components being:  
# Front-end
This folder takes care of processing the rules and grammars of the language, it deals with **lexical analysis** (extracting specific tokens from the source), **syntax analysis** (formulating the abstract representation of the interplay between the tokens) and **semantic analysis** (validating the states of statements and correlation between the code and definitions). On top of that, it also detects all sorts of errors in the code and raises them in the command line interface.  

Aside from that, **Genesis.cc** takes care of processing Genesis-specific features and aspects, such as parsing classes, functions, interfaces, library linking, GQR and GSA, type conversion, smart engines and registering them into the *identifier table.*
# Middle-end
In the second stage, the compiler generates a low-level *intermediate representation* of the code. It is machine-independent, therefore cannot be run directly by the hardware, however the said IR named **Genesis Mediator Assembly**, can be easily translated into a specific CPU instruction set and be extended to a new architecture, therefore achieving complete portability of code. Additionally, on this step the IR is maturely optimised to deliver refined code.

# Back-end
Finally, Genesis Mediator Assembly is turned into a machine-dependent executable file that can run directly on the hardware.  

Additionally, helpful utilities like data structures and algorithms are to be added in *Exports.cc*.