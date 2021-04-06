#pragma once
#include "SymTabEntry.h"
class VisibilityEntry : public SymTabEntry
{
public:
	string visibility;
	VisibilityEntry();

	// Inherited via SymTabEntry
	virtual string toString() = 0;
	virtual string toDotString() = 0;
};

