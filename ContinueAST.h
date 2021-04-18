#pragma once
#include "TokenAST.h"
class ContinueAST : public TokenAST
{
public:
	ContinueAST(Token token);

	// Inherited via TokenAST
	virtual void accept(Visitor* visitor, bool handleDepthSearch = true) override;
	virtual string toString() override;
};

