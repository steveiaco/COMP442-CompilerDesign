#pragma once
#include "AST.h"
#include <string>
#include "Token.h"

using std::string;

class VisibilityAST : public AST {
private:
	Token token;
	string vis;

public:
	VisibilityAST(Token token);

	string toString();
};