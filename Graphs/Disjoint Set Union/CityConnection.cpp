// Kruskels Algorithm
#include<bits/stdc++.h>
using namespace std;
const int N= 2e3+10;
int parent[N];
int size[N];
// make a 0 node for transformer
void make(int v){
    parent[v] = v;
    size[v]=1;
}

int find(int v){
    if(v==parent[v]) return v;
    // path compression
    else return parent[v]=find(parent[v]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a !=b) {
        if(size[a]<size[b])
            swap(a,b);
        parent[b] = a;
        size[a]+=size[b]; // union by size
    }
}

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> cities(n+1);
    for(int i =1; i <=n; i++){
        cin >> cities[i].first >> cities[i].second;
    }
    vector<int> c(n+1), k(n+1);
    for(int i =1; i <=n; i++) cin >> c[i];
    for(int i =1; i <=n; i++) cin >> k[i];

    vector<pair<int, pair<int, int>>> edges;
    for(int i=1; i <= n; i++){
        for (int j = i+1; j <=n; j++)
        {
            int dist = abs(cities[i].first - cities[j].first) + abs(cities[i].second - cities[j].second);
            long long cost = dist*1LL*(k[i]+k[j]);
            edges.push_back({cost , {i , j}});
        }   
    }
    for (int i = 1; i <= n; i++) {
        edges.push_back({c[i], {0, i}});
    }
    sort(edges.begin(), edges.end());
    for(int i =1; i <=n; i++) make(i);
    long long total_cost =0;
    vector<int> power_stations;
    vector<pair<int, int>> connections;
    for (auto &edge : edges)
    {
        int u, v, wt;
        wt = edge.first;
        u = edge.second.first;
        v= edge.second.second;
        // to find if their is loop
        if(find(u) == find(v)) continue; // if there is a loop then they will have same parent
        Union(u,v);
        total_cost += wt;
        if(u==0 || v==0){
            power_stations.push_back(max(u,v));

        }else{
            connections.push_back({u,v});
        }
    }
    cout << total_cost << endl;
    cout << power_stations.size() << endl;
    for(auto &connection : connections){
        cout << connection.first << " " << connection.second;
    }   
}