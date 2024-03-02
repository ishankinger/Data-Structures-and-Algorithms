// DIJKSTRA'S ALGORITHM ( USING SET DATASTRUCTURE )
// IN THIS ALSO SIMILAR PROCEDURE IS FOLLOWED AS THAT FOR PRIORITY QUEUE
// BUT THIS WILL BE SLIGHTLY MORE EFFICIENT THEN PRIORITY QUEUE AS FOR SAME NODES MINIMAL DISTANCE WILL BE CHOSEN AND OTHER GREATER ONES
// WILL BE SIMPLY ERASED WHILE IN PRIORITY QUEUE WE HAVE TO CHECK THAT ALSO

#include<bits/stdc++.h>
using namespace std;

vector<int> minDistArr(vector< vector< pair<int,int> > > graph){
    // a dist arr is defined
    vector<int> dist(graph.size(), INT_MAX);

    // a set is defined which have unique elements in the sorted order
    set< pair<int,int> > st;
    
    // initialise the values
    st.insert({0,0});
    dist[0] = 0;

    // traverse in the set till not empty
    while(not st.empty()){

        // get node and len from the first element of the set and then erase it
        int node = (*st.begin()).second;
        int len = (*st.begin()).first;
        st.erase(*st.begin());

        // traverse through all of it's neighbours
        for(auto neighbour : graph[node]){

            // get neighbour node information
            int neighbourNode = neighbour.first;
            int nodeToNeighbour = neighbour.second;

            // check for the updation
            if(dist[neighbourNode] > len + nodeToNeighbour){

                // if dist of neighbour node is not int_max means it is initially in the set with some greater distance
                // so simply erase it
                if(dist[neighbourNode] != INT_MAX){
                    st.erase({dist[neighbour.first],neighbour.first});
                }

                // then update the value of neighbour node and push it into the stack
                dist[neighbourNode] = len + nodeToNeighbour;
                st.insert({len + nodeToNeighbour,neighbourNode});
            }
        }
    }
    // at end return the minimum distance array
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
