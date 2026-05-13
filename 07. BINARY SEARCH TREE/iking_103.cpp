// DELETION IN A BINARY SEARCH TREE
// AFTER DELETION OUR TREE SHOULD INTACT WITH BINARY SEARCH TREE PROPERTIES
// FOR DELETION IN A BINARY SEARCH TREE THREE CASES WILL ARISE 
// >>> NODE TO BE DELETED HAVING NO CHILD
// >>> NODE TO BE DELETED HAVING ONE CHILD
// >>> NODE TO BE DELETED HAVING TWO CHILDS

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

void inorder(struct Node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* largestNodeBST(Node*root){             // FOR A GIVEN NODE IT WILL GET THE JUST SMALLER VALUE THEN IT
    Node*curr = root;
    while(curr && curr->right){              // SO WE WILL MAKE TRAVERSAL ONLY TO THE RIGHT OF THE CURR NODE AS POSSIBLY OUR REQUIRED NODE 
        curr = curr->right;                  // WILL BE IN THAT PART OF THE TREE
    }
    return curr;
}

Node* deleteInBST(Node* root, int key){                           // FUNCTION TO DELETE NODE HAVING VALUE = KEY 
    if(root == NULL) return root;                                 // IF WE GET AT LEAF NODE THEN IT'S CHILD WILL BE NULL

    if(key < root->data){                                         // FIRST WE WILL SEARCH FOR THE KEY NODE
        root->left = deleteInBST(root->left,key);                 // IF VALUE LESS THEN IT WILL GO TO LEFT SIDE
    }
    else if(key > root->data){                                    // IF MORE VALUE THEN RIGHT SIDE
        root->right = deleteInBST(root->right,key);
    }
    else{                                                         // IF EQUAL THEN FIRST WE WILL CHECK THE THREE CASES

        if(root->left == NULL && root->right == NULL){            // CASE 1: HAVING ZERO CHILD
            free(root);                                           // SIMPLY DELETE THE ROOT
            return NULL;                                          // THEN IN PLACE OF THAT ROOT RETURN NULL TO BE ATTACHED IN THE BINARY SEARCH TREE
        }

        else if(root->left == NULL){                              // CASE 2: HAVING ONE CHILD
            Node *temp = root->right;                             // STORE THE NODE TO BE RETURNED
            free(root);                                           // DELETE THE NODE TO BE DELETED
            return temp;                                          // THEN IN PLACE
        }

        else if(root->right == NULL){                             // SIMILARLY THE OTHER SUB-CAE OF CASE 2
            Node* temp = root->left;
            free(root);
            return temp;
        }

        else{                                                      // CASE 3: WHEN TWO CHILD NODES ARE PRESENT
            Node* justSmallerNode = largestNodeBST(root->left);    // WE WILL CHECK THE JUST SMALLER NODE IN LEFT SUB-TREE OF OUR KEY NODE
            root->data = justSmallerNode->data;                    // IT'S DATA IS REPLACE AND THE LEFT OF THE ROOT IS DELETED
            root->left = deleteInBST(root->left, justSmallerNode->data);  // POSSIBLY IT WILL HAVE 0 OR 1 CHILD ONLY
        }
    }
    return root;
}

int main(){
    Node* root=NULL;
    root=insertBST(root,5);
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,4);
    insertBST(root,2);
    insertBST(root,7);

    inorder(root);
    cout<<"\n";
    deleteInBST(root,4);
    inorder(root);

    return 0;
}