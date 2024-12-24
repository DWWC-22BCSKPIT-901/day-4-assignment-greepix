#include <iostream>
#include <string>
#include <vector>
using namespace std;

int firstUniqChar(string s) {
    vector<int> freq(26, 0); // Array to store frequency of each character

    // First traversal: Count the frequency of each character
    for (char c : s) {
        freq[c - 'a']++;
    }

    // Second traversal: Find the first character with frequency 1
    for (int i = 0; i < s.length(); i++) {
        if (freq[s[i] - 'a'] == 1) {
            return i; // Return the index of the first non-repeating character
        }
    }

    return -1; // No non-repeating character found
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    int result = firstUniqChar(s);

    if (result != -1) {
        cout << "The index of the first non-repeating character is: " << result << endl;
    } else {
        cout << "No non-repeating character exists." << endl;
    }

    return 0;
}

