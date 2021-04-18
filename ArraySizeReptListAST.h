#pragma once
#include "CompositeConceptAST.h"

class ArraySizeReptListAST :
	public CompositeConceptAST
{
public:
	ArraySizeReptListAST(CompositeConcept c);
	virtual void accept(Visitor* visitor, bool handleDepthSearch = true) override;
};

