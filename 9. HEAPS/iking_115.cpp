// YOU ARE GIVEN A SET OF POINTS IN A XY PLANE. YOU NEED TO FIND THE KTH CLOSEST POINTS TO THE ORIGIN USING
// MANHATTAN DISTANCES => SUM OF DISTANCES BETWEEN DIFF OF X AND Y COORDINATES
// SO OUR DISTANCE = X-0 + Y-0
// SO WE WANT THIS VALUE TO BE MINIMUM
// IT IS GUARANTEED THAT NO TWO POINTS WILL HAVE THS SAME DISTANCE FROM THE ORIGIN

#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> kthClosestPoints(vector<pair<int,int>> pts,int n, int k){
    priority_queue<pair<int,pair<int,int>>> pq;
    for(auto &pt: pts){
        int distance  = pt.first + pt.second;
        pq.push(make_pair(distance,pt));
        if(pq.size() > k){
            pq.pop();
        }
    }
    vector<pair<int,int>> ans(k);
    while(not pq.empty()){
        ans[pq.size()-1] = pq.top().second;
        pq.pop();
    }
    return ans;
}

int main(){
    int n,k; 
    cin>>n>>k;
    vector<pair<int,int>> pts(n);
    for(auto &pt : pts){
        cin>>pt.first>>pt.second;
    }
    pts = kthClosestPoints(pts,n,k);
    for(auto &pt : pts){
        cout<<pt.first<<" "<< pt.second<<"\n";
    }
    return 0;
}