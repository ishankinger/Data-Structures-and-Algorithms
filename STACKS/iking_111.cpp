// WRITE A FUNCTION TO WRITE MIN ELEMENT IN O(1) SPACE AND TIME COMPLEXITY

// WE WILL BE USING APPROACH OF (ELE-MIN) PUSHING
// MEANS WE WILL MAKE ONE MIN VARIABLE WHICH WILL STORE MINIMUM VALUE OF THE STACK
// AND FOR NEXT ELEMENT WE WILL BE STORING THE (ELE-MIN)=NEW_ELE
// NOW IF THIS NEW ELEMENT IS NEGATIVE MEANS ELE WHICH IS ADDED IS LESS THAN MINIMUM SO MINIMUM WILL BE UPDATED
// AND WHENEVER WE ARE ASKED FOR MINIMUM ELEMENT WE WILL PRINT MIN VARIABLE
// IF WE ARE POPING THE NEGATIVE ELEMENT AT THAT TIME OUR NEW MIN VALUE WILL BE ELE-NEW_ELE AS FROM THE FORMULA THAT IS MIN-THAT ELE
// THUS AFTER EACH POP WE ARE ALSO UPDATING OUR MIN ELEMENT HENCE WE CAN ANS IN O(1) TIME COMPLEXITY

#include<bits/stdc++.h>
using namespace std;

# define ll long long int

class MinStack{
    public:
        stack<ll>st;
        ll mn;

        MinStack(){
            mn=INT_MIN;                // STORING VALUE OF MINIMUM VALUE OF ELEMENT
        }

        void push(int val){
            if(st.empty()){
                mn=val;
                st.push(val);
            }else{
                st.push(val-mn);         // PUSHING OCCURS BY SUBTRACTING MINIMUM FROM EACH ELEMENT
                mn=val;
            }
        }
        
        void pop(){
            if(not st.empty()){
                if(st.top()>=0){          // IF ELEMENT POSITIVE THEN SIMPLY POP
                    st.pop();
                }else{
                    mn=mn-st.top();       // IF ELEMENT NEGATIVE THEN CHANGE MINIMUM TO PREVIOUS MINIMUM WITHOUT IT
                    st.pop();
                }
            }
        }

        int top(){
            if(st.size()==1){
                return st.top();          // IF ONLY ONE ELEMENT THEN IT WILL BE CORRECT
            }else if(st.top()<0){
                return mn;                // IF NEGATIVE MEANS MINIMUM ELEMENT IS STORED SO OUTPUT MIN ELEMENT
            }else{
                return mn+st.top();       // IF ORIGINAL ELEMENT THEN ADD MINIMUM TO IT TO GET ORIGINAL ELEMENT              
            }
        }

        int getMin(){
            return mn;                    // FOR MINIMUM ELEMENT SIMPLY RETURN MN
        }
};