// NUMBER OF ISLANDS
// A GRID OF 0'S AND 1'S IS GIVEN TO US AND WE HAVE TO TELL TOTAL NUMBER OF MAXIMAL COLLECTION OF ONE'S WHICH ARE TOTALY SURROUNDED BY 0'S FROM 8 SIDES
// SO IT'S NOTHING BUT THE PROBLEM OF CONNECTED COMPONENTS IN THE GRAPH
// THE ONLY DIFFERECE IS THAT HERE WE HAVE TO TRAVERSE IN THE GRID
// FOR US 1-1 BOX IS CONNECTED AS AN EDGE 1-0 HAS NOT ANY EDGE

#include<bits/stdc++.h>
using namespace std;

// we will run the bfs on the 1's in the matrix
void bfs(int i, int j, vector<vector<int>> &visited, vector<vector<int>> grid){

    // a visited 2-d array is formed 
    visited[i][j] = 1;
    queue<pair<int,int>> q;
    q.push({i,j});

    while(not q.empty()){

        // get the current row and col value
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        // 2 loop way to get all the surrounded vertices in 8 sides
        for(int dr = -1 ; dr <= 1; dr++){
            for(int dc = -1; dc <= 1; dc++){
                int nrow = row + dr;
                int ncol = col + dc;

                // first check the validity of the new row and new col , then check whether this coordinate is a land and also not visited
                if(nrow < visited.size() and nrow >=0 and ncol < visited[0].size() and ncol >= 0
                    and grid[nrow][ncol] == 1 && not visited[nrow][ncol]){

                        // make visited and push it's coordinates in the queue
                        visited[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                }
            }
        }
    }
}

// function to return total no. of islands in the matrix
int numOfIslands(int n, int m,vector<vector<int>> grid){
    int count = 0;
    vector<vector<int>> visited(n,vector<int>(m,0));

    // we have to visit all the nodes to check whether any node is remained unvisited then we will do one more bfs on it
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m;i++){
            if(not visited[i][j] and grid[i][j] == 1){
                bfs(i,j,visited,grid);
                count++;
            }
        }
    }
    return count;
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
    cout << numOfIslands(n,m,grid) << "\n";
    return 0;
}
