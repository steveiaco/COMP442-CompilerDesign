#pragma once
#include "CompositeConceptAST.h"
class ProgAST :
	public CompositeConceptAST
{
public:
	ProgAST(CompositeConcept c);
	virtual void accept(Visitor* visitor, bool handleDepthSearch = true) override;
};

