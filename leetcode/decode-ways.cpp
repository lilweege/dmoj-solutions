class Solution {
    bool oneOk(char d1) {
        return d1 != '0';
    }
    bool twoOk(char d1, char d2) {
        return d1 == '1' || (d1 == '2' && '0' <= d2 && d2 <= '6');
    }
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return 0;
        
        vector<int> dp(n+1);
        dp[n] = 1;
        
        for(int i = n-1; i >= 0; --i) {
            if (oneOk(s[i])) {
                dp[i] = dp[i+1];
                if (i < n-1 && twoOk(s[i], s[i+1])) {
                    dp[i] += dp[i+2];
                }
            }
        }
        
        return dp[0];
    }
};