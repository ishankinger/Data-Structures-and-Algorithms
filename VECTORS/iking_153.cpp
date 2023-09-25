// DIFFERENCE BETWEEN THE SUM OF ELEMENTS AT EVEN TO SUM OF ELEMENTS AT THE ODD

#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>v;                                           // MAKING A VECTOR
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    for(int i=0;i<v.size();i++){                           // PRINTING THE VECTOR
        cout<<v[i]<<" ";
    }
    cout<<endl;
    
    int sum1=0;                                            // VARIABLE TO GET SUM AT EVEN
    int sum2=0;                                            // VARIABLE TO GET SUM AT ODD
    for(int i=0;i<v.size();i++){                           // TRAVERSING IN THE LOOP
        if(i%2==0){                                        // FOR EVEN PLACE
            sum1 += v[i];                                  // ADD THAT IN SUM1
        }else{                                             // FOR ODD 
            sum2 += v[i];                                  // ADD THAT IN SUM2
        }
    }
    cout<<"difference of sum at even and at odd : "<<sum1-sum2; // GET DIFFERENCE AT THE END
}