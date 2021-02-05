#include "Lexer.h"
#include <iostream>

Lexer::Lexer(std::ifstream& input) : input(input)
{
}

Token Lexer::nextToken()
{
	std::string token;
	input >> token;
	std::cout << token << std::endl;
	return Token(ERROR, "e");
}
