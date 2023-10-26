// ******************* LARGEST RECTANGLE IN A HISTOGRAM *******************

// SO TO DO THIS QUESTION APPROACH CAN BE INHERITED FROM THE PREVIOUS APPROACH OF NEXT GREATER TYPE PROBLEMS
// SO WE WILL FIRST CALCULTE NSE AND PSE FOR THE GIVEN ARRAY OF HEIGHTS OF HISTOGRAM
// THEN WE WILL TRAVERSE IN THE ARRAY AND FOR EACH ELEMENT WE WILL CHECK LENGTH OF I-J-1 WHERE I IS FOR NSE AND J IS FOR PSE
// AS THIS WILL GIVE A LENGTH FOR WHICH THE ELEMENT HAVE ELEMENTS GREATER THAN IT AND A PARTICULAR RECTANGLE CAN BE FORMED
// SO TO GET AREA WE WILL USE FORMULA --> (I-J-1)*(HEIGHT OF ITH)

#include<bits/stdc++.h>
using namespace std;

vector<int> psePos(vector<int> &arr){
    int n = arr.size();
    reverse(arr.begin(),arr.end());
    vector<int> output(n,-1);                               // HERE INITIALISE THE OUTPUT ARRAY TO BE -1
    stack<int> st;                                          // THIS IS SO BECAUSE IF PREVIOUS SMALLER ELEMENT DOESNOT EXIST THEN IT WILL BE
    st.push(0);                                             // SMALLEST AMONG ALL THE PREVIOU ELEMENTS
    for(int i=1;i<n;i++){  
        while(!st.empty() && arr[i]<arr[st.top()]){
            output[st.top()] = n-i-1;                       // ARRAY IS REVERSED SO REAL INDEX WILL ALSO BE REVERSED
            st.pop();
        }
        st.push(i);
    }
    reverse(arr.begin(),arr.end());
    reverse(output.begin(),output.end()); 
    return output;
}

vector<int> nsePos(vector<int> &arr){
    int n = arr.size();
    vector<int> output(n,arr.size());                     // HERE INITIALISE THE OUTPUT ARRAY TO BE ARR.SIZE()
    stack<int> st;                                        // THIS IS SO BECAUSE IF NEXT SMALLER ELEMENT DOESNOT EXIST THEN IT WILL BE SMALLEST 
    st.push(0);                                           // AMONG ALL THE UPCOMING ELEMENTS
    for(int i=1;i<n;i++){
        while(!st.empty() && arr[i]<arr[st.top()]){
            output[st.top()] = i;                         // HERE ARRAY SAME SO REAL INDEX ARE STILL THE SAME
            st.pop();
        }
        st.push(i);
    }
    return output;
}

int largeArea(vector<int> &arr){
    vector<int> v1 = nsePos(arr);
    vector<int> v2 = psePos(arr);
    int ans = INT_MIN;
    for(int i=0;i<arr.size();i++){
        ans = max(ans,(v1[i]-v2[i]-1)*arr[i]);
    }
    return ans;
}

// BUT THE ABOVE APPROACH IS DONE IN TWO TRAVERSAL
// WE CAN SHORTEN THAT BY THINKING THAT ALWAYS TO GET NSE OUR INCREASING CURVE WAIT SO WHENEVER WE GET NSE THAT MEANS FOR THAT ELEMENT THE
// SMALLEST ELEMENT MUST BE JUST PREVIOUS OF IT SO SIMULTANEOUSLY WE GET OUR PSE ALSO SO ONLY ONE TRAVERSAL IS NEEDED

int largestArea(vector<int>&arr){
    int n=arr.size();
    stack<int>st;
    int ans=INT_MIN;
    st.push(0);
    for(int i=0;i<n;i++){
        while(not st.empty() and arr[i]<arr[st.top()]){         // CONDITION FOR NSE

            int ele=arr[st.top()];                              // WE STORE PARTICULAR HEIGHT OF ELEMENT
            st.pop();                                           // POP OUT THE ELEMENT

            int nsi=i;                                          // NEXT SMALLER ELEMNT WILL BE JUST AFTER THE NEXT ELEMENT OF ELE
            int psi=(st.empty()) ? (-1): st.top();              // PSI WILL DEPEND UPON STACK EMPTY OR NOT IF NOT THEN PREV. INDEX WILL BE PRINTED
            ans=max(ans,ele*(nsi-psi-1));
        }
        st.push(i);
    }
    while(not st.empty()){                                      // THIS WHILE LOOP IS FOR THE ELEMENTS WHOSE NEXT SMALLER ELEMENT WILL NOT EXIST
        int ele=arr[st.top()];
        st.pop();
        int nsi=n;
        int psi=(st.empty()) ? (-1):st.top();
        ans=max(ans,ele*(nsi-psi-1));
    }
    return ans;
}

int main(){
    vector<int>v={2,1,1,3,4,8,3,2,9,3};
    int n =10;

    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    cout<<"\n";

    vector<int> v1 = psePos(v);
    for(int i=0;i<n;i++) cout<<v1[i]<<" ";
    cout<<"\n";

    vector<int> v2 = nsePos(v);
    for(int i=0;i<n;i++) cout<<v2[i]<<" ";
    cout<<"\n";

    int ans=largeArea(v);
    cout<<ans<<"\n";

    int ans2 = largestArea(v);
    cout<<ans2<<"\n";

    return 0;
}
