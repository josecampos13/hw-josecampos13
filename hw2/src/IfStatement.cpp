#include "IfStatement.h"


// Need to change this
IfStatement::IfStatement(std::string variableName, std::string op, int value, int line)
	: m_variableName( variableName ), operator_( op ), m_value( value ),
	  line_num( line )
{}

void IfStatement::execute(ProgramState * state, std::ostream &outf)
{
	// Check first if variable doesn't yet exist
	// Create in map if necessary
	if ( !(state -> checkMap(m_variableName)) ) {
		state -> setMap(m_variableName, 0);
	}
	
	// Get keyvalue of the left variable
	int left = state -> getMap(m_variableName);
	bool check = false;

	// Read through operator string to determine which to use
	// Change bool value accordinly
	if (operator_ == ">") {

		check = (left > m_value);
	}
	else if (operator_ == ">=") {

		check = (left >= m_value);
	}
	else if (operator_ == "<") {

		check = (left < m_value);
	}
	else if (operator_ == "<=") {

		check = (left <= m_value);
	}
	else if (operator_ == "=") {

		check = (left == m_value);
	}
	else if (operator_ == "<>") {

		check = (left != m_value);
	}

	// If operator returned true, GOTO
	if (check) {
		state -> changeCounter(line_num);
	}
	// Otherwise, just move to next line
	else {
		state -> incrementCounter();
	}

}