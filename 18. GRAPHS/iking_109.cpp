// ROTTEN ORANGES
// 0 - EMPTY CELL, 1 - FRESH ORANGES AND 2 - ROTTEN ORANGES GIVEN IN A GRID
// WE HAVE TO TELL THE TOTAL TIME TO ROTTEN ALL THE FRESH ORANGES AND IF WE CAN'T ROTTEN ALL THEN RETURN -1
// HERE WE WILL DO BFS TRAVERSAL TO GET THE MINIMUM TIME
// ON FIRST LEVEL WE WILL TRAVERSE ALL THE ROTTEN ORANGES WHICH ARE UNVISITED THEN WE WILL TRAVERSE 
// TO ORANGES WHICH GET ROTTEN THEN TO NEXT LEVEL

#include<bits/stdc++.h>
using namespace std;

int orangesRotten(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();

    // bfs traversal so using visited array and queue
    queue< pair< pair<int,int>, int>> q; // -> queue contains pair of (coordinate pair), it's time to rotte
    vector<vector<int>> vis(n,vector<int>(m)); // ->  a 2d visited matrix tells whether orange rotten or not

    // traversing in all the cells of the visited 2-d array
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){

            // if rotten orange is present then push that in 1st level of the queue
            if(grid[i][j] == 2){
                q.push({{i,j},0});
                vis[i][j] = 2;
            }

            // others make unvisited
            else{
                vis[i][j] = 0;
            }
        }
    }

    // we will only rotten in four directions
    int delRow[] = {-1, 0 , +1, 0};
    int delCol[] = {0, +1 , 0, -1};
    int tm = 0;

    // till queue is not empty
    while(not q.empty()){

        // get coordinates of the element in the queue and it's time
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        q.pop();

        // for each element compare with time to get max. time
        tm = max(tm,t);

        // using two array method traverse in all four directions
        for(int i = 0; i < 4; i++){
            int nrow = r + delRow[i];
            int ncol = c + delCol[i];

            // check the validity condition of coordinates and it should be fresh and should be rotten initially
            if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m
                and vis[nrow][ncol] != 2 and grid[nrow][ncol] == 1){
                    q.push({{nrow,ncol},t + 1});
                    vis[nrow][ncol] = 2;
            }
        }
    }

    // checking whether there is any cell which is not visited but having fresh orange
    // if yes then -1 is returned
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(vis[i][j] != 2 and grid[i][j] == 1){
                return -1;
            }
        }
    }

    // else return the max time taken by any orange to rotte
    return tm;
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

    cout<<orangesRotten(grid);

    return 0;
}
