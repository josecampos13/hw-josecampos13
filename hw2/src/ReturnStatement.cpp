#include "ReturnStatement.h"

ReturnStatement::ReturnStatement()
{}

void ReturnStatement::execute(ProgramState * state, std::ostream &outf)
{
    state -> incrementCounter();
    // Returning means you pop the last line_num
    state -> popStack();
}