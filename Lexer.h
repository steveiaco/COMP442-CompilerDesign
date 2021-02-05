#pragma once
#include "Token.h"
#include <fstream>

class Lexer {
	Lexer(std::ifstream input);
	Token nextToken();
};