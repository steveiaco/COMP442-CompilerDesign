#pragma once
#include "CompositeConceptAST.h"
class VarDeclListAST :
	public CompositeConceptAST
{
public:
	VarDeclListAST(CompositeConcept c);
	virtual void accept(Visitor* visitor) override;
};

