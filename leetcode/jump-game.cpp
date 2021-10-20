// https://leetcode.com/problems/jump-game

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int end = nums.size() - 1;
        for (int i = end; i >= 0; i--)
            if (end <= i + nums[i])
                end = i;
        return end == 0;
    }
};