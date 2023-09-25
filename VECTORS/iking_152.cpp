// CHECK ASCENDING ORDER OR NOT

#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>v;                                      // MAKING A VECTOR
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(7);
    v.push_back(5);
    v.push_back(6);
    for(int i=0;i<v.size();i++){                      // PRINTING THE VECTOR
        cout<<v[i]<<" ";
    }
    cout<<endl;
    int i=0;                                         // VARIABLE FOR INITIALISATION IN THE WHILE LOOP
    int k=0;                                         // SAME CONCEPT DONE PREVIOUSLY IN THE ARRAY
    while(i<4){
        if(v[i]<v[i+1]){
            i++;
            k++;
        }else{
            cout<<"array is not in ascending order";
            break;
        }
    }
    if(k==4){
        cout<<"array is in ascending order";
    }

}