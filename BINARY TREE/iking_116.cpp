// SUM REPLACEMENT IN A BINARY TREE
// SIMILAR TO PREFIX SUM IN ARRAYS HERE NODE IS REPLACED BY SUM OF ALL THE NODES ORIGINATING FROM IT

#include<bits/stdc++.h>
using namespace std;

struct Node{                                // BINARY TREE'S NODE STORE ONE VALUE AND HAVE TWO POINTERS POINTING TO IT'S TWO CHILDREN
    int data;
    struct Node*left;                       // FOR LEFT SUB-TREE
    struct Node*right;                      // FOR RIGHT SUB-TREE

    Node(int val){                          // CONSTRUCTOR INITIALISING LEFT AND RIGHT POINTERS BY NULL
        data=val;
        left=NULL;
        right=NULL;
    }
};

void preorder(struct Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void sumReplace(Node* root){
    if(root==NULL) return;
    sumReplace(root->left);                               // JUST TRAVERSE IN A BINARY TREE
    sumReplace(root->right);
    if(root->left) root->data += root->left->data;        // AND THE LEFT NODE DATA TO IT
    if(root->right) root->data += root->right->data;      // AND THEN RIGHT NODE DATA TO IT
}

int main(){
   struct Node* root= new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->right=new Node(5);
    root->left->left=new Node(4);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    preorder(root);
    cout<<"\n";
    sumReplace(root);
    preorder(root);

    return 0;
}