// GIVEN AN ARRAY OF INTEGERS OF SIZE N. ANSWER Q QUERIES WHERE YOU NEED TO PRINT THE SUM OF VALUES IN A GIVEN RANGE FO INDICES
// FROM L TO R. THE VALUES OF L AND R IN QUERIES FOLLOW 1 BASED INDEXING
// IF THERE ARE SO MANY QUERIES AND FOR EACH QUERIE WE HAVE TO USE LOOP WHICH WOULDNOT BE A GOOD CHOICE

// *******IMPORTANT CONCEPT OF QUERIES********
// *******CONCEPT OF PRE-COMPUTATION*******
// DOING SUM FROM L TO R FOR EACH QUERY CAN AFFECT THE TIME COMPLEXITY AS QUERIES RANGES TO 10^5 AND N ALSO NEAR TO 10^5
// SO TOTAL TIME COMPLEXITY WILL BE ABOVE 1S WHICH WILL NOT BE EFFICIENT SOLUTION
// SO IN THESE QUERIES TYPE PROBLEMS WE MAKE ONE MODIFIED ARRAY FROM WHICH WE CAN ANSWER EACH OF THE QUERY IN O(1)
// SO FROM THAT TOTAL COMPLEXITY IS STILL O(N) AND LESS THAN 1S
// SIMILAR CASES CAN BE SEEN IN FACTORIAL PROBLEMS WHERE WE PREDEFINED THESE THINGS

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int arrPref[n];
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        arrPref[i]=sum;
    }
    int q; cin>>q;
    for(int i=0;i<q;i++){
        int l,r; cin>>l>>r;
        if(l==2){
            cout<<arr[0]+arr[1]<<"\n";
            continue;
        }
        cout<<arrPref[r-1]-arrPref[l-2]<<"\n";
    }
}