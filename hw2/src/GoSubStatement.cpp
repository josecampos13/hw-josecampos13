#include "GoSubStatement.h"

GoSubStatement::GoSubStatement(int value) : line_num( value )
{}

void GoSubStatement::execute(ProgramState * state, std::ostream &outf)
{
    state -> incrementCounter();
    state -> pushStack(line_num);
}