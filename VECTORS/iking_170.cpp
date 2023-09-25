// *****TARGET SUM PROBLEM USING TWO POINTER CONCEPT GIVEN ARRAY IS SORTED*****

// GIVEN A SORTED ARRAY AND WE HAVE TO GET TWO ELEMENTS HAVING SUM EQUAL TO K
// ALSO IF NOT SORTED ARRAY THEN WE CAN SORT IT USING O(NLOG(N)) WHICH WILL BE BETTER THEN TWO NESTED LOOPS
// KEEPING OUR MAIN FOCUS TO WRITE AN EFFICIENT CODE FOR A PROBLEM THIS SMALL VARIATION OF SORTING WILL HELP US IN WRITTING 
// CODE IN O(N) INSTEAD OF USING BRUTE FORCE METHOD OF O(N2) (TARGET SUM PAIR)

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int k; cin>>k;
    int pt1=0,pt2=n-1;
    while(pt1<pt2){                               // TWO POINTERS ONE FROM END AND OTHER FROM START 
        int sum=arr[pt1]+arr[pt2];                // GET THEIR SUM
        if(sum==k) break;                         // ACCORDING TO COMPARANCE WITH GIVEN SUM MOVE ONE OF THEM
        else if(sum>k) pt2--;
        else pt1++;
    }
    cout<<arr[pt1]<<" "<<arr[pt2]<<"\n";

// GIVEN A SORTED ARRAY AND WE HAVE TO GET THREE ELEMENTS TO GET SUM EQUAL TO K
// DONE WITH O(N^2) INSTEAD OF USING THREE NESTED LOOPS
   
   int n; cin>>n;
   int arr[n];
   for(int i=0;i<n;i++) cin>>arr[i];
   int k; cin>>k;

   for(int i=0;i<n;i++){
        int sum=k-arr[i];                                  // THREE SUM PROBLEM CONVERTED INTO TWO SUM PROBLEM
        int pt1=i+1,pt2=n-1;                               // SO TIME COMPLEXITY WILL BE O(N^2)
        bool check=false;
        while(pt1<pt2){
            int currSum=arr[pt1]+arr[pt2];
            if(sum==currSum){
                check=true;
                break;
            }
            else if(sum>currSum) pt1++;
            else pt2--;
        }
        if(check){
            cout<<i<<" "<<pt1<<" "<<pt2<<"\n";
            break;
        }
   }















    return 0;
}

