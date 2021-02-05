#pragma once
#include "Token.h"
#include <fstream>

class Lexer {
private:
	std::ifstream& input;

public:
	Lexer(std::ifstream &input);
	Token nextToken();
};