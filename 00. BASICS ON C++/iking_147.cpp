// FIRST AND LAST OCCURENCE OF A CHARACTER OF A STRING

#include<iostream>
using namespace std;

void findFirstAndLast(string s,int*first,int*last,char ch){
    for(int i=0;i<s.size();i++){
        if(s[i]==ch){
            *first=i;
            break;
        }
    }
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]==ch){
            *last=i;
            break;
        }
    }
}

int main(){
    string s="aabaac";
    char ch='a';
    int first=-1;
    int last=-1;
    int *pf=&first;
    int *pl=&last;

    findFirstAndLast(s,pf,pl,ch);
    cout<<*pf<<endl;
    cout<<*pl<<endl;
    return 0;
}