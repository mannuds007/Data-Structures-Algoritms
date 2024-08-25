#include<bits/stdc++.h>
using namespace std;
/**Given q querrien, q= < 10^5
 * in each query given V,
 * Print subtree sum of of V & even Numbers
 * in subtree of V
 */
const int N=1e5+10;
vector<int> graph[N];
int subtree_sum[N];
int even_ct[N];
void dfs(int vertex,int par){
    /*1st section
    action on vertex after entering
    the vertex
    */
    subtree_sum[vertex]+=vertex;
    if(vertex %2==0) even_ct[vertex]++;
    for(int child: graph[vertex]){
        if(child==par) return;
        /*2nd section
        action on child before
        entering the node
        */
       
        dfs(child, vertex);
        subtree_sum[vertex]+=subtree_sum[child];
        even_ct[vertex]+=even_ct[child];
        /*3rd section
        action on child before
        exiting the child node
        */
    }
    /*3rd section
    action on vertex before
    exiting the vertex
    */
}

int main(){
    int n;
    for(int i=0; i<n-1; i++){
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int v;
        cin >> v;
        cout << subtree_sum[v]<<" " << even_ct[v] << endl;
    }
    
}