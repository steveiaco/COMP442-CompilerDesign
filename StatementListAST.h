#pragma once
#include "EnumDeclarations.h"
#include "CompositeConceptAST.h"
class StatementListAST :
	public CompositeConceptAST
{
public:
	StatementListAST(CompositeConcept c);
	virtual void accept(Visitor* visitor, bool handleDepthSearch = true) override;
};

