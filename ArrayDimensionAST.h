#pragma once
#include "CompositeConceptAST.h"
class ArrayDimensionAST :
	public CompositeConceptAST
{
public:
	ArrayDimensionAST(CompositeConcept c);
	virtual void accept(Visitor* visitor) override;
};

