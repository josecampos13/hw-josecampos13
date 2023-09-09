#include <iostream>
using namespace std;


// Write a function that takes in a string and
// outputs all possible permutations of the input,
// one per line

// Helper function prototype
// 
void helper(char* word, int loc, int size);

void permutations(std::string in) {

    // Step 1: Determine size of string
    // Traverse string until Null Char
    int size = 0;
    int i = 0;
    while (in[i] != '\0') {
        size++;
        i++;
    }

    // Base Case, no recursion necessary
    // If String Size 1 or 0
    if (i <= 1) {
        cout << in << endl;
        return; 
    }

    // If string size > 1
    else {
        // Create a character array to manipulate
        char word[size];
        for (int j = 0; j < size; j++) {
            word[j] = in[j];
        }
        // Call on recursive helper function
        helper(word, 0, size);
    }
}


void helper(char* word, int loc, int size) {

    // Base Case: Reached the last character
    // Print this permutation 
    if (loc >= size) {
        for (int i = 0; i < size; i++) {
            cout << word[i];
        }
        cout << endl;
    }
    else {

        // Traverse the lenght of the array
        for (int i = loc; i < size; i++) {

            // Swap the characters
            char temp = word[loc];
            word[loc] = word[i];
            word[i] = temp;
            
            // Recursivly call helper function
            helper(word, loc + 1, size);

            // Swap back the characters
            word[i] = word[loc];
            word[loc] = temp;
        }
    }
    return;
}
