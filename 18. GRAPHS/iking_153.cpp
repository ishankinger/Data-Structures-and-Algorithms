// TARJAN'S ALGORITHM FOR BRIDGES IN THE GRAPH
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// MAINTAIN TWO ARRAYS OF TIME - IN_TIME -> TELLS WHEN I REACHED THE NODE
//                             - LOW_TIME -> STORES THE LOWEST TIME OVER ALL THE NEIGHBOURS OF NODE EXCEPT IT'S PARENT

class Solution {
public:

    void dfs(int node, int parent, vector<int> &vis, vector<int> &inTime, vector<int> &lowTime, 
             int timer, vector<vector<int>> &network, vector<vector<int>> &bridges){
        
        vis[node] = 1;
        inTime[node] = lowTime[node] = timer;
        timer++;
        for(auto neighbour : network[node]){
            if(neighbour == parent)
                continue;

            // if not visited then call for dfs and get low time and check for the bridge condition
            if(!vis[neighbour]){
                dfs(neighbour, node, vis, inTime, lowTime, timer, network, bridges);
                lowTime[node] = min(lowTime[node], lowTime[neighbour]);
                if(lowTime[neighbour] > inTime[node])
                    bridges.push_back({node, neighbour});
            }

            // else if node visited then it can't have a bridge so just minimize the lowTime if possible
            else{
                lowTime[node] = min(lowTime[node], lowTime[neighbour]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        int m = connections.size();

        vector<vector<int>> network(n);
        for(int i = 0; i < m; i++){
            network[connections[i][0]].push_back(connections[i][1]);
            network[connections[i][1]].push_back(connections[i][0]);
        }

        int timer = 1;
        vector<int> vis(n, 0);
        vector<int> inTime(n);
        vector<int> lowTime(n);
        vector<vector<int>> bridges;

        dfs(0, -1, vis, inTime, lowTime, timer, network, bridges);
        return bridges;
    }
};