#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const long long INF = 1e15;
long long dp[105][N];
int weights[105], values[105];

/**All values in input are integers.
1≤N≤100
1≤W≤10^9
1≤w_i≤W 
1≤v_i≤10^3
*/

// Function to compute the minimum weight to achieve a certain value
long long func(int ind, int value_left) {
    if (value_left == 0) return 0;
    if (ind < 0) return INF;
    if (dp[ind][value_left] != -1) return dp[ind][value_left];

    // Do not choose the item
    long long ans = func(ind - 1, value_left);

    // Choose the item if it fits in the knapsack
    if (value_left - values[ind] >= 0) {
        ans = min(ans, func(ind - 1, value_left - values[ind]) + weights[ind]);
    }
    
    return dp[ind][value_left] = ans;
}

int main() {
    int n, w;
    cin >> n >> w;

    for (int i = 0; i < n; i++) {
        cin >> weights[i] >> values[i];
    }

    int max_value = 1e5;
    memset(dp, -1, sizeof(dp));

    // Find the maximum value that can be achieved without exceeding weight w
    for (int value = max_value; value >= 0; value--) {
        if (func(n - 1, value) <= w) {
            cout << value << endl;
            break; // Since we are going from max_value to 0, the first valid value is the answer
        }
    }

    return 0;
}
