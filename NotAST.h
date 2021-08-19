#pragma once
#include "CompositeConceptTokenAST.h"
class NotAST :
	public CompositeConceptTokenAST
{
public:
	NotAST(Token token);
	virtual void accept(Visitor* visitor, bool handleDepthSearch = true) override;
};

