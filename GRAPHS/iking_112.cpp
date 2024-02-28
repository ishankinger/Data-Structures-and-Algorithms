// DISTANCE OF NEAREST CELL HAVING 1
// A GRID OF 0'S AND 1'S IS GIVEN TO US AND WE HAVE TO RETURN NEAREST DISTANCE 2-D ARRAY WHICH WILL GIVE US ALL CELLS LEAST DISTANCE FROM 1
// DISTANCE WILL BE ABSOLUTE DIFFERENCE OF ROWS AND COLS AND THEN ADDITION OF BOTH
// SO HERE WE WILL DO BFS ON ALL THE INITIAL ONE'S PRESENT IN THE GRID AND THEN ALL THE GRID'S WHICH ARE UNVISITED AND ARE 0'S WILL BE ASSIGNED
// NEAREST DISTANCE ACCORDING TO THE LEVEL OF TRAVERSAL OF BFS

#include<bits/stdc++.h>
using namespace std;

void distanceFromNearestOne(vector<vector<int>> grid, vector<vector<int>> &distArr){
    // queue will store (i,j) of cell with it's level (nearest distance) 
    queue< pair< pair<int,int> , int > > q;
    vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));

    // all the initial one's are pushed in the queue and mark visited
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j] == 1){
                q.push({{i,j},0});
                visited[i][j] = 1;
            }
        }
    }

    // we can move only in four directions of the cells
    int delRow[] = {-1,0,+1,0};
    int delCol[] = {0,+1,0,-1};

    // similar code as done before
    while(not q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int dist = q.front().second;
        distArr[row][col] = dist;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow >= 0 and nrow < grid.size() and ncol >= 0 and ncol < grid[0].size() and not visited[nrow][ncol]){
                q.push({{nrow,ncol},dist+1});
                visited[nrow][ncol] = 1;
            }
        }
    }
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

    vector<vector<int>> distArr(n,vector<int>(m,0));

    distanceFromNearestOne(grid,distArr);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << distArr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
