class NumArray {
    vector<int> lSum;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        lSum.resize(n+1);
        lSum[0] = 0;
        for (int i = 0; i < n; ++i)
            lSum[i+1] = lSum[i] + nums[i];
    }
    
    int sumRange(int left, int right) {
        return lSum[right+1] - lSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */