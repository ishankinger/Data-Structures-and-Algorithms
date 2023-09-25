// HEIGHT OF A BINARY TREE => IT IS THE DEPTH OF THE TREE'S DEEPEST NODE FROM THE ROOT

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

int calcHeight(Node* root){                     // FUNCTION TO CALCULATE HEIGHT OF TREE

    if(root==NULL) return 0;                                               // BASE CASE WHERE IF WE GET LAST NODE THEN FROM THERE IT'S HEIGHT RETURN TO BE 0
    return max(calcHeight(root->left),calcHeight(root->right))+1;          // HERE IT WILL RETURN THE HEIGHT OF ALL NODES BELOW IT AND ADDING IT'S OWN HEIGHT AS 1
}

int main(){
    struct Node* root= new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->right=new Node(5);
    root->left->left=new Node(4);
    root->right->left=new Node(6);
    root->right->left->right=new Node(7);
    root->right->left->right->left= new Node(8);

    cout<<calcHeight(root);

    return 0;
}