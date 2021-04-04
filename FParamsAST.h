#pragma once
#include "CompositeConceptAST.h"
class FParamsAST :
	public CompositeConceptAST
{
public:
	FParamsAST(CompositeConcept c);
	virtual void accept(Visitor* visitor) override;
};

