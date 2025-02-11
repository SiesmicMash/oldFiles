#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Initialize vector of strings with some initial values
    vector<string> words = { "apple", "banana", "cherry", "date" };

    // Add "elderberry" to the vector
    words.push_back("elderberry");

    // Sort the vector in alphabetical order
    sort(words.begin(), words.end());

    // Search for "cherry" and print its position
    int position = -1;
    for (int i = 0; i < words.size(); i++) {
        if (words[i] == "cherry") {
            position = i;
            break;
        }
    }
    if (position != -1) {
        cout << "Position of 'cherry': " << position << endl;
    }
    else {
        cout << "'cherry' not found" << endl;
    }

    // Remove "banana" from the vector
    for (int i = 0; i < words.size(); i++) {
        if (words[i] == "banana") {
            words.erase(words.begin() + i);
            break;
        }
    }

    // Print the final list of words
    cout << "Final list of words: ";
    for (int i = 0; i < words.size(); i++) {
        cout << words[i] << " ";
    }
    cout << endl;

    return 0;
}
