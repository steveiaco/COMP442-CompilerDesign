#pragma once
#include "CompositeConceptAST.h"
class ReturnAST :
	public CompositeConceptAST
{
public:
	ReturnAST(CompositeConcept c);
	virtual void accept(Visitor* visitor, bool handleDepthSearch = true) override;
};

