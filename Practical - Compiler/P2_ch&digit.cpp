#include <iostream>
#include <cctype> // For isdigit and isalpha functions

using namespace std;

int main() {
    string inputString;

    // Get input from the user
    cout << "Enter a string: ";
    getline(cin, inputString);

    // Process the string and identify tokens
    cout << "Identified tokens:\n";
    for (char character : inputString) {
        if (isdigit(character)) {
            cout << "Digit: " << character << endl;
        } else if (isalpha(character)) {
            cout << "Character: " << character << endl;
        }
        // Add more conditions if needed (e.g., for special characters)
    }

    return 0;
}
