#pragma once
#include "TokenAST.h"
#include <string>
#include "Token.h"

using std::string;

class IdAST : public TokenAST {
public:
	IdAST(Token token);

	// Inherited via TokenAST
	virtual string toString() override;
	virtual void accept(Visitor* visitor) override;
};