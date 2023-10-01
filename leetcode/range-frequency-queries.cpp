class RangeFreqQuery {
    array<vector<int>, 10001> m;
public:
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++i)
            m[arr[i]].push_back(i);
    }
    
    int query(int left, int right, int value) {
        auto& v = m[value];
        auto lo = lower_bound(v.begin(), v.end(), left);
        auto hi = upper_bound(v.begin(), v.end(), right);
        return hi - lo;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */