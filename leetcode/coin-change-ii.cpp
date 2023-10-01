class Solution {
    int dp[301][5001];
    vector<int> coins;
    int alg(int i, int amount) {
        if (amount == 0)
            return 1;
        if (i == coins.size())
            return 0;
        
        if (dp[i][amount] != -1)
            return dp[i][amount];

        if (coins[i] > amount)
            return dp[i][amount] = alg(i + 1, amount);

        int yes = alg(i, amount - coins[i]);
        int no = alg(i + 1, amount);
        return dp[i][amount] = yes + no;
    }
public:
    int change(int amount, vector<int>& coins_) {
        for (int i = 0; i < 301; ++i)
            for (int j = 0; j < 5001; ++j)
                dp[i][j] = -1;

        coins = move(coins_);
        int a = alg(0, amount);
        return a;
    }
};