#pragma once
#include "CompositeConceptTokenAST.h"
class GreaterThanAST : public CompositeConceptTokenAST
{
public:
	GreaterThanAST(Token token);
	virtual void accept(Visitor* visitor, bool handleDepthSearch = true) override;
};

