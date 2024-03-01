// TOPOLOGICAL SORT
// LINEAR ORDERING OF VERTICES SUCH THAT IF THERE IS AN EDGE FROM U TO V, THEN U ALWAYS APPEARS BEFORE V IN THAT ORDERING
// THERE IS CONDITION FOR TOPOLOGICAL SORT TO EXIST AND THAT IS THE GRAPH SHOULD BE DIRECTED AND ACYCLIC
// SIMPLY WE WILL APPLY DFS ON ALL THE UNVISITED ELEMENTS AND WHEN WE ARE RETURNING FROM ANY ELEMENT WE WILL PUSH IT INTO THE STACK
// THE ORDERING OF NODES WHEN WE ARE POPPING IT OUT WILL BE OUR ANSWER

#include<bits/stdc++.h>
using namespace std;

void dfs(int src, vector< list<int> > graph, vector<int> &vis, stack<int> &st){

    // mark it visited
    vis[src] = 1;

    // traverse through all of it's neighbours
    for(auto neighbour : graph[src]){

        // do dfs on non-visited elements
        if(not vis[neighbour]){
            dfs(neighbour,graph,vis,st);
        }
    }
    
    // pushing into stack when we are returning
    st.push(src);
    return;
}

void topologicalSort(vector< list<int> > graph){
    // stack and visited arr is needed
    stack<int> st;
    vector<int> vis(graph.size(),0);

    // do dfs on all the elements as it is directed graph
    for(int i = 0; i < graph.size(); i++){
        if(not vis[i]){
            dfs(i,graph,vis,st);
        }
    }

    // pop out elements from the stack and print topological sort order for the given graph
    while(not st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
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

