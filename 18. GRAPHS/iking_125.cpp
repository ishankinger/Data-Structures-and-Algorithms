// ALIEN DICTIONARY
// GIVEN A SET OF DICTIONARY IN SORTED ORDER FROM THAT WE HAVE TO FIND COORECT ORDER OF THE DICTIONARY
// SO FOR THIS QUESTION WE WILL COMPARE THE CONSECUTIVE WORDS AND THE CHARACTER UNMATCHED WILL GIVE US ONE EDGE OF GRAPH
// FROM THAT WE CAN APPLY TOPO SORT ON IT

#include<bits/stdc++.h>
using namespace std;

vector<char> alienDict(vector<string> dict, int n, int k){

    // first we will make a graph from the given dictionary
    vector< vector<int> > graph(k,vector<int>());
    for(int i = 0; i < dict.size() - 1; i++){
        for(int j = 0; j < min(dict[i].size(),dict[i+1].size()); j++){

            // for consecutive dict letters the ones making difference will form an edge for us
            if(dict[i][j] != dict[i+1][j]){
                graph[dict[i+1][j]-'a'].push_back(dict[i][j]-'a');
                break;
            }
        }
    }

    // from the graph we will form an indegree vector
    vector<int> indegree(graph.size(),0);
    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph[i].size(); j++){
            indegree[graph[i][j]]++;
        }
    }

    // for bfs traversal we form queue to do topo sort
    queue<int> q;
    for(int i = 0; i < indegree.size(); i++){
        if(indegree[i] == 0) q.push(i);
    }

    // now we will get topo sort vector
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

    // converting topo vector of numbers to characters
    vector<char> ans;
    for(int i = 0; i < topo.size(); i++){
        ans.push_back(topo[i]+'a');
    }
    
    // reversing the vector for the final ans and returning it
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
