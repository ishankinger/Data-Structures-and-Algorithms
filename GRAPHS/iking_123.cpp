// COURSE SCHEDULE
// N TASKS ARE GIVEN FROM 0 TO N-1 AND P PRE-REQUISITES ARE ALSO GIVEN [M,N]-> MEANS TO COMPLETE Mth TASK WE NEED TO FIRST COMPLETE TASK Nth
// SO WE NEED TO TELL THAT ALL PRE-REQUISITES SATISFIED TO ANY COURSE SCHEDULE OR NOT
// SO WE WILL ASSUME PRE-REQUISITE AS M ----> N GRAPH EDGE AND RUN TOPO SORT ON IT
// IF TOPO SORT DOESNOT DETECT THE CYCLE THEN RETURN TRUE THAT SCHEDULE CAN BE FORMED OTHERWISE SCHEDULE CAN'T BE FORMED

#include<bits/stdc++.h>
using namespace std;

// function to check whether course can be formed or not
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
    // if size of topo vector equal to graph size means no cycle is present thus return topo vector as final ans
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
