class SegmentTree {
    int n;
    vector<int> tree;
public:
    void init(int size) {
        n = size;
        tree.resize(size * 4);
    }
    
    void build(const vector<int>& arr) { build(arr, 1, 0, n - 1); }
    void build(const vector<int>& arr, int i, int tl, int tr) {
        if (tl == tr) {
            tree[i] = arr[tl];
        }
        else {
            int tm = (tl + tr) / 2;
            build(arr, i * 2,     tl    , tm);
            build(arr, i * 2 + 1, tm + 1, tr);
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
        }
    }
    
    int query(int l, int r) { return query(1, 0, n - 1, l, r); }
    int query(int i, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (l == tl && r == tr) return tree[i];
        int tm = (tl + tr) / 2;
        return
            query(i * 2    , tl    , tm, l             , min(r, tm)) +
            query(i * 2 + 1, tm + 1, tr, max(l, tm + 1), r         );
    }
    
    void update(int idx, int val) { update(1, 0, n - 1, idx, val); }
    void update(int i, int tl, int tr, int pos, int v) {
        if (tl == tr) {
            tree[i] = v;
        }
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) update(i * 2    , tl    , tm, pos, v);
            else           update(i * 2 + 1, tm + 1, tr, pos, v);
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
        }
    }
};

class NumArray {
    SegmentTree tree;
public:
    NumArray(vector<int>& nums) {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        tree.init(nums.size());
        tree.build(nums);
    }
    
    void update(int index, int val) {
        tree.update(index, val);
    }
    
    int sumRange(int left, int right) {
        return tree.query(left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */