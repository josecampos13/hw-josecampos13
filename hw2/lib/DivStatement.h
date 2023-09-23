#ifndef DIV_STATEMENT_INCLUDED
#define DIV_STATEMENT_INCLUDED

#include "Statement.h"
#include <iostream>

class DivStatement : public Statement
{
    private:
    // Variables
    std::string m_variableName;
    std::string m_variableName_2;
	int m_value;
    int m_value_2;

    public:
    //CTOR
    DivStatement(std::string variableName, int value);
    DivStatement(std::string variableName, std::string variableName2);

    // Virtual Execute Funciton to perform statement functions
    virtual void execute(ProgramState * state, std::ostream &outf);

};

#endif