// SHORTEST DISTANCE BETWEEN TWO GIVEN NODES

// FOR THIS WE HAVE TO CALCULATE THE LOWEST COMMON ANCESTOR FOR THE TWO GIVEN NODES AND THEN
// ADD THE DISTANCE OF THOSE NODES FROM OUR GIVEN COMMON ANCESTORS

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

Node* LCA(Node*root,int n1,int n2){                      // FUNCTION TO GET LOWEST COMMON ANCESTOR OF TWO GIVEN N1 AND N2 NODES

    if(root==NULL) return NULL;

    if(root->data==n1 || root->data==n2) return root;      
    
    Node* left = LCA(root->left,n1,n2);
    Node* right = LCA(root->right, n1, n2);
    
    if(left!=NULL && right!=NULL){
        return root;
    }
    if(left==NULL && right==NULL){
        return NULL;
    }
    if(left!=NULL && right==NULL){
        return LCA(root->left,n1,n2);
    }
    if(left==NULL && right!=NULL){
        return LCA(root->right,n1,n2);
    }
}

int findDist(Node*root, int k,int dist){            // FUNCTION TO GET DISTANCE FROM N1 AND LCA

    if(root==NULL) return -1;                       // IF AT END OF RIGHT OR LEFT TRAVERSAL WE DIDNOT GET ROOT K THEN RETURN -1
    if(root->data==k) return dist;                  // ELSE IF WE GET THEN RETURN THE DIST TILL THAT TRAVERSAL
    
    int left = findDist(root->left,k,dist+1);       // FROM THIS WE WILL TRAVERSE IN LEFT NODES FIRST AND CHECK WHETHER WE GET NODE OR NOT
    if(left!=-1) return left;                       // IF NOT THEN WE WILL MOVE TO RIGHT NODES
    return findDist(root->right,k,dist+1);          // EACH TIME WE ARE MAKING DIST++
}

int distanceBetweenNodes(Node*root,int n1,int n2){  // FUNCTION TO SUMMATE THE FINAL ANSWER

    Node* lca=LCA(root,n1,n2);                      // LCA TO GET LOWEST COMMON ANCESTORS FOR N1 AND N2

    int d1=findDist(lca,n1,0);                      // DISTANCE OF LCA FROM N1
    int d2=findDist(lca,n2,0);                      // DISTANCE OF LDA FROM N2

    return d1+d2;                                   // RETURN THE DISTANCE BETWEEN THEM
}

int main(){
    Node *root=new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);

    cout<<distanceBetweenNodes(root,2,3)<<"\n";

    return 0;
}