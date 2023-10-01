class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> seen;
        int n = nums.size();
        int k = n;
        for (int i = 0; i < k; ++i) {
            if (seen.find(nums[i]) != seen.end()) {
                --k;
                swap(nums[i], nums[k]);
                --i;
            }
            else {
                seen.insert(nums[i]);
            }
        }
        sort(nums.begin(), nums.begin()+k);
        return k;
    }
};