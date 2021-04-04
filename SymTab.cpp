#include "SymTab.h"
#include "SymTabEntry.h"
#include "ClassEntry.h"
#include "FunctionEntry.h"
#include "ParameterEntry.h"
#include "VariableEntry.h"

SymTab::SymTab()
{
}

void SymTab::insertRecord(SymTabEntry* e)
{
	this->table.push_back(e);
}

std::vector<ClassEntry*> SymTab::getClassRecords()
{
	std::vector<ClassEntry*> entries;

	for (SymTabEntry* entry : table) {
		ClassEntry* casted = dynamic_cast<ClassEntry*>(entry);
		if (casted != nullptr) {
			entries.push_back(casted);
		}
	}
	return entries;
}

std::vector<FunctionEntry*> SymTab::getFunctionRecords()
{
	std::vector<FunctionEntry*> entries;

	for (SymTabEntry* entry : table) {
		FunctionEntry* casted = dynamic_cast<FunctionEntry*>(entry);
		if (casted != nullptr) {
			entries.push_back(casted);
		}
	}
	return entries;
}

std::vector<ParameterEntry*> SymTab::getParameterRecords()
{
	std::vector<ParameterEntry*> entries;

	for (SymTabEntry* entry : table) {
		ParameterEntry* casted = dynamic_cast<ParameterEntry*>(entry);
		if (casted != nullptr) {
			entries.push_back(casted);
		}
	}
	return entries;
}

std::vector<VariableEntry*> SymTab::getVariableRecords()
{
	std::vector<VariableEntry*> entries;

	for (SymTabEntry* entry : table) {
		VariableEntry* casted = dynamic_cast<VariableEntry*>(entry);
		if (casted != nullptr) {
			entries.push_back(casted);
		}
	}
	return entries;
}

ClassEntry* SymTab::findClassRecord(string name)
{
	std::vector<ClassEntry*> entries = getClassRecords();
	ClassEntry* entryFound = nullptr;
	for (ClassEntry* entry : entries) {
		if (entry->name == name) {
			entryFound = entry;
			break;
		}
	}
	return entryFound;
}

FunctionEntry* SymTab::findFunctionRecord(string name)
{
	std::vector<FunctionEntry*> entries = getFunctionRecords();
	FunctionEntry* entryFound = nullptr;
	for (FunctionEntry* entry : entries) {
		if (entry->name == name) {
			entryFound = entry;
			break;
		}
	}
	return entryFound;
}

ParameterEntry* SymTab::findParameterRecord(string name)
{
	std::vector<ParameterEntry*> entries = getParameterRecords();
	ParameterEntry* entryFound = nullptr;
	for (ParameterEntry* entry : entries) {
		if (entry->name == name) {
			entryFound = entry;
			break;
		}
	}
	return entryFound;
}

VariableEntry* SymTab::findVariableRecord(string name)
{
	std::vector<VariableEntry*> entries = getVariableRecords();
	VariableEntry* entryFound = nullptr;
	for (VariableEntry* entry : entries) {
		if (entry->name == name) {
			entryFound = entry;
			break;
		}
	}
	return entryFound;
}
