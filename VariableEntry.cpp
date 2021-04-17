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
	return "<TR><TD>" + name + "</TD><TD>variable</TD><TD>" + genereateSignature() + "</TD><TD>" + std::to_string(computeSize()) + "</TD><TD>" + std::to_string(offset) + "</TD><TD PORT=\"" + "variable-" + genereateSignature() + "\">/</TD></TR>\n";
}

int VariableEntry::computeSize()
{
	int baseSize = 0;
	if (type == "integer") {
		baseSize = 4;
	}
	else if (type == "float") {
		baseSize = 8;
	}
	else if (type == "string") {
		//baseSize = ???
	}
	// class detected
	else {
		if (link != nullptr) {
			baseSize = link->computeSize();
		}
	}

	int arrayElements = 1;
	for (int size : arrayIndices) {
		if (size == -1) {
			// undefined behavior, the array size was not specified
			continue;
		}
		arrayElements *= size;
	}

	return baseSize * arrayElements;
}
