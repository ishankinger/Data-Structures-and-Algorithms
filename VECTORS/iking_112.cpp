// ************** BETTER WAY TO DO LAST QUESTION *****************
// ( ONLY TWO TRAVERSALS TO BE DONE )

#include<iostream>
using namespace std;

int main(){
    int arr[]={2,3,6,9,5,9,4};                           // GIVEN ARRAY
    int max=arr[0];                                      // VARIABLE TO GET MAXIMUM VALUE ELEMENT
    for(int i=0;i<7;i++){                                // FIRST TRAVERSAL IN THE ARRAY
        if(arr[i]>max){                                  // AS DONE PREVIOUSLY
            max=arr[i];
        }
    }
    int secMax=arr[0];                                   // NOW DEFINING NEW VARIABLE GIVING OUR REQUIRED SECOND LARGEST ELEMENT
    for(int i=0;i<7;i++){                                // SECOND TRAVERSAL
        if(arr[i]>secMax && arr[i]!=max){                // SO NOW GIVEN ELEMENT SHOULD NOT BE EQUAL TO MAX AND ALSO GREATER THAN SECMAX
            secMax=arr[i];                               // SO VALUE CAN BE CHANGED
        }
    }
    cout<<secMax<<endl;                                  // PRINTING OF SECOND MAXIMUM VALUE WILL OCCUR

}
