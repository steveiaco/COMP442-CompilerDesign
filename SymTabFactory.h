#pragma once
#include "SymTabEntry.h"
#include "SymTab.h"
#include <vector>
#include "FunctionEntry.h"
#include "VariableEntry.h"
#include "ClassEntry.h"
#include "ParameterEntry.h"
#include "TemporaryEntry.h"

using std::vector;

class SymTabFactory
{
	static vector<SymTabEntry*> recordsCreated;
	static vector<SymTab*> tablesCreated;
public:

	static SymTab* makeSymTab();
	
	static VariableEntry* makeSymVariableRec();
	static ClassEntry* makeSymClassRec();
	static FunctionEntry* makeSymFunctionEntry();
	static ParameterEntry* makeSymParameterEntry();
	static TemporaryEntry* makeSymTemporaryEntry();
};

