// NUMBER OF WAYS TO ARRIVE AT DESTINATION

#include<bits/stdc++.h>
using namespace std;

int countPaths(int n, vector<vector<int>>& roads) {
    vector< pair<long long,long long> > adj[n];
    for(auto it : roads){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }

    priority_queue< pair<long long,long long>, vector< pair<long long,long long> > 
    , greater< pair<long long,long long> > > pq;
    
    vector<long long> dist(n,1e14), ways(n,0);
    dist[0] = 0;
    ways[0] = 1;
    pq.push({0,0});
    long long mod = 1e9 + 7;
    while(not pq.empty()){
        long long dis = pq.top().first;
        long long node = pq.top().second;
        pq.pop();

        for(auto it : adj[node]){
            long long adjNode = it.first;
            long long edN = it.second;
            if(dis + edN < dist[adjNode]){
                dist[adjNode] = dis + edN;
                pq.push({dis+edN,adjNode});
                ways[adjNode] = ways[node];
            }
            else if(dis + edN == dist[adjNode]){
                ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
            }
        }
    }
    return ways[n-1] % mod;
}