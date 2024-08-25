#include <bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int> &s, int x) {
    // Base case: Either stack is empty or newly inserted
    // item is greater than top (more than all existing)
    if (s.empty() || x > s.top()) {
        s.push(x);
        return;
    }

    // If top is greater, remove the top item and recur
    int temp = s.top();
    s.pop();
    sortedInsert(s, x);

    // Put back the top item removed earlier
    s.push(temp);
}

void sortStack(stack<int> &s) {
    // If stack is not empty
    if (!s.empty()) {
        // Remove the top item
        int x = s.top();
        s.pop();

        // Sort remaining stack
        sortStack(s);

        // Push the top item back in sorted order
        sortedInsert(s, x);
    }
}

int main() {
    int n;
    cin >> n;
    stack<int> s;
    while (n--) {
        int x;
        cin >> x;
        s.push(x);
    }

    sortStack(s);

    // Print the sorted stack
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}
