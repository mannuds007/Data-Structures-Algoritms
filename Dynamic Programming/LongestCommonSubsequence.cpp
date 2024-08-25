#include<bits/stdc++.h>
using namespace std;
string s1, s2;
int dp[1005][1005];
int lcs(int i,int j){
    if(i<0 || j<0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int mx=lcs(i-1,j);
    mx= max(mx, lcs(i,j-1));
    mx=max(mx, lcs(i-1,j-1)+(s1[i]==s2[j]));
    return dp[i][j]=mx;
}
int main(){
    memset(dp, -1, sizeof(dp)); 
    cin >> s1;
    cin >> s2;
    cout << lcs(s1.length()-1,s2.length()-1);
}