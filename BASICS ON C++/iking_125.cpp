// BUTTERFLY PATTERN

#include<bits/stdc++.h>
using namespace std;

int main(){
    for(int i=1;i<=5;i++){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        for(int j=1;j<=10-2*i;j++){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=5;i>=1;i--){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        for(int j=1;j<=10-2*i;j++){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    cout<<"\n";

    // HOLLOW BUTTERFLY PATTERN

    for(int i=1;i<=5;i++){
        for(int j=1;j<=i;j++){
            if(j==1 ||j==i) cout<<"*";
            else cout<<" ";
        }
        for(int j=1;j<=10-2*i;j++){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            if(j==1 ||j==i) cout<<"*";
            else cout<<" ";
        }
        cout<<endl;
    }
    for(int i=5;i>=1;i--){
        for(int j=1;j<=i;j++){
            if(j==1 ||j==i) cout<<"*";
            else cout<<" ";
        }
        for(int j=1;j<=10-2*i;j++){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            if(j==1 ||j==i) cout<<"*";
            else cout<<" ";
        }
        cout<<endl;
    }
    return 0;

    return 0;
}