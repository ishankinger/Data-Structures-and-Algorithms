// SEGMENT TREE MIN RANGE QUERIES

#include <bits/stdc++.h>
using namespace std;

class SegmentTree{
private:
    int n;
    vector<int> arr;
    vector<int> segTree;

    void buildTree(int ind, int l, int r){
        if(l == r){
            segTree[ind] = arr[l];
            return;
        }

        int mid = (l + r) / 2;
        buildTree(2 * ind + 1, l, mid);
        buildTree(2 * ind + 2, mid + 1, r);

        segTree[ind] = min(segTree[2 * ind + 1], segTree[2 * ind + 2]);
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

        segTree[ind] = min(segTree[2 * ind + 1], segTree[2 * ind + 2]);
    }

    int getMin(int ind, int l, int r, int start, int end){
        if(l > end || r < start)
            return 1e9 + 1;

        if(l >= start && r <= end)
            return segTree[ind];
        
        
        int mid = (l + r) / 2;
        return min(getMin(2 * ind + 1, l, mid, start, end), getMin(2 * ind + 2, mid + 1, r, start, end));
    }

public:
    SegmentTree(){}

    SegmentTree(int n, vector<int> arr){
        this->n = n;
        this->arr = arr;
        segTree.resize(4 * n, 1e9 + 1);
        buildTree(0, 0, n - 1);
    }

    void update(int tar, int newVal){
        arr[tar] = newVal;
        updateTree(0, 0, n - 1, tar, newVal);
    }

    int rangeMin(int start, int end){
        return getMin(0, 0, n - 1, start, end);
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

            cout << st.rangeMin(start - 1, end - 1) << "\n";
        }
    }

    return 0;
}