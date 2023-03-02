// segment tree to find minimum element in a given range..

class SGTree{
public:
    vector<int> seg;
    SGTree(int n){
        seg.resize(4* n + 1, 0);
    }

    void Build(int ind, int low, int high, vector<int> arr){
        if(low == high) {
            seg[ind] = arr[low];
            return;
        }
        int mid = low + (high - low)/2;
        Build(ind*2 + 1, low, mid, arr);
        Build(ind*2 + 2, mid + 1, high, arr);
        seg[ind] = min(seg[ind*2+1], seg[ind*2 + 2]);
    }

    int query(int ind, int low, int high, int l, int r){
        // low high l r,  l r low high
        if(high < l || r < low) return INT_MAX;

        if(l <= low && r >= high) return seg[ind];
        int mid = low + (high - low)/2;
        int left = query(ind*2 +1, low, mid, l, r);
        int right = query(ind* 2 + 2, mid + 1, high, l, r);
        // cout << left << " " << right << endl;
        return min(left, right);
    }

    void update(int ind,int low, int high, int i, int val){
        if(low == high){
            seg[ind] = val;
            return;
        }

        int mid = low + (high - low)/2;
        if(i <= mid) update(ind*2 + 1, low, mid, i, val);
        else update(ind*2 + 2, mid + 1, high, i, val);
        seg[ind] = min(seg[ind*2+1], seg[ind*2 + 2]);
    }
};
