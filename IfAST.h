#pragma once
#include "CompositeConceptAST.h"
class IfAST :
	public CompositeConceptAST
{
public:
	IfAST(CompositeConcept c);
	virtual void accept(Visitor* visitor) override;
};

