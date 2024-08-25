#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        unordered_map<int, int> mp;
        int sum=0;
        int ans=0;
        int curr;
        for(int i=0; i<n; i++){
            sum+=arr[i];
            if(mp.find(sum) != mp.end()){
                curr=i-mp[sum];
                ans = max(ans , curr);
            }
            mp[sum]=i;
        }
        return ans;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];        
    }
    Solution ob;
    cout << ob.maxLen(a,n);
    
}
