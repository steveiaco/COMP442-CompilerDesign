#pragma once
#include "CompositeConceptAST.h"
#include "EnumDeclarations.h"

class VarDeclAST : public CompositeConceptAST
{
public:
	VarDeclAST(CompositeConcept c);
	virtual void accept(Visitor* visitor, bool handleDepthSearch = true) override;
};

