class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        for (int x : nums)
            if (++cnt[x] > n/2)
                return x;
        return 0;
    }
};