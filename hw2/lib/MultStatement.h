#ifndef MULT_STATEMENT_INCLUDED
#define MULT_STATEMENT_INCLUDED

#include "Statement.h"
#include <iostream>

class MultStatement : public Statement
{
    private:
    // Variables
    std::string m_variableName;
    std::string m_variableName_2;
	int m_value;
    int m_value_2;

    public:
    //CTOR
    MultStatement(std::string variableName, int value);
    MultStatement(std::string variableName, std::string variableName2);

    // Virtual Execute Funciton to perform statement functions
    virtual void execute(ProgramState * state, std::ostream &outf);

};

#endif