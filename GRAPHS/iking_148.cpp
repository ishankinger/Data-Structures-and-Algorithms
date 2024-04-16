// ACCOUNT MERGE

#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
        vector<int> rank,parent,size;
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            for(int i = 0; i <= n; i++){
                parent[i] = i;
            }
            size.resize(n+1,1);
        }

        int findUParent(int node){
            if(node == parent[node]){
                return node;
            }
            return parent[node] = findUParent(parent[node]);
        }

        void unionByRank(int u, int v){
            int ulp_u = findUParent(u);
            int ulp_v = findUParent(v);
            if(ulp_u == ulp_v) return;
            if(rank[ulp_v] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }
            else if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_v] = ulp_u;
            }
            else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }

        void unionBySize(int u, int v){
            int ulp_u = findUParent(u);
            int ulp_v = findUParent(v);
            if(ulp_u == ulp_v) return;
            if(size[ulp_v] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};

vector< vector< string > > accountsMerge(vector< vector<string> > details){
    DisjointSet ds(details.size());
    int n = details.size();
    sort(details.begin(), details.end());
    unordered_map<string,int> mapMailNode;
    for(int i = 0; i < n; i++){
        for(int j = 1; j < details[i].size(); j++){
            string mail = details[i][j];
            // mail not seen earlier
            if(mapMailNode.find(mail) == mapMailNode.end()){
                mapMailNode[mail] = i;
            }
            // mail seen earlier
            else{
                ds.unionBySize(i,mapMailNode[mail]);
            }
        }
    }
    
    // combining all mails for an ultimate parent
    vector<string> mergedMails[n];
    for(auto it : mapMailNode){
        
        // mails are stored in the ultimate parent
        string mail = it.first;
        int node = ds.findUParent(it.second);
        mergedMails[node].push_back(mail);
    }

    vector< vector< string > > ans;
    for(int i = 0; i < n; i++){
        
        // if no mails then continue
        if(mergedMails[i].size() == 0) continue;
        
        // sorting is needed
        sort(mergedMails[i].begin(),mergedMails[i].end());
        
        // push all the mails in the temp vector
        vector<string> temp;
        
        // first push user name
        temp.push_back(details[i][0]);
        
        // then push the mails
        for(auto it : mergedMails[i]){
            temp.push_back(it);
        }

        // then finally put into the answer
        ans.push_back(temp);
    }

    return ans;

}



int main(){
    int n;
    cin >> n;
    vector< vector< string > > userIds(n,vector<string>());
    for(int i = 0; i < n; i++){
        string user;
        userIds[i].push_back(user);
        int e; 
        cin >> e;
        for(int i = 0; i < e; i++){
            string email;
            userIds[i].push_back(email);
        }
    }

    vector< vector< string > > ans = accountsMerge(userIds);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}