// SHORTEST DISTANCE IN A BINARY MAZE

#include<bits/stdc++.h>
using namespace std;

int shortestDist(vector< vector<int> > grid, int sr, int sc, int dr, int dc){
    int n = grid.size();
    int m = grid[0].size();
    vector< vector<int> > dist(n,vector<int>(m,INT_MAX));
    set< pair< int,pair<int,int> > > st;
    st.insert({0,{sr,sc}});
    dist[sr][sc] = 0;
    int delRow[] = {0,+1,0,-1};
    int delCol[] = {+1,0,-1,0};
    int minPathLen = INT_MAX;
    while(not st.empty()){
        int row = (*st.begin()).second.first;
        int col = (*st.begin()).second.second;
        int pathLen = (*st.begin()).first;
        st.erase(st.begin());
        if(row == dr and col == dc){
            minPathLen = min(minPathLen,pathLen);
            continue;
        }
        for(int i = 0; i < 4; i++){
            int nr = row + delRow[i];
            int nc = col + delCol[i];
            if(nr >= 0 && nc >= 0 && nr < n && nc < m 
            && grid[nr][nc] && 1+pathLen < dist[nr][nc]){
                if(dist[nr][nc] != INT_MAX){
                    st.erase({dist[nr][nc],{nr,nc}});
                }
                dist[nr][nc] = 1 + pathLen;
                st.insert({1+pathLen,{nr,nc}});
            }
            cout<<(*st.begin()).first<<"\n";
        }
        cout<<"\n\n"<<(*st.begin()).first<<"\n\n";
    }

    if(minPathLen == INT_MAX) return -1;
    return minPathLen;
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
    int sr, sc;
    cin >> sr >> sc;
    int dr, dc;
    cin >> dr >> dc;
    cout << shortestDist(grid,sr,sc,dr,dc);

    return 0;
}