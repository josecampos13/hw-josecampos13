This file runs according to the demands of the assignment

1. make clean
2. make
3. ./Interpreter
4. Input the test file


All 12 Statement classes inherit from the abstract Statement.h abstract class

In Interpreter.cpp, the program parses through the inputted file
It dynamically allocates Statement objects accordingly
These Statements are pushed into the program vector of Statement pointers

A ProgramState is created according to how how many lines are in the file
The ProgramState counter is used to iterate through the vector of Statement pointers
As it walks through the vector, Statement class's execute function is called

All of these execute functions use ProgramState functions to perform the necessary actions

At the end, the vector is deallocated to prevent memory leaks