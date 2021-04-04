#include "FuncDeclAST.h"
#include "Visitor.h"

FuncDeclAST::FuncDeclAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void FuncDeclAST::accept(Visitor* visitor)
{
	CompositeConceptAST::accept(visitor);
	visitor->visit(this);
}
