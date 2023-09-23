CXX = g++
CPPFLAGS = -g -Wall -std=c++11 -Ilib

all: .dirstamp Interpreter

Interpreter: src/Interpreter.cpp AddStatement.o DivStatement.o \
	EndStatement.o GoSubStatement.o GoToStatement.o \
	IfStatement.o LetStatement.o MultStatement.o \
	PrintAllStatement.o PrintStatement.o \
	ReturnStatement.o SubStatement.o \
	ProgramState.o
	$(CXX) $(CPPFLAGS) $^ -o $@

AddStatement.o: src/AddStatement.cpp lib/AddStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

DivStatement.o: src/DivStatement.cpp lib/DivStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

EndStatement.o: src/EndStatement.cpp lib/EndStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

GoSubStatement.o: src/GoSubStatement.cpp lib/GoSubStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

GoToStatement.o: src/GoToStatement.cpp lib/GoToStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

IfStatement.o: src/IfStatement.cpp lib/IfStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

LetStatement.o: src/LetStatement.cpp lib/LetStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

MultStatement.o: src/MultStatement.cpp lib/MultStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

PrintAllStatement.o: src/PrintAllStatement.cpp lib/PrintAllStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

PrintStatement.o: src/PrintStatement.cpp lib/PrintStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

ReturnStatement.o: src/ReturnStatement.cpp lib/ReturnStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

SubStatement.o: src/SubStatement.cpp lib/SubStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
 
ProgramState.o: src/ProgramState.cpp lib/ProgramState.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf *.o
.dirstamp:
	mkdir -p lib
	touch .dirstamp
