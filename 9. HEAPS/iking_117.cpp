// GIVEN AN ARRAY OF CHARACTERS EACH CHARACTER REPRESENTING THE TASK TO BE DONE BY CPU 
// AND WE HAVE TO DO ONE TASK IN ONE UNIT OF TIME OR JUST BE IDLE ( NOT TO PERFORM ANY TAKS )
// HOWEVER THERE IS NON NEGATIVE INTEGER N THAT REPRESENTS THE COOLDOWN PERIOD BETWEEN TWO SAME TASKS
// THAT THERE MUST BE AT LEAST N UNITS OF TIME BETWEEN ANY TWO SAME TASKS
// RETURN THE LEAST UNITS OF TIME CPU WILL TAKE TO FINISH ALL THE GIVEN TASKS

// a=2,b=1 => b-a-*-*a    -> 5 units
// n=2     => a-b-*-a     -> 4 units
// SO MORE FREQUENCY TASK TO EXECUTE FIRST

// IN N+1 UNITS OF TIME EACH CHARACTER WILL OCCUR ONCE

#include<bits/stdc++.h>
using namespace std;

int leastInterval(vector<char> tasks, int n){
    //1. count freq of tasks
    unordered_map<char,int> taskFreq;
    for(auto t:tasks){
        taskFreq[t]++;
    }

    //2. insert freq into max heap
    priority_queue<int>pq;
    for(auto e:taskFreq){
        pq.push(e.second);
    }

    //3. finding time until pq is empty
    int totalTime = 0;
    while(not pq.empty()){
        vector<int> temp;
        for(int i=0;i<=n;i++){
            if(not pq.empty()){
                int freq = pq.top();
                pq.pop();
                if(freq>1){
                    temp.push_back(freq-1);
                }
            }
            totalTime++;
            if(pq.empty() && temp.empty()){
                return totalTime;
            }
        }
        for(auto t:tasks){
            pq.push(t);
        }
    }
    return totalTime;
}

int main(){
    int n; cin>>n;
    vector<char> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int p; cin>>p;

    cout<<leastInterval(v,p)<<"\n";
    return 0;
}