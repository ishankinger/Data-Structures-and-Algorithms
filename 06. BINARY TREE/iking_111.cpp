// RIGHT VIEW OF A BINARY TREE
// PRINT ALL THE NODES COMING FIRST AT EACH LEVEL WHILE SEEING FROM RIGHT TO LEFT

#include<iostream>
#include<queue>
using namespace std;

struct Node{                                // BINARY TREE'S NODE STORE ONE VALUE AND HAVE TWO POINTERS POINTING TO IT'S TWO CHILDREN
    int data;
    struct Node*left;                       // FOR LEFT SUB-TREE
    struct Node*right;                      // FOR RIGHT SUB-TREE

    Node(int val){                          // CONSTRUCTOR INITIALISING LEFT AND RIGHT POINTERS BY NULL
        data=val;
        left=NULL;
        right=NULL;
    }
};

void rightView(struct Node*root){
    if(root==NULL) return;

    queue<Node*>q;                                    // AS DONE IN LEVEL ORDER TRAVERSAL WE WILL MAKE A QUEUE
    q.push(root);                                     // PUSH BACK THE MAIN ROOT

    while(!q.empty()){
        int n=q.size();                               // FIRST MARK THE SIZE AND THEN GO IN LOOP FOR ONLY THAT PARTICULAR LEVEL ELEMENTS
        for(int i=0;i<n;i++){
            Node* curr=q.front();                     // ROOT VALUE WILL BE STORED AT LEVEL L
            q.pop();                                  // THEN POP IT OUT AT LEVEL L
            if(i==n-1) cout<<curr->data<<" ";         // IF IT IS THE LAST NODE AT THAT LEVEL L THEN COUT IT'S DATA
            if(curr->left) q.push(curr->left);        // AND ALSO PUSH BACK IT'S RIGHT AND LEFT NODE
            if(curr->right) q.push(curr->right);
        }
    }
}

// ***FOR LEFT VIEW I==0 THEN COUT AND ALL THINGS SAME

int main(){
    struct Node* root= new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->right=new Node(5);
    root->left->left=new Node(4);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    root->right->right->left=new Node(8);

    rightView(root);

    return 0;
}