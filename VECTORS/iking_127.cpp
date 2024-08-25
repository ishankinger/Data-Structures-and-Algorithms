// OPTIMISED APPROACH OF PREVIOUS QUESTION
// BY *************** TWO POINTER METHOD OR SLIDING WINDOW TECHNIQUE *******************

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n; cin>>n;
    vector<int>v(n);
    for(auto &ele:v) cin>>ele;
    int givenSum; cin>>givenSum;

    int sum=0;
    int i=0;                                                            // ALSO CALLED TWO POINTERS AS WE ARE USING TWO POINTERS I AND J 
    int j=0;
    bool check=true;
    for(;i<n;i++){
        sum+=v[i];
        while(sum>givenSum && j<n){                                       // THIS WHILE LOOP IS THE ONLY KEY POINT OF THIS TECHNIQUE
            sum-=v[j];                                                    // THIS LOOP IS KNOWN TO BE SLIDING WINDOW
            j++;
        }
        if(sum==givenSum){
            cout<<"WE GET THE GIVEN SUM FROM "<<j<<" TO "<<i<<"\n";
            check=false;
            break;
        }
    }
    if(check) cout<<"THERE IS NO SUB-ARRAY SUMMING UP TO GIVE OUR REQUIRED GIVEN SUM\n";
    return 0;
}
