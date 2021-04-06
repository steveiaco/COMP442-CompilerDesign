#include "Visitor.h"

void Visitor::reportError(string error, int line)
{
	string s = "Line " + std::to_string(line) + ": " + error;
	errorList.push_back(s);
}
