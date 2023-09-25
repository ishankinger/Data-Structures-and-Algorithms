// CHECK PALLINDROME( NITIN WORD FROM WHICH THEY ARE MIRROR IMAGES )

#include<iostream>
using namespace std;

int main(){
    char arr[6]="noton";                                    // HERE IF WE DO ARR[5] THEN IT WILL SHOW EROR SO WE HAVE TO DO N+1
    int i=0;
    bool check=true;
    while(i<=4){
        if(arr[i]==arr[4-i]){                              // SO SIMPLY FORM FIRST AND LAST ELEMENTS MOVEMENTS WE WILL CHECK WHETHER 
            i++;                                           // THEY ARE EQUAL OR NOT IF ALL EQUAL THEN IT WILL BE A PALLINDROME
        }else{
            check=false;
            break;
        }
    }
    if(check==true){
        cout<<"given character array is a pallindrome";
    }
    if(check==false){
        cout<<"given character array is not a pallindrome";
    }
}