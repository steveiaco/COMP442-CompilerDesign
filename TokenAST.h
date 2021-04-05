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

	virtual string toString() = 0;
	virtual string getData() override;

};

