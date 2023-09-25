// MEDIAN OF A RUNNING STREAM

// INPUT OF NUMBER IS TAKEN AND AFTER EVERY INPUT NUMBER RETURN THE MEDIAN OF THE ARRAY FORMED TILL THAT INPUT
// SO TO THIS QUESTION WE ARE USING PRIORITY QUEUES
// SO FOR THIS QUESTION EACH TIME WHEN WE TAKE ANY INPUT FIRST WE HAVE TO SORT THE WHOLE VECTOR AND THEN TELL THE MEDIAN
// TO MAKE A SORTED ARRAY EACH TIME AFTER INPUT WE WILL MAKE TWO PRIORITY QUEUES ONE AS MIN HEAP AND OTHER AS MAX HEAP
// BOTH THE HEAPS WILL HELP US TO GET THE MEDIAN AFTER EACH INPUT
// SO IF WE TAKE INPUT NOW WE HAVE SOME CASES ARISES
// CASE 1 => IF THEY HAVE SAME SIZES THEN IF ELE IS LOWER THAN MAX HEAP TOP ELEMENT THEN ADDED IN MAX ELSE ADDED IN MIN
// CASE 2 => IF MAX>MIN SIZE THEN IF-
//                                  X>MAX.TOP THEN IT WOULD BE ADDED IN MIN
//                                  X<MAX.TOP THEN REPLACE THAT ELEMENT WITH TOP AND TOP TO ADD IN MIN
// CASE 3 => IF MIN>MAX SIZE THEN IF-
//                                  X<MAX.TOP THEN IT WOULD BE ADDED IN MAX
//                                  X>MAX.TOP THEN REPLACE THAT ELEMENT WITH TOP AND TOP TO ADD IN MAX
// SO FOR EACH CASE MAX DIFF BETWEEN MAX AND MIN SIZE WILL BE 1
// SO THAT EXTRA ONE ELEMENT WILL BE OUR MEDIAN AND IF SIZE EQUAL THEN AVG OF MID ELEMENTS THAT ARE TOP OF BOTH WILL BE MEDIAN
// MAX HEAP WILL CONTAIN ELEMENT IN DESCENDING ORDER AND MIN WILL CONTAIN IN ASCENDING
// SO AFTER EVERY ADDITION WE ARE SIMPLY MAINTAINING SORTED ARRAY AND THUS GET OUR ANSWER IN EACH INPUT

#include<bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>>pqmax;                  // TO DO THIS QUESTION WE WILL MAKE TWO HEAPS ONE MIN HEAP
priority_queue<int,vector<int>,greater<int>>pqmin;     // AND OTHER WILL BE MAX HEAP

void insertEle(int x){                                 // WHEN EVER WE TAKE INPUT WE HAVE TO DECIDE WHERE THIS X TO INSERT MIN OR MAX
    if(pqmax.size()==pqmin.size()){                    // IF BOTH HAVE EQUAL SIZES
        if(pqmax.size()==0){                           // IF BOTH ARE EMPTY THEN 
            pqmax.push(x);                             // PUSH IN ANY SO PQ MAX
            return;
        }
        if(x<pqmax.top()) pqmax.push(x);               // IF ELEMENT IS LESS THAN PQ MAX TOP SO IT WILL BE ADDED IN PQ MAX AS LAST OF THAT WILL BE MIN ELEM
        else pqmin.push(x);                            // ELSE ADD IN PQ MIN AND WILL BE PLACE ACCORDINGLY
    }else{
        if(pqmax.size()>pqmin.size()){                 // IF MAX HEAP HAS MORE SIZE THEN
            if(x>=pqmax.top()) pqmin.push(x);          // IF X IS GREATER THAN PQ MAX TOP THEN INSERT IN MIN HEAP
            else{                                      // ELSE TO MAINTAIN SYMMETERY TO GET MEDIAN WE HAVE TO SHIFT TOP ELEMENT AND THEN INSERT
                int temp=pqmax.top();                  // TOP ELEMENT IS STORED
                pqmax.pop();                           // THEN IT IS POPPED OUT
                pqmin.push(temp);                      // IN MIN HEAP STORED ELEMENT IS PUSHED
                pqmax.push(x);                         // THEN PUSH THAT ELEMENT IN PQ MAX
            }
        }else{                                         // NOW IF SIZE OF MIN HEAP IS GREATER THEN 
            if(x<=pqmin.top()) pqmax.push(x);          // IF X IS LESS THAN MIN TOP MEANS IT WILL NOT CREATE DISTURBANCE TO MEDIAN SO ADDED IN MAX
            else{                                      // ELSE IF GREATER THEN IT WILL BE NEW TOP SO TO DO SO
                int temp=pqmin.top();                  // NOW SIMILAR THING IS DONE AS DONE FOR UPPER CASE
                pqmin.pop();
                pqmax.push(temp);
                pqmin.push(x);
            }
        }
    }
}
double findMedian(){                                    // SIMPLE FUNCTION TO GET MINIMUM
    if(pqmax.size()==pqmin.size()){                     // IF THEY HAVE SAME SIZE THEN AVG OF TWO MID VALUES WILL BE RETURNED FOR MEDIAN
        return (pqmin.top()+pqmax.top())/2.0;
    }else if(pqmax.size()>pqmin.size()){                // IF PQ MAX HAS GREATER SIZE THEN IT'S TOP WILL BE AT MID OF BOTH THE QUEUES  
        return pqmax.top();                             // SO RETURN PQ MAX'S TOP
    }else{
        return pqmax.top();                             // ELSE RETURN PQ MIN'S TOP
    }
}

int main(){
    int n; cin>>n;
    while(n--){
        int x; cin>>x;
        insertEle(x);
        cout<<findMedian()<<"\n";
    }
    return 0;
}