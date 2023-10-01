class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt[3]{};
        for (int x : nums) ++cnt[x];
        int i = 0;
        for (int x = 0; x < cnt[0]; ++x) nums[i++] = 0;
        for (int x = 0; x < cnt[1]; ++x) nums[i++] = 1;
        for (int x = 0; x < cnt[2]; ++x) nums[i++] = 2;
    }
};