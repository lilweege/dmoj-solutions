class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            auto it = seen.find(x);
            if (it != seen.end())
                return { it->second, i };
            seen[target - x] = i;
        }
        return {};
    }
};