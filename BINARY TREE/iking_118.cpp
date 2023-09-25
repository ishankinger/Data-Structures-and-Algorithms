// PATH SUM PROBLEM
// GIVEN A BINARY TREE AND A TARGET SUM VALUE
// WE HAVE TO TELL THE TOTAL NUMBER OF PATHS WHOSE VALUES ADD TO TARGET VALUE
// GIVEN THAT PATH CAN START FROM ANY NODE AND MUST GO DOWNWARDS

// THE MAIN CONCEPT WE WILL BE USING IS OF PREFIX SUM AND STORING PRFIX SUM IN A MAP
// IF CURR PREFIX SUM - TARGET SUM IS ALREADY PRESENT IN THE MAP THEN IT MEANS THAT THERE IS ONE PATH POSSIBLE TO GET TARGET SUM
// HERE WE ARE USING MAP AS TO GET FREQUENCY OF A PARTICULAR PREFIX SUM
// AS IF THERE ARE TWO  SAME VALUES OF PREFIX SUM THEN WE WILL ADD TWO TO THE ANSCOUNT
// ALSO WHILE BACKTRACKING WE HAVE TO DO -- THE FREQUECY AS WE ARE CHANGING THE PATH OF OUR TRAVERSAL AND CURRSUM

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


int pathSumHelper(Node*root, int targetSum, int currSum, unordered_map<int,int>&pathCount){
    if(root == NULL) return 0;

    currSum += root->value;                                                     // INTIALY VALUE OF CURR NODE IS ADDED
    int ansCount = pathCount[currSum-targetSum];                                // IF PRESET THEN FREQUENCY ADDED ELSE 0 ADDED

    pathCount[currSum]++;                                                       // CURR SUM FREQUENCY TO BE INCREASED

    ansCount += pathSumHelper(root->left, targetSum, currSum, pathCount) +      // USING RECURSION TO TRAVERSE IN THE BINARY TREE
                pathSumHelper(root->right, targetSum, currSum, pathCount);

    pathCount[currSum]--;                                                       // WHILE BACKTRACKING WE HAVE TO DECREMENT THE FREQ BY 1

    return ansCount;
}
int pathSum(Node*root, int targetSum){
    unordered_map<int,int> pathCount;                                           // UNORDERED MAP WITH CURR SUM AS KEY AND IT' FREQ AS VALUE
    pathCount[0]=1;                                                             // INITALLY CURR SUM = 0 AND IT'S FREQ = 1
    return pathSumHelper(root, targetSum, 0, pathCount);
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

    cout<<pathSum(root,8);

    return 0;
}