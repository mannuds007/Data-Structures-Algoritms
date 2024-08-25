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
vector<vector<int>> cc;
vector<int> current_cc;

void dfs(int vertex){
    
   if(vis[vertex]) return;
   current_cc.push_back(vertex);
   vis[vertex] =true;
    for(int child: graph[vertex]){
        dfs(child);
    }

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
    int ct =0;
    for(int i=1; i<n+1; i++){
        if(vis[i]) continue;
        current_cc.clear();
        dfs(i);
        cc.push_back(current_cc);
        ct++;
    }
    cout<< cc.size() << endl;
    for(auto c_cc: cc){
        for(auto vertex : c_cc){
            cout <<vertex << " ";
        }
        cout << endl;
    }
}