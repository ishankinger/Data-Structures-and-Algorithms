// GET THE LARGEST WORD IN THE SENTENCE

#include<iostream>
using namespace std;

int main(){
    int n;                                   // TAKING INPUT OF CHARACTER ARRAY
    cin>>n;
    cin.ignore();
    char arr[n+1];
    cin.getline(arr,n);
    cin.ignore();

    int i=0;                                 // POINTING VARIABLE THAT IS POINTING TOWARDS THE CHARACTER OF THE STRNG
    int curLen=0, maxLen=0;                  // CURLEN STORE LENGTH OF EACH ELEMENT AND MAXLEN STORES MAXLENGTH

    while(1){                                // WHILE THE LOOP TRUES ( SO IN THIS CASE WE HAVE USE BREAK KEYWORD )
        if(arr[i]==' '|| arr[i]=='\0'){      // WORD ENDS WHEN THERE IS ' ' OR FOR THE LAST WORD OF SENTENCE AFTER THAT WE HAVE DEFAUL \0
            if(curLen>maxLen){               // CURLEN WILL BE LENGHT OF WORD BEFORE ' ' AND WE HAVE CHECK IT WITH OTHER MAX STORED LENGHT 
                maxLen=curLen;               // IF IT IS GREATER THEN WE WILL TAKE MAXLEN NEW VALUE
            }
            curLen=0;                        // AND VERY IMPORTANT AND CRITICALLY WE WILL MAKE CURRLEN=0
        }else{                               // IF THERE IS NOT ANY ' ' OR \0 THEN 
        curLen++;                            // WE WILL MAKE OUR CURRLEN TO ++ SO TO CALCULATE THE LENGHT OF THE WORD
        }
        if(arr[i]=='\0'){                    // AT END OF THE SENTENCE WE WILL LEAVE FROM THE SENTENCE
            break;                           // BY USING THE KEYWORD 'BREAK'
        }

        i++;                                 // AFTER CHECKING ALL THE PROCESS FOR ONE CHARACTER WE HAVE TO JUMP TO ANOTHER CHARACTER
    }
    cout<<maxLen;
    return 0;
}