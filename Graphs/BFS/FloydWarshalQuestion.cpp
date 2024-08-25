#include <bits/stdc++.h>
using namespace std;
/** Greg has a weighed directed graph, consisting of n vertices. In this graph any pair of distinct vertices has an edge between them in both directions. Greg loves playing with the graph and now he has invented a new game:

The game consists of n steps.
On the i-th step Greg removes vertex number xi from the graph. As Greg removes a vertex, he also removes all the edges that go in and out of this vertex.
Before executing each step, Greg wants to know the sum of lengths of the shortest paths between all pairs of the remaining vertices. The shortest path can go through any remaining vertex. In other words, if we assume that 
d(i, v, u) is the shortest path between vertices v and u in the graph that formed before deleting vertex xi, then Greg wants to know the value of the following sum: d(i, v, u) for all v,u except v=u*/
const int N = 510;
const int INF = 1e9 + 10;

long long dist[N][N];

int main() {
    int n;
    cin >> n;
    // Initialize the distance matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> dist[i][j];
        }
    }
    vector<int> del_order(n);
    for (int i = 0; i < n; i++)
    {
       cin >> del_order[i];
    }
    reverse(del_order.begin(), del_order.end());
    vector<long long> ans;
    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        int k_v = del_order[k];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k_v] + dist[k_v][j]);
            }
        }
        long long sum =0;
        for (int i = 0; i <=k; i++)
        {
             for (int j = 0; j <=k; j++){
                sum+=dist[del_order[i]][del_order[j]];
             }
        }
        ans.push_back(sum);
        
    }
    reverse(ans.begin(), ans.end());
    for(auto value : ans){
        cout << value << endl;
    }

    return 0;
}
