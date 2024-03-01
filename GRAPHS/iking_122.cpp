// DETECT A CYCLE IN DIRECTED GRAPH USING BFS ALGORITHM
// KAHN'S ALGO IS VALID FOR DAG ONLY BUT IF IT'S CYCLIC THEN IT WILL NOT GIVE FULL SEQUENCE

#include<bits/stdc++.h>
using namespace std;

// applying same code of kahn's algorithm
int isCycle(vector< vector<int> > graph){
    vector<int> topo;
    vector<int> indegree(graph.size(),0);
    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph[i].size(); j++){
            indegree[graph[i][j]]++;
        }
    }
    queue<int> q;
    for(int i = 0; i < indegree.size(); i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(not q.empty()){
        int ele = q.front();
        q.pop();
        topo.push_back(ele);
        for(auto neighbour : graph[ele]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0) q.push(neighbour);
        }
    }
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
    cout<<isCycle(graph)<<"\n";

    // if there is difference in size then graph has a cycle as kahn's algo doesnot give correct answer for cyclic graphs
    if(isCycle(graph) == graph.size()) cout << "The graph doesnot have cycle\n";
    else cout << "The graph has a cycle\n";

    return 0;
}
