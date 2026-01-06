// INORDER TRAVERSAL

//     (A)             
//   /  |  \           'B' WILL BE PRINTED FROM L->R THEN 'C' WILL BE PRINTED
//  (B) (C) (D)         BUT 'D' WILL NOT BE PRINTED
//  /  \     |         'E' PRINTED THEN 'B' TO BE PRINTED AS ROOT NODE AND THEN 'F' AS LAST NODE FOR B'S SUB-TREE
// (E)  (F) (G)        'D' PRINTED AND THEN 'G' WILL BE PRINTED

// ==> [E,B,F,C,A,D,G]

// RECURSIVELY VISIT ALL CHILD NODES EXCEPT LAST CHILD NODE
// PRINT ROOT NODE
// RECURDIVELY VISIT LAST CHILD NODE

#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int val;
    vector<Node*> list_children;
    Node(int data){
        val = data;
    }
};

void inorder(Node* root){
    if(root == NULL) return;
    int childNodes = root->list_children.size();
    for(int i=0;i<childNodes-1;i++){
        inorder(root->list_children[i]);
    }
    cout<<root->val<<" ";
    if(childNodes>0){
        inorder(root->list_children[childNodes-1]);
    }
}

int main(){
    Node* root = new Node(1);
    root->list_children.push_back(new Node(2));
    root->list_children.push_back(new Node(3));
    root->list_children.push_back(new Node(6));
    root->list_children[1]->list_children.push_back(new Node(4));
    root->list_children[1]->list_children.push_back(new Node(5));
    root->list_children[2]->list_children.push_back(new Node(9));

    inorder(root);

    return 0;
}