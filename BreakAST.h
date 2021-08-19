#pragma once
#include "TokenAST.h"
class BreakAST : public TokenAST
{
public:
	BreakAST(Token token);

	// Inherited via TokenAST
	virtual void accept(Visitor* visitor, bool handleDepthSearch = true) override;
	virtual string toString() override;
};

