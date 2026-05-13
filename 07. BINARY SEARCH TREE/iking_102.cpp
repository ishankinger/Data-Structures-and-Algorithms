// SEARCH IN A BINARY SEARCH TREE

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

Node* searchInBST(Node* root, int key){                           // SEARCH ALSO OCCUR IN AVG(LOG(N)) AND O(N) FOR WORST 
    if(root->data==key) return root;
    else if(root->data>key) return searchInBST(root->left,key);
    else return searchInBST(root->right,key);
    return NULL;
}

Node* searchInBST_iter(Node* root, int key){
    Node* curr = root;
    while(true){
        if(curr->data > key){
            curr = curr->left;
        }
        else if(curr->data < key){
            curr = curr->right;
        }
        else{
            return curr;
        }
    }
    return NULL;
}

int main(){
    
    Node* root=NULL;
    root=insertBST(root,5);
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,4);
    insertBST(root,2);
    insertBST(root,7);

    cout<<searchInBST(root,2)->data<<"\n";
    cout<<searchInBST_iter(root,2)->data;

    return 0;
}