class Solution {
public:
    int missingNumber(vector<int>& nums) {
//         int n = nums.size();
//         for (int i = 0; i < n; ++i) {
//             int x = nums[i];
//             if (x == n)
//                 continue;
//             if (nums[i] != i) {
//                 int t = nums[x];
//                 nums[x] = nums[i];
//                 nums[i] = t;
//                 --i;
//             }
//         }
//         for (int i = 0; i < n; ++i)
//             if (nums[i] == n)
//                 return i;
//         return n;
        
        
//         int n = nums.size();
//         int s = 0;
//         for (int x : nums)
//             s += x;
//         return (n*(n+1))/2 - s;
        
        
        int n = nums.size();
        int a = 0, b = 0;
        for (int i = 0; i < n; ++i) {
            a ^= i+1;
            b ^= nums[i];
        }
        return a ^ b;
    }
};