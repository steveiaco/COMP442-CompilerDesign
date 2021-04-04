#pragma once
#include "CompositeConceptAST.h"
class FuncCallStatAST :
	public CompositeConceptAST
{
public:
	FuncCallStatAST(CompositeConcept c);
	virtual void accept(Visitor* visitor) override;
};

