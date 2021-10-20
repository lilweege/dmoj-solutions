// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = size(height);
        int l = 0, r = n-1;
        int best = 0;
        while (l < r) {
            int idxDiff = r - l;
            int maxHeight = min(height[r], height[l]);
            int area = idxDiff * maxHeight;
            best = max(area, best);
            
            // trick
            if (height[r] > height[l])
                ++l;
            else
                --r;
        }
        // for (int i = 0; i < n; ++i)
        //     for (int j = i+1; j < n; ++j)
        //         best = max(best, min(height[i], height[j]) * (j-i));
        return best;
        
    }
};