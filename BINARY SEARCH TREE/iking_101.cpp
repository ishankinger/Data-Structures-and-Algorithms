// BUILDING A BINARY SEARCH TREE

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

void inorder(struct Node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* insertBST(Node*&root, int val){              // RECURSIVE APPROACH TO DO INSERTION IN A BINARY SEARCH TREE
    if(root==NULL) return new Node(val);
    if(val < root->data) root->left = insertBST(root->left,val);
    else root->right = insertBST(root->right,val);
    return root;
}

void insertBST_iter(Node*&root, int val){          // ITERATIVE WAY TO INSERT ELEMENT IN BST IN AVERAGE(LOG(N)) WHILE WORST IS O(N)
    Node* newNode = new Node(val);                 // NODE OF THAT PARTICULAR VALUE IS MADE
    if(root == NULL){                              // IF BST EMPTY THEN ROOT WILL BE NEW NODE
        root = newNode;
        return;
    }

    Node* current = root;                          // CURRENT VARIABLE FOR TRAVERSAL
    while(true){                                   // GOING IN A WHILE LOOP
        if(current->data > val){                   // IF VALUE OF CURR IS GREATER THEN OUR NODE TO BE INSERTED IN LEFT OF IT
            if(current->left == NULL){             // IF THERE IS NO NODE IN LEFT OF CURR NODE THEN NEW NODE WILL BE INSERTED THERE AND RETURN
                current->left = newNode;
                return;
            }  
            current = current->left;               // ELSE MAKE IT'S LEFT AS OUR NEW CURRENT
        }
        else{                                      // SIMILARLY FOR RIGHT SIDE
            if(current->right == NULL){
                current->right = newNode;
                return;
            }
            current = current->right;
        }
    }
}

int main(){
    Node* root=NULL;
    root = insertBST(root,5);
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,4);
    insertBST(root,2);
    insertBST(root,7);

    inorder(root);
    cout<<"\n";

    Node* root2 = NULL;
    insertBST_iter(root2,5);
    insertBST_iter(root2,1);
    insertBST_iter(root2,3);
    insertBST_iter(root2,4);
    insertBST_iter(root2,2);
    insertBST_iter(root2,7);

    inorder(root2);
    
    return 0;
}