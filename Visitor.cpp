#include "Visitor.h"

void Visitor::reportError(string error, int line)
{
	errorList.push_back("Line " + std::to_string(line) + ": " + error);
}
