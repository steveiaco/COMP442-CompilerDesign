#pragma once
#include "TokenAST.h"
class FloatIdAST : public TokenAST
{
public:
	FloatIdAST(Token token);

	// Inherited via AST
	virtual void accept(Visitor* visitor, bool handleDepthSearch = true) override;
	virtual string toString() override;
};

