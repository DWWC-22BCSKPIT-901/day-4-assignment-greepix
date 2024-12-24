#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <functional>
using namespace std;

int evalRPN(vector<string>& tokens) {
    // Define operations using a lambda map
    unordered_map<string, function<int(int, int)>> operations = {
        {"+", [](int a, int b) { return a + b; }},
        {"-", [](int a, int b) { return a - b; }},
        {"*", [](int a, int b) { return a * b; }},
        {"/", [](int a, int b) { return a / b; }} // Integer division truncates toward zero
    };

    stack<int> s;

    for (const string& token : tokens) {
        if (operations.count(token)) { // If the token is an operator
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            s.push(operations[token](a, b)); // Apply the operation and push the result
        } else { // If the token is a number
            s.push(stoi(token)); // Convert string to integer and push to stack
        }
    }

    // The final result is the only element left in the stack
    return s.top();
}

int main() {
    vector<string> tokens1 = {"2", "1", "+", "3", "*"};
    vector<string> tokens2 = {"4", "13", "5", "/", "+"};
    vector<string> tokens3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};

    cout << "Example 1 Output: " << evalRPN(tokens1) << endl; // Output: 9
    cout << "Example 2 Output: " << evalRPN(tokens2) << endl; // Output: 6
    cout << "Example 3 Output: " << evalRPN(tokens3) << endl; // Output: 22

    return 0;
}

