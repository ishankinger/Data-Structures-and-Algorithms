// ******NEXT GREATER ELEMENT PROBLEM******
// IN THIS PROBLEM WE HAVE TO RETURN AN ARRAY GIVING EACH ELEMENT'S NEXT FIRST ELEMENT THAT IS GREATER THAN IT

// SO TO DO THIS QUESTION WE WILL USING STACK DATASTRUCTURE
// THIS IS SO BECAUSE FIRST IF WE ARE GETTING DECREASING CURVE THEN WE WILL KEEP ADDING THE ELEMENTS IN THE STACK
// BUT WHEN WE WILL GET INCREASING CURVE IT MEANS THAT IT MUST BE NEXT ELEMENT FOR THE TOP ELEMENT OF THE STACK
// SO WE NEED REVERSE TYPE OF FUNCTION SO WE ARE USING STACK DATASTRUCTURE HERE
// AND WHEN WE WILL GET INCREASE IN VALUE WE WILL TRAVERSE BACK INTO THE ARRAY AND TRAVERSE TILL WE GET ELEEMNT GREATER THAN IT
// AT THAT POINT WE WILL PUSH THAT ELEMENT AND MOVE FURTHER 
// AT END THE ELEMENTS POSITION LEFT IN THE STACK WILL BE PRINTED AS "-1"

#include<bits/stdc++.h>
using namespace std;

vector<int> nge(vector<int> &arr){                        // FUNCTION FOR NEXT GREATER ELEMENT
    int n=arr.size();
    vector<int>output(n,-1);                              // FIRST CREATING A VECTOR OF ALL FILLED WITH -1
    stack<int>st;                                         // CREATING A STACK TO GET NGE
    st.push(0);
    for(int i=1;i<n;i++){                                 // START TRAVERSING IN THE ARRAY
        while(!st.empty() && arr[i]>arr[st.top()]){       // TILL STACK NOT EMPTY AND IT'S A DECREAING CURVE WE WILL ADD     
            output[st.top()]=arr[i];                      // IF WE GET AN INCREASE THEN WE WILL CHANGE VALUE FROM -1
            st.pop();                                     // AND THAT ELEMENT WILL POP OUT
        }
        st.push(i);                                       // AND WE WILL BE STORING THAT ELEMENT'S INDEX ALWAYS FOR IT'S CHECKING
    }
    return output;
}

// FOR NEXT SMALLER ELEMENT JUST CHANGE THE SIGN OF > TO < AND OTHER ALL THINGS TO BE SAME
// FOR PREV. SMALLER AND PREV. LARGER JUST REVERSE THE GIVEN ARRAY AND OUTPUT IT BY REVRSING

vector<int> pge(vector<int> &arr){
    int n=arr.size();
    reverse(arr.begin(),arr.end());                         // REVERSE THE ARRAY
    vector<int>output(n,-1);
    stack<int>st;
    st.push(0);
    for(int i=1;i<n;i++){
        while(!st.empty() && arr[i]>arr[st.top()]){
            output[st.top()]=arr[i];
            st.pop();
        }
        st.push(i);
    }
    reverse(arr.begin(),arr.end());                       // AGAIN REVERSE TO MAKE IT ORIGINAL
    reverse(output.begin(),output.end());                 // REVERSE OUR OUTPUT ALSO TO GET FINAL ANSWER
    return output;
}
// *******STOCK SPAN PROBLEM******** ( APPLICATION OF ABOVE METHODOLOGY )
// IN THIS WE HAVE TO TELL THE NUMBER OF CONSECUTIVE DAYS BEHIND THE GIVEN DAY STOCK THAT ARE LESS THAN OR EQUAL TO IT.
// SO SIMPLY WE WILL GET POSITION OF PREVIOUS LARGER ELEMENT AND THEN WE WILL SUBTRACT POSITION TO GET CONSECUTIVE DAYS

vector<int> stockSpan(vector<int> &arr){
    int n=arr.size();
    reverse(arr.begin(),arr.end());                        // REVERSING OUR GIVEN ARR TO PLE
    vector<int>output(n,-1);
    stack<int>st;
    st.push(0);
    for(int i=1;i<n;i++){
        while(!st.empty() && arr[i]>arr[st.top()]){        // ALL CONDITIONS SAME AS DONE ABOVE
            output[st.top()]=n-i-1;                        // HERE WE WILL NOT STORE GREATER ELEMENT INSTEAD STORE IT'S INDEX
            st.pop();                                      // WE HAVE REVERSE THE ARR SO REAL IND WILL BE ALSO REVERSED
        }
        st.push(i);
    }
    reverse(output.begin(),output.end());
    reverse(arr.begin(),arr.end());
    return output;
}

int main(){
    vector<int>v={2,1,1,3,4,8,3,2,9,3};
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    cout<<"\n";

    vector<int>result1=nge(v);
    for(int i=0;i<result1.size();i++) cout<<result1[i]<<" ";                   // NEXT GREATER ELEMENT
    cout<<"\n";

    vector<int>result2=pge(v);                                                 // PREVIOUS GREATER ELEMENT
    for(int i=0;i<result2.size();i++) cout<<result2[i]<<" ";
    cout<<"\n";
    
    vector<int>resStockSpan=stockSpan(v);
    for(int i=0;i<resStockSpan.size();i++) cout<<(i-resStockSpan[i])<<" ";     // THIS GIVE US DIFFERENCE IN THE TWO INDICES SO GIVING THE NO. OF 
    return 0;                                                                  // ELEMENTS THAT ARE LARGER THAN IT
}