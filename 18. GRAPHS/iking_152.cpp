// KOSARAJU'S ALGORITHM FOR STRONGLY CONNECTED COMPONENTS
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// SORT ALL THE EDGES ACCORDING TO THE FINISHING TIME
// REVERSE THE GRAPH
// DO A DFS

void dfs(int node, vector<int> &vis, vector<vector<int>> &graph, stack<int> &st){
    vis[node] = 1;
    for(auto neighbour : graph[node]){
        if(!vis[neighbour])
            dfs(neighbour, vis, graph, st);
    }
    st.push(node);
}

void dfs(int node, int scc, vector<int> &nodeComp, vector<vector<int>> &graph){
    nodeComp[node] = scc;
    for(auto neighbour : graph[node]){
        if(!nodeComp[neighbour])
            dfs(neighbour, scc, nodeComp, graph);
    }
}

int getStronglyConnectedComponents(int V, vector<vector<int>> &graph){

    vector<int> vis(V, 0);
    stack<int> st;
    for(int i = 0; i < V; i++){
        if(!vis[i]){
            dfs(i, vis, graph, st);
        }
    }

    vector<vector<int>> graphRev(V);
    for(int node = 0; node < V; node++){
        for(auto neighbour : graph[node]){
            graphRev[neighbour].push_back(node);
        }
    }

    int scc = 0;
    vector<int> nodeComp(V, 0);
    while(!st.empty()){
        int node = st.top();
        st.pop();
        
        if(!nodeComp[node]){
            scc++;
            dfs(node, scc, nodeComp, graphRev);
        }
    }

    cout << scc << "\n";
    for(int i = 0; i < V; i++)
        cout << nodeComp[i] << ' ';
    cout << "\n";

    return scc;
}

int main(){

    int n;
    cin >> n;

    int m;
    cin >> m;

    vector<vector<int>> graph(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    getStronglyConnectedComponents(n, graph);

    return 0;
}