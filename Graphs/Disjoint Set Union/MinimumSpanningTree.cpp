// Kruskels Algorithm
#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+10;
int parent[N];
int size[N];
// take all the nodes in graph
// sort the edges in sorted order
// add the edges one be one and check if the loops forms
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
    int n, m;
    cin >> n >>m;
    vector<pair<int, pair<int, int>>> edges;
    while (m--)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({wt, {u ,v}});

    }
    for(int i =1; i <=n; i++) make(i);
    int total_cost =0;
    sort(edges.begin(), edges.end());
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
        cout << u << " " << v << endl;
    }
    cout << total_cost << endl;
    
    
}