// CITY WITH THE SMALLEST NUMBER OF NEIGHBOUR AT A THRESHOLD DISTANCE

#include<bits/stdc++.h>
using namespace std;

int cityNeeded(vector< vector< pair<int,int> > > graph, int threshold){
    vector< vector<int> > distMatrix(graph.size(), vector<int>(graph.size(),INT_MAX));
    
    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph[i].size(); j++){
            distMatrix[i][graph[i][j].first] = graph[i][j].second; 
        }
    }
    
    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph.size(); j++){
            if(i == j) distMatrix[i][j] = 0;
        }
    }
    
    for(int via = 0; via < graph.size(); via++){
        for(int i = 0; i < graph.size(); i++){
            for(int j = 0; j < graph.size(); j++){
                if(distMatrix[i][via] != INT_MAX && distMatrix[via][j] != INT_MAX){
                    distMatrix[i][j] = min(distMatrix[i][j],(distMatrix[i][via]+distMatrix[via][j]));
                }
            }
        }
    }

    vector<int> cityNum(graph.size(),0);
    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph.size(); j++){
            if(distMatrix[i][j] <= threshold and distMatrix[i][j] != INT_MAX){
                cityNum[i]++;
            }
        }
    }

    int ans = -1;
    int minNum = INT_MAX;
    for(int i = 0; i < cityNum.size(); i++){
        if(cityNum[i] <= minNum){
            ans = i;
            minNum = cityNum[i];
        }
    }
    return ans;
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
    int threshold;
    cin >> threshold;

    for(int i = 0; i < graph.size(); i++){
        cout << i << " -> ";
        for(int j = 0; j < graph[i].size(); j++){
            cout << "(" << graph[i][j].first << "," << graph[i][j].second << ") ";
        }
        cout << "\n";
    }

    cout << cityNeeded(graph,threshold);

    return 0;
}