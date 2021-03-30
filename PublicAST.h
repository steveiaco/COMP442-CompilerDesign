#pragma once
#include "TokenAST.h"
#include "Token.h"

class PublicAST : public TokenAST
{
public:
	PublicAST(Token token);

	// Inherited via TokenAST
	virtual void accept(Visitor* visitor) override;
	virtual string toString() override;
};

