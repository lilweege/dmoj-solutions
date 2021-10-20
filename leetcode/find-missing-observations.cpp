// https://leetcode.com/problems/find-missing-observations

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = size(rolls);
        int rollSum = 0;
        for (int x : rolls)
            rollSum += x;
        double rollAvg = double(rollSum) / m;
        int missingSum = (m + n) * mean - rollSum;
        if (missingSum < 0)
            return {};
        vector<int> missing(n, 1);
        missingSum -= n;
        
        if (missingSum < 0)
            return {};
        for (int i = 0; i < n; ++i) {
            if (missingSum == 0)
                break;
            int sub = min(missingSum, 5);
            missing[i] += sub;
            missingSum -= sub;
        }
        if (missingSum != 0)
            return {};
        return missing;
    }
};