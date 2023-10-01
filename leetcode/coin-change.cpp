class Solution {
    // int dp[13][10001];
    // vector<int> coins;
    // int bad(int i, int amount) {
    //     if (amount == 0)
    //         return 0;
    //     if (i == coins.size())
    //         return 1 << 30;
    //     if (dp[i][amount] != -1)
    //         return dp[i][amount];
    //     if (coins[i] > amount)
    //         return dp[i][amount] = bad(i + 1, amount);
    //     int yes = bad(i, amount - coins[i]) + 1;
    //     int no = bad(i + 1, amount);
    //     return dp[i][amount] = min(yes, no);
    // }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        // for (int i = 0; i < 13; ++i)
        //     for (int j = 0; j < 10001; ++j)
        //         dp[i][j] = -1;
        // coins = move(coins_);
        // int a = bad(0, amount);
        // return a >= (1 << 30) ? -1 : a;

        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
        for (int j = 0; j <= amount; ++j)
            dp[0][j] = 1 << 30;
        // sort(begin(coins), end(coins));
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= amount; ++j)
                dp[i][j] = min(
                    dp[i-1][j], // don't take
                    (coins[i-1] > j) ? (1<<30) : // can't take
                        (dp[i][j-coins[i-1]] + 1) // take
                );
        
        int a = dp[n][amount];
        return a >= (1 << 30) ? -1 : a;
    }
};