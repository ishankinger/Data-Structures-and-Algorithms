// BALANCED HEIGHT TREE => MAX(LEFT HEIGHT, RIGHT HEIGHT) <= 1

#include<iostream>
using namespace std;

struct Node{                                       // BINARY TREE'S NODE STORE ONE VALUE AND HAVE TWO POINTERS POINTING TO IT'S TWO CHILDREN
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
// USING CALC_HEIGHT FUNCTION TO GET HEIGHT
// TIME COMPLEXITY => O(N^2)

int calcHeight(Node* root){                             
    if(root==NULL) return 0;
    return max(calcHeight(root->left),calcHeight(root->right))+1; 
}

bool checkBalanceTree(struct Node*root){               
    if(root==NULL) return true;

    if(checkBalanceTree(root->left)==false){            // IF ANY ONE ROOT WILL RETURN FALSE THEN TILL END WE WILL GET OUR ANS TO BE FALSE
        return false;
    }
    if(checkBalanceTree(root->right)==false){
        return false;
    }

    int lh=calcHeight(root->left);                      // CALCULATE LH AND RH FOR NODE THEN CHECK CONDITION ON IT
    int rh=calcHeight(root->right);
    if(abs(lh-rh)<=1) return true;                      // IF CONDITION SATISFY THEN TRUE ELSE FALSE
    else return false;
}


// APPROACH 2 -
// OPTIMISED USING POINTER CONCEPT
// TIME COMPLEXITY => O(N)

bool checkBalance_Opt(struct Node*root,int &height){        // USING AMPERSANT OPERATOR FOR HEIGHT        
    if(root==NULL) return true;
 
    int lh=0,rh=0;

    if(checkBalance_Opt(root->left,lh)==false){
        return false;
    }
    if(checkBalance_Opt(root->right,rh)==false){
        return false;
    }

    height=max(lh,rh)+1;                             // HERE WE ARE SIMUTANEOUSLY CALCULATING THE LH AND RH TO GET HEIGHT OF TREE

    if(abs(lh-rh)<=1) return true;                    // THEN CHECKING THE CONDITION ON ONE TRAVERSAL
    else return false;
}

int main(){
    struct Node* root= new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->left->left=new Node(5);


    if(checkBalanceTree(root)) cout<<"Balanced\n";
    else cout<<"Unbalanced\n";

    int height=0;
    if(checkBalance_Opt(root,height)) cout<<"Balanced\n";
    else cout<<"Unbalanced\n";

    return 0;
}