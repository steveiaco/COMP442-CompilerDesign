#pragma once
#include "AST.h"
#include "Token.h"
#include <string>

using std::string;

class IntegerAST : public AST {
private:
	Token token;
	string value;

public:
	IntegerAST(Token token);

	string toString();

	void setValue(string value);
	string getValue();
};