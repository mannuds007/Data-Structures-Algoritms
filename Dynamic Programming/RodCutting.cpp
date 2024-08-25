#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
vector<int> p(N);
int dp[N];

int n; // Length of the rod

int func(int len) {
    if (len == 0) return 0;
    if (dp[len] != -1) return dp[len];
    
    int ans = 0; // Initialize ans to 0 to handle the case where no cuts are made
    for (int i = 1; i <= n; i++) {
        if (len - i >= 0) {
            ans = max(ans, func(len - i) + p[i]);
        }
    }
    return dp[len] = ans;
}

int main() {
    memset(dp, -1, sizeof(dp)); // Initialize dp array with -1

    cout << "Enter the length of the rod: ";
    cin >> n;

    cout << "Enter the prices for each piece length from 1 to " << n << ":\n";
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    cout << "Maximum obtainable value is: " << func(n) << endl;

    return 0;
}
