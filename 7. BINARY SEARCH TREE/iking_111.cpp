// BETTER SOLUTION FOR THE LAST QUESTION
// WE WILL MAKE UPPERBOUND FOR EACH ELEMENT 
// IF IT IS OUT OF UPPERBOUND THEN RETURN NULL MEANS WE HAVE REACHED THE LEAF NODE

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *right, *left;
    Node(int val){
        data = val;
        left = right = NULL;
    }
}; 
void inorder(Node *root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* BSTFromPreorderHelper(vector<int> &preorder,int &index, int upperbound){
    if(index >= preorder.size()){
        return NULL;
    }

    if(preorder[index] >= upperbound){
        return NULL;
    }

    Node *root = new Node(preorder[index]);
    index++;

    root->left = BSTFromPreorderHelper(preorder,index,root->data);
    root->right = BSTFromPreorderHelper(preorder,index,upperbound);
}

Node* BSTFromPreorder(vector<int> &preorder){
    int index = 0;
    return BSTFromPreorderHelper(preorder,index,INT_MAX);

}

int main(){
    int n; cin>>n;
    vector<int> preorder(n);
    for(int i=0;i<n;i++) cin>>preorder[i];

    Node* root = BSTFromPreorder(preorder);
    inorder(root);

    return 0;
}