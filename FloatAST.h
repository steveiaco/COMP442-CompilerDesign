#pragma once
#include "AST.h"
#include <string>
#include "Token.h"

using std::string;

class FloatAST : public AST {
private:
	Token token;
	string flt;

public:
	FloatAST(Token token);

	string toString();
};