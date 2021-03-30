#include "StringIdAST.h"

StringIdAST::StringIdAST(Token token) : TokenAST(token)
{
}

void StringIdAST::accept(Visitor* visitor)
{
	visitor->visit(this);
}

string StringIdAST::toString()
{
	return string();
}