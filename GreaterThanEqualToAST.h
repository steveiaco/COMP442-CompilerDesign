#pragma once
#include "CompositeConceptTokenAST.h"
class GreaterThanEqualToAST : public CompositeConceptTokenAST
{
public:
	GreaterThanEqualToAST(Token token);
	virtual void accept(Visitor* visitor, bool handleDepthSearch = true) override;
};

