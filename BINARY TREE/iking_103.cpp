// BUILD A BINARY TREE FROM GIVEN PREORDER AND INORDER TRAVERSALS

#include<bits/stdc++.h>
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
void inorder(struct Node* root){
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
// TIME COMPLEXITY IS O(N2) ( TRAVERSING IN AN ARRAY AND EACH TIME SEARCHING FOR IT'S POSITION SO TIME COMPLEXITY IS N*N )
// >> PICK ELEMENT FROM PRE ORDER AND CREATE NODE
// >> INCREMENT PRE ORDER INDEX
// >> SEARCH FOR PICKED ELEMENTS IN INORDER TRAVERSAL
// >> CALL TO BUILD SUB-TREE FROM 0 TO POS-1
// >> CALL TO BUILD RIGHT SUB-TREE FOR POS+1 TO N

int search(int inorder[],int start,int end,int curr){                 // FUNCTION TO SEARCH OUR GIVEN ELEMENT IN A PRE-ORDER TRAVERSAL
    for(int i=start;i<=end;i++){                                      // SEARCH OF ELEMENT WILL ONLY BE IN START TO END SUB-ARRAY
        if(inorder[i]==curr) return i;                                // AND POSITION OF THE TARGET ELEMENT WILL BE RETURNED
    }
    return -1;                                                        // ELSE RETURN -1
}

Node* buildTree(int preorder[], int inorder[], int start, int end){    // NOW WE COME TO OUR MAIN FUNCTION
    static int idx=0;                                                  // OUR INDEX WHICH WILL NOT CHANGE IN ALL THE CALLS

    if(start>end) return NULL;                                         // IT MEANS THAT WHOLE ARRAY TRAVERSAL HAS TAKEN PLACE

    int curr = preorder[idx];                                          // STORE CURR ELEMENT AND THEN MOVE INDEX FURTHER
    idx++;

    Node* node = new Node(curr);                                       // MAKE A NODE OF THAT ELEMENT

    if(start==end) return node;                                        // MEANS IT WAS THE LEAF NODE THEN SIMPLY RETURN
    
    int pos = search(inorder,start,end,curr);                          // ELSE GET THE POSITION IN INORDER SEQUENCE
    
    node->left = buildTree(preorder,inorder,start,pos-1);              // MAKE CALL FOR TWO SUB-TREES ONE IS LEFT THAT IS LEFT SUB-ARRAY
    node->right = buildTree(preorder,inorder,pos+1,end);               // OTHER IS RIGHT THAT IS RIGHT SUB-ARRAY
} 




// APPROACH 2 -
// OPTIMAL AND BETTER APPROACH WITH O(N)
// IN THIS EACH TIME WE ARE MAKING TWO NEW PREORDER AND INORDER VECTORS
// THE VECTORS ARE DECIDED BY THE FOUR POINTERS USED AS PRESTART, PREEND, INSTART, INEND
// ALSO TO GET INDEX OF ROOTNODE OF PARTICULAR NODE WE ARE USING MAPS
// AND TO GET NO. OF ELEMENTS IN LEFT SUB-TREE WE ARE USING SIMPLE FORMULA 

// MAIN CONCEPTUAL THING USED IS THAT IN IN-ORDER VECTOR FOR A PARTICULAR ROOT NODE ALL ELEMENT LEFT TO IT WILL LIE IN LST AND RIGHT IN RST
// THEN FROM THAT WE WILL CONSTRUCT INORDER VECTORS FOR LST AND RST
// TO GET PREORDER VECTORS FOR RST AND LST WE WILL BE USING COUNTING METHOD THAT IS WE WILL COUNT ELEMENTS OF LST FROM INORDER
// AND THAT WILL BE USED IN GETTING PREORDER FOR LST AND RST
// THAT IS SO BECAUSE IN PREORDER TRAVERSAL FIRST ROOT NODE IS PRESENT AND THEN SOME NODES OF LST AND THEN SOME NODES OF RST SO WE CAN EASILY 
// TELL RST AND LST BY COUNTING THE NO. OF ELEMENTS AFTER ROOT NODES
// RECURSIVELY WE WILL BREAKING ALL THE SMALL PREORDER AND INORDER FORMED AFTER EVERY CALL
// AT END WHEN LEAF NODE COMES THEN RETURN NULL

Node *buildTreeHelper(vector<int> &preorder,int prestart, int preend, vector<int> &inorder, int instart, int inend, unordered_map<int,int> inmap){
    if(prestart > preend || instart > inend) return NULL;
    
    Node* rootNode = new Node(preorder[prestart]);
    
    int rootInorderIndex = inmap[rootNode->data];             // INDEX OF THE ROOT FROM THE INORDER VECTOR
    int leftSubtreeSize = rootInorderIndex - instart;         // LEFT SUB-TREE NODES WILL BE FROM INSTART TO WHERE THE ROOT ENDS
    
    rootNode->left = buildTreeHelper(preorder, prestart+1, prestart+leftSubtreeSize,inorder,instart,rootInorderIndex-1,inmap);
    rootNode->right = buildTreeHelper(preorder, prestart+leftSubtreeSize+1, preend, inorder, rootInorderIndex+1,inend,inmap);
    
    return rootNode;
}

Node *buildTree2(vector<int>&preorder,vector<int>&inorder){
    unordered_map<int,int> inMap;                                            // MAP TO STORE THE INDEX FOR INORDER TRAVERSALS 
    for(int i=0;i<inorder.size();i++) inMap[inorder[i]] = i; 
    
    return buildTreeHelper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);

}

int main(){
    int preorder[]= {1,2,4,3,5};
    int inoder[]= {4,2,1,5,3};
    Node* tree= buildTree(preorder,inoder,0,4);
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