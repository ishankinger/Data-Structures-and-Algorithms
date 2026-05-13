// *************** PASCAL'S TRIANGLE PROBLEM *********************
// ( CAN BE WRITTEN IN THE FORM OF iCj WHERE i=ROWS AND j=COLS )

#include<iostream>
#include<vector>
using namespace std;

int factorial(int n){
    int factorial=1;
    for(int i=n;i>=1;i--){
        factorial *= i;
    }
    return factorial;
}

int element(int i, int j){
    int factorialOfI=factorial(i);
    int factorialOfJ=factorial(j);
    int factorialOfDiff=factorial(i-j);
    int denominator=factorialOfJ*factorialOfDiff;
    int numerator=factorialOfI;
    return numerator/denominator;
}

int main(){
    for(int i=0;i<=6;i++){
        for(int j=1;j<=7-i;j++){
            cout<<" ";
        }
        for(int j=0;j<=i;j++){
            cout<<element(i,j)<<" ";
        }
        cout<<endl;
    }
    
    // ANOTHER APPROACH OF THE ABOVE QUESTION( ELE[I][J]= ELE[I-1][J]+ELE[I-1])[J-1] )
    
    return 0;
}
  


// *********** WITHOUT USING FACTORIAL DIRECT WAY TO DO *************
vector<int> generateRow(int row) {
        long long ans = 1;
        vector<int> ansRow;

        //inserting the 1st element
        ansRow.push_back(1); 

        //calculate the rest of the elements:
        for (int col = 1; col < row; col++) {
            ans = ans * (row - col);
            ans = ans / col;
            ansRow.push_back(ans);
        }
        return ansRow;
    }
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>> ans;
        //store the entire pascal's triangle:
        for (int row = 1; row <= n; row++) {
            ans.push_back(generateRow(row));
        }
        return ans;
    }

