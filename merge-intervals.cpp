// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = size(intervals);
        sort(begin(intervals), end(intervals));
        // inner vectors compared same as pairs
        
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for (int i = 1; i < n; ++i) {
            auto& last = result.back();
            auto& cur = intervals[i];
            if (last[1] < cur[0]) {
                result.push_back(cur);
            }
            else {
                last[1] = max(last[1], cur[1]);
            }
        }
        
        return result;
    }
};