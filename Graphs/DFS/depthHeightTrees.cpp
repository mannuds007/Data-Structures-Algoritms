#include<bits/stdc++.h>
using namespace std;

const int N=1e3;
int depth[N] , height[N];

vector<int> graph[N];
void dfs(int vertex,int par){
    /*1st section
    action on vertex after entering
    the vertex
    */

    for(int child: graph[vertex]){
        if(child==par) return;
        depth[child]=depth[vertex]+1;
        /*2nd section
        action on child before
        entering the node
        */
       
        dfs(child, vertex);
        /*3rd section
        action on child before
        exiting the child node
        */
       height[vertex] = max(height[vertex], height[child]+1);
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
    dfs(1,0);

    // output depth and height array
}