// ProgramState.h
//
// CS 104
//
// The ProgramState class encapsulates the state of an executing Facile
// program.  The state of a BASIC program consists of three parts:
//
//    * The program counter, which specifies the line number of the
//      statement that will execute next.
//    * A map, as explained by the problem writeup.
//    * A stack of integers, which is used to hold return lines for GOSUB
//      statements.
//
// We've provided you a start on this class, but you'll need to add methods
// to it as you go along.  In particular, you'll need methods to access and
// modify the state; these methods will be called primarily by the various
// execute() methods in the Statement subclasses, to allow the execution of
// a statement to change the state of a program.  For example, executing a
// GOTO statement will cause the program counter to be changed.

#ifndef PROGRAM_STATE_INCLUDED
#define PROGRAM_STATE_INCLUDED

#include <stack>
#include <map>

class ProgramState
{
public:
	ProgramState(int numLines);

	// You'll need to add a variety of methods here.  Rather than trying to
	// think of what you'll need to add ahead of time, add them as you find
	// that you need them.

	// Out of Bounds function
	bool outOfBounds(int line_num);

	// Counter Function
	unsigned int accessCounter();
	void incrementCounter();
	void changeCounter(int line_num);
	void maxCounter();

	// Map Functions
	int getMap(std::string key);
	void setMap(std::string key, int num);
	void printMap(std::ostream &outf);
	bool checkMap(std::string key);
	
	// Stack functions 
	void popStack();
	void pushStack(int line_num);

private:
	int m_numLines;
	// Specifies line number of the statement that will execute next
	unsigned int counter;
	std::map <std::string, int> mp;
	std::stack<int> st;
	
};

#endif
