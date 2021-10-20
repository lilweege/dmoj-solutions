// https://leetcode.com/problems/two-city-scheduling

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        auto comp = [](const vector<int>& a, const vector<int>& b) {
            return (a[0] - a[1] < b[0] - b[1]);
        };
        sort(costs.begin(), costs.end(), comp);
        
        int cost = 0;
        for (int i = 0, n = costs.size() / 2; i < n; ++i)
            cost += costs[i][0] + costs[i + n][1];
        return cost;
    }
};