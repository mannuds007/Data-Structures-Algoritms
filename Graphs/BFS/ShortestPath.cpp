#include<bits/stdc++.h>

using namespace std;

/** Find the least jump between 
 * 2 positions in chess board
 * for horse
**/
const int N=1e5+10;
const int INF = 1e9+10;
vector<int> graph[N];
int vis[8][8];
int level[8][8];

int getX(string s){
    return s[0]-'a';
}
int getY(string s){
    return s[1]-'1';
}
bool isValid(int x, int y){
    return x>=0 && x<8 && y>=0 && y<8;
}
vector<pair<int, int>> movements = {
    {-1,2},{1,2},
    {-1,-2},{1,-2},
    {2,-1},{2,1},
    {-2,-1},{-2,1}
};

int bfs(string source, string dest){
    reset();
    int source_x= getX(source);
    int source_y= getY(source);
    int dest_x= getX(dest);
    int dest_y= getY(dest);
    queue<pair<int,int>> q;
    q.push({source_x,source_y});
    vis[source_x][source_y]=1;
    level[source_x][source_y]=0;

    while (!q.empty())
    {
        pair<int, int> v =q.front();
        q.pop();
        for(auto movement : movements){
            int child_x = movement.first + source_x;
            int child_y = movement.second +source_y;
            if(!isValid(child_x, child_y)) continue;
            if(!vis[child_x][child_y]){
                q.push({child_x, child_y});
                level[child_x][child_y] = level[source_x][source_y]+1;
                vis[child_x][child_y] = 1;
            }
        }

    }
    return level[dest_x][dest_y];
}

void reset(){
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            level[i][j]=INF;
            vis[i][j]=0;
        }
        
    }
    
}

int main(){
    int n;
    cin >>n;
    while (n--)
    {
        string s1, s2;
        cin >>s1 >> s2;
        cout << bfs(s1, s2) << endl;
    }
    
    

}