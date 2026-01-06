// TOP VIEW OF A BINARY TREE
// USING LEVEL ORDER TRAVERSAL, CONCEPT OF COLUMNS IN BINARY TREES, MAPS, QUEUES AND VECTORS

#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

class Node{
    public:
        int value;
        Node* left;
        Node* right;
    Node(int v){
        value = v;
        left = right = NULL;
    }
};

vector<int> topViewBinaryTree(Node* root){                          // FUNCTION RETURNING A VECTOR
    vector<int>ans;                                                 // ANS VECTOR IS INITAILISED
    if(root == NULL) return ans;                                    // IF BINARY TREE EMPTY THEN RETURN EMPTY VECTOR
    
    queue<pair<Node*,int>>q;                                        // MAKING A QUEUE IN WHICH A PAIR OF NODE AND IT'S COLUMN WILL BE INSERTED
    q.push(make_pair(root,0));                                      // FIRST ROOT NODE IS INSERTED WITH IT'S COLUMN NUMBER AS 0
    
    map<int,int>m;                                                  // MAP IS ALSO INITIALISED TO CHECK ONLY FOR FIRST OCC OF ELE FOR ANY PARTICLUAR COL

    while(!q.empty()){                                           // NOW TRAVERSING USING LEVEL ORDER TRAVERSAL
        int nodesAtCurrentLevel = q.size();
        while(nodesAtCurrentLevel--){
            pair<Node*, int> p = q.front();                         // VALUE OF FRONT PAIR OF QUEUE IS NOTED AND THEN IT IS POPPED
            Node* currNode = p.first;
            int currColumn = p.second;
            q.pop();

            // TO GET TOP ELEMENT OF THE COLUMN
            if(m.find(currColumn)==m.end()){                        // IF NOT FIND THEN RETURN M.END() WHICH INDIRECTLY MEANS FOR THIS COL NO. IT IS THE FIRST VALUE TO BE INTIALISED
                m[currColumn] = currNode->value;                    // HENCE WE WILL ASSIGN IT A VALUE
            }                                                       // AFTER THIS IT'S VALUE CAN'T BE ALTERED
            
            if(currNode->left){                                     // PUSHING THE LEFT AND RIGHT NODE OF OUR CURRENT NODE
                q.push(make_pair(currNode->left,currColumn-1));     // IT'S COLUMN WILL BE -1
            }
            if(currNode->right){
                q.push(make_pair(currNode->right, currColumn+1));   // IT'S COLUMN WILL BE +1
            }
        }
    }
    for(auto it: m){                                                // MAP STORES IN ORDER WAY OF KEYS SO FROM LEFT TO RIGHT PRINTING OCCUR CORRECTLY
        ans.push_back(it.second);
    }
    return ans;
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

    vector<int>ans = topViewBinaryTree(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}

// FOR BOTTOM VIEW JUST IN PLACE OF IF - ELSE STATEMENT OF MAP USE SIMPLE MAP ASSIGNMENT
// AS FROM THAT LAST DECLARED VALUE WILL BE ASSIGNED TO THAT COLUMN WHICH WILL LAST VALUE