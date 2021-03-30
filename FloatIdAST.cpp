#include "FloatIdAST.h"

FloatIdAST::FloatIdAST(Token token) : TokenAST(token)
{
}

void FloatIdAST::accept(Visitor* visitor)
{
}

string FloatIdAST::toString()
{
	return string();
}
