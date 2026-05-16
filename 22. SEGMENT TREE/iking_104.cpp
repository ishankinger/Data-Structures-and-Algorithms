// SEGMENT TREE WITH BINARY SEARCH
// GIVEN QUERIES (a,b) TELL ME THE LEFTMOST ELEMENT IN THE RIGHT RANGE WHICH IS > ARR[a] && > ARR[b]

#include <bits/stdc++.h>
using namespace std;

class SegmentTree{
private:
    int n;
    vector<int> arr;
    vector<int> segTree;

    void buildTree(int ind, int l, int r){
        if(l == r){
            segTree[ind] = l;
            return;
        }

        int mid = (l + r) / 2;
        buildTree(2 * ind + 1, l, mid);
        buildTree(2 * ind + 2, mid + 1, r);
        
        if(arr[segTree[2 * ind + 1]] > arr[segTree[2 * ind + 2]])
            segTree[ind] = segTree[2 * ind + 1];
        else
            segTree[ind] = segTree[2 * ind + 2];
    }

    int getMaxEleInd(int ind, int l, int r, int start, int end){
        if(l > end || r < start)
            return -1;
        
        if(l >= start && r <= end)
            return segTree[ind];

        int mid = (l + r) / 2;
        int leftMaxEleInd = getMaxEleInd(2 * ind + 1, l, mid, start, end);
        int rightMaxEleInd = getMaxEleInd(2 * ind + 2, mid + 1, r, start, end);

        if(leftMaxEleInd == -1)
            return rightMaxEleInd;
        else if(rightMaxEleInd == -1)
            return leftMaxEleInd;
        else if(arr[leftMaxEleInd] > arr[rightMaxEleInd])
            return leftMaxEleInd;
        else
            return rightMaxEleInd;
    }

public:
    SegmentTree(){}

    SegmentTree(int n, vector<int> arr){
        this->n = n;
        this->arr = arr;
        segTree.resize(4 * n);
        buildTree(0, 0, n - 1);
    }

    int getLeftMostMaxToRight(int start, int end){
        int low = end + 1, high = n - 1;
        int mid, ans = -1;
        while(low <= high){
            mid = (low + high) / 2;
            int maxEleInd = getMaxEleInd(0, 0, n - 1, end + 1, mid);
            if(arr[maxEleInd] > arr[start] && arr[maxEleInd] > arr[end])
                high = mid - 1, ans = maxEleInd;
            else
                low = mid + 1;
        }
        return ans;
    }

};

int main(){

    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    SegmentTree st(n, arr);

    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;

        cout << st.getLeftMostMaxToRight(a, b) << "\n";
    }
}