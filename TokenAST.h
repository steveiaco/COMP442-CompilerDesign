#pragma once
#include "AST.h"
#include <string>
#include "Token.h"

class TokenAST : public AST
{
private:
	Token token;

public:
	TokenAST(Token token);
	Token getToken();
	std::string getValue();
};

