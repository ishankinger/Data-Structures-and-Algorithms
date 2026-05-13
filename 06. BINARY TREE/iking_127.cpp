// CONVERT THE TREE INTO IT'S MIRROR

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
void preorder(Node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    for(int i=0;i<root->list_children.size();i++){
        preorder(root->list_children[i]);
    }
} 
void mirrorTree(Node* &root){                                         // REVERSING ALL THE VECTORS
    if(root == NULL) return;
    if(root->list_children.size() < 2){
        return;
    }
    reverse(root->list_children.begin(),root->list_children.end());    // SIMPLY FIRST REVERSE THE VECTOR OF CHILD NODES THEN GO FOR IT'S PARENT
    for(int i=0;i<root->list_children.size();i++){                     // USING PREORDER TRAVERSALS
        mirrorTree(root->list_children[i]);
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

    preorder(root);
    cout<<"\n";
    mirrorTree(root);
    cout<<"\n";
    preorder(root);
    return 0;
}