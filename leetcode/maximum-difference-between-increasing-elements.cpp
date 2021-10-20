// https://leetcode.com/problems/maximum-difference-between-increasing-elements

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = size(nums);
        int best = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                int diff = nums[j] - nums[i];
                if (diff > 0)
                    best = max(best, diff);
            }
        }
        return best;
    }
};