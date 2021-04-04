#pragma once
#include "CompositeConceptAST.h"
class FParamsListAST :
	public CompositeConceptAST
{
public:
	FParamsListAST(CompositeConcept c);	
	virtual void accept(Visitor* visitor) override;
};

