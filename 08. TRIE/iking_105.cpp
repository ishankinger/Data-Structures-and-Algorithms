#include <iostream>
#include <vector>
#include <memory>
using namespace std;

struct TrieNode{
    TrieNode* child[2];
    int bit;

    TrieNode(int bit){
        child[0] = nullptr;
        child[1] = nullptr;
        this->bit = bit;
    }
};

class Trie{
private:
    TrieNode* root;

public:
    Trie(){
        root = new TrieNode(-1);
    }

    void insert(long long val){
        TrieNode* currNode = root;
        for(int i = 63; i >= 0; i--){
            int bit = ((val >> i) & 1);
            if(currNode->child[bit] == nullptr)
                currNode->child[bit] = new TrieNode(bit);
            currNode = currNode->child[bit];
        }
    }

    long long getMaxComplement(long long val){
        TrieNode* currNode = root;
        
        if(!currNode->child[0] && !currNode->child[1])
            return 0;
            
        long long comp = 0;
        for(int i = 63; i >= 0; i--){
            int bit = ((val >> i) & 1);
            if(currNode->child[1 - bit] != nullptr){
                comp |= (1ll << i);
                currNode = currNode->child[1 - bit];
            }
            else{
                currNode = currNode->child[bit];
            }
        }
        return comp;
    }
};

class Solution{
private:
    Trie* t;

    long long getSubTreeSums(int node, int par, vector<vector<int>> &tree, 
                            vector<int> &values, vector<long long> &subTreeSums){
        
        long long subTreeSum = values[node];

        for(auto child : tree[node]){
            if(par == child)
                continue;
            subTreeSum += getSubTreeSums(child, node, tree, values, subTreeSums);
        }

        return subTreeSums[node] = subTreeSum;
    }

    void findMaxXor(int node, int par, vector<vector<int>> &tree, 
                    vector<long long> &subTreeSums, long long &maxXor){
        
        maxXor = max(maxXor, t->getMaxComplement(subTreeSums[node]));

        for(auto child : tree[node]){
            if(par == child)
                continue;
            findMaxXor(child, node, tree, subTreeSums, maxXor);
        }

        t->insert(subTreeSums[node]);
    }

public:

    long long getMaxXorSubTrees(vector<vector<int>> &edges, vector<int> &values){
        int n = edges.size() + 1;
        t = new Trie();

        vector<vector<int>> tree(n);
        for(int i = 0; i < n-1; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        vector<long long> subTreeSums(n);
        getSubTreeSums(0, -1, tree, values, subTreeSums);

        long long maxXor = 0;
        findMaxXor(0, -1, tree, subTreeSums, maxXor);

        return maxXor;
    }
};

int main(){

    int n;
    cin >> n;

    vector<vector<int>> edges;
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    vector<int> values(n);
    for(int i = 0; i < n; i++)
        cin >> values[i];
    
    Solution s;
    cout << s.getMaxXorSubTrees(edges, values) << "\n";

    return 0;
}