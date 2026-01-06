#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
 
struct Point{
    long long x;
    long long y;
};
 
long long getDistance(Point P1, Point P2){
    long long diffx = P1.x - P2.x;
    long long diffy = P1.y - P2.y;
    long long dist = (diffx * diffx) + (diffy * diffy);
    return dist;
}
 
pair<Point, Point> getClosestPairPoints(long long l, long long r, vector<Point> &Points){
    
    if(r - l == 1){
        if(Points[r].y < Points[l].y)
            swap(Points[r], Points[l]);
        return {Points[r], Points[l]};
    }
 
    long long mid = (l + r) / 2;
    long long middleX = Points[mid].x;

    long long minDist = LLONG_MAX;
    pair<Point, Point> ans;
    if(mid - l + 1 >= 2){
        pair<Point, Point> leftClosestPair = getClosestPairPoints(l, mid, Points);
        minDist = min(minDist, getDistance(leftClosestPair.first, leftClosestPair.second));
        ans = leftClosestPair;
    }
 
    if(r - mid >= 2){
        pair<Point, Point> rightClosestPair = getClosestPairPoints(mid+1, r, Points);
        if(getDistance(rightClosestPair.first, rightClosestPair.second) < minDist){
            minDist = getDistance(rightClosestPair.first, rightClosestPair.second);
            ans = rightClosestPair;
        }
    }

    int ptr1 = 0, ptr2 = 0;
    int n = mid - l + 1, m = r - mid;
    vector<Point> c;
    while(ptr1 < n and ptr2 < m){
        if(Points[ptr1 + l].y > Points[ptr2 + mid + 1].y){
            c.push_back(Points[ptr2 + mid + 1]);
            ptr2++;
        }
        else{
            c.push_back(Points[ptr1 + l]);
            ptr1++;
        }
    }
    
    while(ptr1 < n){
        c.push_back(Points[ptr1 + l]);
        ptr1++;
    }
    
    while(ptr2 < m){
        c.push_back(Points[ptr2 + mid + 1]);
        ptr2++;
    }
    
    for(int i = l; i <= r; i++){
        Points[i] = c[i - l];
    }

    vector<Point> subSetPoints;
    for(long long ind = l; ind <= r; ind++){
        long long currX = Points[ind].x;
        if(abs(currX - middleX) * abs(currX - middleX) <= minDist)
            subSetPoints.push_back(Points[ind]);
    }
    
    long long minCrossDist = LLONG_MAX;
    pair<Point, Point> crossPoints;
    long long subsetSize = subSetPoints.size();
    for(long long ind = 0; ind < subsetSize; ind++){
        for(long long ind2 = ind+1; ind2 <= min(ind + 15, subsetSize-1); ind2++){
            long long crossDistance = getDistance(subSetPoints[ind], subSetPoints[ind2]);
            if(crossDistance < minCrossDist){
                minCrossDist = crossDistance;
                crossPoints = {subSetPoints[ind], subSetPoints[ind2]};
            }
        }
    }
    
    if(minCrossDist < minDist)
        return crossPoints;
    
    return ans;
}
 
 
long long getClosestPairDistance(vector<Point> &Points){
    long long n = Points.size();
    if(n <= 1)
        return -1;
 
    sort(Points.begin(), Points.end(), [&](Point &p1, Point &p2){
        return p1.x < p2.x;
    });
 
    pair<Point, Point> Point = getClosestPairPoints(0, n-1, Points);
 
    long long dist = getDistance(Point.first, Point.second);
    return dist;
}
 
int main(){
 
    long long n;
    cin >> n;
 
    vector<Point> Points;
    for(long long i = 0; i < n; i++){
        long long x, y;
        cin >> x >> y;
        Points.push_back({x, y});
    }
 
    long long dist = getClosestPairDistance(Points);
    cout << dist << "\n";
 
    return 0;
}