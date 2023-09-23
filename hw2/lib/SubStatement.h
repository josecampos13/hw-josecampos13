#ifndef SUB_STATEMENT_INCLUDED
#define SUB_STATEMENT_INCLUDED

#include "Statement.h"
#include <iostream>

class SubStatement : public Statement
{
    private:
    // Variables
    std::string m_variableName;
    std::string m_variableName_2;
	int m_value;
    int m_value_2;

    public:
    //CTOR
    SubStatement(std::string variableName, int value);
    SubStatement(std::string variableName, std::string variableName2);

    // Virtual Execute Funciton to perform statement functions
    virtual void execute(ProgramState * state, std::ostream &outf);

};

#endif