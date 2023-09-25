// INVERSE FOR A MATRIX

#include<bits/stdc++.h>
using namespace std;

int det(vector<vector<int>> matrix){
    int n = matrix.size();
    for(int j=0;j<n;j++){
        
    }
}

vector<vector<int>> inverse_Of_Matrix(vector<vector<int>> matrix){

}

int main(){
    int n; cin>>n;
    vector<vector<int>> matrix(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    
    vector<vector<int>> ans_matrix = inverse_Of_Matrix(matrix);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ans_matrix[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}