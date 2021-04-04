#pragma once
#include "CompositeConceptAST.h"
class FuncDefAST :
	public CompositeConceptAST
{
public:
	FuncDefAST(CompositeConcept c);
	virtual void accept(Visitor* visitor) override;
};

