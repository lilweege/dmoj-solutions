class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            int target = -x;
            int j = i+1, k = n-1;
            while (j < k) {
                int y = nums[j], z = nums[k];
                int sum = y + z;
                if (sum == target) {
                    ans.push_back({x, y, z});
                    // skip duplicates
                    while (j < k && nums[j] == y) ++j;
                    while (j < k && nums[k] == z) --k;
                }
                else if (sum > target)
                    --k;
                else ++j;
            }
            while (i < n-1 && nums[i] == nums[i+1]) ++i;
        }
        return ans;
    }
};