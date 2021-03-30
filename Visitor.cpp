#include "Visitor.h"

void Visitor::visit(AST* n)
{
	if (CompositeConceptAST* c = dynamic_cast<CompositeConceptAST*>(n)) {
		visit(c);
	}
	else if (GeneralTokenAST* c = dynamic_cast<GeneralTokenAST*>(n)) {
		visit(c);
	}
}