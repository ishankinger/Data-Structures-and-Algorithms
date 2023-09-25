// GETTING SQUARE ROOT OF A GIVEN NUMBER

#include<iostream>
using namespace std;

int main(){
    int n; cin>>n;
    int low=1;
    int high=n;
    int ans=0;
    while(low<=high){
        int mid=(low+high)/2;
        if(n<mid*mid){                      // IF IT IS LESS THAN SQUARE OF NUMBER THEN WE WILL CHECK LESS VALUES PART
            high=mid-1;
        }
        else if(n>mid*mid){                // IF IT IS GREATER THAN SQUARE OF NUMBER THEN WE WILL CHECK MORE VALUE PART AND 
            low=mid+1;                     // STORE THE ANS AS IT MAY BE POSSIBLE THAT IT IS NOT A PERFECT SQUARE AND NEXT TIME LOW > HIGH
            ans=mid;
        }
        else{
            ans=mid;
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}