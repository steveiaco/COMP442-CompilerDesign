#pragma once
#include "VisibilityEntry.h"
#include <vector>

using std::vector;
class FunctionEntry : public VisibilityEntry
{
public:
	string visibility;
	string classmethod;

	// type, arrayind
	string returnType;

	// type, id, arrayind
	vector<std::tuple<string, string, vector<int>>> parameterVarList;
	FunctionEntry();

	// Inherited via VisibilityEntry
	virtual string toString() override;
};

