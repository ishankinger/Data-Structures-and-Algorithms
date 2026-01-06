// DFS TRAVERSAL TO CHECK WHETHER A PATH EXIST BETWEEN GIVEN TWO VERTICES
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
unordered_set<int> visited;

// function to run dfs on a graph for given source and dest
bool dfs(int curr, int end){
    
    // means we reach the destination so return true
    if(curr == end) return true;
    
    // mark curr as visited 
    visited.insert(curr);

    // traverse throught all the neighbours of curr that are not visited and call for them as new curr recursively
    for(auto neighbour: graph[curr]){
        if(not visited.count(neighbour)){
            // if any of neighbour return true means they reached the destination node
            bool result = dfs(neighbour,end);
            // then return true
            if(result) return true;
        }
    }
    // else return false
    return false;
}

// function to check whether path exist or not
bool anyPath(int src, int dest){
    return dfs(src,dest);
}

int main(){
    cin>>v;
    graph.resize(v,list<int>());
    int e;
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d,false);
    } 
    display();
    int x,y;
    cin>>x>>y;
    cout<<anyPath(x,y)<<"\n";
    return 0;
}
