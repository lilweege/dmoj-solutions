// https://leetcode.com/problems/move-zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), zeroes = 0, j = 0;
        for (int i = 0; i < n; i++, j = i) {
            if (nums[i] == 0) {
                while (j < n && nums[j] == 0)
                    j++;
                if (j < n)
                    swap(nums[i], nums[j]);
            }
        }
    }

};