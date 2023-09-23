// Interpreter.cpp
#include "Statement.h"
#include "LetStatement.h"
#include "PrintStatement.h"
#include "AddStatement.h"
#include "DivStatement.h"
#include "EndStatement.h"
#include "GoSubStatement.h"
#include "GoToStatement.h"
#include "IfStatement.h"
#include "MultStatement.h"
#include "PrintAllStatement.h"
#include "ReturnStatement.h"
#include "SubStatement.h"
#include <vector>
#include <string>
#include <sstream> 
#include <fstream>
#include <cstdlib>


using namespace std;

// parseProgram() takes a filename as a parameter, opens and reads the
// contents of the file, and returns an vector of pointers to Statement.
void parseProgram(istream& inf, vector<Statement *> & program);

// parseLine() takes a line from the input file and returns a Statement
// pointer of the appropriate type.  This will be a handy method to call
// within your parseProgram() method.
Statement * parseLine(string line);

// interpretProgram() reads a program from the given input stream
// and interprets it, writing any output to the given output stream.
// Note:  you are required to implement this function!
void interpretProgram(istream& inf, ostream& outf);


int main()
{
        cout << "Enter BASIC program file name: ";
        string filename;
        getline(cin, filename);
        ifstream infile(filename.c_str());
        if (!infile)
        {
                cout << "Cannot open " << filename << "!" << endl;
                return 1;
        }
        interpretProgram(infile, cout);
		
}



void parseProgram(istream &inf, vector<Statement *> & program)
{
	program.push_back(NULL);
	string line;
	while( ! inf.eof() )
	{
		getline(inf, line);
		program.push_back( parseLine( line ) );
	}
}


Statement * parseLine(string line)
{
	Statement * statement;	
	stringstream ss;
	string type;
	string var;
	string var2;
	string first;
	string then;
	int val;
	int line_num;


	ss << line;
	ss >> first;
	ss >> type;
	
	if ( type == "LET" )
	{
		ss >> var;
		ss >> val;
		// Note:  Because the project spec states that we can assume the file
		//	  contains a syntactically legal program, we know that
		//	  any line that begins with "LET" will be followed by a space
		//	  and then a variable and then an integer value.
		statement = new LetStatement(var, val);
	}

	// Incomplete;  TODO:  Finish this function!
	// Write if statements for all other possible statments

	else if ( type == "PRINT") {
		ss >> var;
		statement = new PrintStatement(var);
	}

	else if ( type == "PRINTALL") {
		statement = new PrintAllStatement();
	}

	// For ADD, check whether value added is int or variable
	else if ( type == "ADD") {
		ss >> var;
		ss >> var2;

		// Check if second argument was digit or not
		// Check 2nd index also in case of negative number
		if (isdigit(var2[0]) || isdigit(var2[1])) {
			// If yes, convert to int
			val = stoi(var2);
			statement = new AddStatement(var,val);
		}
		else {
			// Otherwise pass var2 as the right argument
			statement = new AddStatement(var,var2);
		}
	}

	else if ( type == "SUB") {
		ss >> var;
		ss >> var2;

		// Check if second argument was digit or not
		// Check 2nd index also in case of negative number
		if (isdigit(var2[0]) || isdigit(var2[1])) {

			// If yes, convert to int
			val = stoi(var2);
			statement = new SubStatement(var,val);
		}
		else {
			// Otherwise pass var2 as the right argument
			statement = new SubStatement(var,var2);
		}
	}

	else if ( type == "MULT") {
		ss >> var;
		ss >> var2;

		// Check if second argument was digit or not
		// Check 2nd index also in case of negative number
		if (isdigit(var2[0]) || isdigit(var2[1])) {

			// If yes, convert to int
			val = stoi(var2);
			statement = new MultStatement(var,val);
		}
		else {
			// Otherwise pass var2 as the right argument
			statement = new MultStatement(var,var2);
		}
	}

	else if ( type == "DIV") {
		ss >> var;
		ss >> var2;

		// Check if second argument was digit or not
		// Check 2nd index also in case of negative number
		if (isdigit(var2[0]) || isdigit(var2[1])) {

			// If yes, convert to int
			val = stoi(var2);

			// Check to prevent division by 0
			if (val == 0) {
				cout << "Divide by 0 exception" << endl;
				exit(0);
			}
			statement = new DivStatement(var,val);
		}
		// Otherwise pass var2 as the right argument
		else {
			statement = new DivStatement(var,var2);
		}
	}

	else if ( type == "GOTO") {
		ss >> val;
		statement = new GoToStatement(val);
	}
	else if ( type == "IF") {
		ss >> var;
		// Var2 will be the operator
		ss >> var2;
		// val will be the right value
		ss >> val;
		// string to get past then
		ss >> then;
		ss >> line_num;

		statement = new IfStatement(var, var2, val, line_num);
	}
	else if ( type == "GOSUB") {
		ss >> val;
		statement = new GoSubStatement(val);
	}
	else if ( type == "RETURN") {
		statement = new ReturnStatement();
	}
	// END Statement, period(.) or invalid statements to make program terminate
	else { 
		statement = new EndStatement();
	}

	return statement;
}


void interpretProgram(istream& inf, ostream& outf)
{
	vector<Statement *> program;

	// Fills the vector with Statement pointers
	parseProgram( inf, program );

	// Create ProgramState based on size of program vector
	// Subtract 1 since first index is NULL
	ProgramState state(program.size() - 1);

	// Must use counter to iterate through 
	while (state.accessCounter() < program.size() - 1) {
		program[state.accessCounter()] -> execute(&state, outf);
	}
	
	// Deallocate program vector of Statement pointers
	for (unsigned int i = 0; i < program.size(); i++) {
		delete program[i];
	}
	program.clear();

	return;
}
