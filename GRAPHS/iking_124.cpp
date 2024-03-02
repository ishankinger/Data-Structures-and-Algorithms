// FIND EVENTUAL STATE USING BFS
// EVENTUAL SAFE STATE QUEUSTION PREVIOUSLY DONE USING DFS( IF NODE IS ENTERING IN CYCLE OR PART OF IT THEN NOT A SAFE NODE)
// NOW WE WILL DO THIS USING TOPOLOGICAL SORT
// >> MAKE TRANSPOSE OF THE GIVEN GRAPH
// >> THEN APPLY TOPOLOGICAL SORT
// >> THE ELEMENTS WHICH ARE COMING IN TOPOLOGICAL SORT VECTOR ARE THE SAFE NODES OF THE GRAPH

#include<bits/stdc++.h>
using namespace std;

int numOfSafeNodes(vector< vector<int> > graph){

    // make one transpose graph in which arrow's direction is reversed
    vector< vector<int> > graph_transpose(graph.size(),vector<int>());
    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph[i].size(); j++){
            graph_transpose[graph[i][j]].push_back(i);
        }
    }

    // indegree vector for topo sort is formed
    vector<int> indegree(graph.size(),0);
    for(int i = 0; i < graph_transpose.size(); i++){
        for(int j = 0; j < graph_transpose[i].size(); j++){
            indegree[graph_transpose[i][j]]++;
        }
    }

    // queue to have bfs traversal is also formed
    queue<int> q;
    for(int i = 0; i < indegree.size(); i++){
        if(indegree[i] == 0) q.push(i);
    }

    // the elements which are coming in topo vector of the graph are the safe nodes
    vector<int> topo;
    while(not q.empty()){
        int ele = q.front();
        q.pop();
        topo.push_back(ele);
        for(int i = 0; i < graph_transpose[ele].size(); i++){
            indegree[graph_transpose[ele][i]]--;
            if(indegree[graph_transpose[ele][i]] == 0)
                q.push(graph_transpose[ele][i]);
        }
    }

    // returning size of topological vector
    return topo.size();
}

int main(){

    int v;
    cin >> v;
    vector< vector<int> > graph(v,vector<int>());
    int e;
    cin >> e;
    while(e--){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    for(int i = 0; i < graph.size(); i++){
        cout << i << " -> ";
        for(int j = 0; j < graph[i].size(); j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<"\n";
    }

    cout<<numOfSafeNodes(graph);
    
    return 0;
}
