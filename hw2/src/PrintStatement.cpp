// PrintStatement.cpp:
#include "PrintStatement.h"

PrintStatement::PrintStatement(std::string variableName)
	: m_variableName( variableName )
{}


void PrintStatement::execute(ProgramState* state, std::ostream &outf)
{
	state -> incrementCounter();
	// Check if Variable does not exist
	// If not, insert and set to 0
	if ( !(state -> checkMap(m_variableName)) ) {
		state -> setMap(m_variableName, 0);
	}
	// Find keyvalue of the m_variableName
	// Add to ostream
	outf << state -> getMap(m_variableName) << std::endl;
	return;
}
