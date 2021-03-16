#pragma once
#include "AST.h"
#include <string>
#include "Token.h"

class GeneralTokenAST : public AST
{
private:
	Token token;
	string id;

public:
	GeneralTokenAST(Token token);

	string toString();
};

