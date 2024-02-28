// FLOOD FILL ALGORITHM
// ONE SOURCE IS GIVEN AND COLOR IS ALSO GIVEN 
// FOR ANY CELL WE CAN MOVE IN FOUR DIRECTIONS
// WE HAVE TO CHANGE THE COLOR OF ALL THE GRID TO GIVEN COLOR WHICH FOLLOW TWO PROPERTIES-
// 1. THEY SHOULD HAVE SAME COLOR AS THAT OF SOURCE INITIALLY(INITIAL SOURCE GIVEN IN THE INPUT)
// 2. THEY SHOULD BE IN FOUR SIDES CELLS

#include<bits/stdc++.h>
using namespace std;

void dfs(int sr, int sc, int color, vector<vector<int>> &ans, vector< vector<int> > image,int newColor){

    // change the color which satisfy properties
    ans[sr][sc] = newColor;

    // way to write coordinates of the grid elements joining from the four sides
    // two array way to get all four sides around the given cell
    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1};
    for(int i = 0; i < 4; i++){
        int nrow = sr + delRow[i];
        int ncol = sc + delCol[i];

        // valid conditions for the cell coordinates and 
        if(nrow >= 0 and nrow < ans.size() and ncol >= 0 and ncol < ans[0].size()
            and ans[nrow][ncol] == color and image[nrow][ncol] != newColor){
            
                // then again do dfs on nrow,ncol
                dfs(nrow,ncol,color,ans,image,newColor);
           }
    }
}

vector<vector<int>> floodFillAlgo(int sr, int sc, int color, vector<vector<int>> grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> ans = grid;
    dfs(sr,sc,grid[sr][sc],ans,grid,color);
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
