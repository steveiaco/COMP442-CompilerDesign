#include "FloatAST.h"
#include <sstream>
#include "Visitor.h"

FloatAST::FloatAST(Token token) : TokenAST(token)
{
}

string FloatAST::toString()
{
	std::stringstream ss;
	ss << (void const*)this;
	return "float: " + getToken().getLexeme() + " (" + ss.str() + ")";
}

void FloatAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	visitor->visit(this);
}
