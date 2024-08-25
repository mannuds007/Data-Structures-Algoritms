#include<bits/stdc++.h>
using namespace std;
//// question 6 edges 9 Vertices
// 1 3
// 1 5
// 3 5
// 3 4
// 3 6
// 3 2
// 2 6
// 4 6
// 5 6 
// DFS ALGO

const int N=1e3;
bool vis[N];

vector<int> graph[N];
void dfs(int vertex){
    /*1st section
    action on vertex after entering
    the vertex
    */
   cout << vertex << endl;
   if(vis[vertex]) return;
   vis[vertex] =true;
    for(int child: graph[vertex]){
        cout << "par " << vertex << " , child" << child << endl;
        /*2nd section
        action on child before
        entering the node
        */
       
        dfs(child);
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
    int n, m;
    cin >>n >>m;
    for(int i=0; i<m; i++){
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
}