#pragma once
#include "SymTabEntry.h"
class TemporaryEntry :
	public SymTabEntry
{
public:
	TemporaryEntry();

	string data;
	string type;

	// Inherited via SymTabEntry
	virtual string toString() override;
	virtual string toDotString() override;

	// Inherited via SymTabEntry
	virtual int computeSize() override;
};

