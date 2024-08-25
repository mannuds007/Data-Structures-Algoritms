#include<bits/stdc++.h>

using namespace std;
/**multiple sorces are put in queue at same time
 * the level of every source is 0
 * and its children will be one

 */
const int N=1e3+10;
const int INF = 1e9+10;
vector<int> graph[N];
int vis[N][N];
int val[N][N];
int level[N][N];
int n, m;

void reset(){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            level[i][j]=INF;
            vis[i][j]=0;
        }
        
    }
    
}
vector<pair<int, int>> movements = {
    {0,1},{1,0},
    {-1,0},{0,-1},
    {-1, -1},{-1,1},
    {1,1}, {1,-1}
};
bool isValid(int x, int y){
    return x>=0 && x<n && y>=0 && y<m;
}


int bfs(){
    int mx=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mx = max(mx, val[i][j]);
        }
        
    }
    queue<pair<int,int>> q;
       for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(mx == val[i][j]){
                q.push({i,j});
                level[i][j]=0;
                vis[i][j]=1;
            }
        }
        
    }
    int ans = 0;
    while(!q.empty()){
        auto v =q.front();
        int v_x = v.first;
        int v_y = v.second;
        q.pop();
        for(auto movement : movements){
            int child_x = movement.first + v_x;
            int child_y = movement.second + v_y;
            if(!isValid(child_x, child_y)) continue;
            if(vis[child_x][child_y]) continue;
            q.push({child_x, child_y});
            level[child_x][child_y] = level[v_x][v_y]+1;
            vis[child_x][child_y] = 1;
            ans = max(level[child_x][child_y] , ans);
        }
    }
    return ans;
}

int main(){
    int t;
    cin >>t;
    while(t--){
        cin >> n >> m;
        reset();
        for(int i=0; i<n; i++){
           for (int j = 0; j < m; j++)
           {
            cin >> val[i][j];
           }
        }
        cout << bfs() << endl;
    }

}