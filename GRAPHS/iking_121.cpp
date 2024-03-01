// KAHN'S ALGORITHM ( TOPOLOGICAL SORT USING BFS )
// ELEMENT OF INDEGREE 0 IS PUSHED INTO THE QUEUE AND WHEN WE ARE POPPING OUT THE ELEMENT ALL IT'S NEIGHBOUR EDGES ARE ALSO TO BE REMOVED

#include<bits/stdc++.h>
using namespace std;

void topologicalSort(vector< vector<int> > graph){

    // indegree array for all the nodes is maintained
    vector<int> indegree(graph.size(),0);
    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph[i].size(); j++){
            indegree[graph[i][j]]++;
        }
    }

    // first we will push all elements of indegree 0 in our queue
    queue<int> q;
    for(int i = 0; i < graph.size(); i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    // traverse till the queue is not empty
    while(not q.empty()){
        
        // taking the front element of the queue
        int ele = q.front();
        cout<<ele<<" ";
        q.pop();

        // for each node it's neighbour's will also be removed
        for(auto neighbour : graph[ele]){
            indegree[neighbour]--;

            // if it has indegree 0 then push into the queue
            if(indegree[neighbour] == 0) 
                q.push(neighbour);
        }
    }
}

int main(){
    int v;
    cin >> v;
    vector< vector<int> > graph(v,vector<int>());
    int e;
    cin >> e;
    while(e--){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    for(int ele = 0; ele < graph.size(); ele++){
        cout << ele << " -> ";
        for(auto neighbour : graph[ele]){
            cout << neighbour << " ";
        }
        cout << "\n";
    }   
    topologicalSort(graph);

    return 0;
}
