// INORDER PREDECESSOR AND SUCCESSOR FOR A GIVEN KEY IN BST
// INORDER PREDESESSOR => GREATEST VALUE SMALLER THAN KEY 
//                     => PRESENT IN THE LST OF THE NODE AND WILL LIE AT THE MOST RIGHT OF THE LST
// INORDER SUCCESSOR => SMALLEST VALUE GREATER THAN THE KEY
//                   => PRESENT IN THE RST OF THE NODE AND WILL LIE AT THE  MOST LEFT OF THE RST

// OTHER SIMPLER WAY TO DO THIS IS TO STORE THE INORDER VECTOR AND THEN PRINT IT'S NEIGHBOURS

#include<bits/stdc++.h>
using namespace std;

struct Node{
    public:
    int val;
    Node *right, *left;
    Node(int data){
        val = data;
        left = right = NULL;
    }
};
void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

void inorderPreSuccBST(Node* &root, Node* &pre, Node* &succ, int key){
    if(root == NULL) return;

    if(root->val == key){                                // ROOT VALUE IS EQUAL TO KEY
        if(root->left != NULL){                          // IF LEFT SUB-TREE IS NOT NULL
            Node *temp = root->left;                     // THEN WE WILL GO TO THE RIGHTMOST ELEMENT TO GET PREDECESSOR
            while(temp->right != NULL){
                temp = temp->right;
            }
            pre = temp;
        }
        if(root->right != NULL){                         // IF RIGHT SUB-TREE IS NOT NULL
            Node *temp = root->right;                    // WE WILL MOVE TO LEFTMOST ELEMENT TO GET SUCCESSOR
            while(temp->left != NULL){
                temp = temp->left;
            }
            succ = temp;
        }
    }
    if(root->val > key){                                 // IF VALUE GREATER THAN WE HAVE TO GO TO LST
        succ = root;                                     // BUT THERE CAN BE A POSSIBILITY THAT THIS IS SUCC AS AFTER THAT ALL ELEMENTS IN LST 
        inorderPreSuccBST(root->left,pre,succ,key);      // CAN BE SMALLER THAN IT
    }
    else if(root->val < key){                            // IF VALUE LESS THAN THE KEY THEN WE WILL GO TO RST
        pre = root;                                      // BUT IT COULD BE THE PRE
        inorderPreSuccBST(root->right,pre,succ,key);
    }
}

int main(){
    Node *root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->left->right->left = new Node(2);
    
    int key = 3;
    Node *pre, *succ;
    inorderPreSuccBST(root,pre,succ,key);
    inorder(root);
    cout<<"\n"<<pre->val<<" "<<succ->val<<"\n";

    return 0;
}