#pragma once
#include "TokenAST.h"
class StringIdAST :
	public TokenAST
{
public:
	StringIdAST(Token token);

	// Inherited via TokenAST
	virtual void accept(Visitor* visitor, bool handleDepthSearch = true) override;
	virtual string toString() override;
};

