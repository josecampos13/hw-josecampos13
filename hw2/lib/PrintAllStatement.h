#ifndef PRINTALL_STATEMENT_INCLUDED
#define PRINTALL_STATEMENT_INCLUDED

#include "Statement.h"
#include <iostream>

class PrintAllStatement : public Statement
{
    private:
    // Variables

    public:
    //CTOR
    PrintAllStatement();

    // Virtual Execute Funciton to perform statement functions
    virtual void execute(ProgramState * state, std::ostream &outf);

};

#endif