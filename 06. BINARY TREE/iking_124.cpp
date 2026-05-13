// POST ORDER TRAVERSAL

//     (A)             // 'E' PRINTED THEN 'F' THEN 'B'    
//   /  |  \           // 'C' WILL BE PRINTED 
//  (B) (C) (D)        // 'G' WILL BE PRINTED THEN 'D'
//  /  \     |         // THEN AT END 'A' WILL BE PRINTED
// (E)  (F) (G)        

// ==> [E,F,B,C,G,D,A]

// RECURSIVELY VISIT ALL CHILD NODES 
// THEN WE WILL PRINT ALL CHILD VALUES
// THEN THE PARENT NODE VALUE

#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int data;
    vector<Node*> list_children;
    Node(int val){
        data = val;
    }
};

void postorder(Node*root){
    if(root == NULL) return;
    for(int i=0;i<root->list_children.size();i++){
        postorder(root->list_children[i]);
    }
    cout<<root->data<<" ";
}

int main(){
    Node* root = new Node(1);
    root->list_children.push_back(new Node(2));
    root->list_children.push_back(new Node(3));
    root->list_children.push_back(new Node(6));
    root->list_children[1]->list_children.push_back(new Node(4));
    root->list_children[1]->list_children.push_back(new Node(5));
    root->list_children[2]->list_children.push_back(new Node(9));

    postorder(root);

    return 0;
}