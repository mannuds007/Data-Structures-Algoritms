#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> symbols = {{'[', 1}, {'(', 2}, {'{', 3}, {']', -1}, {')', -2}, {'}', -3}};

int main() {
    stack<char> s;
    string str;
    cin >> str;
    bool isBalanced = true;
    
    for (char bracket : str) {
        if (symbols[bracket] > 0) { 
            s.push(bracket);
        } else { 
            if (s.empty()) {
                isBalanced = false;
                break;
            }
            char top = s.top();
            s.pop();
            if (symbols[top] + symbols[bracket] != 0) {
                isBalanced = false;
                break;
            }
        }
    }
    
    if (!isBalanced || !s.empty()) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    
    return 0;
}
