// GIVEN A BINARY TREE AND WE HAVE TO RETURN THE SUM OF THE LARGEST SUB-TREE WHICH IS A BST.
// INTUTION => IF FOR A NODE IT'S LST IS BST AND RST IS ALSO BST AND  MIN_VAL_RST > NODE->VAL > MAX_VAL_LST
// ALSO KEEP CHECK THAT NODE VALUES CAN BE NEGATIVE

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *right,*left;
    Node(int val){
        data = val;
        right = left = NULL;
    }
};

class NodeInfo{
    public: 
    int minValue;
    int maxValue;
    int maxCurrSum;

    NodeInfo(int min, int max, int sum){
        minValue = min;
        maxValue = max;
        maxCurrSum = sum;
    }
};

int ans = 0;

NodeInfo maxSumBSTHelper(Node* root){
    if(not root) return NodeInfo(INT_MAX, INT_MIN,0);
    
    NodeInfo leftsubtree = maxSumBSTHelper(root->left);
    NodeInfo rightsubtree = maxSumBSTHelper(root->right);

    if(root->data > leftsubtree.maxValue && root->data < rightsubtree.minValue){
        ans = max(ans,leftsubtree.maxCurrSum+rightsubtree.maxCurrSum+root->data);

        return NodeInfo(min(leftsubtree.minValue, root->data), 
                        max(rightsubtree.maxValue,root->data),
                        leftsubtree.maxCurrSum+rightsubtree.maxCurrSum+root->data);
    }
    return NodeInfo(INT_MIN,INT_MAX,max(leftsubtree.maxCurrSum,rightsubtree.maxCurrSum));
}

int maxSumBST(Node *root){
    maxSumBSTHelper(root);
    return ans;
}

int main(){
    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(60);
    root->left->left = new Node(5);
    root->left->right = new Node(20);
    root->right->left = new Node(45);
    root->right->right = new Node(75);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

    cout<<maxSumBST(root);

    return 0;
}