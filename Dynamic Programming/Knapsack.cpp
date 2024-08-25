#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int dp[105][N];
int weights[105], values[105];
/**All values in input are integers.
1≤N≤100
1≤W≤10^5
1≤w_i≤W
1≤v_i≤10^9
*/
int func(int amount, int ind) {
    if (amount == 0) return 0;
    if (ind < 0) return 0;
    if (dp[ind][amount] != -1) return dp[ind][amount];

    // Do not choose the item
    int ans = func(amount, ind - 1);

    // Choose the item if it fits in the knapsack
    if (amount - weights[ind] >= 0) {
        ans = max(ans, func(amount - weights[ind], ind - 1) + values[ind]);
    }
    
    return dp[ind][amount] = ans;
} //O(n*w) 

int main() {
    int n, w;
    cin >> n >> w;

    for (int i = 0; i < n; i++) {
        cin >> weights[i] >> values[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << func(w, n - 1) << endl;

    return 0;
}
