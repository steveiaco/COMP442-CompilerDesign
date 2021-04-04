#pragma once
#include "VisibilityEntry.h"
#include "Token.h"
#include <vector>
#include "AST.h"

using std::vector;

class VariableEntry : public VisibilityEntry
{
public:
	string visibility;
	string type;
	vector<int> arrayIndices;

	VariableEntry();

	// Inherited via VisibilityEntry
	virtual string toString() override;
};

