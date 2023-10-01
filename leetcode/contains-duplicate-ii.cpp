class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            auto it = m.find(x);
            if (it != m.end()) {
                int j = it->second;
                if (abs(i - j) <= k) {
                    return true;
                }
            }
            m[x] = i;
        }
        return false;
    }
};