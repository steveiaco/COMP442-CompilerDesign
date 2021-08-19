#include "LabelGenerator.h"

LabelGenerator::LabelGenerator()
{
}

string LabelGenerator::generateZeroLabel()
{
	return "zero" + std::to_string(zeroLabels++);
}

string LabelGenerator::generateNonZeroLabel()
{
	return "nonzero" + std::to_string(nonZeroLabels++);
}

string LabelGenerator::generateEndAndLabel()
{
	return "endand" + std::to_string(endAndLabels++);
}

string LabelGenerator::generateEndOrLabel()
{
	return "endor" + std::to_string(endOrLabels++);
}

string LabelGenerator::generateEndNotLabel()
{
	return "endNot" + std::to_string(endNotLabels++);
}

string LabelGenerator::generateElseLabel()
{
	return "else" + std::to_string(endNotLabels++);
}

string LabelGenerator::generateEndIfLabel()
{
	return "endif" + std::to_string(endIfLabels++);
}

string LabelGenerator::generateGoWhileLabel()
{
	return "gowhile" + std::to_string(goWhileLabels++);
}

string LabelGenerator::generateEndWhileLabel()
{
	return "endwhile" + std::to_string(endWhileLabels++);
}

string LabelGenerator::generateGetStrLabel()
{
	return "getstr" + std::to_string(getStrLabels++);
}

string LabelGenerator::generateEndGetLabel()
{
	return "endget" + std::to_string(endGetLabels++);
}
