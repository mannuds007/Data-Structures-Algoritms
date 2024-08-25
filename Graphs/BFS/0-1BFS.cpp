#include<bits/stdc++.h>

using namespace std;
/**at a time there is only 2 levels present
 * if the qwieght is 0 then
 * put it in first and if 1 then
 * put it in end 
**/
/*ques. find minimum edges need to reverse to create a directed 
path from source to destination
*/
/**Input
 * 7 7
 * 1 2
 * 3 2
 * 3 4
 * 7 4
 * 6 2
 * 5 6
 * 7 5 
 */// output 2
const int N=1e5+10;
const int INF=1e+9+10;
vector<pair<int, int>> graph[N];
vector<int> level(N, INF);
int n, m;
int bfs(){
    deque<int> q;
    q.push_back(1);
    level[1]=0;
    while (!q.empty())
    {
        int cur_v = q.front();
        q.pop_front();
        for (auto child : graph[cur_v])      
        {   
            int child_v = child.first;
            int wt = child.second;
            if (level[cur_v]+wt < level[child_v])
            {
                level[child_v] = level[cur_v]+wt;
                if(wt){
                    q.push_back(child_v);
                }else{
                    q.push_front(child_v);
                }
            }
        }
        
    }
    return level[n]==INF ? -1 : level[n];

}

int main(){
    cin >>n >> m;
    for(int i=0; i<n-1; i++){
        int v1, v2;
        cin >> v1 >> v2;
        if(v1==v2) continue;
        graph[v1].push_back({v2,0});
        graph[v2].push_back({v1,1} );
    }
    cout << bfs() << endl;
    

}