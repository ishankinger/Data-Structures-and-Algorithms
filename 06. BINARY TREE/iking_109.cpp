// GET SUM OF NODES AT Kth LEVEL

#include<iostream>
#include<queue>
using namespace std;

struct Node{
    public:
    int data;
    Node* left, *right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

int getSumKthLevel(Node* root,int l){                        // MAIN CONCEPT USED IS OF LEVEL ORDER TRAVERSALS
    if(l==0){
        return root->data;
    }
    if(root==NULL) return -1;
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    int count=0;                                              // MAKE COUNT AND SUM VARIABLE
    int sum=0;
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        if(node != NULL){
            if(count==l-1){                                  // IF WE ARE AT OUR (REQUIRED LEVEL-1) THEN ADD IT'S CHILD TO SUM
                if(node->left) sum+=node->left->data;
                if(node->right) sum+=node->right->data;
            }
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }else if(!q.empty()){                               // ELSE WE MOVE TO NEW LEVEL
            q.push(NULL);                                   // LEVEL COUNT ++ THEN IF WE REACH OUR LEVEL THEN RETURN THE SUM OF THAT LEVEL
            count++;
            if(count==l) return sum;
        }
    }
}

int main(){
    struct Node* root= new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->right=new Node(5);
    root->left->left=new Node(4);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    cout<<getSumKthLevel(root,2);

    return 0;
}