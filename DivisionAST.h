#pragma once
#include "CompositeConceptTokenAST.h"
class DivisionAST : public CompositeConceptTokenAST
{
public:
	DivisionAST(Token token);
	virtual void accept(Visitor* visitor, bool handleDepthSearch = true) override;
};

