// FIND EVENTUAL SAFE NODES
// A SAFE NODE IS A NODE HAVING ALL IT'S PATH ENDING AT A TERMINAL NODE ( NODE WHICH HAVE 0 OUTGOING EDGES )
// NODES WHICH FORM A CYCLE CAN'T BE A SAFE NODE
// ALSO NODES WHICH ARE ENTERING INTO THE CYCLE WILL ALSO NOT BE A SAFE NODE
// EXCEPT THAT ALL NODES WILL BE SAFE NODES

#include<bits/stdc++.h>
using namespace std;

bool dfs(int src, vector< list<int> > graph, vector<int> &vis, vector<int> &path_vis, vector<int> &safe){
    // make curr node as visited, path_visited and not a safe node
    vis[src] = 1;
    path_vis[src] = 1;
    safe[src] = 0;

    // traverse on all the neighbours of source
    for(auto neighbour : graph[src]){

        // if neighbour is not visited
        if(not vis[neighbour]){

            // then run dfs on neighbour and if give true means cycle present
            if(dfs(neighbour,graph,vis,path_vis,safe)){

                // then this node is in the cycle so can't be a safe node
                safe[src] = 0;

                // and return true
                return true;
            }
        }

        // else is not visited and is path visited
        else if(path_vis[neighbour]){
            // so this node is in cycle
            // so not safe and return true
            safe[src] = 0;
            return true;
        }
    }

    // else if neighbour doesnot result in cycle formation
    // then it is a safe node and make path visited = 0 and return false
    path_vis[src] = 0;
    safe[src] = 1;
    return false;
}

vector<int> safeNodes(vector< list<int> > graph){
    vector<int> safe(graph.size(),0);
    vector<int> vis(graph.size(),0);
    vector<int> path_vis(graph.size(),0);
    for(int i = 0; i < graph.size(); i++){
        if(not vis[i]){
            dfs(i,graph,vis,path_vis,safe);
        }
    }
    vector<int> ans;
    for(int i = 0; i < safe.size(); i++){
        if(safe[i]) ans.push_back(i);
    }
    return ans;
}

int main(){
    vector< list<int> > graph;
    int v;
    cin >> v;
    graph.resize(v,list<int>());
    int e;
    cin >> e;
    while(e--){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    for(int ele = 0; ele < graph.size(); ele++){
        cout << ele << " -> ";
        for(auto neighbour : graph[ele]){
            cout << neighbour << " ";
        }
        cout << "\n";
    }

    vector<int> ans = safeNodes(graph);
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}
