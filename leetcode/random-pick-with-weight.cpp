class Solution {
public:
    vector<int> v;
    Solution(vector<int>& w) {
        for (const int& i : w)
            v.push_back(v.empty() ? i : (i + v.back()));
    }

    int pickIndex() {
        return upper_bound(v.begin(), v.end(), rand() % v.back()) - v.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */