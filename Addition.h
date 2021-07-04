#ifndef ADDITION_H	//This is a header guard, checks if ADDITION_H has been defined before.
#define ADDITION_H	//If Addition.h hasn't been included yet, ADDITION_H is defined here.
int proj3GetInteger();	//Function prototype for Addition.cpp
int proj17ReadNumber();
void proj17WriteAnswer(int input);
namespace constants //These are compile time constants, constexpr. A runtime constant is const.
{
	inline constexpr double pi{ 3.14159 };
	inline constexpr double avogadro{ 6.0221413e23 };
	inline constexpr double gravity{ 9.8 }; // m/s^2
	//... other related constants
	//Use the scope resolution operator (::) to access your constants in .cpp files:
}
#endif				//If ADDITION_H has been defined the content of Addition.h is not included again.

	//It's best practice to only use forward declarations here and define the function in the .cpp files.
	//Sometimes it's necessary to put non-function definitions in header files, which is why we use header guards.
	//It's also a good idea to put constants in the header file and include a namespace for their use.