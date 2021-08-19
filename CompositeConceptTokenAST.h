#pragma once
#include "TokenAST.h"
#include <sstream>

class CompositeConceptTokenAST : public TokenAST
{
public:
	CompositeConceptTokenAST(Token token);

	// Inherited via AST
	virtual void accept(Visitor* visitor, bool handleDepthSearch = true) override;
	virtual string toString() override;
	virtual string getAssemData() override;
};

