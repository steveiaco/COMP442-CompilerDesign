#pragma once
#include "VisibilityEntry.h"
#include <vector>

using std::vector;
class FunctionEntry : public VisibilityEntry
{
	string signatureString();
public:
	SymTab* containerClass;
	string classmethod;

	// type, arrayind
	string returnType;

	// type, id, arrayind
	vector<std::tuple<string, string, vector<int>>> parameterVarList;
	FunctionEntry();

	// Inherited via VisibilityEntry
	virtual string toString() override;

	// Inherited via VisibilityEntry
	virtual string toDotString() override;

	// Inherited via VisibilityEntry
	virtual bool compare(FunctionEntry* e);

	// Inherited via VisibilityEntry
	virtual int computeSize() override;
};

