// FLATTEN A BINARY TREE
// FLATTEN A BINARY TREE INTO A LINKED LIST
// AFTER FLATTERING LEFT OF EACH NODE SHOULD POINT TO NULL AND RIGHT NODE SHOULD CONTAIN NEXT NODE IN PREORDER SEQUENCE

//     (1)               (1)
//    /   \                \ 
//  (2)    (3)    ===>      (2)
//         /                  \ 
//        (4)                  (3)
//                               \ 
//                                (4)

//    (1)              SO FOR THIS SMALL SUBTREE WE WILL MAKE LAST AS 3 FOR NOW AND OUR NODE WILL BE TWO
//    /  \             ROOT->RIGHT = LAST AND ROOT->LEFT = NULL
//   (2)  (3)          LAST = ROOT THEN WE CAN DO THIS EASILY    

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
void inorder(struct Node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(struct Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

Node* lastNode = NULL;
void flatten(Node* root){
    if(root == NULL) return;

    flatten(root->right);
    flatten(root->left);

    root->right = lastNode;
    root->left = NULL;

    lastNode = root;
    
    return;
}

int main(){
Node *root=new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->right = new Node(4);
    root->left->left = new Node(3);
    root->right->right = new Node(6);
    
    inorder(root);
    cout<<"\n";
    preorder(root);
    cout<<"\n";

    flatten(root);

    inorder(root);
    cout<<"\n";
    preorder(root);
    cout<<"\n";

    return 0;
}