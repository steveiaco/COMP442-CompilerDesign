#include "CompositeConceptAST.h"
#include "Visitor.h"
#include <sstream>

CompositeConceptAST::CompositeConceptAST(CompositeConcept t) : cconcept(t)
{
}

CompositeConcept CompositeConceptAST::getCompositeConcept()
{
	return cconcept;
}

void CompositeConceptAST::accept(Visitor* visitor)
{
	AST* child = leftMostChild;
	while (child != nullptr) {
		child->accept(visitor);
		child = child->rightSibling;
	}
}

string CompositeConceptAST::toString()
{
	std::stringstream ss;
	ss << (void const*)this;

	return EnumDeclarations::compositeConceptToString(cconcept) + " (" + ss.str() + ")";
}