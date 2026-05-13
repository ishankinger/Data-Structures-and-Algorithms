// CHECK IF THE GIVEN BINARY TREE IS A BST

#include<iostream>
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

Node* insertBST(Node* root, int val){
    if(root==NULL) return new Node(val);
    if(val<root->data) root->left = insertBST(root->left,val);
    else root->right = insertBST(root->right,val);
    return root;
}

// FOR LEFT SUB-CHILD MIN_VALUE CAN BE DECIDED FROM IT WHILE IT'S MAXIMUM VALUE IS IT'S ROOT NODE VALUE
// FOR RIGHT SUB-CHILD MAX_VALUE CAN BE DECIDED FROM IT WHILE IT'S MININUM VALUE IS IT'S ROOT NODE VALUE
bool isBST(Node* root,int minValue, int maxValue){                        // FUNCTION GIVES RESULT IN O(N) TIME COMPLEXITY                

    if(root==NULL) return true;
    if(root->data < minValue || root->data > maxValue) return false;
    return isBST(root->left,minValue,root->data) && isBST(root->right,root->data,maxValue);
}

// ANOTHER WAY TO DO THIS QUESTION IS USING INORDER VECTOR
// IF INORDER VECTOR IS SORTED THEN IT IS A BINARY SEARCH TREE ELSE NOT A BINARY SEARCH TREE
// BUT THIS WILL BE LESS SPACE EFFICIENT AS WE ARE MAKING A N VECTOR
// BUT WE CAN ALSO THIS WITHOUT USING SPACE
bool isBST2(Node* root,Node* &prev){
    if(root == NULL) return true;
    if(!isBST2(root->left , prev)) return false;
    if(prev != NULL && root->data <= prev->data) return false;
    prev = root;
    return isBST2(root->right, prev);
}

int main(){
    Node *root3 = new Node(4);
    root3->left = new Node(2);
    root3->right = new Node(5);
    root3->left->right = new Node(3);
    root3->left->left = new Node(7);
    Node* prev = NULL;
    if(isBST2(root3,prev)) cout<<"Yes, it is a BST\n";
    else cout<<"No, it is not a BST\n";
    if(isBST(root3,INT_MIN,INT_MAX))  cout<<"Yes, it is a BST\n";
    else cout<<"No, it is not a BST\n";

    return 0;
}