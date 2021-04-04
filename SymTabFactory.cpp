#include "SymTabFactory.h"

vector<SymTabEntry*> SymTabFactory::recordsCreated;
vector<SymTab*> SymTabFactory::tablesCreated;

SymTab* SymTabFactory::makeSymTab()
{
	SymTab* t = new SymTab();
	tablesCreated.push_back(t);
	return t;
}

VariableEntry* SymTabFactory::makeSymVariableRec()
{
	VariableEntry* r = new VariableEntry();
	recordsCreated.push_back(r);
	return r;
}

ClassEntry* SymTabFactory::makeSymClassRec()
{
	ClassEntry* r = new ClassEntry();
	recordsCreated.push_back(r);
	return r;
}

FunctionEntry* SymTabFactory::makeSymFunctionEntry()
{
	FunctionEntry* r = new FunctionEntry();
	recordsCreated.push_back(r);
	return r;
}

ParameterEntry* SymTabFactory::makeSymParameterEntry()
{
	ParameterEntry* r = new ParameterEntry();
	recordsCreated.push_back(r);
	return r;
}
