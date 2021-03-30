#include "CompositeConceptTokenAST.h"

CompositeConceptTokenAST::CompositeConceptTokenAST(Token token) : TokenAST(token) 
{
}

void CompositeConceptTokenAST::accept(Visitor* visitor)
{
	AST* child = leftMostChild;
	while (child != nullptr) {
		child->accept(visitor);
		child = child->rightSibling;
	}
}

string CompositeConceptTokenAST::toString()
{
	std::stringstream ss;
	ss << (void const*)this;
	return getValue() + " (" + ss.str() + ")";
}
