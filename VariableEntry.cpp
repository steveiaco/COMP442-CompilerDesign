#include "VariableEntry.h"

VariableEntry::VariableEntry(string name, string type, vector<int> arrayInd)
{
	this->name = name;
	this->type = type;
	this->indices = arrayInd;
}
