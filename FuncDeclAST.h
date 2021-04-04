#pragma once
#include "CompositeConceptAST.h"
class FuncDeclAST :
	public CompositeConceptAST
{
public:
	FuncDeclAST(CompositeConcept c);
	virtual void accept(Visitor* visitor) override;
};

