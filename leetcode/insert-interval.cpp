class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = int(intervals.size());
        vector<vector<int>> ans;
        ans.reserve(n + 1);
        size_t i = (size_t)(find_if(intervals.begin(), intervals.end(),
            [newInterval](const vector<int>& interval) {
                return interval[1] >= newInterval[0];
            }) - intervals.begin());
        ans.insert(ans.end(), intervals.begin(), intervals.begin() + i);
        
        for (; i < n && intervals[i][0] <= newInterval[1]; ++i) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
        }
        
        ans.push_back(newInterval);
        ans.insert(ans.end(), intervals.begin() + i, intervals.end());
        return ans;
    }
};