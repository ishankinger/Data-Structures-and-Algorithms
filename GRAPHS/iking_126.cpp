// SHORTEST PATH IN DAG
// SO TO DO THIS QUESTION WE WILL BE TAKING HELP OF TOPOLOGICAL SORT LOGIC
// IN TOPO SORT USING DFS WE FORM ONE STACK FROM WHICH AFTER POPPING ELEMENTS FROM IT WE GET TOPO SORT
// THIS TIME WHILE POPPING THE ELEMENTS FROM THE STACK WE WILL RELAX THE EDGES
// RELAX THE EDGES -> MAKE A DIST ARR(INITIALISE WITH INT-MAX) NOW WHEN FOR THE GIVEN ELEMENT WE WILL CHECK ALL IT'S NEIGHBOUR
// AND WILL UPDATE THE DIST OF NEIGHBOUR IF IT'S INITIAL VALUE IS GREATER THAN (DIST[CURR ELE] + WEIGHT(CURR,NEIGHBOUR))

#include<bits/stdc++.h>
using namespace std;

// topo sort dfs previously done
void dfs(int src, vector< vector< pair<int,int> > > graph, vector<int> &visited, stack<int> &st){
    visited[src] = 1;
    for(auto neighbour : graph[src]){
        if(not visited[neighbour.first]){
            dfs(neighbour.first,graph,visited,st);
        }
    }
    st.push(src);
}

// function to give shortest path from given source
vector<int> shortestPath(vector< vector< pair<int,int> > > graph){

    // visited arr and stack are made for topo sort
    vector<int> visited(graph.size(),0);
    stack<int> st;

    // applying dfs on all non visited elements and pushing them in the stack
    for(int i = 0; i < graph.size(); i++){
        if(not visited[i]){
            dfs(i,graph,visited,st);
        }
    }

    // an answer dist array is formed
    vector<int> dist(graph.size(),1000);
    dist[0] = 0; // source = 0

    // traversing in the stack
    while(not st.empty()){

        // get top element and pop it
        int ele = st.top();
        st.pop();

        // traversing through it's neighbour and updating dist[neighbour] if needed
        for(auto neighbour : graph[ele]){
            dist[neighbour.first] = min(dist[neighbour.first], neighbour.second + dist[ele]);
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
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
    }

    for(int i = 0; i < graph.size(); i++){
        cout << i << " -> ";
        for(int j = 0; j < graph[i].size(); j++){
            cout<<"("<<graph[i][j].first<<","<<graph[i][j].second<<") ";
        }
        cout<<"\n";
    }

    vector<int> ans = shortestPath(graph);
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}
