// LOWEST COMMON ANCESTOR OF BST
// LCA => SHARED ANCESTOR FARTHEST FROM THE ROOT NODE
// ALSO EVERY NODE HAVE ANCESTORS INCLUDING ITSELF
//          (8)                 HERE, ANCESTORS OF 4 => 4,6,3,8           
//         /   \                      ANCESTORS OF 3 => 3,8
//       (3)   (10)             COMMON ANCESTORS BETWEEN 4 AND 3 ARE 3,8
//      /  \      \             LOWEST COMMON ANCESTORS BETWEEN 4 AND 3 IS 3
//     (1)  (6)    (14)         
//          /  \                SIMILARLY LCA FOR 14 AND 6 IS 8
//         (4)  (7)             LCA FOR 7 AND 1 IS 3

// LCA FOR ANY TWO NUMBERS WILL LIE BETWEEN VALUES OF THE TWO NUMBERS IN A BST

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node*right, *left;
    Node(int value){
        val = value;
        right = left = NULL;
    }
};

Node* lca(Node* root, Node* node1, Node* node2){                    // FUNCTION TO GET LOWEST COMMON ANCESTOR OF THE NODES GIVEN
    if(root == NULL){                                               // BASE CASE THAT IS IF WE REACH NULL THEN RETURN NULL
        return NULL;
    }

    if(root->val > node1->val && root->val > node2->val){           // THIS IS WHEN BOTH NODE VALUES ARE LESS THAN ROOT NODE
        return lca(root->left,node1,node2);                         // THEN WE WILL GO TO LEFT SUB-TREE
    }
    if(root->val < node1->val && root->val < node2->val){           // THIS IS WHEN BOTH NODE VALUES ARE GREATER THAN ROOT NODE
        return lca(root->right,node1,node2);                        // THEN WE WILL GO TO RIGHT SUB-TREE
    }
    return root;                                                    // ELSE IF ROOT LIES BETWEEN THE VALUE OR MAY BE EQUAL TO ONE OF THEM THEN RETURN

}
int main(){
    Node *root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node (14);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);

    cout<<lca(root,root->left,root->left->right->left)->val<<"\n";
    cout<<lca(root,root->right->right,root->left->right)->val<<"\n";
    cout<<lca(root,root->left->right->right,root->left->left)->val<<"\n";
    cout<<lca(root,root->left->right->left,root->left->right->right)->val<<"\n";

    return 0;
}