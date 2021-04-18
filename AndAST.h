#pragma once
#include "CompositeConceptTokenAST.h"
class AndAST :
	public CompositeConceptTokenAST
{
public:
	AndAST(Token token);
	virtual void accept(Visitor* visitor, bool handleDepthSearch = true) override;
};

