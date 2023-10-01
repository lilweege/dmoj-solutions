class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1) return nums[0] == target ? 0 : -1;
        int first = nums[0];
        int lo = 0, hi = nums.size()-1;
        while (lo < hi) {
            int mi = (lo + hi) / 2;
            int x = nums[mi];
            if (x >= first) {
                lo = mi + 1;
            }
            else {
                hi = mi;
            }
        }
        int part = lo;
        // cout << "part = " << part;

        if (nums[part] == target) return part;
        if (target >= first) {
            lo = 0, hi = part-1;
        }
        else {
            lo = part, hi = nums.size()-1;
        }

        // if (nums[lo] == target) return lo;
        // if (nums[hi] == target) return hi;
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