// FLOYD WARSHALL ALGORITHM
// TIME COMPLEXITY -> O(N^3)

#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > floydWarshallAlgo(vector< vector< pair<int,int> > > graph){
    
    vector< vector<int> > distMatrix(graph.size(), vector<int>(graph.size(),INT_MAX));
    
    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph[i].size(); j++){
            distMatrix[i][graph[i][j].first] = graph[i][j].second; 
        }
    }
    
    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph.size(); j++){
            if(i == j) distMatrix[i][j] = 0;
        }
    }
    
    for(int via = 0; via < graph.size(); via++){
        for(int i = 0; i < graph.size(); i++){
            for(int j = 0; j < graph.size(); j++){
                if(distMatrix[i][via] != INT_MAX && distMatrix[via][j] != INT_MAX){
                    distMatrix[i][j] = min(distMatrix[i][j],(distMatrix[i][via]+distMatrix[via][j]));
                }
            }
        }
    }

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