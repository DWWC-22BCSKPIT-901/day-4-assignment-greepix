#include <stack>
#include <iostream>
#include <string>
using namespace std;

class MinStack {
private:
    stack<int> s; // Stack to store all elements
    stack<int> minStack; // Stack to store the minimum values

public:
    MinStack() {
        // Initialize the stack
    }

    // Pushes an element onto the stack
    void push(int val) {
        s.push(val);
        // Push to minStack the smaller value between val and the current minimum
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    // Removes the element on the top of the stack
    void pop() {
        if (!s.empty()) {
            if (s.top() == minStack.top()) {
                minStack.pop(); // Pop from minStack if it's the current minimum
            }
            s.pop();
        }
    }

    // Gets the top element of the stack
    int top() {
        if (!s.empty()) {
            return s.top();
        }
        throw runtime_error("Stack is empty.");
    }

    // Retrieves the minimum element in the stack
    int getMin() {
        if (!minStack.empty()) {
            return minStack.top();
        }
        throw runtime_error("Stack is empty.");
    }
};

int main() {
    MinStack minStack;
    string command;
    int value;

    cout << "Enter commands (push <value>, pop, top, getMin, exit):" << endl;

    while (true) {
        cin >> command;
        if (command == "push") {
            cin >> value;
            minStack.push(value);
            cout << "Pushed " << value << " onto the stack." << endl;
        } else if (command == "pop") {
            try {
                minStack.pop();
                cout << "Popped the top element from the stack." << endl;
            } catch (exception &e) {
                cout << "Error: " << e.what() << endl;
            }
        } else if (command == "top") {
            try {
                cout << "Top element is: " << minStack.top() << endl;
            } catch (exception &e) {
                cout << "Error: " << e.what() << endl;
            }
        } else if (command == "getMin") {
            try {
                cout << "Minimum element is: " << minStack.getMin() << endl;
            } catch (exception &e) {
                cout << "Error: " << e.what() << endl;
            }
        } else if (command == "exit") {
            cout << "Exiting program." << endl;
            break;
        } else {
            cout << "Invalid command. Please try again." << endl;
        }
    }

    return 0;
}

