#include<bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
int dp[N];
int dp1[310][N];

int func(int amount, vector<int>& coins) {
    if (amount == 0) return 0;
    if (dp[amount] != -1) return dp[amount];
    
    int ans = INT_MAX;
    for (auto coin : coins) {
        if (amount - coin >= 0) {
            int res = func(amount - coin, coins);
            if (res != INT_MAX) { // Check to avoid overflow
                ans = min(ans, res + 1);
            }
        }
    }
    return dp[amount] = ans;
}

int func1(int ind, int amount, vector<int>& coins){
    if (amount == 0) return 1;
    if (ind < 0 || amount < 0) return 0; // Handle invalid indices and amounts
    if (dp1[ind][amount] != -1) return dp1[ind][amount];
    
    int ways = 0;
    for (int coin_amount = 0; coin_amount <= amount; coin_amount += coins[ind]) {
        ways += func1(ind - 1, amount - coin_amount, coins);
    }
    return dp1[ind][amount] = ways;
}

int main() {
    int n, amount;
    cin >> n >> amount; // n is the number of coin denominations, amount is the target amount
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    memset(dp, -1, sizeof(dp));
    memset(dp1, -1, sizeof(dp1));
    
    int result = func(amount, coins);
    if (result == INT_MAX) {
        cout << -1 << endl; // If no combination can form the amount
    } else {
        cout << "Minimum number of coins required: " << result << endl;
    }

    int ways = func1(n - 1, amount, coins);
    cout << "Number of ways to form the amount: " << ways << endl;
    
    return 0;
}
