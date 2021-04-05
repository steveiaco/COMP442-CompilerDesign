#pragma once
#include <vector>
#include <string>

class SymTabEntry;
class ClassEntry;
class FunctionEntry;
class ParameterEntry;
class VariableEntry;

using std::string;

class SymTab
{
private:
	std::vector<SymTabEntry*> table;
	string name;

public:
	SymTab();
	void insertRecord(SymTabEntry* e);

	std::vector<ClassEntry*> getClassRecords();
	std::vector<FunctionEntry*> getFunctionRecords();
	std::vector<ParameterEntry*> getParameterRecords();
	std::vector<VariableEntry*> getVariableRecords();

	ClassEntry* findClassRecord(string name);
	FunctionEntry* findFunctionRecord(string name);
	ParameterEntry* findParameterRecord(string name);
	VariableEntry* findVariableRecord(string name);

	string getName() { return name; }
	void setName(string name) { this->name = name; }

	string toDotString();
};

