#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int getPrecedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

string infixToPrefix(const string& infix) {
    stack<char> operators;
    string prefix;

    // Reverse the infix expression
    string reversedInfix = infix;
    reverse(reversedInfix.begin(), reversedInfix.end());

    for (char c : reversedInfix) {
        if (isalnum(c)) {
            // Operand
            prefix += c;
        } else if (c == ')') {
            // Closing parenthesis
            operators.push(c);
        } else if (c == '(') {
            // Opening parenthesis
            while (!operators.empty() && operators.top() != ')') {
                prefix += operators.top();
                operators.pop();
            }
            operators.pop();  // Discard the matching ')'
        } else if (isOperator(c)) {
            // Operator
            while (!operators.empty() && getPrecedence(operators.top()) > getPrecedence(c)) {
                prefix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    // Process remaining operators in the stack
    while (!operators.empty()) {
        prefix += operators.top();
        operators.pop();
    }

    // Reverse the final result to get the prefix expression
    reverse(prefix.begin(), prefix.end());

    return prefix;
}

int main() {
    string infixExpression;

    // Get input from the user
    cout << "Enter an infix expression: ";
    getline(cin, infixExpression);

    // Convert infix to prefix
    string prefixExpression = infixToPrefix(infixExpression);

    // Display the result
    cout << "Prefix expression: " << prefixExpression << endl;

    return 0;
}
