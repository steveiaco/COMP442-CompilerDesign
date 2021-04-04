#pragma once
#include "CompositeConceptAST.h"

class ArraySizeReptListAST :
	public CompositeConceptAST
{
public:
	ArraySizeReptListAST(CompositeConceptAST c);
	virtual void accept(Visitor* visitor) override;
};

