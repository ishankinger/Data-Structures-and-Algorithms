// PRINTING SHORTEST PATH FROM 0 TO N-1 ( SECOND METHOD )
// HERE WE WILL BE USING A PARENT ARRAY WHICH WILL STORE THE PARENTS OF ALL THE NODES WHENEVER THE NODE IS PUSHED INTO THE PRIORITY QUEUE

#include<bits/stdc++.h>
using namespace std;

// function to get shortest path
vector<int> minDistArr(vector< vector< pair<int,int> > > graph){

    // dist arr
    vector<int> dist(graph.size(), INT_MAX);

    // priority queue - min heap containing node and it's edge weight
    priority_queue< pair<int,int>, vector< pair<int,int> > , greater< pair<int,int> > > pq;

    // parent vector storing the parent of each node and will be used in printing the path
    vector<int> parent(graph.size());

    // initially all nodes are parents of itself
    for(int i = 0; i < parent.size(); i++){
        parent[i] = i;
    }

    // initialise pq and dist
    pq.push({0,0});
    dist[0] = 0;

    // go in loop till pq is not empty
    while(not pq.empty()){

        // extract node data and edge weight and then remove from pq
        int node = pq.top().second;
        int len = pq.top().first;
        pq.pop();

        // traverse through all it's neighbours
        for(auto neighbour : graph[node]){

            // if we got better path to reach
            if(dist[neighbour.first] > len + neighbour.second){
                
                // update the dist arr, push into the pq and also update parent array
                dist[neighbour.first] = len + neighbour.second;
                pq.push({len + neighbour.second,neighbour.first});
                parent[neighbour.first] = node;
            }
        }
    }

    // now we will use parent array to get the shortest path
    vector<int> shortestPath;
    shortestPath.push_back(graph.size()-1);

    // backtracking the parent array to get the shortest path
    int par = parent[graph.size()-1];
    while(par != parent[par]){
        shortestPath.push_back(par);
        par = parent[par];
    }
    shortestPath.push_back(par);

    // finalise the ans
    reverse(shortestPath.begin(),shortestPath.end());
    return shortestPath;
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
            cout << "(" << graph[i][j].first << "," << graph[i][j].second << ")";
        }
        cout << "\n";
    }

    vector<int> distArr = minDistArr(graph);
    for(int i = 0; i < distArr.size(); i++){
        cout << distArr[i] << " ";
    }

    return 0;
}