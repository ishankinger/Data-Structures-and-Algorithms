// ***************** CHECK WHETHER GIVEN TWO STRINGS ARE ISOMORPHIC OR NOT *****************
// ISOMORPHIC MEANS EACH ELEMENT OF THE STRINGS HAVE ONE TO ONE MAPPING

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1,s2; cin>>s1>>s2;
    if(s1.size()!=s2.size()){
        cout<<"no"<<"\n";
        return 0;
    }
    vector<int>v(26,-100);
    bool check=true;
    for(int i=0;i<s1.size();i++){
        if(v[s1[i]-'a']==-100 && v[s2[i]-'a']==-100){
            v[s1[i]-'a']=s1[i]-s2[i];
            v[s2[i]-'a']=s2[i]-s1[i];
        }else if(v[s1[i]-'a']!=-100 && v[s2[i]-'a']!=-100){
            if( v[s1[i]-'a']==s1[i]-s2[i] && v[s2[i]-'a']==s2[i]-s1[i] ) check=true;
            else{
                check=false;
                break;
            }
        }else{
            check=false;
            break;
        }
    }
    if(check) cout<<"yes"<<"\n";
    else cout<<"no"<<"\n";
    return 0;
}
