class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        // lol
        nums1.insert(nums1.begin() + m, nums2.begin(), nums2.end());
        nums1.erase(nums1.end() - n, nums1.end());
        sort(nums1.begin(), nums1.end());
    }
};