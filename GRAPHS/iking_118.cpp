// DETECT A CYCLE IN A DIRECTED GRAPH USING DFS 
// SIMILAR CONCEPT USED AS THAT OF USED IN BFS TRAVERSAL ONLY TECHNIQUE IS DIFFERENT

#include<bits/stdc++.h>
using namespace std;

bool dfs(int src, vector<int> &color, vector< list<int> > graph, int col){
    
    // first change the color to not of it's parent one
    color[src] = not(col);

    // traverse to all the neighbours of our curr node
    for(auto neighbour : graph[src]){

        // if neighbour is not visited 
        if(color[neighbour] == -1){

            // call for it's neighbour and if we get false from this call then return false
            if(not dfs(neighbour,color,graph,color[src]))
                return false;  
        }

        // else if neighbour is already visited
        else{

            // if they have same color then return false
            if(color[neighbour] == color[src]){
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(vector< list<int> > graph){
    vector<int> color(graph.size(),-1);
    // traverse in all the nodes
    for(int i = 0; i < graph.size(); i++){
        if(color[i] == -1){
            bool check = dfs(i,color,graph,1);
            if(not check) return false;
        }
    }
    return true;
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
        graph[v].push_back(u);
    }

    for(int ele = 0; ele < graph.size(); ele++){
        cout << ele << " -> ";
        for(auto neighbour : graph[ele]){
            cout << neighbour << " ";
        }
        cout << "\n";
    }

    if(isBipartite(graph)){
        cout << "The graph is Bipartite\n";
    }
    else{
        cout << "The graph is not Bipartite\n";
    }

    return 0;
}
