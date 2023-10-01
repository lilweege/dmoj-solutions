class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i = 0, j = 0, n = 1;
        for (; j != k; ++n)
            if (i < arr.size() && arr[i] == n)
                ++i;
            else
                ++j;
            
        return n - 1;
    }
};