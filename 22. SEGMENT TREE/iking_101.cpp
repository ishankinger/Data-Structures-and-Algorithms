// SEGMENT TREE
// AN EFFICIENT DATA STRUCTURE THAT ALLOWS
// EFFICIENT QUERING OF INTERVALS/RANGE
// EFFICIENT UPDATING OF INTERVAL/RANGE

// RANGE QUERIES TO FIND SUM, MIN, MAX ...

// SEGMENT TREE IS BALANCED BINARY TREE
// 2*n NODES IN SEGMENT TREE (APPROX.)

#include <bits/stdc++.h>
using namespace std;

class SegmentTree{
private:
    int n;
    vector<int> arr;
    vector<long long> segTree;

    void buildTree(int ind, int l, int r){
        if(l == r){
            segTree[ind] = arr[l];
            return;
        }

        int mid = (l + r) / 2;
        buildTree(2 * ind + 1, l, mid);
        buildTree(2 * ind + 2, mid + 1, r);

        segTree[ind] = segTree[2 * ind + 1] + segTree[2 * ind + 2];
    }

    void updateTree(int ind, int l, int r, int tar, int newVal){
        if(l == r){
            segTree[ind] = newVal;
            return;
        }

        int mid = (l + r) / 2;
        if(tar <= mid)
            updateTree(2 * ind + 1, l, mid, tar, newVal);
        else
            updateTree(2 * ind + 2, mid + 1, r, tar, newVal);

        segTree[ind] = segTree[2 * ind + 1] + segTree[2 * ind + 2];
    }

    long long getSum(int ind, int l, int r, int start, int end){
        if(l > end || r < start)
            return 0;

        if(l >= start && r <= end)
            return segTree[ind];
        
        
        int mid = (l + r) / 2;
        return getSum(2 * ind + 1, l, mid, start, end) + getSum(2 * ind + 2, mid + 1, r, start, end);
    }

public:
    SegmentTree(){}

    SegmentTree(int n, vector<int> arr){
        this->n = n;
        this->arr = arr;
        segTree.resize(4 * n);
        buildTree(0, 0, n - 1);
    }

    void update(int tar, int newVal){
        arr[tar] = newVal;
        updateTree(0, 0, n - 1, tar, newVal);
    }

    long long rangeSum(int start, int end){
        return getSum(0, 0, n - 1, start, end);
    }

};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    SegmentTree st(n, arr);
    for(int i = 0; i < q; i++){
        int type;
        cin >> type;

        if(type == 1){
            int tar, newVal;
            cin >> tar >> newVal;

            st.update(tar - 1, newVal);
        }
        else{
            int start, end;
            cin >> start >> end;

            cout << st.rangeSum(start - 1, end - 1) << "\n";
        }
    }

    return 0;
}