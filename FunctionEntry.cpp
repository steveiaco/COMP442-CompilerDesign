#include "FunctionEntry.h"
#include <sstream>

FunctionEntry::FunctionEntry()
{
}

string FunctionEntry::toString()
{
	std::stringstream ss;

	for (std::tuple<string, string, vector<int>> parameter : parameterVarList) {
		ss << std::get<0>(parameter);

		for (int arrayInd : std::get<2>(parameter)) {
			if (arrayInd == -1) {
				ss << "[]";
			}
			else {
				ss << "[" + std::to_string(arrayInd)+ "]";
			}
		}

		ss << ", ";
	}

	return "function: " + name +
		"\n\treturn type: " + returnType +
		"\n\tparameters: " + ss.str();
}
