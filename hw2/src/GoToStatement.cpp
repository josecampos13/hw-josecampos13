#include "GoToStatement.h"

GoToStatement::GoToStatement(int value) : line_num( value )
{}

void GoToStatement::execute(ProgramState * state, std::ostream &outf)
{
    state -> changeCounter(line_num);
}