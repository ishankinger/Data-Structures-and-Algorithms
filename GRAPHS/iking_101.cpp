// IMPLEMENTATION OF A GRAPH USING ADJACENCY LIST ( ARRAY OF LINKED LISTS )

#include<bits/stdc++.h>
using namespace std;

vector< list< pair<int,int> > > directed_weighted_graph;
int v;

void add_edge(int src,int dest,vector<list<pair<int,int>>> &graph,int wt = 1,bool bi_dir = true){
    graph[src].push_back({dest,wt});
    if(bi_dir){
        graph[dest].push_back({src,wt});
    }
}

void display(vector<list<pair<int,int>>> &graph){
    for(int i=0;i<graph.size();i++){
        cout<<i<<" -> ";
        for(auto ele:graph[i]){
            cout<<" ("<<ele.first<<" "<<ele.second<<") ";
        }
        cout<<"\n";
    }
}

int main(){
    cin>>v;
    directed_weighted_graph.resize(v,list<pair<int,int>>());
    int e;
    cin>>e;
    while(e--){
        int s,d,wt;
        cin>>s>>d>>wt;
        add_edge(s,d,directed_weighted_graph,wt,false);
    } 
    display(directed_weighted_graph);
    return 0;
}