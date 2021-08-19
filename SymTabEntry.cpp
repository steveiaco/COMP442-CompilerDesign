#include "SymTabEntry.h"

SymTabEntry::SymTabEntry()
{
	this->link = nullptr;
}

int SymTabEntry::getOffset()
{
	return offset;
}
