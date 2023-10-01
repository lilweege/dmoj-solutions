class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        n *= 2;
        vector<int> result(n);
        int m = n/2;
        for (int i = 0; i < m; ++i) {
            result[i*2] = nums[i];
            result[i*2+1] = nums[m+i];
        }
        return result;
    }
};