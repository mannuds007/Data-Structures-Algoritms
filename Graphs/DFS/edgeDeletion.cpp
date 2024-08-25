#include<bits/stdc++.h>
using namespace std;
/**find the edge which should be deleyed in
 * order to get maximum product of the sum of 
 * trees obtained
 */
const int N=1e5+10;
vector<int> graph[N];
int subtree_sum[N];
int val[N];
const int M=1e9+7;
void dfs(int vertex,int par=-1){
    subtree_sum[vertex]+=val[vertex-1];
    for(int child: graph[vertex]){
        if(child==par) return;
       
        dfs(child, vertex);
        subtree_sum[vertex]+=subtree_sum[child];
    }
}

int main(){
    int n;
    for(int i=0; i<n-1; i++){
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    dfs(1);
    long long ans=0;
    for (int i = 2; i < n-1; i++)
    {
       int part1 = subtree_sum[i];
       int part2 = subtree_sum[1]-part1;
       ans = max(ans, (part1*1LL*part2)%M);
    }
    cout << ans;
    
}