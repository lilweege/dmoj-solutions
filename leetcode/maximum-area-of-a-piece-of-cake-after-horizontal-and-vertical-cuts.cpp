// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts

class Solution {
public:
    
    int mod = 1e9 + 7;
    
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.reserve(horizontalCuts.size() + 2);
        verticalCuts.reserve(verticalCuts.size() + 2);
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int largestHorz = 0,
            largestVert = 0;
        for (int i = 1; i < horizontalCuts.size(); ++i)
            largestHorz = max(largestHorz, horizontalCuts[i] - horizontalCuts[i - 1]);
        for (int i = 1; i < verticalCuts.size(); ++i)
            largestVert = max(largestVert, verticalCuts[i] - verticalCuts[i - 1]);
        return (uint64_t(largestHorz) * uint64_t(largestVert)) % mod;
    }
};