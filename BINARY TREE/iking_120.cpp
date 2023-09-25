// TIME TAKEN TO COMPLETELY INFECT ALL THE NODES OF THE TREE
//

#include<bits/stdc++.h>
using namespace std;

struct Node{
    public:
    int data;
    Node*right,*left;
    Node(int val){
        data = val;
        right = left = NULL;
    }
};

int calculateTime(Node* startNode, unordered_map<Node*, Node*>&parent){
    unordered_set<Node*>infected;
    queue<Node*>q;
    q.push(startNode);
    infected.insert(startNode);
    int time = 0;

    while(not q.empty()){
        int currLevelNodes = q.size();
        bool infectFlag = false;
        while(currLevelNodes--){
            Node* currNode = q.front();
            q.pop();
            if(currNode->left && infected.count(currNode->left)){
                q.push(currNode->left);
                infected.insert(currNode->left);
                infectFlag = true;
            }
            if(currNode->right && infected.count(currNode->right)){
                q.push(currNode->right);
                infected.insert(currNode->right);
                infectFlag = true;
            }
            if(parent[currNode] && !infected.count(parent[currNode])){
                q.push(parent[currNode]);
                infected.insert(parent[currNode]);
                infectFlag = true;
            }
            if(infectFlag) time++;
        }
    }
    return time;
}

Node* makeParent(Node*root,unordered_map<Node*,Node*>&parent,int start){
    queue<Node*>q;
    q.push(root);
    Node* startNode;
    while(not q.empty()){
        Node* currNode = q.front();
        q.pop();
        if(currNode->data == start){
            startNode = currNode;
        }
        if(currNode->left){
            parent[currNode->left]=currNode;
            q.push(currNode->left);
        }
        if(currNode->right){
            parent[currNode->right]=currNode;
            q.push(currNode->right);
        }
    }
    return startNode;
}

int amountOfTime(Node*root, int start){
    unordered_map<Node*,Node*>parent;
    Node*startNode = makeParent(root,parent,start);
    return calculateTime(startNode, parent);
}

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(5);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(10);
    root->right->right = new Node(6);
    root->left->right->left = new Node(9);
    root->left->right->right = new Node(2);

    cout<<amountOfTime(root,3);
    return 0;
}