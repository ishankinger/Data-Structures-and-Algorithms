// DIVISORS USING SEIVE ALGO
// TIME COMPLEXITY => O(N.LOG(N))

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=1e5+10;
    vector<int>divisors[n];                       // VECTOR OF ARRAYS IS DEFINED ( FOR Ith ARRAY IT WILL GIVE US ALL PRIME FACTORS FOR I)
    for(int i=2;i<n;i++){
        for(int j=i;j<n;j+=i){                    // EACH TIME WE WILL MOVE I BY SO
            divisors[j].push_back(i);             // SO IT'S LIKE TABLE OF I IS PUSHED
        }
    }
    int k; cin>>k;
    cout<<"Divisors of this number are -\n";
    for(int i=0;i<divisors[k].size();i++){
        cout<<divisors[k][i]<<" ";
    }
    return 0;
}