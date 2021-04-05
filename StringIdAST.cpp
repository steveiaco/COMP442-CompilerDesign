#include "StringIdAST.h"
#include "Visitor.h"

StringIdAST::StringIdAST(Token token) : TokenAST(token)
{
}

void StringIdAST::accept(Visitor* visitor)
{
	visitor->visit(this);
}

string StringIdAST::toString()
{
	std::stringstream ss;
	ss << "integer ";
	ss << "(" << (void const*)this << ")";
	return ss.str();
}
