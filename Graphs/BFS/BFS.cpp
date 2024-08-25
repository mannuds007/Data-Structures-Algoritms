#include<bits/stdc++.h>

using namespace std;
// level wise traverse
/** using queue and visited array
 * level wise node is given in queue
 * when going to next level queue is pop and new nodes are inserted in queue
 * visited array is used to mark the visited nodes of graph or tree
 * used in finding shortest path
**/
const int N=1e5+10;
vector<int> graph[N];
int vis[N];
int level[N];
void bfs(int source){
    queue<int> q;
    q.push(source);
    vis[source]=1;
    while (!q.empty())
    {
        int cur_v = q.front();
        q.pop();
        cout << cur_v << " " ;
        for (int child : graph[cur_v])      
        {
            if(!vis[child]){
                q.push(child);
                vis[child]=1;
                level[child] = level[cur_v]+1;
            }
        }
        
    }
    cout << endl;
    // V-node, E-edges
    // O(V+E)
}

int main(){
    int n;
    cin >>n;
    for(int i=0; i<n-1; i++){
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    bfs(1);
    for (int i = 1; i <=n; i++)
    {
        cout << i << ": "<< level[i] << endl;
    }
    

}