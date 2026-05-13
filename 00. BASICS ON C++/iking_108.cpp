// SWITCH STATEMENTS

#include<iostream>
using namespace std;

int main(){
    int day;
    cin>>day;

    switch(day){
        case 1:
        cout<<"day is monday";
        break;                                            // BREAK STATEMENT SHOULD BE WRITTEN 
        case 2:                                           // IF BREAK STATEMENT NOT WRITTEN THEN IT WILL JUMP TO VERY NEXT CASE
        cout<<"day is tuesday";
        break;
        case 3:
        cout<<"day is wednesday";
        break;
        default:                                          // VALUES OTHER THAN CASES ABOVE WILL HAVE DEFAULT CODE
        cout<<"put any number";                           // IF NO CASE WORKS THEN THIS WILL AUTOMATICALLY WORKS
    }
    return 0;
}