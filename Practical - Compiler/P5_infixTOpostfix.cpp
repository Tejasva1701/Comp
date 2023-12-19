#include <iostream>
#include <stack>
#include <cctype>

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

string infixToPostfix(const string& infix) {
    stack<char> operators;
    string postfix;

    for (char c : infix) {
        if (isalnum(c)) {
            // Operand
            postfix += c;
        } else if (c == '(') {
            // Opening parenthesis
            operators.push(c);
        } else if (c == ')') {
            // Closing parenthesis
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop();  // Discard the matching '('
        } else if (isOperator(c)) {
            // Operator
            while (!operators.empty() && getPrecedence(operators.top()) >= getPrecedence(c)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    // Process remaining operators in the stack
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

int main() {
    string infixExpression;

    // Get input from the user
    cout << "Enter an infix expression: ";
    getline(cin, infixExpression);

    // Convert infix to postfix
    string postfixExpression = infixToPostfix(infixExpression);

    // Display the result
    cout << "Postfix expression: " << postfixExpression << endl;

    return 0;
}
