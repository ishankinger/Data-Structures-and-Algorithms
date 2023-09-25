// PRINTING THE ELEMENTS IN REVERSE LEVEL ORDER
// MEANS FIRST ALL ELEMENTS OF LAST LEVEL WILL BE PRINTED IN ORIGINAL ORDER
// THEN LAST SECOND AND GO ON TILL FIRST LEVEL

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int value;
    Node* left;
    Node* right;
    Node(int data){
        value = data;
        left = right = NULL;
    }
};

vector<Node*> reverseLevelOrder(Node* root){                     // FUNCTION TO REVERSE LEVEL ORDER TRAVERSAL
    vector<Node*> ans;                                           // ANSWER VECTOR
    if(root == NULL) return ans;                                 // IF EMPTY BINARY TREE THEN RETURN EMPTY VECTOR
    
    queue<Node*> q;                                              // QUEUE NECESSARY FOR LEVEL ORDER TRAVERSALS
    q.push(root);                                                // PUSH FIRST ELEMENT AS ROOT OF TREE

    stack<Node*> s;                                              // HERE WE WILL BE USING STACK TO GET REVERSE ORDER

    while(not q.empty()){
        int nodeAtCurrLevel = q.size();                          // SAME PROCEDURE AS FOR LEVEL ORDER TRAVERSALS
        while(nodeAtCurrLevel--){

            Node* currNode = q.front();
            q.pop();

            s.push(currNode);                                   // HERE NOW WE WILL NOT PRINT THE VALUE INSTEAD PUSH THE ELEMENT IN STACK TO REVERSE

            if(currNode->right) q.push(currNode->right);        // ALSO ONE MORE TRICK IS FIRST RIGHT SUB-TREE TO BE PUSHED BACK SO 
            if(currNode->left) q.push(currNode->left);          // WHEN WE ARE PRINTING FROM THE STACK EACH LEVEL'S ELEMENTS ARE PRINTED ORDERWISE
        }
    }
    while(not s.empty()){                                       // PUSH ALL THE ELEMENTS IN THE STACK TO OUR ANSWER VECTOR
        ans.push_back(s.top());
        s.pop();
    }
    return ans;                                                 // AND THUS RETURN ANSWER VECTOR 
}

int main(){
    struct Node* root= new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->right=new Node(5);
    root->left->left=new Node(4);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    root->right->right->left=new Node(8);

    vector<Node*>ans = reverseLevelOrder(root);
    for(auto ele: ans){
        cout<<ele->value<<" ";
    }
    return 0;
}