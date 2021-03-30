#pragma once
#include "TokenAST.h"
class IntegerIdAST : public TokenAST
{
public:
	IntegerIdAST(Token t);

	// Inherited via AST
	virtual string toString() override;
	virtual void accept(Visitor* visitor) override;
};

