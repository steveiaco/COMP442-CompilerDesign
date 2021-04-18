#pragma once
#include "TokenAST.h"
#include <string>
#include "Token.h"

using std::string;

class StringAST : public TokenAST {
public:
	StringAST(Token token);

	// Inherited via TokenAST
	virtual string toString() override;
	virtual void accept(Visitor* visitor, bool handleDepthSearch = true) override;
};