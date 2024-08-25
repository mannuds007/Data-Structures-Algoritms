#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
// Steps1 write brute force recursion 
// the =n convert it for dp storing the values
int dp[N];
int height[N];

int func(int i){
    if(i==1) return 0;
    if(i==0) return 0;
    if(dp[i] !=-1) return dp[i];
    int cost = INT_MAX;

    // way1
    cost = min(cost, func(i-1)+abs(height[i]-height[i-1]));

    // way2
    cost = min(cost, func(i-2)+abs(height[i]-height[i-2]));

    return dp[i]=cost;
}


int main(){
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    for (int i = 1; i <=n; i++)
    {
        cin >> height[i];
    }
    cout << func(n);
    
}