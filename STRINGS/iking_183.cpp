// SORTING OF STRINGS

#include<iostream>
#include<algorithm>                 // IMPORTANT TO WRITE TO USE THESE TYPES OF FUNCTIONS
#include<string>

using namespace std;

int main(){
    
    string s1="lskfodsghasgh";        // STRING.BEGIN()--> STARTING INDEX OF THE STRING
                                      // STRING.END()--> ENDING INDEX OF THE STRING
    sort(s1.begin(), s1.end());       // SORT IS THE INBUILT FUNCTION FOR STRINGS WHICH SORT THE WORDS ALPHABETICALLY
    cout<<s1<<endl;
}