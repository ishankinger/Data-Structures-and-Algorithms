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

int calcDiameter_Optimised(Node* root, int &height){    // AMPERSANT OPERATOR IS USED SO THAT THE HEIGHT CAN BE MODIFIED EACH TIME IN THE FUNCTION        
    if(root==NULL){                                  
        height=0;
        return 0;
    }

    int lh=0,rh=0;
    
    int lDiameter = calcDiameter_Optimised(root->left,lh);
    int rDiameter = calcDiameter_Optimised(root->right,rh);

    int currDiameter = lh+rh+1;
    
    height = max(lh,rh)+1;

    return max(currDiameter,max(lDiameter,rDiameter));
}

int main(){
    struct Node* root= new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->right=new Node(5);
    root->left->left=new Node(4);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    root->right->right->right = new Node(8);
    int height=0;
    // int *ptrToHeight= &height;
    //cout<<calcDiameter(root)<<"\n";
    cout<<calcDiameter_Optimised(root,height);
    return 0;
}