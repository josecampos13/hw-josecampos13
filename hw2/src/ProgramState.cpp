#include "ProgramState.h"
#include <iostream>

// Constructor
ProgramState::ProgramState(int numLines) : m_numLines(numLines), counter(1)
{}

// Check if line_num passed in exceeds number of lines existing
bool ProgramState::outOfBounds(int line_num) {
    return  line_num > m_numLines;
}

// Function to access private counter
unsigned int ProgramState::accessCounter() {
    return counter;
}

// Increment Counter by 1
void ProgramState::incrementCounter() {
    counter++;
}

// Change counter according to line_num passed
void ProgramState::changeCounter(int line_num) {
    // Check if line_num is out of bounds
    if (outOfBounds(line_num)) {
        std::cout << "Illegal jump instruction" << std::endl;
        exit(0);
    }
    else {
        counter = line_num;
    }
}

// Change counter to move ot last line
void ProgramState::maxCounter() {
    counter = m_numLines;
}

// Check if key exists
bool ProgramState::checkMap(std::string key) {
    return mp.count(key);
}

// Needed for print, we want the int assigned to key
int ProgramState::getMap(std::string key)
{
    // Check if key exists in the map first
    // If not found, return 0
    if (!checkMap(key)) {
        return 0;
    }
    return mp[key];
}

// Insert Value into the map
void ProgramState::setMap(std::string key, int num)
{
    // Check if key already exists in map
    // If it does, edit existing keyvalue
    if (checkMap(key)) {
        mp.find(key) -> second = num;
    }
    else {
        mp.insert(std::pair<std::string, int> (key, num));
    }
    return; 
}

// User iterator to walk through and print the map
// Needed for PrintAll
void ProgramState::printMap(std::ostream &outf)
{
    std::map<std::string, int>::iterator it;

    for (it = mp.begin(); it != mp.end(); ++it) {
        outf << it->first << " " << it->second << std::endl;
    }
    return;
}

// Pop stack when return to a line number
void ProgramState::popStack() 
{
    // If stack is empty, terminate program
    if (st.empty()) {
        exit(0);
    }
    // Reset counter to original value before popping
    counter = st.top();
    st.pop();
    return; 
}

// Push line_num onto stack when we jump lines
void ProgramState::pushStack(int line_num)
{
    if (outOfBounds(line_num)) {
        std::cout << "Illegal jump instruction" << std::endl;
        exit(0);
    }
    else {
        // Push old value of counter onto stack
        // Keep track of which line to go back to
        st.push(counter);

        // Change counter to line_num we are jumping to
        counter = line_num; 
    }
}