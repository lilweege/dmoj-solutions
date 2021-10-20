// https://leetcode.com/problems/get-maximum-in-generated-array

class Solution {
    vector<int> generate(int n)
    {
        vector<int> nums;
        nums.resize(n + 1);
        nums[0] = 0;
        nums[1] = 1;
        
        for (int i = 2; i < n; i += 2)
        {
            nums[i] = nums[i / 2];
            nums[i + 1] = nums[i / 2] + nums[i / 2 + 1];
        }
        return nums;
    }
    
public:
    int getMaximumGenerated(int n) {
        if (n <= 1)
            return n;
        
        vector<int> v = generate(n);
        return *max_element(v.begin(), v.end());
    }
};