#include<bits/stdc++.h>
using namespace std;
/**With any root find max depth node
 * with that node as root find max depth
 */
const int N=1e5+10;
int depth[N];

vector<int> graph[N];
void dfs(int vertex,int par){

    for(int child: graph[vertex]){
        if(child==par) return;
        depth[child]=depth[vertex]+1;
       
        dfs(child, vertex);
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
    dfs(1,0);
    int mx_depth=-1;
    int mx_d_node;
    for (int i = 1; i <=n; i++)
    {
        if(mx_depth<depth[i]) {
            mx_depth = depth[i];
            mx_d_node = i;
        }
        depth[i]=0;
    }
    dfs(mx_d_node,0);
    for (int i = 1; i <=n; i++)
    {
        if(mx_depth<depth[i]) {
            mx_depth = depth[i];
        }
    }
    cout << mx_depth << endl;
    
}