#pragma once
#include "CompositeConceptAST.h"


class AParamsListAST :
	public CompositeConceptAST
{
public:
	AParamsListAST(CompositeConcept c);
	virtual void accept(Visitor* visitor, bool handleDepthSearch = true) override;
};

