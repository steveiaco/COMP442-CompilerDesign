#pragma once
#include "CompositeConceptAST.h"
class InheritAST :
	public CompositeConceptAST
{
public:
	InheritAST(CompositeConcept c);
	virtual void accept(Visitor* visitor) override;
};

