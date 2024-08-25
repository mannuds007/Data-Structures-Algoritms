#include <bits/stdc++.h>
using namespace std;

vector<string> valid;

void gP(int open, int close, string &s) {
    if (open == 0 && close == 0) {
        valid.push_back(s);
        return;
    }
    if (open > 0) {
        s.push_back('(');
        gP(open - 1, close, s);
        s.pop_back();
    }
    if (close > open) {
        s.push_back(')');
        gP(open, close - 1, s);
        s.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    string s;
    gP(n, n, s);
    for (const auto &it : valid) {
        cout << it << endl; 
    }
    return 0;
}
