#pragma once
#include <vector>
#include <string>

class AST;
class SymTabEntry;
class ClassEntry;
class FunctionEntry;
class ParameterEntry;
class VariableEntry;
class TemporaryEntry;

using std::string;

class SymTab
{
private:
	AST* associatedNode;
	std::vector<SymTabEntry*> table;
	string name;

public:
	SymTab();
	void insertRecord(SymTabEntry* e);

	std::vector<ClassEntry*> getClassRecords();
	std::vector<FunctionEntry*> getFunctionRecords();
	std::vector<ParameterEntry*> getParameterRecords();
	std::vector<VariableEntry*> getVariableRecords();
	std::vector<TemporaryEntry*> getTemporaryRecords();

	ClassEntry* findClassRecord(string name);
	std::vector<FunctionEntry*> findFunctionRecord(string name);
	ParameterEntry* findParameterRecord(string name);
	VariableEntry* findVariableRecord(string name);
	TemporaryEntry* findTemporaryRecord(string name);

	string getName() { return name; }
	void setName(string name) { this->name = name; }

	AST* getNode() { return associatedNode; };
	void setNode(AST* node) { this->associatedNode = node; }

	int computeInternalOffset();
	int computeSize();

	string toDotString();
};

