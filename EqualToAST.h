#pragma once
#include "CompositeConceptTokenAST.h"
class EqualToAST : public CompositeConceptTokenAST
{
public:
	EqualToAST(Token token);
	virtual void accept(Visitor* visitor) override;
};

