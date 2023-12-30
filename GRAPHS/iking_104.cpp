// BREADH FIRST TRAVERSAL IN GIVEN GRAPH
// SPACE COMPLEXITY -> O(N)
// TIME COMPLEXITY -> O(N + E), N-> NO. OF NODES AND M -> NO. OF EDGES

#include<bits/stdc++.h>
using namespace std;

// taking input of vector as adjacency list
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
// a visited set is defined to check whether our node is visited or not
unordered_set<int> visited;

// function to run bfs
vector<int> bfs(int src,vector<int> &dist){

    // different arrays defined -
    vector<int> bfs_arr;            // ans arr of bfs   
    queue<int> qu;                  // queue
    visited.clear();                // visited set
    dist.resize(v,INT_MAX);         // dist vector

    // for source node -
    dist[src] = 0;                  // distance is 0
    visited.insert(src);            // marked as visited
    qu.push(src);                   // souce is pushed in the queue
    bfs_arr.push_back(src);         // pushed in the ans array

    // till qu is not empty
    while(not qu.empty()){
        // the front element of queue is saved and then popped
        int curr = qu.front();
        qu.pop();
        // then we will traverse on the neighbours of the front element
        for(auto neighbour : graph[curr]){
            // if neighbour is not in the set means not visited
            if(not visited.count(neighbour)){
                // perform same steps as done in source node
                visited.insert(neighbour);
                dist[neighbour] = dist[curr] + 1;
                qu.push(neighbour);
                bfs_arr.push_back(neighbour);
            }
        }
    }
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
    vector<int> dist;
    vector<int> ans = bfs(0,dist);
    for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
    cout<<"\n";
    for(int i=0;i<dist.size();i++) cout<<dist[i]<<" ";
    return 0;
}