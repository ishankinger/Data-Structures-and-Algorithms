// GIVEN A PREORDER TRAVERSAL OF A BINARY SEARCH TREE CONSTRUCT THE BST

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *right, *left;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

void inorder(Node *root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* BSTFromPreorderHelper(vector<int> &preorder, int prestart, int preend, vector<int> &inorder, int instart, int inend, unordered_map<int,int> &inmap){
        if(prestart > preend || instart>inend) return NULL;
        
        Node *root = new Node(preorder[prestart]);
        int inroot_idx = inmap[preorder[prestart]];
        int leftSubTreeElements = inroot_idx - instart;
        
        root->left = BSTFromPreorderHelper(preorder,prestart+1,prestart+leftSubTreeElements,inorder,instart,inroot_idx-1,inmap);
        root->right = BSTFromPreorderHelper(preorder,prestart+leftSubTreeElements+1, preend,inorder,inroot_idx+1,inend,inmap);
}

Node* BSTFromPreorder(vector<int> &preorder){
    vector<int> inorder = preorder;
    sort(inorder.begin(),inorder.end());

    unordered_map<int,int> inmap;
    for(int i=0;i<inorder.size();i++){
        inmap[inorder[i]] = i;
    }
 
    return BSTFromPreorderHelper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inmap);
}

int main(){
    int n; cin>>n;
    vector<int> preorder(n);
    for(int i=0;i<n;i++) cin>>preorder[i];

    Node* root = BSTFromPreorder(preorder);
    inorder(root);
    
    return 0;
}