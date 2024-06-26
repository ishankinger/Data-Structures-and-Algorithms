// NUMBER OF PROVINCES
// GIVEN AN UNDIRECTED GRAPH , WE HAVE TO TELL THE TOTAL NUMBER OF CONNECTED COMPONENTS IN IT
// A SINGLE UNDIRECTED GRAPH WHICH IS CONNECTED FULLY CAN BE TRAVERSED IN ONE SINGLE BFS OR DFS FROM ANY SOURCE NODE
// IN THIS QUESTION THERE ARE MULTIPLE CONNECTED COMPONENTS FORM ONE SINGLE GRAPH SO WE HAVE TO TELL NO. OF ALL COMPONENTS

#include<bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
int v;
unordered_set<int> visited;

void addEdge(int src, int dest,int bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
}

void display(){
    for(int ele = 0; ele < graph.size(); ele++){
        cout<<ele<<" -> ";
        for(auto neighbours : graph[ele]){
            cout<<neighbours<<" - ";
        }
        cout<<"\n";
    }
}

void dfs(int src){
    visited.insert(src);
    for(auto neighbour : graph[src]){
        if(not visited.count(neighbour)){
            dfs(neighbour);
        }
    }

}

// function to get total components of the graph
int numberOfProvinces(){
    int count = 0;
    // we will run dfs assuming all elements as source using a for loop
    // when we get an element from a particular component which is not intially covered that means new component is present
    // so we will do count++
    for(int ele = 0; ele < graph.size(); ele++){
        if(not visited.count(ele)){
            dfs(ele);
            count++;
        }
    }
    return count;
}

int main(){
    cin>>v;
    graph.resize(v,list<int>());
    int e; 
    cin>>e;
    while(e--){
        int u,v; 
        cin>>u>>v;
        addEdge(u,v);
    }
    display();
    cout<<numberOfProvinces()<<"\n";

    return 0;
}
