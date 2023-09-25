// GIVEN AN ARRAY OF STRINGS WE HAVE TO TELL THE LONGEST COMMON PREFIX IN ALL THE STRINGS

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<string>v(n);
    for(auto &ele:v) cin>>ele;
    string ans="";

    // BRUTE FORCE METHOD

    int minsize=INT_MAX;
    for(int i=0;i<n;i++){
        int size=v[i].size();
        minsize=min(minsize,size);
    }
    for(int j=0;j<minsize;j++){
        bool check=true;
        int c=v[0][j];
        for(int i=1;i<n;i++){
            if(c==v[i][j]) check=true;
            else{
                check=false;
                break;
            }
        }
        if(check) ans+=c;
        else break;
    }
    if(ans.empty()) cout<<"NO COMMON PREFIX"<<"\n";
    else cout<<ans<<"\n";

    // SECOND METHOD : FIRST DO SORTING OF THE STRINGS AND THEN COMPARE LAST AND FIRST ELEMENTS COMMON PART
    
    string ans1="";
    sort(v.begin(),v.end());
    for(int i=0;i<min(v[0].size(),v[n-1].size());i++){
        if(v[0][i]==v[n-1][i]) ans1+=v[0][i];
        else break;
    }
    if(ans1.empty()) cout<<"NO COMMON PREFIX"<<"\n";
    else cout<<ans1<<"\n";

    // THIRD METHOD : START COMPARING FIRST STRING WITH ALL THE STRINGS IN THE VECTOR AND GET THE LOWEST COMMON STRING AS THE ANSWER
    
    int minlength;
    string s=v[0];
    for(int i=1;i<n;i++){
        int length=0;
        for(int j=0;j<s.size();j++){
            if(v[i][j]==s[j]) length++;
        }
        minlength=min(length,minlength);
    }
    string ans2="";
    if(minlength==0) cout<<"NO COMMON PREFIX"<<"\n";
    else {
        for(int i=0;i<minlength;i++) ans2+=s[i];
    }
    cout<<ans2<<"\n";

    return 0;
}