#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        multiset<int> s;
        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;
            s.insert(v);
        }
        int c = 0;
        for (int i = 0; i < k; i++) {
            auto it = --s.end();
            c += *it;
            int newVal = *it / 2;
            s.erase(it);
            s.insert(newVal);
        }
        cout << c << endl;
    }
    return 0;
}
