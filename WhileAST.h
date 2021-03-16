#pragma once
#include "AST.h"
#include <string>
#include "Token.h"

using std::string;

class WhileAST : public AST {
private:
	Token token;
	string id;

public:
	WhileAST(Token token);

	string toString();
};