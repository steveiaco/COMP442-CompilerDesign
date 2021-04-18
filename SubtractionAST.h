#pragma once
#include "CompositeConceptTokenAST.h"
class SubtractionAST : public CompositeConceptTokenAST
{
public:
	SubtractionAST(Token token);
	virtual void accept(Visitor* visitor, bool handleDepthSearch = true) override;
};

