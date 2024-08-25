#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 10;
int dp[205][N];

// Function to check if it's possible to partition the array into two subsets with equal sum
bool func1(int ind, int sum, vector<int>& nums) {
    if (sum == 0) return true; // If the sum becomes 0, we found a subset
    if (ind < 0 || sum < 0) return false; // Invalid indices or sum
    if (dp[ind][sum] != -1) return dp[ind][sum];
    
    // Do not consider the current element
    bool isPossible = func1(ind - 1, sum, nums);
    // Consider the current element
    isPossible |= func1(ind - 1, sum - nums[ind], nums);

    return dp[ind][sum] = isPossible;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int totalSum = accumulate(nums.begin(), nums.end(), 0);

    // If the total sum is odd, it's impossible to partition into two equal subsets
    if (totalSum % 2 != 0) {
        cout << "It's not possible to partition the array into two subsets with equal sum." << endl;
        return 0;
    }

    memset(dp, -1, sizeof(dp));
    bool result = func1(n - 1, totalSum / 2, nums);

    if (result) {
        cout << "It's possible to partition the array into two subsets with equal sum." << endl;
    } else {
        cout << "It's not possible to partition the array into two subsets with equal sum." << endl;
    }

    return 0;
}
