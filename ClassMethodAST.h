#pragma once
#include "CompositeConceptAST.h"
class ClassMethodAST :
	public CompositeConceptAST
{
public:
	ClassMethodAST(CompositeConcept c);
	virtual void accept(Visitor* visitor) override;
};

