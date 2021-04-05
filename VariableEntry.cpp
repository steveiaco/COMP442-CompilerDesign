#include "VariableEntry.h"
#include <sstream>

string VariableEntry::genereateSignature()
{
	std::stringstream ss;

	ss << type;

	for (int arrayInd : arrayIndices) {
		if (arrayInd == -1) {
			ss << "[]";
		}
		else {
			ss << "[" + std::to_string(arrayInd) + "]";
		}
	}

	return ss.str();
}

VariableEntry::VariableEntry()
{
}

string VariableEntry::toString()
{
	return "variable-"+ genereateSignature();
}

string VariableEntry::toDotString()
{
	return "<TR><TD>" + name + "</TD><TD>variable</TD><TD>" + genereateSignature() + "</TD><TD PORT=\"" + "variable-" + genereateSignature() + "\">/</TD></TR>\n";
}
