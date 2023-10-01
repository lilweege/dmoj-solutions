class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans = 0;
        for (const int& num : nums)
            ans ^= num;
        return ans;
    }
};
static auto speedup = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return nullptr;
}();