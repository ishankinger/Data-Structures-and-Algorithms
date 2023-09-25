// LEVEL ORDER TRAVERSAL 

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    vector<Node*> list_children;
    Node(int val){
        data = val;
    }
};

void levelOrder(Node *root){
    queue<Node*> q;
    q.push(root);

    while(not q.empty()){
        int currNodeNum = q.size();
        while(currNodeNum--){
            Node* currNode = q.front();
            q.pop();
            cout<<currNode->data<<" ";
            for(int i=0;i<currNode->list_children.size();i++){
                q.push(currNode->list_children[i]);
            }
        }
        cout<<"\n";
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

    levelOrder(root);
    return 0;
}