// ACCOUNT MERGE
// HERE WE ARE GIVEN DIFFERENT USERS AND FOR EACH USER WE ARE PROVIDED WITH SOME OF HIS EMAILS
// THE SAME USER CAN REPEAT WITH DIFFERENT SET OF EMAILS
// IF FOR SAME NAME USER, AT LEAST ONE EMAIL MATCHES THEN WE CAN MERGE THAT USER'S EMAILS INTO ONE SET
// RETURN THE NEW UPDATED LIST OF USERS WITH NEW SET OF EMAILS MERGED
// IT CAN BE POSSIBLE THAT TWO USERS HAVE SAME NAME BUT NO EMAIL IS MATCHED SO CONSIDER DIFFERENT AND REPRESENT IN DIFFERENT LISTS
// ALSO EMAILS ADDRESSES SHOULD BE IN SORTED ORDER

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

// function to merge the accounts of the user
vector< vector< string > > accountsMerge(vector< vector<string> > details){
    
    // disjoint set for each initial user is created giving each user 0 based indices
    DisjointSet ds(details.size());
    int n = details.size();
    
    // initial sort the details string vector
    sort(details.begin(), details.end());
    
    // map storing email's owner number index
    unordered_map<string,int> mapMailNode;
    
    // go in the details of users one by one to merge the accounts
    for(int i = 0; i < n; i++){
        for(int j = 1; j < details[i].size(); j++){
            
            // mail of the user
            string mail = details[i][j];
            
            // mail not seen earlier
            // so this user will become the owner of this email for now
            if(mapMailNode.find(mail) == mapMailNode.end()){
                mapMailNode[mail] = i;
            }
            
            // mail seen earlier
            // so present user and user who is owner of this email will be merged
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