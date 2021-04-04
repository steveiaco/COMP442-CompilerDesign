#pragma once
#include "CompositeConceptTokenAST.h"
class LessThanEqualToAST : public CompositeConceptTokenAST
{
public:
	LessThanEqualToAST(Token token);
	virtual void accept(Visitor* visitor) override;
};

