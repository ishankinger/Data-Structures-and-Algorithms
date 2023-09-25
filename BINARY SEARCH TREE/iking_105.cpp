// MAKING OF BINARY SEARCH TREE FROM A SORTED ARRAY
// AND IT SHOULD BE BALANCED TREE ALSO MEANS HEIGHT DIFFERENCE BETWEEN RSH AND LSH IS 1,0,-1

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

Node* insertBST(Node* root, int val){
    if(root==NULL) return new Node(val);
    if(val<root->data) root->left = insertBST(root->left,val);
    else root->right = insertBST(root->right,val);
    return root;
}

void inorder(struct Node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* sortedArrToBST(int arr[], int start, int end){     
    if(start>end) return NULL;                                // IF START POINTER CROSSES END MEANS WHOLE ARRAY IS TRAVESED SO BREAK
    
    int mid = (start+end)/2;                                  // MID VARIABLE IS DEFINED
    Node* root = new Node(arr[mid]);                          // A NODE OF THAT MID VALUE IS MADE

    root->left = sortedArrToBST(arr,start,mid-1);             // NOW FOR THAT NODE LEFT IS DEFINED ON LEFT OF SPACE OF THAT NODE
    root->right = sortedArrToBST(arr,mid+1,end);              // SIMILARLY FOR RIGHT AS THAT WE DO IN BINARY SEARCH ALGO

    return root;                                              // AND THEN WE WILL MAKE THAT ROOT TO PALCE IN POSITION OF BINARY TREE
}

int main(){
    int arr[]={10,20,30,40,50};
    Node* root=sortedArrToBST(arr,0,4);
    inorder(root);
    return 0;
}