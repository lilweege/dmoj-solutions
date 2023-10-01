class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for (int i = 1; i < n; ++i) {
            auto& last = result.back();
            auto& curr = intervals[i];
            if (last[1] < curr[0])
                result.push_back(curr);
            else
                last[1] = max(last[1], curr[1]);
        }
        
        return result;
    }
};