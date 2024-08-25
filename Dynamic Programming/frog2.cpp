#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n, k;
// Steps1 write brute force recursion 
// then convert it for dp storing the values
int dp[N];
int height[N];

int func(int i) {
    if (i == 0) return 0;
    if (dp[i] != -1) return dp[i];
    
    int cost = INT_MAX;

    // k ways
    for (int j = 1; j <= k; j++) {
        if (i - j >= 0) {
            cost = min(cost, func(i - j) + abs(height[i] - height[i - j]));
        }
    }

    return dp[i] = cost;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }
    cout << func(n - 1);
    
    return 0;
}