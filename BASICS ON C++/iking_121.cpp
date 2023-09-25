// PYRAMID PATTERN

#include<bits/stdc++.h>
using namespace std;

int main(){
    for(int i=1;i<=7;i++){
        for(int j=1;j<=7-i;j++){
            cout<<" ";
        }
        for(int j=1;j<=2*i-1;j++){
            cout<<"*";
        }
        cout<<endl;
    }

    // HOLLOW PYRAMID PATTERN 

    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        for(int j=1;j<=n-i;j++){
            cout<<" ";
        }
        for(int j=1;j<=2*i-1;j++){
            if(j==1 || j==2*i-1){
                cout<<"*";
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    for(int i=1;i<=2*n-1;i++){
        cout<<"*";
    }
    cout<<"\n";
    
    // DIAMOND PATTERN

    for(int i=1;i<=5;i++){
        for(int j=1;j<=5-i;j++){
            cout<<" ";
        }
        for(int j=1;j<=2*i-1;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=5;i>=1;i--){
        for(int j=1;j<=5-i;j++){
            cout<<" ";
        }
        for(int j=1;j<=2*i-1;j++){
            cout<<"*";
        }
        cout<<endl;
    }

}