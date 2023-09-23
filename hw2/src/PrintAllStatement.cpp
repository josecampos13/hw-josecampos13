#include "PrintAllStatement.h"

PrintAllStatement::PrintAllStatement()
{}

void PrintAllStatement::execute(ProgramState * state, std::ostream &outf)
{
    state -> incrementCounter();
    // Print entire map to outf
    state -> printMap(outf);
    return; 
}