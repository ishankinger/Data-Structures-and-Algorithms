// SERIALISE A GENERIC TREE
// SERIALISATION IS THE PROCESS OF CONVERTING AN OBJECT INTO A FORMAT THAT CAN BE STORED OR TRANSMITTED
// SERIALISATION IS TO STORE TREE IN A FILE SO THAT IT CAN BE LATER RESTORED
    
//      GENERIC TREE       SERIALIZATION
//         (A)             A: 3: B,C,D
//       /  |  \           B: 0:
//     (B) (C) (D)         C: 3: E,F,G
//        / |  \           E: 0:
//     (E) (F) (G)         F: 2: H,I
//          / \            H: 0:
//         (H) (I)         I: 0:
//                         G: 0:
//                         D: 0:

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    vector<Node*>list_children;
    Node(int val){
        data = val;
    }
};

void preorder(Node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    for(int i=0;i<root->list_children.size();i++){
        preorder(root->list_children[i]);
    }
}

void serialiseGenericTree(Node* root){
    if(root == NULL) return;
    cout<<root->data<<": "<<root->list_children.size()<<": ";
    for(int i=0;i<root->list_children.size();i++) cout<<root->list_children[i]->data<<", ";
    cout<<"\n";
    for(int i=0;i<root->list_children.size();i++){
        serialiseGenericTree(root->list_children[i]);
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
    
    serialiseGenericTree(root);
    preorder(root);

    return 0;
}