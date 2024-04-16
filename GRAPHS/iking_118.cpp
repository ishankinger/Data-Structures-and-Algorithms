// DETECT A CYCLE IN A DIRECTED GRAPH USING DFS 
// SO HERE TO DETECT A CYCLE WE NEED TO HAVE TWO THINGS ONE IS CONNECTIVITY AND ANOTHER IS THE DIRECTION OF CYCLE ALSO
// THIS TIME WE WILL BE HAVING TWO CONDITIONS ONE IS IT SHOULD BE VISITED AND OTHER IS IT SHOULD BE PATH VISITED ALSO
// IF ANY OF CONDITION IS NOT VALID THEN WE CAN'T SAY THAT THE GRAPH HAS A CYCLE
// PATH VISITED WILL BECOME UNVISITED WHEN WE ARE RETURNING FROM IT

#include<bits/stdc++.h>
using namespace std;

bool dfs(int src, vector< list<int> > graph, vector<int> &vis, vector<int> &path_vis){

    // make visited and path visited once
    vis[src] = 1;
    path_vis[src] = 1;

    // traverse to all of it's neighbours
    for(auto neighbour : graph[src]){

        // if not visited yet then we will move
        if(not vis[neighbour]){

            // if we get true from further calls the return true
            if(dfs(neighbour,graph,vis,path_vis)){
                return true;
            }

            // else while returning we will make path unvisited
            else{
                path_vis[neighbour] = 0;
            }
        }

        // if already visited then check the condition
        else{

            // if path visited also then we got cycle return true
            if(path_vis[neighbour]){
                return true;
            }
            // otherwise it is connected but not direction wise
        }
    }
    return false;
}

bool isCycle(vector< list<int> > graph){

    // visited and path visited arrays are defined
    vector<int> vis(graph.size(),0);
    vector<int> path_vis(graph.size(),0);

    // for all elements we have to do dfs as for directed graph also we can't get all elements traversed in once
    for(int i = 0; i < graph.size(); i++){

        // not visited then we will do dfs
        if(not vis[i]){

            // if we get true means cycle present the we will directly return true
            bool check = dfs(i,graph,vis,path_vis);
            if(check) return true;
        }
    }
    
    // else we will return false
    return false;
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

    if(isCycle(graph)){
        cout<<"The graph has a cycle\n";
    }
    else{
        cout<<"The graph doesnot have a cycle\n";
    }

    return 0;
}
