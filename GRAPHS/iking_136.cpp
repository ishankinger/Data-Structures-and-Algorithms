// PATH WITH MINIMUM EFFORT
// GIVEN A N*M GRID AND WE HAVE TO TELL THE PATH WITH MINIMUM EFFORT FROM 0,0 TO N-1,M-1
// EFFORT IS EQUAL TO THE DIFFERENCE OF THE CELL'S HEIGHTS
// SO WE HAVE TO MINIMIZE THE TOTAL PATH EFFORT

#include<bits/stdc++.h>
using namespace std;

int minimumEffort(vector< vector<int> > grid){
    int n = grid.size();
    int m = grid[0].size();
    priority_queue< pair< int,pair<int,int> >, vector< pair< int,pair<int,int> > >, greater< pair< int,pair<int,int> > > > pq;
    vector< vector<int> > effMatrix(n,vector<int>(m,INT_MAX));
    pq.push({0,{0,0}});
    effMatrix[0][0] = 0;
    int delRow[] = {0,+1,0,-1};
    int delCol[] = {+1,0,-1,0};
    int minEffort = INT_MAX;
    while(not pq.empty()){
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        int effort = pq.top().first;
        if(row == n-1 and col == m-1){
            minEffort = min(minEffort,effort);
            break;
        }
        pq.pop();
        for(int i = 0; i < 4; i++){
            int nr = row + delRow[i];
            int nc = col + delCol[i];
            if(nr >= 0 && nc >= 0 && nr < n && nc < m){
                int diff = abs(grid[nr][nc]-grid[row][col]);
                int newEff = max(effort,diff);
                if(newEff < effMatrix[nr][nc]){
                    effMatrix[nr][nc] = newEff;
                    pq.push({newEff,{nr,nc}});
                }
            }
        }
    }
    return minEffort;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector< vector<int> > grid(n,vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    cout << minimumEffort(grid) << "\n";

    return 0;
}