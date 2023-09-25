// MAXIMUM PATH SUM PROBLEM
// GET THE MAXIMUM SUM ALONG ANY PATH
// POSSIBILITIES
// >> ADD RIGHT CHILD ( IF >0) AS RIGHT MAX
// >> ADD LEFT CHILD ( IF >0) AS LEFT MAX
// >> FOR A PARTICULAR NODE CHECK MAXSUM BY ADDING ROOT->DATA + RIGHTMAX + LEFTMAX
// >> AGAIN CHECKING MAXSUM AS MAX(MAXSUM, MAX(LEFTMAX,RIGHTMAX)+ ROOT->DATA)

#include<bits/stdc++.h>
using namespace std;

struct Node{
    public:
    int value;
    Node *right, *left;
    Node(int data){
        value = data;
        left = right = NULL;
    }
};

int maxSumPathHelper(Node*root, int &maxSum){
    if(root == NULL) return 0;
    int leftMaxSum = max(0,maxSumPathHelper(root->left,maxSum));         // MAX SUM OF LST FOR A PARTICULAR NODE
    int rightMaxSum = max(0,maxSumPathHelper(root->right,maxSum));       // MAX SUM OF RST FOR A PARTICULAR NODE
    maxSum = max(maxSum, root->value + leftMaxSum + rightMaxSum);        // CHECKING WHETHER THE RST, ROOT AND LST CAN FORM MAX SUM
    return root->value + max(leftMaxSum, rightMaxSum);                   // THEN AT END RETURNING VALUE FOR MAX SUM OF LST OR RST FOR A PARTICULAR CALL
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(-3);
    root->left->left = new Node(3);
    root->left->right = new Node(2);
    root->right->right = new Node(11);
    root->left->right->right = new Node(1);
    root->left->left->left = new Node(3);
    root->left->left->right = new Node(-2);

    int maxSum = 0;
    cout<<maxSumPathHelper(root,maxSum);
    return 0;
}