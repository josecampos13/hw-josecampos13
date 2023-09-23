#include "DivStatement.h"

DivStatement::DivStatement(std::string variableName, int value)
	: m_variableName( variableName ), m_value( value )
{}

DivStatement::DivStatement(std::string variableName, std::string variableName2)
	: m_variableName( variableName ), m_variableName_2( variableName2 ),
	  m_value(-1)
{}

void DivStatement::execute(ProgramState * state, std::ostream &outf)
{
	// Increment counter for every statement line
    state -> incrementCounter();

    // Check if key exists in map
    // If so Set m_value_2 to the keyvalue
    if (state -> checkMap(m_variableName_2)) {
        m_value_2 = state -> getMap(m_variableName_2);
    }
    // Otheriwse, just set m_value_2 to int value of m_value
    else {
        m_value_2 = m_value;
    }
    // Check for Divide by 0 exception
    if (m_value_2 == 0) {
	    std::cout << "Divide by 0 exception" << std::endl;
		exit(0);
	}

    // Edit existing value
    state -> setMap(m_variableName, (state -> getMap(m_variableName)) / m_value_2);


    return; 

}