#pragma once
#include "CompositeConceptTokenAST.h"
class TernaryAST :
	public CompositeConceptTokenAST
{
public:
	TernaryAST(Token token);
	virtual void accept(Visitor* visitor) override;
};

