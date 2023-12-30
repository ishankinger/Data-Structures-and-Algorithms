// ALIEN DICTIONARY

#include<bits/stdc++.h>
using namespace std;

vector<char> alienDict(vector<string> dict, int n, int k){
    
    vector< vector<int> > graph(k,vector<int>());
    for(int i = 0; i < dict.size() - 1; i++){
        for(int j = 0; j < min(dict[i].size(),dict[i+1].size()); j++){
            if(dict[i][j] != dict[i+1][j]){
                graph[dict[i+1][j]-'a'].push_back(dict[i][j]-'a');
                break;
            }
        }
    }

    vector<int> indegree(graph.size(),0);
    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph[i].size(); j++){
            indegree[graph[i][j]]++;
        }
    }

    queue<int> q;
    for(int i = 0; i < indegree.size(); i++){
        if(indegree[i] == 0) q.push(i);
    }

    vector<int> topo;
    while(not q.empty()){
        int ele = q.front();
        q.pop();
        topo.push_back(ele);
        for(auto neighbour : graph[ele]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0) q.push(neighbour);
        }
    }

    vector<char> ans;
    for(int i = 0; i < topo.size(); i++){
        ans.push_back(topo[i]+'a');
    }

    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){

    int n, k;
    cin >> n >> k;
    vector<string> dict(n);
    for(int i = 0; i < n ; i++){
        cin >> dict[i];
    }

    vector<char> order = alienDict(dict,n,k);
    for(int i = 0; i < order.size(); i++){
        cout << order[i] << " ";
    }

    return 0;
}