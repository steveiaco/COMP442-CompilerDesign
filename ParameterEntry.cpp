#include "ParameterEntry.h"
#include <sstream>

ParameterEntry::ParameterEntry()
{
}

string ParameterEntry::toString()
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

	return "parameter: " + ss.str();
}
