// REMOVE ALL LEAF NODES FROM THE BINARY SEARCH TREE

#include<iostream>
using namespace std;

struct Node{
    int val;
    Node *left, *right;
    Node(int data){
        val = data;
        left = NULL;
        right = NULL;
    }
};
Node* inorder(Node* root){
    if(root==NULL) return NULL;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

Node* removeLeafNodes(Node* &root){
    if(root == NULL){                                   
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){               // CONDITION FOR LEAF NODES
        return NULL;                                             // WHEN WE ARE AT THIS POSITION THEN RETURN NULL IN PLACE OF ROOT FOR LEAF NODE
    }
    root->left = removeLeafNodes(root->left);               
    root->right = removeLeafNodes(root->right);
    return root;
}

int main(){
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);

    inorder(root);
    cout<<"\n";
    removeLeafNodes(root);
    cout<<"\n";
    inorder(root);
    

    return 0;
}