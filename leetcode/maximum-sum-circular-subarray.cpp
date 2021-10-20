// https://leetcode.com/problems/maximum-sum-circular-subarray

class Solution {
    int kadane(const vector<int>& A) {
        int ans = INT_MIN, lmx = 0;
        for (const int& n : A)
            ans = max(ans, lmx = max(lmx + n, n));
        return ans;
    }
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int ans1 = kadane(A);
        if (!any_of(A.begin(), A.end(), [](const int& n) { return n > 0; }))
            return ans1;
        
        int ans2 = 0;
        for (int& n : A)
            ans2 -= n = -n;
        ans2 += kadane(A);

        return max(ans1, ans2);
    }
};