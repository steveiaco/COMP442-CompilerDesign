#pragma once
#include "CompositeConceptAST.h"
class ClassDeclBodyListAST :
	public CompositeConceptAST
{
public:
	ClassDeclBodyListAST(CompositeConcept c);
	virtual void accept(Visitor* visitor) override;
};

