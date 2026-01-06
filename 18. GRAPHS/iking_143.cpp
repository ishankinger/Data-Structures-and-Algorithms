// PRIM'S ALGORITHM 
// THIS ALGORITHM GIVES US MINIMUM SPANNING TREE - IT'S SUM AND ALL EDGES ASSOSCIATED WITH IT

#include<bits/stdc++.h>
using namespace std;

// function to implement prim's algorithm
int primsAlgo(vector< vector< pair<int,int> > > graph){
    
    // a min heap is defined storing (weight, (node,parent))
    priority_queue< pair< int,pair<int,int> >, 
    vector<pair< int,pair<int,int> > >,
    greater< pair< int,pair<int,int> > > > pq;
    
    // a visited array for all the nodes
    vector<int> vis(graph.size(),0);
    
    // list of edges in the mst
    vector< pair<int,int> > mstList;
    
    // sum storing the total sum of our mst
    int sum = 0;
    
    // initialise with 0 and taking it's parent to be -1
    pq.push({0,{0,-1}});
    
    // loop till pq will not become empty
    while(not pq.empty()){

        // extract the info from the top element
        int wt = pq.top().first;
        int node = pq.top().second.first;
        int parent = pq.top().second.second;
        // then pop it
        pq.pop();

        // if visited then nothing to do
        if(vis[node]) continue;

        // mark visited if not
        vis[node] = 1;

        // push the edge in our list
        if(parent != -1){
            mstList.push_back({parent,node});
        }

        // add the weight to sum
        sum += wt;

        // traverse through neighbours and if not visited then push into the priority queue
        for(auto neighbour : graph[node]){
            if(not vis[neighbour.first]){
                pq.push({neighbour.second,{neighbour.first,node}});
            }
        }
    }

    // print the mstList
    for(int i = 0; i < mstList.size(); i++){
        cout << mstList[i].first << " " << mstList[i].second << "\n";
    }
    // and return the sum
    return sum;
}

int main(){
    int v;
    cin >> v;
    vector< vector< pair<int,int> > > graph(v,vector< pair<int,int> >());
    int e;
    cin >> e;
    while(e--){
        int u, v, wt;
        cin >> u >> v >> wt;
        graph[u].push_back({v,wt});
        graph[v].push_back({u,wt});
    }
    for(int i = 0; i < graph.size(); i++){
        cout << i << " -> ";
        for(int j = 0; j < graph[i].size(); j++){
            cout << "(" << graph[i][j].first << "," << graph[i][j].second << ") ";
        }
        cout << "\n";
    }

    cout << primsAlgo(graph) << "\n";

    return 0;
}