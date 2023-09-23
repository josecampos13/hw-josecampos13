#ifndef IF_STATEMENT_INCLUDED
#define IF_STATEMENT_INCLUDED

#include "Statement.h"
#include <iostream>

class IfStatement : public Statement
{
    private:
    // Variables
    std::string m_variableName;
    std::string operator_;
    int m_value;
    int line_num;

    public:
    //CTOR
    IfStatement(std::string variableName, std::string op, int value, int line);

    // Virtual Execute Funciton to perform statement functions
    virtual void execute(ProgramState * state, std::ostream &outf);

};

#endif