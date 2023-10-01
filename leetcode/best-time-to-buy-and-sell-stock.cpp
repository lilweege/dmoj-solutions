class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int money = 0;
        int curr_min = 1<<30;
        for (int i = 0; i < prices.size(); ++i) {
            curr_min = min(curr_min, prices[i]);
            money = max(money, prices[i] - curr_min);
        }
        return money;
    }
};