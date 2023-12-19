#include <iostream>
#include <vector>

using namespace std;

class Stack {
private:
    vector<int> elements;

public:
    // Function to push an element onto the stack
    void push(int value) {
        elements.push_back(value);
        cout << value << " pushed onto the stack.\n";
    }

    // Function to pop an element from the stack
    void pop() {
        if (elements.empty()) {
            cout << "Stack underflow. Cannot pop from an empty stack.\n";
        } else {
            int poppedValue = elements.back();
            elements.pop_back();
            cout << poppedValue << " popped from the stack.\n";
        }
    }

    // Function to display the elements of the stack
    void display() {
        if (elements.empty()) {
            cout << "Stack is empty.\n";
        } else {
            cout << "Stack elements: ";
            for (int element : elements) {
                cout << element << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    Stack myStack;
    int choice, value;

    while (true) {
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter the value to push: ";
            cin >> value;
            myStack.push(value);
        } else if (choice == 2) {
            myStack.pop();
        } else if (choice == 3) {
            myStack.display();
        } else if (choice == 4) {
            cout << "Exiting the program.\n";
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
