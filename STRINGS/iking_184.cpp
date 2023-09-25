// CONVERSION OF UPPER CASE AND LOWER CASE

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    cout<<"A"-"a"<<endl;
    string str= "kdfhwphfern";
    for(int i=0;i<str.length();i++){
        if(str[i]>='a' && str[i]<='z'){
            str[i] -=32;
        }
    }
    cout<<str<<endl;

    for(int i=0;i<str.length();i++){
        if(str[i]>='A' && str[i]<='Z'){
            str[i] +=32;
        }
    }
    cout<<str<<endl;
    
    // USING INBUILT STL FUNCTIONS
    // TRANSFORM FUNCTIONS
    string s1= "iohergergh";
    transform(s1.begin(),s1.end(),s1.begin(),::toupper);      // INBUILT FUNCTIONS TO TRANSFORM (BEGINING IDX, ENDING IDX, )
    cout<<s1<<endl;
    transform(s1.begin(),s1.end(),s1.begin(),::tolower);
    cout<<s1<<endl;





    return 0;
}