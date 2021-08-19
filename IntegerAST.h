#pragma once
#include "TokenAST.h"
#include "Token.h"
#include <string>

using std::string;

class IntegerAST : public TokenAST {
public:
	IntegerAST(Token token);

	// Inherited via AST
	virtual string toString() override;
	virtual void accept(Visitor* visitor, bool handleDepthSearch = true) override;
};