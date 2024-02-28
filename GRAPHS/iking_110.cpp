// DETECT A CYCLE IN AN UNDIRECTED GRAPH USING BFS
// THE MAIN CONCEPT USED HERE IS FOR A NODE IT'S ALL NEIGHBOUR NODES WHICH ARE INITIALLY VISITED SHOULD BE PARENT OF THIS NODE OTHERWISE
// THERE IS A CYCLE PRESENT IN THE GRAPH

#include<bits/stdc++.h>
using namespace std;

bool bfs(vector<list<int>> graph, vector<int> &visited,int src){

    // we will push pair (node,parent) in the queue
    queue< pair<int,int> > q;
    q.push({src,-1});

    // we will traverse in the graph using queue
    while(not q.empty()){

        // get value of node and it's parent for given element
        int ele = q.front().first;
        int ele_parent = q.front().second;
        q.pop();

        // traverse all the neighbours of the node
        for(auto neighbour : graph[ele]){

            // if neighbour is not element's parent
            if(neighbour != ele_parent){

                // they have different parent still visited then cycle is detected
                if(visited[neighbour]){
                    return true;
                }
                
                // else push that in queue
                else{
                    visited[neighbour] = 1;
                    q.push({neighbour,ele});
                }
            }
        }
    }
    return false;
}

bool isCycle(vector<list<int>> graph){
    vector<int> visited(graph.size(),0);
    // traversing in all elements to check for all the unconnected components present in the graph
    for(int ele = 0; ele < graph.size(); ele++){
        if(not visited[ele]){
            visited[ele] = 1;
            bool check = bfs(graph,visited,ele);
            if(check){
                return true;
            }
        }
    }
    return false;
}

int main(){
    vector<list<int>> graph;
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

    if(isCycle(graph)) cout << "Cycle is Present\n";
    else cout << "Cycle is not Present\n";

    return 0;
}
