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
	return "<TR><TD>" + name + "</TD><TD>class</TD><TD></TD><TD PORT=\"" + "class-" + name + "\">+</TD></TR>\n";
}
