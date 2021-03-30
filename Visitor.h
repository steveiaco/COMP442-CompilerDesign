#pragma once
#include "AST.h"
#include "CompositeConceptAST.h"
#include "TokenAST.h"

class Visitor
{
private:
	virtual void visit(CompositeConceptAST* n) = 0;
	virtual void visit(TokenAST* n) = 0;

public:
	void visit(AST* n);
};

