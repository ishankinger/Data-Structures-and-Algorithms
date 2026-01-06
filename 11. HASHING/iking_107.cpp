// CHECK WHETHER TWO STRINGS ARE ANAGRAME OR NOT
// ANAGRAM MEANS - BOTH THE STRINGS SHOULD HAVE SAME CHARACTER AND SAME FREQUENCY OF EACH CHARACTER

#include<bits/stdc++.h>
using namespace std;

int main(){
    string a,b; cin>>a>>b;
    unordered_map<char,int>m;

    for(int i=0;i<a.size();i++) m[a[i]]++;

    for(int i=0;i<b.size();i++) m[b[i]]++;

    for(auto it=m.begin();it!=m.end();it++){
        if((*it).second%2!=0){
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
    
    return 0;
}