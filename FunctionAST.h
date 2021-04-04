#pragma once
#include "CompositeConceptAST.h"
class FunctionAST :
	public CompositeConceptAST
{
public:
	FunctionAST(CompositeConcept c);
	virtual void accept(Visitor* visitor) override;
};

