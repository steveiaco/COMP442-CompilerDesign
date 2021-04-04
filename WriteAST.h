#pragma once
#include "CompositeConceptAST.h"
class WriteAST :
	public CompositeConceptAST
{
public:
	WriteAST(CompositeConcept c);
	virtual void accept(Visitor* visitor) override;
};

