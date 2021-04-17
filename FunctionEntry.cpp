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
	return "<TR><TD>" + name + "</TD><TD>function</TD><TD>" + returnType + ":" + signatureString() + "</TD><TD>" + std::to_string(computeSize()) + "</TD><TD>" + std::to_string(offset) + "</TD><TD PORT=\"" + "function-" + name + "-" + signatureString() + "\">+</TD></TR>\n";
}

bool FunctionEntry::compare(FunctionEntry* e)
{
	if (name == e->name && returnType == e->returnType && parameterVarList.size() == e->parameterVarList.size()) {
		bool fullMatch = true;
		for (int i = 0; i < parameterVarList.size(); i++) {
			auto t1 = parameterVarList[i];
			auto t2 = e->parameterVarList[i];

			if (!(std::get<0>(t1) == std::get<0>(t2) && std::get<2>(t1).size() == std::get<2>(t2).size())) {
				fullMatch = false;
			}
		}
		return fullMatch;
	}
	return false;
}

int FunctionEntry::computeSize()
{
	int baseSize = 0;

	if (link != nullptr) {
		baseSize = link->computeSize();
	}

	return baseSize;
}
