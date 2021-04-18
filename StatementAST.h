#pragma once
#include "CompositeConceptAST.h"
class StatementAST :
	public CompositeConceptAST
{
public:
	StatementAST(CompositeConcept c);
	virtual void accept(Visitor* visitor, bool handleDepthSearch = true) override;
};

