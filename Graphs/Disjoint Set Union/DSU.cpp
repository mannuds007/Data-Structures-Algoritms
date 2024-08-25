/**used in making groups
 * 3 functions
 * make: add new independent node
 * find: gives parent of the group
 * union: makes in one group
 * 
 */
#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+10;
int parent[N];
int size[N];

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
        size[a]+=size[b];// union by size
    }
} // O(alpah(n)) alpah(n) reverse ackerman function
  // amoterized time complexity
int main(){
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        make(i);
    }
    while (m--)
    {
        int u, v;
        cin >> u >>v;
        Union(u,v);
    }
    int connected_ct=0;
    for (int i = 0; i <=n; i++)
    {
        if (find(i)==i)
        {
            connected_ct++;
        }
        
    }
    
}