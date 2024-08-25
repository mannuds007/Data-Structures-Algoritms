#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int n, c;
int v[N];

bool ism(long long m) {
    int last_pos = v[0]; 
    int count = c - 1;   
    
    for (int i = 1; i < n; i++) {
        if (v[i] - last_pos >= m) {
            count--;
            last_pos = v[i];
        }
        if (count == 0) break;
    }
    
    return count == 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> c;
        
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v, v + n);
        
        long long lo = 0;
        long long hi = 1e9 + 1; 
        
        while (hi - lo > 1) {
            long long m = (hi + lo) / 2;
            if (ism(m)) {
                lo = m;
            } else {
                hi = m - 1;
            }
        }
        
        if (ism(hi)) {
            cout << hi << endl;
        } else {
            cout << lo << endl;
        }
    }
    
    return 0;
}
