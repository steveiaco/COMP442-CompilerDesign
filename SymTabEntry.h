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

	virtual string toString() = 0;
};

