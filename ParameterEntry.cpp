#include "ParameterEntry.h"
#include <sstream>

string ParameterEntry::genereateSignature()
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

ParameterEntry::ParameterEntry()
{
}

string ParameterEntry::toString()
{
	return "parameter-" + genereateSignature();
}

string ParameterEntry::toDotString()
{
	return "<TR><TD>" + name + "</TD><TD>parameter</TD><TD>" + genereateSignature() + "</TD><TD PORT=\"" + "parameter-" + genereateSignature() + "\">/</TD></TR>\n";
}
