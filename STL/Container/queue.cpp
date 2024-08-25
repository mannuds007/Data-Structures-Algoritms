#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<string> q;
    q.push("abc");
    q.push("bcd");
    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}
