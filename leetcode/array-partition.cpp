class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int m = nums.size();
        sort(nums.begin(), nums.end());
        int x = 0;
        for (int i = 0; i < m; i += 2)
            x += nums[i];
        return x;
    }
};