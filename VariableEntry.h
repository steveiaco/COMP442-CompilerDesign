#pragma once
#include "SymTabEntry.h"
#include "Token.h"
#include <vector>
#include "AST.h"

using std::vector;

class VariableEntry : public SymTabEntry
{
public:
	string type;

	// -1 represents an empty array declaration (a[][2] => [-1,2])
	vector<int> indices;

	VariableEntry(string name, string type, vector<int> arrayInd);
};

