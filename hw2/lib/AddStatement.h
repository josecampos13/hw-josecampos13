#ifndef ADD_STATEMENT_INCLUDED
#define ADD_STATEMENT_INCLUDED

#include "Statement.h"
#include <iostream>

class AddStatement : public Statement
{
    private:
    // Variables
    std::string m_variableName;
    std::string m_variableName_2;
	int m_value;
    int m_value_2;

    public:
    //CTORS
    AddStatement(std::string variableName, int value);
    AddStatement(std::string variableName, std::string variableName2);

    // Virtual Execute Funciton to perform statement functions
    virtual void execute(ProgramState * state, std::ostream &outf);

};

#endif