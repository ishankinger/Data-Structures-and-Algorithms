// LEVEL ORDER TRAVERSAL ( BREATH FIRST TRAVERSAL )

// MEANS ALL ELEMENTS WILL BE PRINTED LEVEL WISE
// WE WILL BE USING QUEUE TO DO THIS
// WE WILL BE PUSHING ROOT AND THEN IT'S BOTH CHILD AND PRINTING THE ROOT AND THEN SAME FOR IT'S CHILD TAKING THEM AS INDEPENDENT ROOT

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

void printLevelOrder(Node* root){                   // FUNCTION TO PRINT LEVEL ORDER
    if(root==NULL) return;
    queue<Node*>q;                                  // WE WILL MAKE QUEUE FOR THIS
    q.push(root);                                   // FIRST ROOT WILL BE INSERTED
    q.push(NULL);                                   // AND THEN TO JUMP TO NEXT LEVEL A MARK AS NULL WILL BE INSERTED
    while(!q.empty()){                              // TILL THE QUEUE IS NOT EMPTY    
        Node* node = q.front();                     // STORING0 THE NODE AND
        q.pop();                                    // THEN POPPING IT
        if(node != NULL){                           // IF NODE IS NOT EQUAL TO NULL THEN PRINT IT
            cout<<node->data<<" ";
            if(node->left) q.push(node->left);      // AND IT'S LEFT AND RIGHT NODE WILL BE PUSHED BACK
            if(node->right) q.push(node->right);
        }
        else if(!q.empty()){                        // IF QUEUE IS NOT EMPTY AND NOT EQUAL TO NULL THEN ADD NULL TO IT                
            q.push(NULL);
        }
    }
}

void printLevelOrder2(Node* root){                  // FUNCTION WITHOUT ADDING THE NULL NODE AFTER EACH LEVEL END
    if(root == NULL) return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int sizeOfLevel = q.size();                 // SIMPLY DEFINE SIZE OF EVERY LEVEL AND STORE IT AND GO IN LOOP FOR ALL ELEMENTS IN THAT LEVEL
        while(sizeOfLevel--){
            Node* currNode = q.front();
            q.pop();
            cout<<currNode->data<<" ";
            if(currNode->left) q.push(currNode->left);
            if(currNode->right) q.push(currNode->right);
        }
        cout<<"\n";
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

    printLevelOrder(root);
    cout<<"\n";
    printLevelOrder2(root);

    return 0;
}