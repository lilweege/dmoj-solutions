class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for (const auto& word : wordDict)
            dict.insert(word);
        
        int n = s.size();
        bool dp[301]{};
        dp[0] = true;
        for (int i = 1; i <= n; ++i)
            for (int j = i-1; j >= 0; --j)
                if (dp[j] && dict.find(s.substr(j, i-j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
        // cout << s << '\n';
        // for (int i = 1; i <= n; ++i)
        //     cout << (dp[i] ? '*' : ' ');
        return dp[n];
    }
};