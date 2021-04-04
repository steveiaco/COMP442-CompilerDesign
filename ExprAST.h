#pragma once
#include "CompositeConceptAST.h"
class ExprAST :
	public CompositeConceptAST
{
public:
	ExprAST(CompositeConcept c);	
	virtual void accept(Visitor* visitor) override;
};

