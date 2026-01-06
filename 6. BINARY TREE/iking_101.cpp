// BINARY TREE BASIC FORMATION

#include<iostream>
using namespace std;

class Node{                                // BINARY TREE'S NODE STORE ONE VALUE AND HAVE TWO POINTERS POINTING TO IT'S TWO CHILDREN
public:
    int data;
    Node*left;                       // FOR LEFT SUB-TREE
    Node*right;                      // FOR RIGHT SUB-TREE

    Node(int val){                          // CONSTRUCTOR INITIALISING LEFT AND RIGHT POINTERS BY NULL
        data=val;
        left=NULL;
        right=NULL;
    }
};

int main(){
    Node* root= new Node(1);                  //              (1)
    root->left=new Node(2);                   //             /   \         
    root->right=new Node(3);                  //           (2)   (3)
    root->left->left=new Node(4);             //           / \ 
    root->left->right=new Node(5);            //        (4)   (5)
     
    return 0;
}