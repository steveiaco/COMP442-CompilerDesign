#pragma once
#include "TokenAST.h"

class FloatAST : public TokenAST {

public:
	FloatAST(Token token);

	// Inherited via TokenAST
	virtual string toString() override;
	virtual void accept(Visitor* visitor, bool handleDepthSearch = true) override;
};