#pragma once
#include "CompositeConceptAST.h"
class ClassDeclBodyAST :
	public CompositeConceptAST
{
public:
	ClassDeclBodyAST(CompositeConcept c);
	virtual void accept(Visitor* visitor, bool handleDepthSearch = true) override;
};

