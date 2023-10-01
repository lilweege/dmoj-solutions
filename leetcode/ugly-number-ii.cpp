class Solution {
public:
    int nthUglyNumber(int n) {
        // Intended solution do be kinda goofy doe
        // using ull = unsigned long long;
        // priority_queue<ull, vector<ull>, greater<ull>> h;
        // unordered_set<ull> m;
        // h.push(1);
        // int x;
        // while (m.size() < n) {
        //     x = h.top(); h.pop();
        //     if (m.find(x) != m.end())
        //         continue;
        //     m.insert(x);
        //     h.push(x * 2ull);
        //     h.push(x * 3ull);
        //     h.push(x * 5ull);
        // }
        // return x;

        vector<int> dp(n, 0);
        dp[0] = 1;
        int i = 0, j = 0, k = 0;
        for (int z = 1; z < n; ++z) {
            dp[z] = min({ dp[i]*2, dp[j]*3, dp[k]*5 });
            if (dp[z] == dp[i]*2) ++i;
            if (dp[z] == dp[j]*3) ++j;
            if (dp[z] == dp[k]*5) ++k;
        }
        
        return dp[n-1];
    }
};