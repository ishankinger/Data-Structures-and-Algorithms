// ****PREFIX SUM PROBLEM****
// EACH PRECEDING TO BE ADDED WITH ELEMENT ITSELF AT POSITION TO BE FILLED 
// HAVE TO DONE THIS WITHOUT CREATING A NEW ARRAY

#include<iostream>
#include<vector>
using namespace std;

void runningSum(vector<int> &v){                // FUNCTION TO VODIFY VECTOR V
    for(int i=1;i<6;i++){                       // TRAVERSING IN THE LOOP
        v[i]=v[i-1]+v[i];                       // ELEEMT VALUE IS ADDED BY IT'S PREVIOUS ELEMENT
    }
    return;
}

int main(){
    vector<int>v;                               // MAKING A VECTOR
    v.push_back(5);
    v.push_back(4);
    v.push_back(6);
    v.push_back(1);
    v.push_back(9);
    v.push_back(3);

    for(int i=0;i<6;i++){                       // PRINTING OF THE VECTOR
        cout<<v[i]<<" ";
    }
    runningSum(v);                              // MODIFYING THE VECTOR USING THE GIVEN FUCTION
    
    cout<<endl;
    for(int i=0;i<6;i++){                       // NOW PRINTING THE MODIFIED VECTOR V
        cout<<v[i]<<" ";
    }

}