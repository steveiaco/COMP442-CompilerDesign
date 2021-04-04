#pragma once
#include "CompositeConceptAST.h"
class VarCallStatAST :
	public CompositeConceptAST
{
public:
	VarCallStatAST(CompositeConcept c);
	virtual void accept(Visitor* visitor) override;
};

