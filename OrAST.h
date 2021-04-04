#pragma once
#include "CompositeConceptTokenAST.h"
class OrAST :
	public CompositeConceptTokenAST
{
public:
	OrAST(Token token);
	virtual void accept(Visitor* visitor) override;
};

