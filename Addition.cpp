#include "Addition.h"
#include <iostream>
int proj3GetInteger()					
{
	std::cout << "Enter an integer: ";
	int y{};
	std::cin >> y;
	return y;
}
int proj17ReadNumber()
{
	int input{};
	std::cout << "Enter an integer:";
	std::cin >> input;
	return input;
}
void proj17WriteAnswer(int input)
{
	std::cout << "The sum is " << input << '\n';
}
//the variable 'y' is only used in this function, any other function can use variable 'y' as it's not in this scope
//if 'y' were a global variable it could only be defined in one function
