#include "EnumDeclarations.h"


std::string EnumDeclarations::nonTerminalToString(NonTerminal t) {
	std::string s;

	switch (t) {
	case NonTerminal::ADDOP:
		s = "ADDOP";
		break;
	case NonTerminal::APARAMSTAIL:
		s = "APARAMSTAIL";
		break;
	case NonTerminal::ARITHEXPRTAIL:
		s = "ARITHEXPRTAIL";
		break;
	case NonTerminal::ASSIGNOP:
		s = "ASSIGNOP";
		break;
	case NonTerminal::CLASSDECLBODY:
		s = "CLASSDECLBODY";
		break;
	case NonTerminal::EXPRTAIL:
		s = "EXPRTAIL";
		break;
	case NonTerminal::ARITHEXPR:
		s = "ARITHEXPR";
		break;
	case NonTerminal::FPARAMSTAIL:
		s = "FPARAMSTAIL";
		break;
	case NonTerminal::CLASSMETHOD:
		s = "CLASSMETHOD";
		break;
	case NonTerminal::FPARAMS:
		s = "FPARAMS";
		break;
	case NonTerminal::FUNCDECLTAIL:
		s = "FUNCDECLTAIL";
		break;
	case NonTerminal::FUNCORASSIGNSTATIDNESTFUNCTAIL:
		s = "FUNCORASSIGNSTATIDNESTFUNCTAIL";
		break;
	case NonTerminal::FUNCORASSIGNSTATIDNESTVARTAIL:
		s = "FUNCORASSIGNSTATIDNESTVARTAIL";
		break;
	case NonTerminal::FUNCORASSIGNSTATIDNEST:
		s = "FUNCORASSIGNSTATIDNEST";
		break;
	case NonTerminal::ASSIGNSTATTAIL:
		s = "ASSIGNSTATTAIL";
		break;
	case NonTerminal::FUNCORVAR:
		s = "FUNCORVAR";
		break;
	case NonTerminal::FUNCORVARIDNESTTAIL:
		s = "FUNCORVARIDNESTTAIL";
		break;
	case NonTerminal::FUNCORVARIDNEST:
		s = "FUNCORVARIDNEST";
		break;
	case NonTerminal::APARAMS:
		s = "APARAMS";
		break;
	case NonTerminal::FUNCSTATTAILIDNEST:
		s = "FUNCSTATTAILIDNEST";
		break;
	case NonTerminal::FUNCSTATTAIL:
		s = "FUNCSTATTAIL";
		break;
	case NonTerminal::FUNCTION:
		s = "FUNCTION";
		break;
	case NonTerminal::FUNCHEAD:
		s = "FUNCHEAD";
		break;
	case NonTerminal::INHERIT:
		s = "INHERIT";
		break;
	case NonTerminal::INTNUM:
		s = "INTNUM";
		break;
	case NonTerminal::MEMBERDECL:
		s = "MEMBERDECL";
		break;
	case NonTerminal::FUNCDECL:
		s = "FUNCDECL";
		break;
	case NonTerminal::METHODBODYVAR:
		s = "METHODBODYVAR";
		break;
	case NonTerminal::NESTEDID:
		s = "NESTEDID";
		break;
	case NonTerminal::CLASSDECL:
		s = "CLASSDECL";
		break;
	case NonTerminal::FUNCDEF:
		s = "FUNCDEF";
		break;
	case NonTerminal::FUNCBODY:
		s = "FUNCBODY";
		break;
	case NonTerminal::RELOP:
		s = "RELOP";
		break;
	case NonTerminal::SIGN:
		s = "SIGN";
		break;
	case NonTerminal::START:
		s = "START";
		break;
	case NonTerminal::PROG:
		s = "PROG";
		break;
	case NonTerminal::FUNCORASSIGNSTAT:
		s = "FUNCORASSIGNSTAT";
		break;
	case NonTerminal::STATBLOCK:
		s = "STATBLOCK";
		break;
	case NonTerminal::EXPR:
		s = "EXPR";
		break;
	case NonTerminal::STATEMENT:
		s = "STATEMENT";
		break;
	case NonTerminal::STATEMENTLIST:
		s = "STATEMENTLIST";
		break;
	case NonTerminal::TERM:
		s = "TERM";
		break;
	case NonTerminal::MULTOP:
		s = "MULTOP";
		break;
	case NonTerminal::FACTOR:
		s = "FACTOR";
		break;
	case NonTerminal::TERMTAIL:
		s = "TERMTAIL";
		break;
	case NonTerminal::TYPE:
		s = "TYPE";
		break;
	case NonTerminal::ARRAYSIZEREPT:
		s = "ARRAYSIZEREPT";
		break;
	case NonTerminal::VARDECL:
		s = "VARDECL";
		break;
	case NonTerminal::VARDECLREP:
		s = "VARDECLREP";
		break;
	case NonTerminal::VARIABLE:
		s = "VARIABLE";
		break;
	case NonTerminal::INDICEREP:
		s = "INDICEREP";
		break;
	case NonTerminal::VARIABLEIDNESTTAIL:
		s = "VARIABLEIDNESTTAIL";
		break;
	case NonTerminal::VARIABLEIDNEST:
		s = "VARIABLEIDNEST";
		break;
	case NonTerminal::VISIBILITY:
		s = "VISIBILITY";
		break;
	}
	return s;
}