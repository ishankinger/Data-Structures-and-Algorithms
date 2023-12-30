// SHORTEST PATH IN DAG

#include<bits/stdc++.h>
using namespace std;

void dfs(int src, vector< vector< pair<int,int> > > graph, vector<int> &visited, stack<int> &st){
    visited[src] = 1;
    for(auto neighbour : graph[src]){
        if(not visited[neighbour.first]){
            dfs(neighbour.first,graph,visited,st);
        }
    }
    st.push(src);
}

vector<int> shortestPath(vector< vector< pair<int,int> > > graph){
    vector<int> visited(graph.size(),0);
    stack<int> st;
    for(int i = 0; i < graph.size(); i++){
        if(not visited[i]){
            dfs(i,graph,visited,st);
        }
    }
    vector<int> dist(graph.size(),1000);
    dist[0] = 0;
    while(not st.empty()){
        int ele = st.top();
        st.pop();
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