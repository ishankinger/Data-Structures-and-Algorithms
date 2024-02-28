// DFS TRAVERSAL IN THE GRAPH
// TIME COMPLEXITY -> O(V + E)

#include<bits/stdc++.h>
using namespace std;

// taking input of the vector as an adjacency list
vector<list<int>> graph;
int v;
void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
}
void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<" -> ";
        for(auto ele:graph[i]){
            cout<<ele<<" - ";
        }
        cout<<"\n";
    }
}

// visited set is defined
unordered_set<int> visited; // -> keep track of elements that are already added to bfs sequence

// function to run dfs on a graph for given source
void dfs(int curr,vector<int> &bfs_arr){
    
    // first add the node in sequence and also mark as visited
    visited.insert(curr);
    bfs_arr.push_back(curr);

    // then traverse through all of it's neighbour which are not visited by recursive calls
    for(auto neighbour : graph[curr]){
        if(not visited.count(neighbour)){
            dfs(neighbour,bfs_arr);
        }
    }
}

vector<int> dfsOfGraph(int src){

    // different arrays defined -
    vector<int> bfs_arr;            // ans arr of bfs
    visited.clear();                // visited set

    // call the dfs function to return ans array
    dfs(src,bfs_arr);
    return bfs_arr;
}

int main(){
    cin>>v;
    graph.resize(v,list<int>());
    int e;
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d);
    } 
    display();

    vector<int> ans = dfsOfGraph(0);
    for(auto ele : ans) cout<<ele<<" ";
    
    return 0;
}
