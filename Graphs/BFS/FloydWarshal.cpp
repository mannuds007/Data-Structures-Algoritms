#include <bits/stdc++.h>
using namespace std;
// handles negative weights
// do not handle negative weighted cycle
const int N = 510;
const int INF = 1e9 + 10;

int dist[N][N];

int main() {
    // Initialize the distance matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) dist[i][j] = 0; // Distance from a node to itself is 0
            else dist[i][j] = INF; // Distance to other nodes is set to infinity initially
        }
    }

    int n, m;
    cin >> n >> m;

    // Read edges and update the distance matrix
    for (int i = 0; i < m; i++) {
        int x, y, wt;
        cin >> x >> y >> wt;
        dist[x][y] = wt; // Direct distance from x to y is wt
    }

    // Floyd-Warshall algorithm
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Output the distance matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF) cout << "I "; // Print 'I' for infinity
            else cout << dist[i][j] << " "; // Print the shortest distance
        }
        cout << endl;
    }

    return 0;
}
