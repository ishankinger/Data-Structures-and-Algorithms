// TO TAKE INPUT FROM USER OF VECTORS

#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int>v;                   // HERE FOR THIS PARTICULAR VECTOR WE HAVE NOT DEFINE THE SIZE INITIALLY
    for(int i=0;i<5;i++) cin>>v[i];
    for(int i=0;i<5;i++) cout<<v[i]<<" ";
    for(int i=0;i<5;i++){           // SO HERE WE CANNOT USE METHOD OF V[INDEX]
        int element;                // ASSUME AN ELEMENT
        cin>>element;               // TAKE INPUT AS MANY TIME AS LOOP MOVES
        v.push_back(element);       // ADD THAT ELEMENT IN THE VECTOR
    }
    vector<int>dynamicArr(5);       // HERE WE HAVE DEFINE THE SIZE OF THE ARRAY
    for(int i=0;i<5;i++){           // SO HERE WE CAN USE THE V[INDEX] METHOD AS FOR TAKING INPUT WE HAVE DEFINE THE SPACE ALREADY
        cin>>v[i];         
    }
    
    for(int ele:v){                 // USE OF 'FOR EACH LOOP' TO PRINT THE ELEMENTS OF THE VECTORS
        cout<<ele<<" ";             
    }
    cout<<endl;
    int i=0;                        // WAY TO PRINT THE VECTOR USING WHILE LOOP
    while(i<dynamicArr.size()){
        cout<<dynamicArr[i]<<" ";
        i++;
    }
}
