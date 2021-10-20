// https://leetcode.com/problems/check-if-it-is-a-straight-line

class Solution {
    double getSlope(vector<int> p, vector<int> q) {
        if (p[0] == q[0]) return DBL_MIN;
        return (double)(q[1] - p[1]) / (double)(q[0] - p[0]);
    }
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        if (n <= 2)
            return true;
        
        double referanceSlope = getSlope(coordinates[0], coordinates[1]);
        for (int i = 2; i < n; i++)
            if (getSlope(coordinates[i], coordinates[0]) != referanceSlope)
                return false;
        return true;
    }
};