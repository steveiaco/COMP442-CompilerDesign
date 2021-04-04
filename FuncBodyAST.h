#pragma once
#include "CompositeConceptAST.h"
class FuncBodyAST :
	public CompositeConceptAST
{
public:
	FuncBodyAST(CompositeConcept c);
	virtual void accept(Visitor* visitor) override;
};

