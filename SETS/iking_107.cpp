// IN AN EXAMINATION IF QUESTION SOLVED THEN P MARKS
// IF WRONG THEN Q MARKS
// IF SKIPPED THEN 0 MARKS
// GIVEN N AS NUMBER OF QUESTION GET ALL THE POSSIBILITIES OF GETTING MARKS 

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int p,q; cin>>p>>q;
    
    unordered_set<int>s;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            int correct=i;
            int incorrect=j;
            int unattempted=n-i-j;
            if(unattempted>=0){
                int score=correct*p +incorrect*q;
                s.insert(score);
            }else{
                break;
            }
        }
    }

    for(auto ele:s) cout<<ele<<" ";
    cout<<"\n";

    return 0;
}