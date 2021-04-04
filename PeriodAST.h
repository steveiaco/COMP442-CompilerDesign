#pragma once
#include "CompositeConceptTokenAST.h"
class PeriodAST :
	public CompositeConceptTokenAST
{
public:
	PeriodAST(Token t);
	virtual void accept(Visitor* visitor) override;
};

