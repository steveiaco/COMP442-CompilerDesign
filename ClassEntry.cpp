#include "ClassEntry.h"

ClassEntry::ClassEntry()
{
}

string ClassEntry::toString()
{
	return "class-" + name;
}

string ClassEntry::toDotString()
{
	return "<TR><TD>" + name + "</TD><TD>class</TD><TD></TD><TD>" + std::to_string(computeSize()) + "</TD><TD>" + std::to_string(offset) + "</TD><TD PORT=\"" + "class-" + name + "\">+</TD></TR>\n";
}

int ClassEntry::computeSize()
{
	int baseSize = 0;

	if (link != nullptr) {
		baseSize = link->computeSize();
	}

	return baseSize;
}
