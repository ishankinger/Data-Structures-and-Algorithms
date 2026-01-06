// A NUMBER IS K-PRIME IF IT HAS K DISTINCT PRIME NUMBERS IN IT'S PRIME FACTORISATION
// GET THE NUMBER OF K-PRIME NUMBERS BETWEEN GIVEN A AND B

#include <bits/stdc++.h>
#define ll long long
using namespace std;

void factor(vector<int> &c,int n){                      // IN THIS FUNCTION WE ARE CREATING AN ARRAY WHICH TELLS THE PRIME FACTORS FREQUENCY{
    vector<int> factor(n+1,0);
    factor[1]=1;
    for(int i=2;i<=n;i++){
        if(factor[i]==0){
            factor[i]=1;                               // FOR PRIME NUMBERS
            for(int j=2*i;j<=n;j+=i){
                factor[j]=factor[j]+1;                 // ONLY VARIATION IN SIEVE ALGO IS HERE THAT WE ARE NOT CROSSING OUT THE MULTIPLES
            }                                          // RATHER WE ARE INCREMENTED NUMBER OF TIMES THE FACTOR[J] COMES
        }
    }
    c=factor;
}

int main() {
    ios_base::sync_with_stdio(false);                    // FAST INPUT OUTPUT
    cin.tie(NULL); 
    cout.tie(NULL);
    
	int t;
	cin>>t;
    vector<int> all;
    factor(all,100000);
	while(t--)
	{
	    int a,b,k;
	    cin>>a>>b>>k;
        int cnt=0;
	    for(int j=a;j<=b;j++)
        {
            if(all[j]==k)
                cnt++;
        }
        cout<<cnt<<endl;
	}
	return 0;
}