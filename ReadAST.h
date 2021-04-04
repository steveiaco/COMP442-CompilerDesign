#pragma once
#include "CompositeConceptAST.h"
class ReadAST :
	public CompositeConceptAST
{
public:
	ReadAST(CompositeConcept c);
	virtual void accept(Visitor* visitor) override;
};

