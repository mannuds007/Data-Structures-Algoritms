#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

int dp[N];
// top down approach
int func(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    if (dp[n] !=-1) dp[n];
       
    return dp[n]=func(n-1)+func(n-2);
    
} // O(2^n) time complexity of each iteration
/** dynamic programming is to store the calculated values so that
 * we don't have to calculate each time
 * now O(2^n) is converted to O(N)
 */ 
int main(){
    memset(dp, -1, sizeof(dp));
    int n=8;
    cout << func(n);
    // // bottom up approach
    // dp[0]=0;
    // dp[1]=1;
    // for (int i = 0; i <=n; i++)
    // {
    //     dp[i]=dp[i-1]+dp[i-2];
    // }
    
    // for (int i = 0; i < n; i++)
    // {
    //     cout << func(i) << " ";
    // }   
}