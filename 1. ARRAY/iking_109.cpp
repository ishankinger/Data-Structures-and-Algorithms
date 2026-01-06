// *********** TARGET SUM TRIPLET *******************
// COUNT THE SUM OF TRIPLETS WHOSE SUM IS EQUAL TO THE GIVEN X

#include<iostream>
using namespace std;

int main(){
    int arr[]={0,1,2,3,4,5,6,7};                            // SIMILAR TO PREVIOUS ONLY HERE WE HAVE TO GO IN THREE LOOPS
    int x=7;
    int number=0;
    for(int i=0;i<8;i++){
        for(int j=i+1;j<8;j++){
            for(int k=j+1;k<8;k++){
                if(arr[i]+arr[j]+arr[k]==x){
                    number++;
                }
            }
        }
    }
    cout<<number;
}
