#include "IdAST.h"
#include <sstream>
#include "Visitor.h"


IdAST::IdAST(Token token) : TokenAST(token)
{
}

string IdAST::toString()
{
	std::stringstream ss;
	ss << (void const*)this;
	return "ID: " + getValue() + " (" + ss.str() + ")";
}

void IdAST::accept(Visitor* visitor)
{
	visitor->visit(this);
}