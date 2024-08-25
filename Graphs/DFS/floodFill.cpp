#include<bits/stdc++.h>
using namespace std;


const int N=1e5+10;


void dfs(int i, int j, int intitialColor, int newColor, vector<vector<int>>&image){
   int n = image.size();
   int m = image[0].size();
   if(i < 0 || j<0) return;
   if(i >=n || j>=m) return;
   if(image[i][j] != intitialColor) return;

   image[i][j] = newColor;
   dfs(i-1,j, intitialColor, newColor, image);
   dfs(i+1,j, intitialColor, newColor, image);
   dfs(i,j-1, intitialColor, newColor, image);
   dfs(i,j+1, intitialColor, newColor, image);
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color){
    int initialColor = image[sr][sc];
    if (initialColor != color)
    {
        dfs(sr,sc,initialColor,color, image);
    }
    
}

int main(){
    int n, m;
    cin >>n >>m;
    for(int i=0; i<m; i++){
        // input matrix
    }
}