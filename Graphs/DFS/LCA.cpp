#include<bits/stdc++.h>
using namespace std;
/**Store path from root in array
 * find the extreme common value in array
 */
const int N=1e5+10;
int par[N];

vector<int> graph[N];
void dfs(int vertex,int p=-1){
    par[vertex]=p;
    for(int child: graph[vertex]){
        if(child==p) return;
        dfs(child, vertex);
    }
}
vector<int> path(int v){
    vector<int> ans;
    while(v!=-1){
        ans.push_back(v);
        v=par[v];
    }
    reverse(ans.begin(), ans.end());
    return ans;
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
    int x, y;
    cin >> x >> y;
    vector<int> path_x = path(x);
    vector<int> path_y = path(y);
    int mn_ln = min(path_x.size(),path_y.size());
    int lca=-1;
    for (int i = 0; i < mn_ln; i++)
    {
        if(path_x[i] == path_y[i]){
            lca = path_x[i];
        }else break;
    }  
}