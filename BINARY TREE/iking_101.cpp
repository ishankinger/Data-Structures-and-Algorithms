// BINARY TREE BASIC FORMATION

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

int main(){
    struct Node* root= new Node(1);           //              (1)
    root->left=new Node(2);                   //             /   \         
    root->right=new Node(3);                  //           (2)   (3)
    root->left->left=new Node(4);             //           / \ 
    root->left->right=new Node(5);            //        (4)   (5)
     
    return 0;
}