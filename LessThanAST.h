#pragma once
#include "CompositeConceptTokenAST.h"
class LessThanAST : public CompositeConceptTokenAST
{
public:
	LessThanAST(Token token);
	virtual void accept(Visitor* visitor, bool handleDepthSearch = true) override;
};

