// GIVEN A BINARY STRING AND INTEGER K AND WE HAVE TO FIND THE MAXIMUM CONSECUTIVE ONE'S IF WE CAN FLIP AT MOST K ZEROES
// MEANS WE WANT LONGEST SUBSTRING CONTAINING AT MAX K ZEROES
// WHENEVER WE HAVE TO FIND THE LONGEST OR SMALLEST SUB ARRAY OR SUB STRING WE USE THIS SLIDING TECHNIQUE
// USING *****SLIDING WINDOW CONCEPT*****

#include<bits/stdc++.h>
using namespace std;

int longestOnes(string str,int k){                      // FUNCTION TO GET LONGEST ONES AFTER FLIPPING K ZEROES
    int start=0,end=0;                                  // POINTERS TO TRAVERSE IN THE STRING
    int zero_count=0;                                   // VARIABLE TO COUNT NUMBER OF ZEROES
    int max_length=0;                                   // MAX LENGTH STORING VARIABLE(OUR ANS)
    for(;end<str.length();end++){                       // STARTING THE LOOP TILL END POINTER REACHES THE END
        if(str[end]=='0') zero_count++;                 // IF '0' THEN COUNT++
        while(zero_count>k){                            // IF COUNT>K THEN START POINTER WILL MOVE SO THAT WE GET K ZEROES
            if(str[start]=='0') zero_count--;           // IF 0 THEN -- ELSE NOTHING
            start++;                                    // JUST MOVE
        }
        max_length=max(max_length,end-start+1);         // EVERYTIME CHECK MAXLENGTH
    }
    return max_length;
}

int main(){
    string str; cin>>str;
    int k; cin>>k;

    cout<<longestOnes(str,k);
    
    return 0;
}

// ISHAN'S SPECIAL ----

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    int k; cin>>k;
    int numZeroes=0;
    int len=0;
    int j=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0') numZeroes++;
        while(numZeroes>k){
            if(s[j]=='0') numZeroes--,j++;
        }
        if(numZeroes==k) len=max(len,i-j+1);
    }
    cout<<len<<"\n";
    return 0;
}