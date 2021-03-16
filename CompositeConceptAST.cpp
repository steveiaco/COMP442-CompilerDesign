#include "CompositeConceptAST.h"
#include <sstream>

CompositeConceptAST::CompositeConceptAST(CompositeConcept t) : concept(t)
{
}

string CompositeConceptAST::toString()
{
	std::stringstream ss;
	ss << (void const*)this;

	string cctext;

	switch (concept) {
		// Not part of the grammar
	case CompositeConcept::APARAMSLIST:
		cctext = "APARAMSLIST";
		break;
	case CompositeConcept::ARRAYDIMENSION:
		cctext = "ARRAYDIMENSION";
		break;
	case CompositeConcept::ARRAYSIZEREPTLIST:
		cctext = "ARRAYSIZEREPTLIST";
		break;
	case CompositeConcept::ASSIGNSTAT:
		cctext = "ASSIGNSTAT";
		break;
	case CompositeConcept::CLASSDECLBODYLIST:
		cctext = "CLASSDECLBODYLIST";
		break;
	case CompositeConcept::CLASSLIST:
		cctext = "CLASSLIST";
		break;
	case CompositeConcept::FPARAMSLIST:
		cctext = "FPARAMSLIST";
		break;
	case CompositeConcept::FUNCCALLSTAT:
		cctext = "FUNCCALLSTAT";
		break;
	case CompositeConcept::FUNCLIST:
		cctext = "FUNCLIST";
		break;
	case CompositeConcept::FUNCORVARLIST:
		cctext = "FUNCORVARLIST";
		break;
	case CompositeConcept::INDICEREPLIST:
		cctext = "INDICEREPLIST";
		break;
	case CompositeConcept::INHERITLIST:
		cctext = "INHERITLIST";
		break;
	case CompositeConcept::TERNARY:
		cctext = "TERNARY";
		break;
	case CompositeConcept::VARCALLSTAT:
		cctext = "VARCALLSTAT";
		break;
	case CompositeConcept::VARDECLLIST:
		cctext = "VARDECLLIST";
		break;


		// Part of the grammar
	case CompositeConcept::ARITHEXPR:
		cctext = "ARITHEXPR";
		break;
	case CompositeConcept::BREAK:
		cctext = "BREAK";
		break;
	case CompositeConcept::CLASSDECL:
		cctext = "CLASSDECL";
		break;
	case CompositeConcept::CLASSDECLBODY:
		cctext = "CLASSDECLBODY";
		break;
	case CompositeConcept::CLASSMETHOD:
		cctext = "CLASSMETHOD";
		break;
	case CompositeConcept::CONTINUE:
		cctext = "CONTINUE";
		break;
	case CompositeConcept::EXPR:
		cctext = "EXPR";
		break;
	case CompositeConcept::FPARAMS:
		cctext = "FPARAM";
		break;
	case CompositeConcept::FUNCBODY:
		cctext = "FUNCBODY";
		break;
	case CompositeConcept::FUNCDECL:
		cctext = "FUNCDECL";
		break;
	case CompositeConcept::FUNCDEF:
		cctext = "FUNCDEF";
		break;
	case CompositeConcept::FUNCHEAD:
		cctext = "FUNCHEAD";
		break;
	case CompositeConcept::FUNCSTAT:
		cctext = "FUNCSTAT";
		break;
	case CompositeConcept::FUNCTION:
		cctext = "FUNCTION";
		break;
	case CompositeConcept::IF:
		cctext = "IF";
		break;
	case CompositeConcept::INDICEREP:
		cctext = "INDICEREP";
		break;
	case CompositeConcept::INHERIT:
		cctext = "INHERIT";
		break;
	case CompositeConcept::PROG:
		cctext = "PROG";
		break;
	case CompositeConcept::READ:
		cctext = "READ";
		break;
	case CompositeConcept::RETURN:
		cctext = "RETURN";
		break;
	case CompositeConcept::START:
		cctext = "START";
		break;
	case CompositeConcept::STATEMENT:
		cctext = "STATEMENT";
		break;
	case CompositeConcept::STATEMENTLIST:
		cctext = "STATEMENTLIST";
		break;
	case CompositeConcept::VARDECL:
		cctext = "VARDECL";
		break;
	case CompositeConcept::VARIABLE:
		cctext = "VARIABLE";
		break;
	case CompositeConcept::WHILE:
		cctext = "WHILE";
		break;
	case CompositeConcept::WRITE:
		cctext = "WRITE";
		break;
	default:
		cctext = "MISSING TYPE SPECIFIER";
		break;
	}

	return cctext + " (" + ss.str() + ")";
}