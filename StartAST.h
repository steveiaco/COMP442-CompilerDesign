#pragma once
#include "CompositeConceptAST.h"
class StartAST :
	public CompositeConceptAST
{
public:
	StartAST(CompositeConcept c);
	virtual void accept(Visitor* visitor) override;
};

