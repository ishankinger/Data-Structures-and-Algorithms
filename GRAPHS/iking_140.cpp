// BELLMAN FORD ALGORITHM
// USED TO FIND THE SHORTEST PATH FROM THE SOURCE NODE
// THIS CAN BE USED FOR DIRECTED GRAPHS HAVING NEGATIVE CYCLES WHICH IS LIMITATION OF DIJKSTRA ALGORITHM
// IN THIS WE WILL BE RELAXING ALL THE EDGES N-1 TIMES AND EDGES CAN BE TAKEN IN ANY ORDER
// TIME COMPLEXITY - O(V.E)

#include<bits/stdc++.h>
using namespace std;

// function to return shortest path array
vector<int> bellmanFordAlgo(vector< vector< pair<int,int> > > graph){

    // a dist array taking all values to be INT_MAX
    vector<int> dist(graph.size(),INT_MAX);
    // initialise distance of node 0 to be 0
    dist[0] = 0;
    
    // starting node , ending node and weight of the edge between them
    int u, v, wt;

    // traverese throudh all the edges n-1 times
    for(int i = 0; i < graph.size()-1; i++){
        for(int j = 0; j < graph.size(); j++){
            for(int k = 0; k < graph[j].size(); k++){
                u = j;
                v = graph[j][k].first;
                wt = graph[j][k].second;

                // relax the edges if possible
                if(dist[u] != INT_MAX and dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
    }
    return dist;
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

    vector<int> shortestArr = bellmanFordAlgo(graph);
    for(int i = 0; i < shortestArr.size(); i++){
        cout << shortestArr[i] << " ";
    }

    return 0;
}