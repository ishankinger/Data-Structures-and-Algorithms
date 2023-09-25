// PREORDER TRAVERSAL

//      (A)            'A' WILL BE PRINTED
//    /  |  \          'B' WILL BE PRINTED FROM L->R
//  (B) (C) (D)        'E' WILL BE PRINTED
//  /  \     |         'F' AS E DONOT HAVE ANY CHILD THEN 
// (E)  (F) (G)        'C' THEN 'D' AND THEN 'G'

// ==> [A,B,E,F,C,D,G]

// FIRST ROOT WILL BE PRINTED
// THEN WE WILL MOVE FROM LEFT TO RIGHT
// EACH TIME WHILE GOING FROM LEFT TO RIGHT WE WILL PRINT FIRST L -> R OF THAT PARTICULAR NODE
// THEN AGAIN THIS WILL BE GOING ON

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    vector<Node*> list_children;
    Node(int data){
        val = data;
    }
};

void preorder(Node* root){
    if(root == NULL) return;
    cout<<root->val<<" ";
    for(int i=0;i<root->list_children.size();i++){
        preorder(root->list_children[i]);
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

    return 0;
}