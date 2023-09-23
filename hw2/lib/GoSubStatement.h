#ifndef GOSUB_STATEMENT_INCLUDED
#define GOSUB_STATEMENT_INCLUDED

#include "Statement.h"
#include <iostream>

class GoSubStatement : public Statement
{
    private:
    // Variables
    int line_num;

    public:
    //CTOR
    GoSubStatement(int value);

    // Virtual Execute Funciton to perform statement functions
    virtual void execute(ProgramState * state, std::ostream &outf);

};

#endif