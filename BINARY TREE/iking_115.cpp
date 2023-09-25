// PRINT ALL NODES AT DISTANCE K
// FROM A GIVEN NODE WE HAVE TO PRINT ALL THE NODES AT A DISTANCE K FROM IT

// CASE 1: NODES IN SUBTREE OF GIVEN NODE
// FOR EACH ELEMENT WE WILL MOVE DOWN OUR K ELEMENT AND WILL DECREASE BY 1
// WHEN K==0 THEN OUR ANSWER AND OUR DISTANCE IS COVERED

// CASE 2: NODES IN ANCESTORS
// FIND THE DISTANCE FROM ALL THE ANCESTORS FROM TARGET NODE
// FOR ALL ANCESTORS GET NODES FOR K-D WHERE D IS DISTANCE CALCULATED


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

// CASE-1
void printSubTreeNodes(Node* root,int k){
    if(root==NULL || k<0) return;
    if(k==0){
        cout<<root->data<<"\n";
        return;
    }
    printSubTreeNodes(root->left,k-1);          // FROM THESE TWO FUNCTION CALLS WE ARE GOING IN DEPTH OF OUR BINARY TREE
    printSubTreeNodes(root->right,k-1);         // AND IN EACH CALL K -- SO WHEN K==0 MEANS WE GET ONE NODE AT DISTANCE K
}

// CASE-2
int printNodesAtk(Node*root,Node*target, int k){
    if(root==NULL) return -1;
    if(root==target){
        printSubTreeNodes(root,k);
        return 0;
    }
    int dl = printNodesAtk(root->left,target,k);
    if(dl!=1){
        if(dl+1==k){
            cout<<root->data<<" ";
        }
        else{
            printSubTreeNodes(root->right,k-dl-2);
        }
    }
}

int main(){

    return 0;
}