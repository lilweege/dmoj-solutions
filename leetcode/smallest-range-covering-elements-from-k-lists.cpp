class Solution {
    vector<vector<int>> nums;
    using pi = tuple<int, int, int>;
    struct cmp {
        const vector<vector<int>>& aa;
        cmp(const vector<vector<int>>& nums_) : aa(nums_) {}
        bool operator()(const pi& a, const pi& b) {
            if (get<0>(a) != get<0>(b)) return get<0>(a) > get<0>(b);
            return aa[get<1>(a)][get<2>(a)] > aa[get<1>(b)][get<2>(b)];
        }
    };
public:
    vector<int> smallestRange(vector<vector<int>>& nums_) {
        nums = move(nums_);
        int k = nums.size();
        typedef priority_queue<pi, vector<pi>, cmp> pq_t;
        cmp cc(nums);
        pq_t pq(cc);
        int d = 0;
        for (int i = 0; i < k; ++i) {
            pq.emplace(nums[i][0], i, 0);
            d = max(d, nums[i][0]);
        }
        
        int a = -(1<<29), b = 1<<29;
        while (!pq.empty()) {
            auto [c, i, j] = pq.top(); pq.pop();
            if (b - a > d - c)
                a = c, b = d;
            auto& v = nums[i];
            if (j+1 >= v.size())
                break;
            pq.emplace(v[j+1], i, j+1);
            d = max(d, v[j+1]);
        }
        return { a, b };
    }
};