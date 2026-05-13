// FULL TRAVERSAL OF NODES IN A BINARY TREE

// >> COUNT ALL THE NODES IN A BINARY TREE
// >> SUM OF ALL THE NODES IN A BINARY TREE

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
 
int countNodes(Node* root){                                                // TIME COMPLEXITY -> O(N)
    if(root==NULL) return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;           // THIS TYPE OF RECURSION SCENARIO IS USED TO TRAVERSE THE WHOLE TREE
}

int countLeafNodes(Node* root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;                // CONDITION FOR A NODE TO BE A LEAF NODE
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int sumOfAllNodes(Node* root){                                             // ADD DATA WHILE USING THE TWO CALLS OF SUMMATIOIN
    if(root==NULL) return 0;
    return sumOfAllNodes(root->left) + sumOfAllNodes(root->right) + root->data;
}

int main(){
    struct Node* root= new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->right=new Node(5);
    root->left->left=new Node(4);
    root->right->left=new Node(6);
    
    cout<<countNodes(root)<<"\n";
    cout<<countLeafNodes(root)<<"\n";
    cout<<sumOfAllNodes(root)<<"\n";

    return 0;
}