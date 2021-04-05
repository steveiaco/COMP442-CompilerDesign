#pragma once
#include "SymTabEntry.h"
#include <vector>

using std::vector;
class ParameterEntry : public SymTabEntry
{
	string genereateSignature();
public:
	string type;
	vector<int> arrayIndices;

	ParameterEntry();

	// Inherited via SymTabEntry
	virtual string toString() override;

	// Inherited via SymTabEntry
	virtual string toDotString() override;
};

