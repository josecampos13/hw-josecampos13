#ifndef GOTO_STATEMENT_INCLUDED
#define GOTO_STATEMENT_INCLUDED

#include "Statement.h"
#include <iostream>

class GoToStatement : public Statement
{
    private:
    // Variables
    int line_num;

    public:
    //CTOR
    GoToStatement(int value);

    // Virtual Execute Funciton to perform statement functions
    virtual void execute(ProgramState * state, std::ostream &outf);

};

#endif