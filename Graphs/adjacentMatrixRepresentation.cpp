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
const int N=1e3;
int graph[N][N];
int main(){
    //vertices =n, matrix of n*n
    // a[i][j]=1 if connected i and j
    // a[i][j]=0 if not connected
    // symmeric matrix if bidirectional otherwise not
    // if there is weight in edge
    // a[i][j] = wt
    int n, m;
    cin >>n >>m;
    for(int i=0; i<m; i++){
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1][v2]=1;
        graph[v1][v2]=1; 
    }
    // O(N^2) space complexity
}