#include "VoidAST.h"
#include <sstream>
#include "Visitor.h"

VoidAST::VoidAST(Token token) : TokenAST(token)
{
}

void VoidAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	visitor->visit(this);
}

string VoidAST::toString()
{
	std::stringstream ss;
	ss << (void const*)this;
	return getValue() + " (" + ss.str() + ")";
}
