// GIVEN A STRING WE HAVE TO CHECK WHETHER ALL THE ENGLISH ALPHABETS ARE PRESENT OR NOT

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    if(s.size()<26){
        cout<<"NO\n";
        return 0;
    }

    transform(s.begin(),s.end(),s.begin(),::tolower);

    set<char>sChar;
    for(int i=0;i<s.size();i++){
        sChar.insert(s[i]);
    }
    if(sChar.size()==26) cout<<"YES\n";
    else cout<<"NO\n";

    return 0;
}