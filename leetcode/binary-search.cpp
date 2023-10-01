class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1;
        while (lo < hi) {
            int mi = (lo + hi) / 2;
            int x = nums[mi];
            if (x < target) {
                lo = mi + 1;
            }
            else {
                hi = mi;
            }
        }
        if (lo >= nums.size() || nums[lo] != target)
            return -1;
        return lo;
    }
};