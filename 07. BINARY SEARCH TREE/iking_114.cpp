// GIVEN AN ARRAY OF INTEGERS, REPLACE EVERY ELEMENT WITH THE LEAST GREATER ELEMENT ON IT'S RIGHT SIDE IN THE ARRAY.
// IF THERE ARE NO GREATER ELEMENTS ON THE RIGHT SIDE, REPLACE IT WITH -1

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *right, *left;
    Node(int val){
        data = val;
        right = left = NULL;
    }
};
Node* insertNode(Node* root, int element, int &successor){
    if(root == NULL){
        return new Node(element);
    }
    
    if(element < root->data){
        successor = root->data;
        root->left = insertNode(root->left, element, successor);
    }
    else if(element > root->data){
        root->right = insertNode(root->right, element, successor);
    }

    return root;
}
void replaceWithLeastGreaterElement(vector<int> &v){
    Node *root = NULL;
    for(int i=v.size()-1;i>=0;i--){
        int successor = -1;
        insertNode(root,v[i],successor);
        v[i] = successor;
    }
}

int main(){
    int n; cin>>n;
    vector<int> v(n);
    for(auto &ele:v) cin>>ele;
    for(int i=0;i<n;i++) cout<<v[i]<<" ";
    cout<<"\n";
    replaceWithLeastGreaterElement(v);
    for(int i=0;i<n;i++) cout<<v[i]<<" ";
    return 0;
}