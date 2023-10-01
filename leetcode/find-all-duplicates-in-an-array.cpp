class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for (int j = 0; j < n; ++j) {
            int i = abs(nums[j])-1;
            if (nums[i] < 0)
                ans.push_back(i+1);
            else
                nums[i] *= -1;
        }
        return ans;
    }
};