#pragma once
#include <string>
#include "EnumDeclarations.h"

using std::string;

class SymTabEntry
{
public:
	string name;
	SymTabEntry* link;
};

