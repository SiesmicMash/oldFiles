#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str = "Problem Solving with C++";
    transform(str.begin(), str.end(), str.begin(), ::toupper);  // transform str to uppercase
    cout << str << endl;

    int pos; // variable for position

    // find the position of "LEM"
    pos = str.find("LEM");
    if (pos != string::npos) {
        cout << "Position of 'LEM': " << pos << endl;
    }

    // find the position of "WITH" and replace it
    pos = str.find("WITH");
    if (pos != string::npos) {
        str.replace(pos, 4, "WITH AMAZING");  // Replace "WITH" with "WITH AMAZING"
    }
    cout << "Modified Sentence: " << str << endl;

    return 0;
}
