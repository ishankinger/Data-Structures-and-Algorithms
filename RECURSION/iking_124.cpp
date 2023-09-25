// KEYPAD PROBLEM

#include<bits/stdc++.h>
using namespace std;

void f(string &str,int idx,string result,vector<string>&li,vector<string>&v){
    if(idx==str.size()){
        li.push_back(result);
        return;
    }
    int digit=str[idx]-'0';
    for(int j=0;j<v[digit].size();j++){
        f(str,idx+1,result+v[digit][j],li,v);
    }
    return;
}

int main(){
    vector<string>v{"","","ab","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string str="222";
    vector<string>li;
    f(str,0,"",li,v);
    for(int i=0;i<li.size();i++) cout<<li[i]<<"\n ";
    return 0;
}