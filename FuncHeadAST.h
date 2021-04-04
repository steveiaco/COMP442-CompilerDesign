#pragma once
#include "CompositeConceptAST.h"
class FuncHeadAST :
	public CompositeConceptAST
{
public:
	FuncHeadAST(CompositeConcept c);
	virtual void accept(Visitor* visitor) override;
};

