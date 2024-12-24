#include <iostream>
#include <stack>
#include <string>
using namespace std;

class TextEditor {
private:
    string S; // The main text
    stack<pair<int, string>> history; // Stack to store history for undo

public:
    // Append W to the string
    void append(const string& W) {
        history.push({1, W}); // Save operation type and appended string
        S += W;
    }

    // Delete the last k characters
    void deleteChars(int k) {
        string deleted = S.substr(S.size() - k); // Capture the deleted part
        history.push({2, deleted}); // Save operation type and deleted string
        S.erase(S.size() - k);
    }

    // Print the k-th character
    void print(int k) const {
        if (k > 0 && k <= S.size()) {
            cout << S[k - 1] << endl; // 1-based index
        }
    }

    // Undo the last append or delete operation
    void undo() {
        if (!history.empty()) {
            auto lastOp = history.top();
            history.pop();
            if (lastOp.first == 1) {
                // Undo append
                int len = lastOp.second.size();
                S.erase(S.size() - len);
            } else if (lastOp.first == 2) {
                // Undo delete
                S += lastOp.second;
            }
        }
    }
};

int main() {
    int Q;
    cout << "Enter the number of operations: ";
    cin >> Q;

    TextEditor editor;

    for (int i = 0; i < Q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            string W;
            cin >> W;
            editor.append(W);
        } else if (type == 2) {
            int k;
            cin >> k;
            editor.deleteChars(k);
        } else if (type == 3) {
            int k;
            cin >> k;
            editor.print(k);
        } else if (type == 4) {
            editor.undo();
        }
    }

    return 0;
}

