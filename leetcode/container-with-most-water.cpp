class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int lo = 0, hi = n-1;
        int best = 0;
        while (lo < hi) {
            int w = hi - lo;
            int h = min(height[lo], height[hi]);
            best = max(best, w*h);
            if (height[lo] < height[hi])
                ++lo;
            else --hi;
        }
        return best;
    }
};