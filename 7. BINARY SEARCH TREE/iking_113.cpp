// GIVEN AN INTEGER N AND WE HAVE TO GENERATE ALL THE POSSIBLE BST'S FOR NODES 1-N

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* right, *left;
    Node(int data){
        val = data;
        right = left = NULL;
    }
};

void preorder(Node* root){
    if(root == NULL) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

vector<Node*> generateTreesHelper(int start, int end){

    vector<Node*> treesList;
    if(start > end){
        treesList.push_back(NULL);
        return treesList;
    }
    for(int i=start;i<=end;i++){
        vector<Node*> leftSubTrees = generateTreesHelper(start,i-1);
        vector<Node*> rightSubTrees = generateTreesHelper(i+1,end);
        
        for(Node* leftSubTree : leftSubTrees){
            for(Node* rightSubTree : rightSubTrees){
                Node* rootNode = new Node(i);
                rootNode->left = leftSubTree;
                rootNode->right = rightSubTree;
                treesList.push_back(rootNode);
            }
        }
    }
    return treesList;
}

vector<Node*> generateTrees(int n){
    int start = 1 ,end = n;
    return generateTreesHelper(start,end);
}

int main(){ 
    int n; cin>>n;
    vector<Node*> list = generateTrees(n);
    for(int i=0;i<list.size();i++){
        preorder(list[i]);
        cout<<"\n";
    }
    return 0;
}