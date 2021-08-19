#pragma once
#include <string>
#include "EnumDeclarations.h"
#include "SymTab.h"

using std::string;

class SymTabEntry
{
protected:
	SymTabEntry();
public:
	string name;
	string visibility;
	SymTab* link;
	int offset;

	virtual string toString() = 0;
	virtual string toDotString() = 0;

	virtual int computeSize() = 0;
	virtual int getOffset();
};

