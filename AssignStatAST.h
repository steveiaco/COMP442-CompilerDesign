#pragma once
#include "CompositeConceptAST.h"
class AssignStatAST :
	public CompositeConceptAST
{
public:
	AssignStatAST(CompositeConcept c);
	virtual void accept(Visitor* visitor) override;
};

