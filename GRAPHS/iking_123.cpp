// COURSE SCHEDULE

#include<bits/stdc++.h>
using namespace std;

vector<int> courseSchedule(vector< vector<int> > graph){
    vector<int> indegree(graph.size(),0);
    for(int i = 0; i < graph.size(); i++){
        for(auto neighbour : graph[i]){
            indegree[neighbour]++;
        }
    }
    vector<int> topo;
    queue<int> q;
    for(int i = 0; i < indegree.size(); i++){
        if(indegree[i] == 0) q.push(i);
    }
    while(not q.empty()){
        int ele = q.front();
        q.pop();
        topo.push_back(ele);
        for(auto neighbour : graph[ele]){
            if((--indegree[neighbour]) == 0) q.push(neighbour);
        }
    }
    if(topo.size() == graph.size()) return topo;
}

int main(){
    int n, p;
    cin >> n >> p;
    vector< vector<int> > graph(n,vector<int>());
    while(p--){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    vector<int> ans = courseSchedule(graph);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    
    return 0;
}