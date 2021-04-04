#include "VariableEntry.h"
#include <sstream>

VariableEntry::VariableEntry()
{
}

string VariableEntry::toString()
{
	std::stringstream ss;

	for (int arrayInd : arrayIndices) {
		if (arrayInd == -1) {
			ss << "[]";
		}
		else {
			ss << "[" + std::to_string(arrayInd) + "]";
		}
	}

	return "variable: " + ss.str();
}
