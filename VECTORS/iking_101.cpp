// FIRST DATASTRUCTURE--> ARRAY ( GROUP OF HOMOGENEOUS ITEMS AND STORED IN CONTIGOUS MEMORY)

#include<iostream>
using namespace std;

int main(){                                        // TWO WAYS TO DEFINE AN ARRAY
    int arr[3];                                    // FIRST WAY TO DEFINE AN ARRAY     DATATYPE_NAME[SIZE IS GIVEN];
    arr[0]=1;                                      // ARR[INDEX] FILL THAT PLACE
    arr[1]=2;                                      // ARRAYS ARE ZERO INDEXED
    arr[2]=3;
    for(int i=0;i<3;i++){                          // USE OF FOR LOOP
        cout<<arr[i]<<" ";                         // SO ELEMENTS OF AN ARRAY WILL BE PRINTED
    }
    cout<<"\n";
    
    int array[]={1,2,3,4,5};                       // SECOND WAY TO DEFINE AN ARRAY
    int arr2[5]={1,2,3,4,5};                       // WE CAN DEFINE SIZE IF WE WANT ON OUR OWN WISH 
    cout<<arr2[3]<<" ";

    // RANGE BASED LOOPS
    
    for(int element:array){                        // FOR EACH LOOP : USED TO TRAVERSE IN THE ARRAY
        cout<<element<<" ";                        // DEFINING A NEW VARIABLE OF DATATYPE AS THAT OF THE DATA TYPE OF THE ARRAY
    }
    cout<<"\n";

    cout<<sizeof(arr)<<endl;                       // SIZEOF--> OPERATION TO GET SIZE OF THE ARRAY(IN BYTES)
    cout<<sizeof(array)<<endl;
    cout<<"length of an array : "<<sizeof(array)/sizeof(array[0])<<endl; // GIVE NUMBER OF ELEMENTS IN THE ARRAY

}
