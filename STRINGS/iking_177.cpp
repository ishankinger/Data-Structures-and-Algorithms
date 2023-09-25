// ****CHARACTER ARRAYS****( ARRAYS OF CHARACTER )
// char arr[n+1] n+1 for "rahul\0"
// \0==> this is a null character
// AFTER THAT ANYTHING WRITTEN WILL BE NOT PRINTED

#include<bits/stdc++.h>
using namespace std;

int main(){

    // TAKING OUTPUT OF CHARACTER ARRAYS

    char arr[100]="apple keeps doctor \0away";   // INITIALLY MAKING A BIG SPACE IN THE ARRAY SO THAT WE DONOT HAVE TO CHECK ANY N+1
    
    int i=0;                                    // GIVING OUTPUT LIKE THIS AS WE DID EARLIER
    while(arr[i]!=0){
        cout<<arr[i];
        i++;
    }

    // TAKING INPUT OF CHARACTER ARRAY OF A SINGLE WORD

    char array[100];                             // A CHARACTER ARRAY OF LARGE SIZE IS MADE TO GET EASY ACCESS TO WORD WIHTOUT ANY FEAR OF N+1
    cin>>array;                                  // TAKE INPUT SIMPLY THIS DEFAULT GIVE US ACCESS TO WRITE THE WORD ( ONLY SINGLE WORD)
    cout<<array<<endl;                           // NOW THAT WORD WILL BE PRINTED
    cout<<array[2]<<endl;                        // NOW WE CAN WRITE CHARACTER OF OUR GIVEN WORD 
    cout<<array[5]<<endl;                        // IT IS ZERO INDEXED AND SPACES WHICH ARE NOT FILLED ARE " " EMPTY

    // TAKING INPUTS OF FULL LINE
    
    int n;                                       // SO IF WE HAVE TO PUT N CHARACTERS ( " " SPACE IS ALSO INCLUDED IN THE CHARACTER )
    cin>>n;
    cin.ignore();                                // THIS IS USED WHEN WE ARE USING THIS GETLINE FUCNTION

    char arr2[n+1];                              // THEN ARR SHOULD BE MADE OF SIZE N+1 OTHERWISE IT WILL SHOW EROR
                                                 // EXTRA SPACE FOR NULL CHARACTER
    cin.getline(arr2,n);                         // IT WILL GIVE N-1 CHARACTERS AS 1 CHARACTER IS RESERVED FOR \0
    // cin.getline(arr2,n+1) ==> THIS WILL GIVE N ELEMENTS
    // ALSO IN CIN WE CAN WRITE ANY NUMBER OF ELEMENTS BUT PRINTED WILL BE ONLY AS PER N+1 AND IF MORE THEN GARBAGE CHAR IF LESS THEN TILL N 
    cin.ignore();                                 // USED AFTER EVERY CIN INPUT
    for(int i=0;i<n;i++){
        cout<<arr2[i];
    }

    char s1[20]="college",s2[20]="IIT";
    cout<<strlen(s1)<<"\n";                       // GIVE LENGTH OF THE CHARACTER ARRAY
    strcat(s1,s2);                                // APPEND S2 TO S1 AT BACK 
    cout<<s1<<"\n";
    cout<<strlen(s1)<<"\n";
    
    return 0;
}