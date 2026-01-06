// BUILD A TREE FROM POST-ORDER AND PRE-ORDER
// THERE CAN BE POSSIBILITY OF MORE THAN ONE SOLUTIONS
// WE CAN PRINT ANY OF THEM

// FOR A COMPLETE BINARY TREE THAT IS EACH NODE HAVING EITHER ZERO OR TWO CHILDREN WILL GIVE A UNIQUE BINARY TREE

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

struct Node{
    public:
    int value;
    Node *right, *left;
    Node(int val){
        value = val;
        right = left = NULL;
    }
};
void postoder(struct Node* root){
    if(root==NULL) return;
    postoder(root->left);
    postoder(root->right);
    cout<<root->value<<" ";
}
void preoder(struct Node* root){           
    if(root==NULL) return;
    cout<<root->value<<" ";                  
    preoder(root->left);                   
    preoder(root->right);                 
}
void inorder(struct Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->value<<" ";
    inorder(root->right);
}

// IN THIS SIMILARLY WE WILL MAKE LST AND RST AND FOR EACH WE WILL MAKE PRE-ORDER AND POST-ORDER
// POST ORDER------
// FOR LST => FROM (POSTSTART) TO (LEFT CHILD INDEX)
// FOR RST => FROM (LEFT CHILD INDEX + 1) TO (POSTEND - 1)
// PRE ORDER-------
// FOR LST => FROM (PRESTART + 1) TO (PRESTART + LEFTSUBTREE ELEMENTS) , LSE = LCI - POSTSTART + 1 
// FOR RST => FROM (PRESTART + LEFTSUBTREE ELEMENTS + 1) TO (PREEND)

// MAIN CONCEPTUAL INTUTION BEHING THIS CODE IS THAT FIRST WE WILL BE AT ROOT NODE OF PREORDER
// FROM THAT WE WILL CONSIDER THE VERY NEXT ELEMENT TO BE LEFT CHILD OF ROOT NODE
// NOW WE WILL SEARCH INDEX OF LEFT CHILD IN POST ORDER VECTOR
// TILL THAT INDEX ALL ELEMENTS WILL BE PRESENT IN THE LST AND LEFT WILL BE IN RST EXCEPT LAST AS IT IS ROOT NODE
// SO FROM POST ORDER VECTOR WE WILL GET NEW POST ORDER VECTOR FOR LST AND RST
// NOW FOR MAKING PRE ORDER FOR RST AND LST FIRST WE WILL BE CALCULATING ELEMENTS IN LST USING POST ORDER VECTOR INDEXES
// AFTER THAT AFTER PRESTART NO. OF ELEMENTS IN LST WILL FORM PREORDER VECTOR FOR LST
// AND LEFT VECTOR OF PREORDER WILL FORM PREORDER VECTOR FOR RST


Node *constructFromPrePostHelper(vector<int> &preorder, int prestart, int preend, vector<int> &postorder, int poststart, int postend, unordered_map<int,int> &postmap){
    if(prestart>preend || poststart>postend) return NULL;
    
    Node *rootNode = new Node(preorder[prestart]);
    
    if(prestart == preend) return rootNode;

    int leftChildVal = preorder[prestart+1];                        // GETTING VALUE OF LEFT CHILD FROM THE PREORDER AS IT OCCURS JUST AFTER ROOT
    int leftChildIndex = postmap[leftChildVal];                     // GETTING INDEX OF LEFT CHILD IN POSTORDER WHICH WILL FURTHER USED
    int leftSubtreeElements = leftChildIndex - poststart + 1;       // NOW FROM THAT LEFTCHILD INDEX WE WILL GET LEFT SUB-TREE ELEMENTS

    rootNode->left = constructFromPrePostHelper(preorder,prestart+1,prestart+leftSubtreeElements,postorder, poststart, leftChildIndex,postmap);
    rootNode->right = constructFromPrePostHelper(preorder,prestart+leftSubtreeElements+1,preend,postorder, leftChildIndex+1, postend-1,postmap);

    return rootNode;
}

Node *buildTree(vector<int> &preorder, vector<int> &postorder){
    unordered_map<int,int> postmap;
    for(int i=0;i<postorder.size();i++) postmap[postorder[i]]=i;
    return constructFromPrePostHelper(preorder,0,preorder.size()-1,postorder,0,postorder.size()-1,postmap);
}

int main(){
    vector<int>preorder = {6,2,1,4,3,5,7,9,8};
    vector<int>postorder = {1,3,5,4,2,8,9,7,6};
    Node* tree = buildTree(preorder,postorder);
    postoder(tree);
    cout<<"\n";
    preoder(tree);
    cout<<"\n";
    inorder(tree);

    return 0;
}