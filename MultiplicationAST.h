#pragma once
#include "CompositeConceptTokenAST.h"
class MultiplicationAST : public CompositeConceptTokenAST
{
public:
	MultiplicationAST(Token token);
	virtual void accept(Visitor* visitor, bool handleDepthSearch = true) override;
};

