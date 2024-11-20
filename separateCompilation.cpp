//C++ Build model
// - Headers(.h) + Translation Units(.cpp)
// - Preprocessor performs text substitutions
// - Compiler translates TUs into object files
// - Linker links object files and external libraries into an executable
//
// Example:
// we have dbl.h with signature of func dbl
// we make dbl.cpp and realize this func
// we make main.cpp and call this func
// Both .cpp files compile to dbl.o
// Both .o files concatenate to one execute file - pd4
//
// g++ -c main.cpp
// g++ -c dbl.cpp
// g++ main.o dbl.o -o pd4
//
// Scheme building C++ app:
// .h and .cpp -> #(preprocessor) -> g++ -> .o -> link with external lib -> exe
//
// Preprocessor:
// - runs before compilation
// directives start with #
//
//
// MACROS = Preprocessor Text Substitutions
// #define MACRO [TEXT]
// #ifdef MACRO / #ifndef MACRO ... #else ... #endif
// #undef MACRO
//
// Example:
//#define PLATFORM intelx86
//
//#ifdef _WIN32
//...
//#endif //compiled only for Windows
//
//#ifndef PLATFORM
//...
//#endif //compiled if PLATFORM is not defined
//
//#undef PLATFORM
//
//Special Macros: __LINE__, __FILE__, __DATE__, __TIME__, __cplusplus
//
//
//Avoid in headers:
// - using namespaces , e.g. using namespace std;
// - using symbols of a namespace , e.g. using std::cout;
// Might cause conflicts if multiple namespaces are implicitly used by inclusion of multiple headers
//
//Linker
// - combines machine code
// - insers jump addresses for function calls
//
// Typical linker error: linker sees a reference in code of .o file, but can`t find any object code for it
// Example:
// g++ -c main.cpp
// g++ -c dbl.cpp
// g++ main.o -o prog //error
//
// g++ main.o dbl.o -o prog //good
//
//
//
//
//
//
//
//
