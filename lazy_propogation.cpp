// Segment tree Lazy Propogation........
// Handling sum Queries after Update on leetcode ...........

class STTree{
    public:
    vector<int > seg;
    vector<int> lazy;
    STTree(int n){
        seg.resize(4*n, -1);
        lazy.resize(4*n, 0);
    }
 
    void build(int ind, int low,int high, vector<int>& arr){
        if(low == high) {
            if(arr[low] == 1) seg[ind] = 1;
            else seg[ind] = 0; 
            return;
        }
        int mid = low + (high - low)/2;
        build(ind*2 + 1, low, mid, arr);
        build(ind*2 + 2, mid+1, high, arr);
        seg[ind] = seg[ind*2 + 1] + seg[ind*2 + 2];
    }
 
    void update(int ind, int low, int high, int l, int r){
        if(lazy[ind] == 1){
            int ele = high - low + 1;
            seg[ind] = ele - seg[ind];
            lazy[ind] = 0;
            if(low != high){
                lazy[ind*2 + 1] = 1 - lazy[ind*2 + 1];
                lazy[ind*2 + 2] = 1 - lazy[ind*2 + 2];
            }
        }
 
        // l r low high low high l r
        if(r < low || high < l) return;
 
        // l low high r
        if(l <= low && high <= r) {
            int ele = high - low + 1;
            seg[ind] = ele - seg[ind];
            lazy[ind] = 0;
            if(low != high){
                lazy[ind*2 + 1] = 1 - lazy[ind*2 + 1];
                lazy[ind*2 + 2] = 1 - lazy[ind*2 + 2];
            }
            return ;
        }
 
        int mid = low + ( high - low )/2;
        update(ind*2 + 1, low, mid, l, r);
        update(ind*2 + 2, mid+1, high, l, r);
        seg[ind] = seg[ind*2 + 1] + seg[ind*2 + 2];
    }
 
};
