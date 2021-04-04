#include "Visitor.h"

void Visitor::reportError(string error)
{
	errorList.push_back(error);
}
