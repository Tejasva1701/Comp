#include <iostream>
#include <cctype>

using namespace std;

bool isOperator(char ch) {
    // Define the operators you want to identify
    string operators = "+-*/%^=";

    size_t found = operators.find(ch);
    if (found != string::npos) {
        return true;  // Character is found in the string of operators
    } else {
        return false; // Character is not found in the string of operators
    }
}

int main() {
    string inputString;

    // Get input from the user
    cout << "Enter a string: ";
    getline(cin, inputString);

    // Process the string and identify alphanumeric characters and operators
    cout << "Identified tokens:\n";
    for (char character : inputString) {
        if (isalnum(character)) {
            cout << "Alphanumeric: " << character << endl;
        } else if (isOperator(character)) {
            cout << "Operator: " << character << endl;
        }
        // Add more conditions if needed (e.g., for special characters)
    }

    return 0;
}
