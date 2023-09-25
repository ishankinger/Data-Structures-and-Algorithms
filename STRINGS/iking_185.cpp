// FORM THE BIGGEST NUMBER FROM THE NUMERIC STRING

#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

int main(){
     string str= "837593";
   
    sort(str.begin(),str.end(),greater<int>());     // INBUILT FUNCTION TO GET GREATEST INTEGER
    cout<<str<<endl;
    
    // OTHER WAY TO DO THIS

    sort(str.begin(),str.end());
    reverse(str.begin(),str.end());
}
