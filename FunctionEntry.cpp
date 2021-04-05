#include "FunctionEntry.h"
#include <sstream>

string FunctionEntry::signatureString()
{
	std::stringstream ss;

	for (std::tuple<string, string, vector<int>> parameter : parameterVarList) {
		ss << std::get<0>(parameter);

		for (int arrayInd : std::get<2>(parameter)) {
			if (arrayInd == -1) {
				ss << "[]";
			}
			else {
				ss << "[" + std::to_string(arrayInd) + "]";
			}
		}

		ss << ", ";
	}

	return ss.str();
}

FunctionEntry::FunctionEntry()
{
}

string FunctionEntry::toString()
{
	return "function-" + name + "-" + signatureString();
}

string FunctionEntry::toDotString()
{
	return "<TR><TD>" + name + "</TD><TD>function</TD><TD>" + returnType + ":" + signatureString() + "</TD><TD PORT=\"" + "function-" + name + "-" + signatureString() + "\">+</TD></TR>\n";
}
