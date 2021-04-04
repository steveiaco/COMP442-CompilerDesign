#include "BreakAST.h"
#include "Visitor.h"
#include <sstream>

BreakAST::BreakAST(Token token) : TokenAST(token) 
{
}

void BreakAST::accept(Visitor* visitor)
{
	visitor->visit(this);
}

string BreakAST::toString()
{
	std::stringstream ss;
	ss << (void const*)this;
	return getValue() + " (" + ss.str() + ")";
}
