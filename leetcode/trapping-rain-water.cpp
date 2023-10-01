class Solution {
public:
    int trap(vector<int>& height) {
        int tot = 0;
        int n = height.size();
        vector<int> lm(n), rm(n);
        lm[0] = height[0];
        rm[n-1] = height[n-1];
        for (int i = 1; i < n; ++i)
            lm[i] = max(lm[i-1], height[i]);
        for (int i = n-2; i >= 0; --i)
            rm[i] = max(rm[i+1], height[i]);
        for (int i = 1; i < n-1; ++i) {
            int x = min(lm[i-1], rm[i+1]) - height[i];
            if (x > 0)
                tot += x;
        }

        return tot;
    }
};