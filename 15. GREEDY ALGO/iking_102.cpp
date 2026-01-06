// MAXIMUM MEETINGS IN A ROOM

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