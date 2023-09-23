#include "AddStatement.h"

AddStatement::AddStatement(std::string variableName, int value)
	: m_variableName( variableName ), m_value( value )
{}

AddStatement::AddStatement(std::string variableName, std::string variableName2)
    : m_variableName( variableName ), m_variableName_2( variableName2 )
{}

void AddStatement::execute(ProgramState * state, std::ostream &outf)
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

    // Don't change m_value otherwise it will affect future statements
    // Instead add m_value_2 to the keyvalue of the left variable
    state -> setMap(m_variableName, (state -> getMap(m_variableName)) + m_value_2);

    return; 
}