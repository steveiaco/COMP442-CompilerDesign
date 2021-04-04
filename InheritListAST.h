#pragma once
#include "CompositeConceptAST.h"
class InheritListAST :
	public CompositeConceptAST
{
public:
	InheritListAST(CompositeConcept c);
	virtual void accept(Visitor* visitor) override;
};

