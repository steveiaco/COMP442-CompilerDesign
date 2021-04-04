#pragma once
#include "CompositeConceptAST.h"
class FuncListAST :
	public CompositeConceptAST
{
public:
	FuncListAST(CompositeConcept c);
	virtual void accept(Visitor* visitor) override;
};

