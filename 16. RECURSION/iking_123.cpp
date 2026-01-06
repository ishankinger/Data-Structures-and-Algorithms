// SUB SEQUENCES OF A STRING

#include<iostream>
#include<vector>
using namespace std;

void f(string &str, int i, string result, vector<string>&li){
    if(i==str.length()){
        li.push_back(result);
        return;
    }
    f(str,i+1,result+str[i],li);
    f(str,i+1,result,li);
}
int main(){
    vector<string>result;
    string str="abcd";
    f(str,0,"",result);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}