#pragma once
#include "AST.h"
#include <string>
#include "Token.h"

using std::string;

class IdAST : public AST {
private:
	Token token;
	string id;

public:
	IdAST(Token token);

	string toString();

	void setId(string id);
	string getId();
};