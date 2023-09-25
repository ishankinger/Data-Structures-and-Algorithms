// *******SUB-ARRAYS******* ( HAVE TO TELL THAT WHETHER THAT THERE EXIST TWO SUB ARRAYS SO THAT THERE SUM WILL BE EQUAL)
// SUB ARRAYS SHOULD BE PREFIX AND SUFFIX TYPE ( MEANS NOT JUMBLING OF SUB ARRAYS IT SHOULD BE ORDERWISE )

#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>v;                                // PREFIX SUM= SUM( A0, A1, A2,........, AI)
    v.push_back(3);                              // SUFFIX SUM= SUM( AI+1, AI+2,......, AN-1)
    v.push_back(3);                              // TOTAL SUM= PREFIX SUM + SUFFIX SUM
    v.push_back(3);                              // SO, SUFFIX SUM= TOTAL SUM - PREFIX SUM
    v.push_back(5);
    v.push_back(3);
    v.push_back(1);
    for(int i=0;i<6;i++){                        // SIMPLY PRINTING THE VECTOR
        cout<<v[i]<<" ";
    }
    cout<<endl;
    int totalSum=0;                              // VARIABLE TO STORE TOTAL SUM OF THE VECTOR'S ELEMENTS
    for(int i=0;i<6;i++){                        // TRAVERSE IN LOOP AND ADD ALL ELEMENTS
        totalSum += v[i];
    }
    int i=0;                                     // TO INITIALISATION IN WHILE LOOP
    int prefixSum=0;                             // VARIABLE TO STORE SUM OF PREFIX
    while(i<6){                                  // STARTING IN THE LOOP
        prefixSum += v[i];                       // PREFIX SUM IS ADDED
        if(prefixSum==0.5*totalSum){             // CONDITION FOR EQUALITY OF SUM OF TWO SUB-ARRAYS
            cout<<"there exists two sub arrays for required condition"<<endl;
            cout<<"first subarray till "<< i<< " index"<<" and other after that";
            break;
        }else{
            i++;
        }
    }
    if(i==6){
        cout<<"there doesnot exist any sub arrays satisfying the required condition ";
    }

    // SOME THEORY ON SUB ARRAYS AND SUB SEQUENCES
    // SUB ARRAYS --> CONTINUOUS PART OF ARRAY ( TOTAL SUB ARRAYS ARE N(N+1)/2 )
    // SUB SEQUENCES --> NOT CONTINUOUS BUT ORDER SHOULD BE SAME ( TOTAL SUB SEQUENCES ARE 2 RAISE TO POWER N )
    // EVERY SUB SEQUENCE IS A SUB ARRAY BUT EVERY SUB ARRAY IS NOT SUB SEQUENCE
}