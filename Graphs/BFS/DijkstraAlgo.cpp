#include <bits/stdc++.h>

using namespace std;

/**
 * Dijkstra's Algorithm: Finds the shortest path in a weighted graph
 * Proof by mathematical induction
 */
const int N = 1e3 + 10;
const int INF = 1e9 + 10;
vector<pair<int, int>> g[N];
    int n, m; // Number of nodes and edges
void dijkstra(int source) {
    vector<int> vis(N, 0); // Visited array to mark visited nodes
    vector<int> dist(N, INF); // Distance array to store the shortest distance to each node
    
    set<pair<int, int>> st; // Set to store the nodes to be processed (weight, node)
    
    st.insert({0, source}); // Insert the source node with distance 0
    dist[source] = 0; // Distance to the source is 0
    
    while (!st.empty()) { // Loop until there are no more nodes to process
        auto node = *st.begin(); // Get the node with the smallest distance
        int v = node.second; // Current node
        int v_dist = node.first; // Distance to the current node
        st.erase(st.begin()); // Remove the current node from the set
        
        if (vis[v]) continue; // If the node is already visited, skip it
        vis[v] = 1; // Mark the current node as visited
        
        // Process all adjacent nodes
        for (auto child : g[v]) {
            int child_v = child.first; // Adjacent node
            int wt = child.second; // Weight of the edge
            
            // If a shorter path to the adjacent node is found
            if (v_dist + wt < dist[child_v]) {
                dist[child_v] = v_dist + wt; // Update the distance
                st.insert({dist[child_v], child_v}); // Insert the adjacent node with the new distance
            }
        }
    }
    
    // Output the shortest distances from the source to all nodes
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == INF) {
            cout << "Node " << i << ": INF\n"; // If the node is not reachable
        } else {
            cout << "Node " << i << ": " << dist[i] << "\n"; // Shortest distance to the node
        }
    }
}

int main() {

    cin >> n >> m;
    
    for (int i = 0; i < m; ++i) {
        int x, y, wt;
        cin >> x >> y >> wt; // Input the edges (x to y with weight wt)
        g[x].push_back({y, wt}); // Add the edge to the adjacency list
        g[y].push_back({x, wt}); // If the graph is undirected, add the reverse edge too
    }
    
    int source;
    cin >> source; // Input the source node
    
    dijkstra(source); // Call Dijkstra's algorithm
    
    return 0;
}
