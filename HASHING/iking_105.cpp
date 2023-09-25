// GIVEN AN ARRAY AND WE HAVE TO TELL THE TOTAL NUMBER OF SUB-ARRAYS SUCH THAT THEIR SUM EQUALS TO ZERO


// SO TO DO THIS QUESTION WE WILL BE USING THE CONCEPT THAT IF WE DO THE PREFIX SUM OF GIVEN ARRAY THEN THE NEW PREFIX SUM ARRAY THAT IS OBTAINED
// WILL TELL US ABOUT THE NUMBER OF SUB-ARRYS. FOR THAT IF WE HAVE REPEATING ELEMENTS IN OUR SUB-ARRAY THEN THAT MEANS THAT THERE WILL BE ONE SUB-
// ARRAY BETWEEN THEM FOR WHICH WE ARE GETTING SUM==0 SO IF WE HAVE N DUPLICATES OF AN ELEMENT THEN TOTAL SUB-ARRAYS WILL BE nC2 AS ONE SUB-ARRAY
// WILL BE CREATED USING TWO ELEMENTS SO WE WILL BE TAKING N DUPLICATES AS A COMBINATION OF TWO NUMBERS PATCHES
// NOW HERE IS ONE EXCEPTIONAL CASE THAT IS 0 AS FOR 0 WE HAVE TO ADD IT'S OWN FREQUENCY ALSO AS WE CAN MAKE SUB-ARRAY OF LENGHT 1 CONTAINING ONLY 0

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int>v(n);
    for(auto &ele:v) cin>>ele;
    map<int,int>m;
    int preSum=0;
    for(int i=0;i<n;i++){
        preSum+=v[i];
        m[preSum]++;
    }
    int ans=0;
    for(auto it=m.begin();it!=m.end();it++){
        if((*it).first==0){
            ans+=(*it).second;
        }
        int c=(*it).second;
        ans+=(c*(c-1))/2;
    }
    cout<<ans<<"\n";
    return 0;
}