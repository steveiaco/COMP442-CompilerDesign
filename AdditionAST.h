#pragma once
#include "CompositeConceptTokenAST.h"
class AdditionAST : public CompositeConceptTokenAST
{
public:
	AdditionAST(Token token);
	virtual void accept(Visitor* visitor) override;
};

