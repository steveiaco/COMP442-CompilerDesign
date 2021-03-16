#pragma once
#include "AST.h"
#include <string>
#include "Token.h"

using std::string;

class StringAST : public AST {
private:
	Token token;
	string str;

public:
	StringAST(Token token);

	string toString();
};