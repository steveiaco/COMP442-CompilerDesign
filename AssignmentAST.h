#pragma once
#include "CompositeConceptTokenAST.h"
class AssignmentAST :
	public CompositeConceptTokenAST
{
public:
	AssignmentAST(Token token);
	virtual void accept(Visitor* visitor) override;
};

