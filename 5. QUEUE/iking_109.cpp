// SLIDING WINDOW MAXIMUM PROBLEM
// GIVEN AN ARRAY AND WE HAVE TO PRINT ALL THE MAX ELE OF SUB-ARRAYS OF ARRAY HAVING SIZE K

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;                                                // INPUT IS TAKEN NUMBER OF ELEMENTS IN GIVEN ARRAY
    vector<int>a(n);                                              // MAKING A VECTOR TO STORE THE ELEMENTS FOR THE ARRAY
    for(auto &ele:a) cin>>ele;                                    // TAKING INPUT FOR ELEMENTS
    int k; cin>>k;                                                // SIZE OF SUB-ARRAY TO CHECK 

    deque<int>q;                                                  // DEFINING A DEQUE TO STORE INDICES OF THE VECTORS                    
    vector<int>ans;                                               // REQUIRED ANS VECTOR TO BE MADE
    for(int i=0;i<k;i++){                                         // GOING IN THE LOOP TILL FIRST K ELEMENTS OF THE ARRAY
        while(!q.empty() && a[q.back()]<a[i]){                    // WE WILL MOVE IN THIS LOOP TILL Q BECOME EMPTY OR WE GET GREATER ELE THAN
            q.pop_back();                                         // OUR CURR ELE AND IF ELE IS GREATER THEN POP LAST ELE SO THAT WE CAN CHECK
        }                                                         // NEXT ELE WHICH WILL THEN BECOME LAST ELEMENT
        q.push_back(i);                                           // WE ARE STORING INDICES OF THE ELEMENT SUCH THAT AT END OF THIS LOOP DEQUES
    }                                                             // FIRST ELEMENT WILL CORRESPOND TO MAX ELEMENT OF THE ARRAY
    ans.push_back(a[q.front()]);                                  // AND WE WILL PUSH-BACK THAT ELEMENT TO OUR ANS VECTOR
    for(int i=k;i<n;i++){                                         // GOING IN LOOP FROM K HERE
        if(q.front()==i-k) q.pop_front();                         // THIS REMOVE THE MAX ELE AS IT'S SIZE OF SUB-ARRAY COMPLETES HERE
        while(!q.empty() && a[q.back()]<a[i]) q.pop_back();       // SIMILAR THING AS DONE ABOVE
        q.push_back(i);                                           // STORING INDICES AGAIN
        ans.push_back(a[q.front()]);                              // PUSH THAT ELEMENT IN ANS ARRAY
    }
    for(auto ele:ans) cout<<ele<<" ";                             // PRINTING OUR ANS ARRAY

    return 0;
}