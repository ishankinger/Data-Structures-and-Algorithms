// ************** EVEN COME FIRST AND THEN ODD INTEGERS *********************
// ( RELATIVE ORDER OF EVEN AND ODD DOESNOT MATTER )

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void sortByParity(vector<int>&v){                       // SIMILAR CONCEPT USED AS DONE BEHIND ONLY CONDTION TO SWITCH THE ELEMENTS IS CHANGED
    int left=0;
    int right=v.size()-1;
    while(left<right){
        if(v[left]%2==1 && v[right]%2==0){
            swap(v[left],v[right]);
            left++;
            right--;
        }
        if(v[left]%2==0){
            left++;
        }
        if(v[right]%2==1){
            right--;
        }
    }
    return;
}

int main(){
     vector<int>v;                                      // MAKING A VECTOR
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    sortByParity(v);
    
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}

