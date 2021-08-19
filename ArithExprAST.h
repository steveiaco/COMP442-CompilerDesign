#pragma once
#include "CompositeConceptAST.h"
class ArithExprAST :
	public CompositeConceptAST
{
public:
	ArithExprAST(CompositeConcept c);
	virtual void accept(Visitor* visitor, bool handleDepthSearch = true) override;
};

