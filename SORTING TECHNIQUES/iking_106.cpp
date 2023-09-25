// COUNT SORT

// FOR CUMULATIVE FREQUENCY ARRAY THE GIVEN ELEMENT POSITION WILL BE GIVEN BY IT'S VALUE IN THAT AS IT TELL THE ELEMENTS PREVIOUS TO IT

#include<bits/stdc++.h>
using namespace std;

int main(){
    // INPUT IS TAKEN OF OUR ARRAY
    int n; cin>>n;
    vector<int>v(n);
    for(auto &ele:v)
        cin>>ele;

    // GET THE MAX ELEMENT OF THE ARRAY
    int m=INT_MIN;
    for(int i=0;i<n;i++)
        m=max(m,v[i]);

    // MAKE FREQUENCY VECTOR OF SIZE OF MAX ELE+1
    vector<int>vf(m+1,0);

    // ADD FREQUENCY FOR ALL ELEMENTS IN THAT 
    for(int i=0;i<n;i++) 
        vf[v[i]]++;

    // CONVERT THAT INTO PREFIX SUM ARRAY
    for(int i=1;i<=m;i++) 
        vf[i]+=vf[i-1];

    // NOW MAKING OUR ANSWER VECTOR
    vector<int>vans(n);

    // TRAVERSE FROM BACK OF OUR GIVEN VECTOR
    // NOW FILL ELEMENT IN ANS VECTOR BY THE LOGIC OF COUNT SORT
    for(int i=n-1;i>=0;i--) 
        vans[--(vf[v[i]])]=v[i];

    // PRINT THE ANSWER VECTOR
    for(int i=0;i<n;i++) 
        cout<<vans[i]<<" ";

    return 0;
}
// FOR DECIMAL CAN'T DO ANYTHING
// FOR NEGATIVE ADD ABS(MIN) TO ALL THE ELEMENTS AND AT END SUBTRACT IN SORTED SUB-ARRAY
// FOR LARGE NUMBERS WE CANNOT USE THIS AS MEMORY WILL BECOME VERY HIGH

// >>> TIME COMPLEXITY = O( N+ MAXELE)
// >>> SPACE COMPLEXITY = O( MAX(N,MAXELE))
// >>> STABLE SORTING ALGORITHM