// FLOYD WARSHALL ALGORITHM
// MULTI SOURCED SMALLEST PATH ALGO AND ALSO HELP IN DETECTING NEGATIVE CYCLES
// TIME COMPLEXITY -> O(N^3)

#include<bits/stdc++.h>
using namespace std;

// function to get shortest path from any given node to any other node of the graph
vector< vector<int> > floydWarshallAlgo(vector< vector< pair<int,int> > > graph){
    
    // first a distMatrix is initialised of size of graph.size()
    vector< vector<int> > distMatrix(graph.size(), vector<int>(graph.size(),INT_MAX));
    
    // u ----> v edge weight is filled in the matrix in (u,v) cell and for no edge mark it as INT_MAX
    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph[i].size(); j++){
            distMatrix[i][graph[i][j].first] = graph[i][j].second; 
        }
    }
    
    // initialise the distMatrix with (i,i) cell values to be 0
    for(int i = 0; i < graph.size(); i++){
        distMatrix[i][i] = 0;
    }
    
    // i ----> via ----> j compare the distance value of (i,j) with distance from i via j
    for(int via = 0; via < graph.size(); via++){
        for(int i = 0; i < graph.size(); i++){
            for(int j = 0; j < graph.size(); j++){
                if(distMatrix[i][via] != INT_MAX && distMatrix[via][j] != INT_MAX){
                    distMatrix[i][j] = min(distMatrix[i][j],(distMatrix[i][via]+distMatrix[via][j]));
                }
            }
        }
    }

    // if distMatrix is negative then negative cycle present
    for(int i = 0; i < graph.size(); i++){
        if(distMatrix[i][i] < 0){
            cout << "NEGATIVE CYCLE PRESENT\n";
        }
    } 
    return distMatrix;
}

int main(){
    int v;
    cin >> v;
    vector< vector< pair<int,int> > > graph(v,vector< pair<int,int> >());
    int e;
    cin >> e;
    while(e--){
        int u, v, wt;
        cin >> u >> v >> wt;
        graph[u].push_back({v,wt});
    }

    for(int i = 0; i < graph.size(); i++){
        cout << i << " -> ";
        for(int j = 0; j < graph[i].size(); j++){
            cout << "(" << graph[i][j].first << "," << graph[i][j].second << ") ";
        }
        cout << "\n";
    }

    // printing the shortest distances between all nodes
    vector< vector<int> > shortestArr = floydWarshallAlgo(graph);
    for(int i = 0; i < shortestArr.size(); i++){
        for(int j = 0;j < shortestArr[i].size(); j++){
            if(shortestArr[i][j] == INT_MAX) cout << "- ";
            else cout << shortestArr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}