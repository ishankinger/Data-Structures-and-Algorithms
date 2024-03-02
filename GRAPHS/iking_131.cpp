// DIJKSTRA'S ALGORITHM ( USING PRIORITY QUEUE DATASTRUCTURE )
// START THE BFS FROM THE SOURCE NODE AND FOR EACH NEIGHBOUR CHECK PATH LENGTH FROM THE PARENT
// IF THAT LENGTH IS LESS THAN DIST[NEIGHBOUR] THEN UPDATE IT AND ALSO PUSH IT INTO THE PRIORITY QUEUE WITH PAIR {DIST,NEIGHBOUR}
// AT END THE DISTANCE ARRAY WILL BE OUR FINAL ANSWER ARRAY

#include<bits/stdc++.h>
using namespace std;

vector<int> minDistArr(vector< vector< pair<int,int> > > graph){
    // a dist arr is defined
    vector<int> dist(graph.size(), INT_MAX);

    // a priority queue is defined (showing minimum element at the top)
    priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > pq;

    // initialise the values
    pq.push({0,0});
    dist[0] = 0;

    // traverse in the priority queue
    while(not pq.empty()){
        
        // get node and it's length from source node and pop it
        int node = pq.top().second;
        int len = pq.top().first;
        pq.pop();

        // then traverse on all it's neighbours and update the dist array
        for(auto neighbour : graph[node]){

            // get neighbour node information
            int neighbourNode = neighbour.first;
            int nodeToNeighbour = neighbour.second;

            // check for updation
            if(dist[neighbourNode] > len + nodeToNeighbour){
                dist[neighbourNode] = len + nodeToNeighbour;
                pq.push({dist[neighbourNode],neighbourNode});
            }
        }
    }

    // return the final answer
    return dist;
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

    vector<int> distArr = minDistArr(graph);
    for(int i = 0; i < distArr.size(); i++){
        cout << distArr[i] << " ";
    }

    return 0;
}
