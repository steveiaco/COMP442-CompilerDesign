#pragma once
#include "CompositeConceptAST.h"
class VariableAST :
	public CompositeConceptAST
{
public:
	VariableAST(CompositeConcept c);
	virtual void accept(Visitor* visitor) override;
};

