#pragma once
#include "TokenAST.h"
class VoidAST : public TokenAST
{
public:
	VoidAST(Token token);

	// Inherited via TokenAST
	virtual void accept(Visitor* visitor, bool handleDepthSearch = true) override;
	virtual string toString() override;
};

