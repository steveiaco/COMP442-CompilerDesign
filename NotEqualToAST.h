#pragma once
#include "CompositeConceptTokenAST.h"

class NotEqualToAST : public CompositeConceptTokenAST
{
public:
	NotEqualToAST(Token token);
	virtual void accept(Visitor* visitor) override;
};

