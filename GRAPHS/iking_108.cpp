// FLOOD FILL ALGORITHM

#include<bits/stdc++.h>
using namespace std;

void dfs(int sr, int sc, int color, vector<vector<int>> &ans,int newColor){
    ans[sr][sc] = newColor;
    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1};
    for(int i = 0; i < 4; i++){
        int nrow = sr + delRow[i];
        int ncol = sc + delCol[i];
        if(nrow >= 0 and nrow < ans.size() and ncol >= 0 and ncol < ans[0].size()
            and ans[nrow][ncol] == color and ans[nrow][ncol] != newColor){
                dfs(nrow,ncol,color,ans,newColor);
           }
    }
}

vector<vector<int>> floodFillAlgo(int sr, int sc, int color, vector<vector<int>> grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> ans = grid;
    dfs(sr,sc,grid[sr][sc],ans,color);
    return ans;
}


int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n,vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    int sr, sc;
    cin >> sr >> sc;
    int color;
    cin >> color;
    vector<vector<int>> ans = floodFillAlgo(sr,sc,color,grid);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[0].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}