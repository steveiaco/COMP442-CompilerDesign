#pragma once
#include "SymTabEntry.h"
#include <vector>

using std::vector;
class ClassEntry : public SymTabEntry
{
public:
	//vector<std::pair<string, SymTab*>> inheritList;
	ClassEntry();

	// Inherited via SymTabEntry
	virtual string toString() override;

	// Inherited via SymTabEntry
	virtual string toDotString() override;

	// Inherited via SymTabEntry
	virtual int computeSize() override;
};

