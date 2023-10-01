class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int k = n;
        for (int i = 0; i < k; ++i) {
            if (nums[i] == val) {
                --k;
                swap(nums[i], nums[k]);
                --i;
            }
        }
        return k;
    }
};