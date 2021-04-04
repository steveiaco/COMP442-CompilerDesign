#pragma once
#include "CompositeConceptAST.h"
class ClassDeclAST :
	public CompositeConceptAST
{
public:
	ClassDeclAST(CompositeConcept c);
	virtual void accept(Visitor* visitor) override;
};

