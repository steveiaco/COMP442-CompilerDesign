#pragma once
#include "CompositeConceptAST.h"
class IndiceRepAST :
	public CompositeConceptAST
{
public:
	IndiceRepAST(CompositeConcept c);
	virtual void accept(Visitor* visitor, bool handleDepthSearch = true) override;
};

