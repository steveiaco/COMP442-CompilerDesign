#pragma once
#include "CompositeConceptAST.h"
class IndiceRepListAST :
	public CompositeConceptAST
{
public:
	IndiceRepListAST(CompositeConcept c);
	virtual void accept(Visitor* visitor) override;
};

