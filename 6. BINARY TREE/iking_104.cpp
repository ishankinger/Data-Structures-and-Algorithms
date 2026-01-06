// BUILD TREE FROM POSTORDER AND INORDER

#include<iostream>
#include<unordered_map>
#include<vector>
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
void inorder(struct Node* root){            // JUST ORDERING IS CHANGED OTHERWISE CONCEPT IS SAME
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postoder(struct Node* root){
    if(root==NULL) return;
    postoder(root->left);
    postoder(root->right);
    cout<<root->data<<" ";
}

// APPROACH 1 -
// TIME COMPLEXITY IS O(N2)
// >> START FROM END OF POSTORDER AND PICK ELEMENT TO CREATE A NODE
// >> DECREMENT POST ORDER INDEX BY ONE
// >> SEARCH FOR PICKED ELEMENT POS IN INORDER
// >> CALL TO BUILD RIGHT SUB-TREE FROM INORDER POS+1 TO N
// >> CALL TO BUILD LEFT SUB-TREE FORM INORDER 0 TO POS-1

int search(int inorder[],int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(inorder[i]==curr) return i;
    }
    return -1;
}

Node* buildTree(int postorder[],int inorder[],int start,int end){    // IT'S JUST THE REVERSE OF THE LAST ONE
    static int idx=4;                                                // HERE IND WILL START FROM BACK TRAVERSE REVERSE

    if(start>end) return NULL;

    int val=postorder[idx];
    idx--;

    Node* curr= new Node(val);
    if(start==end) return curr;
    int pos= search(inorder,start,end,val);

    curr->right= buildTree(postorder,inorder,pos+1,end);              // FIRST RST WILL BE CALLED
    curr->left= buildTree(postorder,inorder,start,pos-1);             // THEN LST WILL BE CALLED
}



// OPTIMAL AND BETTER APPROACH WITH O(N)
// THE CONCEPT USED HERE IS SAME AS THAT OF IN PREVIOUS QUESTION ONLY THING IS TO CLEARLY CALCULATE NO. OF LST ELEMENTS AND INDEX
// ALSO POST ORDER IS HAVING ROOT AT LAST THEN FROM BACK FIRST RIGHT NODES AND THEN LEFT NODES AT FIRST ARE PRESENT 

Node* buildTreeHelper(vector<int>postorder, int poststart, int postend, vector<int>inorder, int instart, int inend, unordered_map<int,int>inMap){
    if(poststart > postend || instart > inend) return NULL;

    Node* rootNode = new Node(postorder[postend]);

    int rootInorderIndex = inMap[rootNode->data];
    int rightSubtreeSize = inend - rootInorderIndex;
    
    rootNode->right = buildTreeHelper(postorder, postend-rightSubtreeSize, postend-1, inorder, rootInorderIndex+1, inend, inMap);
    rootNode->left = buildTreeHelper(postorder, poststart, postend-rightSubtreeSize-1, inorder, instart, rootInorderIndex-1,inMap);

    return rootNode;
}

Node* buildTree2(vector<int>&postorder, vector<int>&inorder){
    unordered_map<int,int> inMap;
    for(int i=0;i<inorder.size();i++) inMap[inorder[i]] = i;

    return buildTreeHelper(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, inMap);
}

int main(){
    int postorder[]= {1,2,4,3,5};
    int inoder[]= {4,2,1,5,3};
    Node* tree= buildTree(postorder,inoder,0,4);
    inorder(tree);
    cout<<"\n";
    postoder(tree);
    cout<<"\n";
    vector<int>v1 = {1,2,4,3,5};
    vector<int>v2 = {4,2,1,5,3};
    Node *tree2 = buildTree2(v1,v2);
    inorder(tree2);
    cout<<"\n";
    postoder(tree2);

    return 0;
}