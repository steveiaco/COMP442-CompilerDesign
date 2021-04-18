#include "TemporaryEntry.h"

TemporaryEntry::TemporaryEntry()
{
}

string TemporaryEntry::toString()
{
	return "parameter-" + name + " " + type;
}

string TemporaryEntry::toDotString()
{
	return "<TR><TD>" + name + "</TD><TD>temp var</TD><TD>" + type + "</TD><TD>" + std::to_string(computeSize()) + "</TD><TD>" + std::to_string(offset) + "</TD><TD PORT=\"" + "tempvar-" + name + type + "\">/</TD></TR>\n";
}

int TemporaryEntry::computeSize()
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

	return baseSize;
}
