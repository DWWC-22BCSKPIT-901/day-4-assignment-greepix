#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> inputStack;  // Stack for pushing elements
    stack<int> outputStack; // Stack for popping/peeking elements

    // Transfer elements from inputStack to outputStack
    void transfer() {
        while (!inputStack.empty()) {
            outputStack.push(inputStack.top());
            inputStack.pop();
        }
    }

public:
    // Initialize the queue
    MyQueue() {}

    // Push element x to the back of the queue
    void push(int x) {
        inputStack.push(x);
    }

    // Removes the element from the front of the queue and returns it
    int pop() {
        if (outputStack.empty()) {
            transfer();
        }
        int front = outputStack.top();
        outputStack.pop();
        return front;
    }

    // Get the front element
    int peek() {
        if (outputStack.empty()) {
            transfer();
        }
        return outputStack.top();
    }

    // Returns whether the queue is empty
    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};

int main() {
    MyQueue myQueue;

    myQueue.push(1); // queue: [1]
    myQueue.push(2); // queue: [1, 2]
    cout << "Front element (peek): " << myQueue.peek() << endl; // return 1
    cout << "Popped element: " << myQueue.pop() << endl; // return 1, queue: [2]
    cout << "Is queue empty? " << (myQueue.empty() ? "Yes" : "No") << endl; // return false

    return 0;
}

