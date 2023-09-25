// // MAXIMUM MEETINGS IN A ROOM

// #include<bits/stdc++.h>
// using namespace std;

// struct duration{
//     int start_time;
//     int finish_time;
// };

// bool cmp(duration d1, duration d2){
//     int diff1 = d1.finish_time-d1.start_time;
//     int diff2 = d2.finish_time-d2.start_time;
//     return diff1<diff2;
// }

// vector<int> maxMeetings(vector<duration>&list_duration){
//     vector<int>ans;
//     sort(list_duration.begin(),list_duration.end(),cmp);
    
//     vector<bool>check(100000,false);
//     for(int i=0;i<list_duration.size();i++){
//         bool valid=true;
//         for(int j=list_duration[i].start_time;j<list_duration[i].finish_time;j++){
//             if(check[j]==false){
//                 check[j]=true;
//             }
//             else{
//                 valid=false;
//                 break;
//             }
//         }
//         if(not valid) continue;
//         else ans.push_back(list_duration[i].start_time);
//     }
//     return ans;
// }

// int main(){
//     int n; cin>>n;
//     vector<duration>list_duration;
//     for(int i=0;i<n;i++){
//         int s,f;
//         cin>>s>>f;
//         duration d;
//         d.start_time=s;
//         d.finish_time=f;
//         list_duration.push_back(d);
//     }
//     vector<int>ans = maxMeetings(list_duration);
//     sort(ans.begin(),ans.end());
//     for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";

//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

struct meeting{
    int start;
    int idx;
    int end;
};

bool cmp(meeting m1, meeting m2){
    return m1.end<m2.end;
}

void print_max_meetings(vector<meeting>&arr){
    sort(arr.begin(),arr.end(),cmp);
    cout<<arr[0].idx<<" ";
    meeting last = arr[0];
    for(int i=1;i<arr.size();i++){
        if(arr[i].start>last.end){
            cout<<arr[i].idx<<" ";
            last = arr[i];
        }
    }

}

int main(){
    int n; cin>>n;
    vector<meeting>arr;
    int i=0;
    while(n--){
        int s,e;
        cin>>s>>e;
        i++;
        meeting m; 
        m.start = s;
        m.end = e;
        m.idx = i;
        arr.push_back(m);
    }
    print_max_meetings(arr);
    return 0;
}