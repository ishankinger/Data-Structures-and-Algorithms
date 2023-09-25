// BINARY TREE TRAVERSALS ( DEPTH FIRST TRAVERSALS )
// WE WILL FIRST MOVE TO DEPTH AND TRAVERSE THROUGH ALL NODES
// THESE ARE OF THREE TYPES -
// 1. PREORDER TRAVERSAL-> PRINT ROOT THEN LEFT SUB-TREE THEN RIGHT SUB-TREE
// 2. INORDER TRAVERSAL-> PRINT LEFT SUB-TREE THEN ROOT THEN RIGHT SUB-TREE
// 3. POSTORDER TRAVERSAL-> PRINT LEFT SUB-TREE THEN RIGHT SUB-TREE THEN ROOT

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

void preorder(struct Node* root){           // TIME COMPLEXITY OF ALL THE THREE METHODS IS O(N) N IS NO. OF TOTAL NODES PRESENT IN TREE
    if(root==NULL) return;
    cout<<root->data<<" ";                  // FIRST PRINT DATA AND THEN
    preorder(root->left);                   // CALL FOR LEFT SUB-TREE
    preorder(root->right);                  // THEN CALL FOR RIGHT SUB-TREE
}
void inorder(struct Node* root){            // JUST ORDERING IS CHANGED OTHERWISE CONCEPT IS SAME
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(struct Node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    struct Node* root= new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->right=new Node(5);
    root->left->left=new Node(4);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    cout<<"preorder traversal -> ";
    preorder(root);
    cout<<"\n";
    cout<<"inorder traversal -> ";
    inorder(root);
    cout<<"\n";
    cout<<"postorder traversal -> ";
    postorder(root);
    cout<<"\n";

    return 0;
}