// GENERIC TREES
// EVERY NODE HAS DATA AND LIST OF REFERECES TO IT'S CHILDREN NODES
// ANY NO. OF CHILDREN NODES INSTEAD OF BINARY TREES HAVING ONLY TWO NODES

//        (1)
//      /  |  \    
//    (2) (3) (6)
//        / \    \ 
//       (4) (5)  (9)

#include<iostream>
#include<vector>
using namespace std;

struct Node{
    public:
    int val;
    vector<Node*> list_children;

    Node(int data){
        val = data;
    }
};

int main(){
    Node* root = new Node(1);
    root->list_children.push_back(new Node(2));
    root->list_children.push_back(new Node(3));
    root->list_children.push_back(new Node(6));
    root->list_children[1]->list_children.push_back(new Node(4));
    root->list_children[1]->list_children.push_back(new Node(5));
    root->list_children[2]->list_children.push_back(new Node(9));

    cout<<root->val<<"\n";
    for(Node* child : root->list_children){
        cout<<child->val<<" ";
    }
    cout<<"\n";
    for(Node* child : root->list_children[1]->list_children){
        cout<<child->val<<" ";
    }
    cout<<"\n";
    for(Node* child : root->list_children[2]->list_children){
        cout<<child->val<<" ";
    }
    cout<<"\n";

    return 0;
}