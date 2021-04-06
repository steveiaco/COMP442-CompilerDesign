#include "SymTab.h"
#include "SymTabEntry.h"
#include "ClassEntry.h"
#include "FunctionEntry.h"
#include "ParameterEntry.h"
#include "VariableEntry.h"
#include <sstream>

SymTab::SymTab()
{
	associatedNode = nullptr;
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

std::vector<FunctionEntry*> SymTab::findFunctionRecord(string name)
{
	std::vector<FunctionEntry*> entries = getFunctionRecords();
	std::vector<FunctionEntry*> entriesFound;
	for (FunctionEntry* entry : entries) {
		if (entry->name == name) {
			entriesFound.push_back(entry);
		}
	}
	return entriesFound;
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

string SymTab::toDotString()
{
	std::stringstream currentTable;

	currentTable	<<	"\"" + name + "\"" + " [label=<\n"
					<<	"<TABLE BORDER = \"0\" CELLBORDER = \"1\" CELLSPACING = \"0\">\n"
					<<	"<TR><TD COLSPAN = \"4\">" + name + "</TD></TR>\n"
					<<	"<TR><TD>Name</TD><TD>Kind</TD><TD>Type</TD><TD>Link</TD></TR>\n";

	std::stringstream other;

	for (SymTabEntry* entry : table) {
		currentTable << entry->toDotString();
		if (entry->link) {
			other << entry->link->toDotString();
			other << "\"" << name << "\"" << ":\"" << entry->toString() << "\"->\"" << entry->link->name << "\"\n";
		}
	}

	currentTable << "</TABLE>>];\n";
	currentTable << other.str();

	return currentTable.str();
}
