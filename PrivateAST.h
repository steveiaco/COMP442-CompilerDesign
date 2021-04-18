#pragma once
#include "TokenAST.h"

class PrivateAST : public TokenAST
{
public:
	PrivateAST(Token token);

	// Inherited via TokenAST
	virtual void accept(Visitor* visitor, bool handleDepthSearch = true) override;
	virtual string toString() override;
};

