// DIAMETER OF A BINARY TREE => NUMBER OF NODES ( MAXIMUM ) BETWEEN ANY TWO FAR AWAY LEAVES

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


// APPROACH 1 - 
// CALCULATING HEIGHT USING CALCHEIGHT FUNCTION
// TIME COMPLEXITY => O(N^2)

int calcHeight(Node* root){
    if(root==NULL) return 0;
    return max(calcHeight(root->left),calcHeight(root->right))+1; 
}

int calcDiameter(Node* root){                    
    if(root==NULL) return 0;

    int lHeight = calcHeight(root->left);          // FUNCTION TO GET HEIGHT OF ROOT'S LEFT NODE
    int rHeight = calcHeight(root->right);         // THIS FOR RIGHT NODE

    int currDiam = lHeight+rHeight+1;              // THIS IS FOR DIAMETER PASSING THROUGH THE NODE

    int lDiameter = calcDiameter(root->left);      // THIS IS DIAMETER OF NODE'S LEFT RETURNING IT
    int rDiameter = calcDiameter(root->right);     // THIS IS DIAMETER OF NODE'S RIGHT RETURNING IT

    return max(currDiam,max(lDiameter,rDiameter)); // THEN MAX OF ALL THESE WILL BE TAKEN IN REGARD
}



// APPROACH 2 -
// IN THIS WE WILL BE USING POINTERS CONCEPT TO GET HEIGHT
// TIME COMPLEXITY => O(N)
class Solution {
public:
    // Function to find the diameter of a binary tree
    int diameterOfBinaryTree(Node* root) {
        // Initialize the variable to store the diameter of the tree
        int diameter = 0;
        // Call the height function to traverse the tree and calculate diameter
        height(root, diameter);
        // Return the calculated diameter
        return diameter;
    }

private:
    // Function to calculate the height of the tree and update the diameter
    int height(Node* node, int& diameter) {
        // Base case: If the node is null,return 0 indicating the height of an empty tree
        if (!node) {
            return 0;
        }

        // Recursively calculate the height of left and right subtrees
        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);

        // Update the diameter with the maximum of current diameter or sum of left and right heights
        diameter = max(diameter, lh + rh);

        // Return the height of the current node's subtree
        return 1 + max(lh, rh);
    }
};

int main(){
    struct Node* root= new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->right=new Node(5);
    root->left->left=new Node(4);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    root->right->right->right = new Node(8);
    cout<<calcDiameter(root)<<"\n";
    return 0;
}