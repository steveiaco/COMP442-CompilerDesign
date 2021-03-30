#pragma once
#include "TokenAST.h"
class VoidAST : public TokenAST
{
public:
	VoidAST(Token token);

	// Inherited via TokenAST
	virtual void accept(Visitor* visitor) override;
	virtual string toString() override;
};

