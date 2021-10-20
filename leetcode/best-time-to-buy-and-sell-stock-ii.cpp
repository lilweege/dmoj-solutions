// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestWith = -INT_MAX, bestWout = 0;
        for (int x : prices) {
            bestWith = max(bestWith, bestWout - x);
            bestWout = max(bestWout, bestWith + x);
        }
        return bestWout;
    }
};