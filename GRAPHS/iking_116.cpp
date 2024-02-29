// CHECK WHETHER A GRAPH IS BIPARTITE OR NOT USING BFS
// BIPARTITE GRAPHS ARE THE GRAPHS WHICH CAN BE COLORED WITH TWO COLORS WITH NO ADJACENT NODES HAVING THE SAME COLOR
// IF WHILE TRAVERSING IN BFS WE GET ELEMENT AND IT'S NEIGHBOUR COLOR SAME THEN RETURN FALSE
// ACYCLIC AND EVEN CYCLIC GRAPHS ARE ALWAYS BIPARTITE

#include<bits/stdc++.h>
using namespace std;

bool bfs(int src, vector< list<int> > graph, vector<int> &color){
    
    // to do bfs we need a queue
    queue<int> q;
    q.push(src);

    // traverse till the queue is not empty
    while(not q.empty()){

        // get the front element of queue and remove it
        int ele = q.front();
        q.pop();

        // check for all the neighbours of front element
        for(auto neighbour : graph[ele]){

            // if not visited then color it
            if(color[neighbour] == -1){
                q.push(neighbour);
                color[neighbour] = not(color[ele]);
            }

            // if visited then we have to check
            else{
                // if same color then return false that not bipartite
                if(color[neighbour] == color[ele])
                    return false;
            }
        }
    }
    return true;
}

bool isBipartite(vector< list<int> > graph){

    // here instead of visited we will use color array 
    // -1 -> not visited  
    // 0 -> visited with one type of color 
    // 1 -> visited with another type of color
    vector<int> color(graph.size(),-1);

    // traverse all the elements of the graph as to prevent disconnected components
    for(int i = 0; i < graph.size(); i++){
        if(color[i] == -1){
            bool check = bfs(i,graph,color);
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
