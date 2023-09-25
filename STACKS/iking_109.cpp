// *******LARGEST RECTANGLE IN A HISTOGRAM*******

// SO TO DO THIS QUESTION APPROACH CAN BE INHERITED FROM THE PREVIOUS APPROACH OF NEXT GREATER TYPE PROBLEMS
// SO WE WILL FIRST CALCULTE NSE AND PSE FOR THE GIVEN ARRAY OF HEIGHTS OF HISTOGRAM
// THEN WE WILL TRAVERSE IN THE ARRAY AND FOR EACH ELEMENT WE WILL CHECK LENGTH OF I-J-1 WHERE I IS FOR NSE AND J IS FOR PSE
// AS THIS WILL GIVE A LENGTH FOR WHICH THE ELEMENT HAVE ELEMENTS GREATER THAN IT AND A PARTICULAR RECTANGLE CAN BE FORMED
// SO TO GET AREA WE WILL USE FORMULA --> (I-J-1)*(HEIGHT OF ITH)

// BUT THE ABOVE APPROA + IS DONE IN TWO TRAVERSAL
// WE CAN SHORTEN THAT BY THINKING THAT ALWAYS TO GET NSE OUR INCREASING CURVE WAIT SO WHENEVER WE GET NSE THAT MEANS FOR THAT ELEMENT THE
// SMALLEST ELEMENT MUST BE JUST PREVIOUS OF IT SO SIMULTANEOUSLY WE GET OUR PSE ALSO SO ONLY ONE TRAVERSAL IS NEEDED

#include<bits/stdc++.h>
using namespace std;

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
    while(not st.empty()){
        int ele=arr[st.top()];
        st.pop();
        int nsi=n;
        int psi=(st.empty()) ? (-1):st.top();
        ans=max(ans,ele*(nsi-psi-1));
    }
    return ans;
}

int main(){
    int n; cin>>n;
    vector<int>v(n);
    for(auto &ele:v) cin>>ele;
    int ans=largestArea(v);
    cout<<ans<<"\n";
    return 0;
}