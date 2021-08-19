#pragma once
#include "CompositeConceptAST.h"
class ClassListAST :
	public CompositeConceptAST
{
public:
	ClassListAST(CompositeConcept c);
	virtual void accept(Visitor* visitor, bool handleDepthSearch = true) override;
};

