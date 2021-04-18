#pragma once
#include <string>

using std::string;

class LabelGenerator
{
	int zeroLabels = 0;
	int nonZeroLabels = 0;
	int endAndLabels = 0;
	int endOrLabels = 0;
	int endNotLabels = 0;
	int elseLabels = 0;
	int endIfLabels = 0;
	int goWhileLabels = 0;
	int endWhileLabels = 0;
	int getStrLabels = 0;
	int endGetLabels = 0;

public:

	LabelGenerator();

	string generateZeroLabel();
	string generateNonZeroLabel();
	string generateEndAndLabel();
	string generateEndOrLabel();
	string generateEndNotLabel();
	string generateElseLabel();
	string generateEndIfLabel();
	string generateGoWhileLabel();
	string generateEndWhileLabel();
	string generateGetStrLabel();
	string generateEndGetLabel();
};

