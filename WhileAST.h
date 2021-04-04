#pragma once
#include "CompositeConceptAST.h"
#include <string>
#include "Token.h"

using std::string;

class WhileAST : public CompositeConceptAST {
public:
	WhileAST(CompositeConcept c);
	virtual void accept(Visitor* visitor) override;
};