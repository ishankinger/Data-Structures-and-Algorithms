// GIVEN A GENERIC TREE AND INTEGER X
// FIND AND RETURN THE NODE WITH NEXT LARGER ELEMENT IN THE TREE
// THAT IS FIND A NODE JUST GREATER THAN X
// IF NO NODE THEN RETURN NULL

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

void preorder(Node* root){
    if(root == NULL) return;
    cout<<root->val<<" ";
    for(int i=0;i<root->list_children.size();i++){
        preorder(root->list_children[i]);
    }
}

void getNSG(Node* root, int x, Node* &ans){                       // HERE WE WILL BE DOING PREORDER TRAVERSAL
    if(root == NULL) return;
    if(root->val > x && (root->val < ans->val || ans == NULL)){  // CHECKING CONDTION FOR SMALLER ELEMENT THAN ANS BUT GREATER THAN X
        ans=root;
    }
    for(Node* child : root->list_children){
        getNSG(child,x,ans);
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

    int x = 5;
    Node *ans = new Node(INT_MAX);
    preorder(root);
    cout<<"\n";
    getNSG(root,x,ans);

    if(ans != NULL) cout<<ans->val<<"\n";
    else cout<<"No Node exist\n";

    return 0;
}