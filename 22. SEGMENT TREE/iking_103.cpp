// SEGMENT TREE LAZY PROPAGATION

#include <bits/stdc++.h>
using namespace std;

class SegmentTree{
private:
    int n;
    vector<int> arr;
    vector<long long> segTree;
    vector<long long> lazyTree;

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

    void updateTree(int ind, int l, int r, int start, int end, int val){
        int mid = (l + r) / 2;

        segTree[ind] += (r - l + 1) * lazyTree[ind];
        if(l != r){
            lazyTree[2 * ind + 1] += lazyTree[ind];
            lazyTree[2 * ind + 2] += lazyTree[ind];
        }
        lazyTree[ind] = 0;
        
        if(l > end || r < start)
            return;

        if(l >= start && r <= end){
            segTree[ind] += (r - l + 1) * 1ll * val;
            if(l != r){
                lazyTree[2 * ind + 1] += val;
                lazyTree[2 * ind + 2] += val;
            }
            return;
        }

        updateTree(2 * ind + 1, l, mid, start, end, val);
        updateTree(2 * ind + 2, mid + 1, r, start, end, val);

        segTree[ind] = segTree[2 * ind + 1] + segTree[2 * ind + 2];
    }

    long long getIndValue(int ind, int l, int r, int tar){
        int mid = (l + r) / 2;

        segTree[ind] += (r - l + 1) * lazyTree[ind];
        if(l != r){
            lazyTree[2 * ind + 1] += lazyTree[ind];
            lazyTree[2 * ind + 2] += lazyTree[ind];
        }
        lazyTree[ind] = 0;

        if(l == r)
            return segTree[ind];

        if(tar <= mid)
            return getIndValue(2 * ind + 1, l, mid, tar);
        else
            return getIndValue(2 * ind + 2, mid + 1, r, tar);
    }

public:
    SegmentTree(){}

    SegmentTree(int n, vector<int> arr){
        this->n = n;
        this->arr = arr;
        segTree.resize(4 * n);
        lazyTree.resize(4 * n, 0);
        buildTree(0, 0, n - 1);
    }

    void rangeUpdate(int start, int end, int val){
        updateTree(0, 0, n - 1, start, end, val);
    }

    long long getValue(int tar){
        return getIndValue(0, 0, n - 1, tar);
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
            int start, end, val;
            cin >> start >> end >> val;

            st.rangeUpdate(start - 1, end - 1, val);
        }
        else{
            int ind;
            cin >> ind;

            cout << st.getValue(ind - 1) << "\n";
        }
    }

    return 0;
}