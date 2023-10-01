class Solution {
    // vector<string> slow(string& s) {
    //     vector<string> ans;
    //     const size_t windowSize = 10;
    //     size_t n = s.size();
    //     if (n < windowSize)
    //         return ans;
    //     unordered_map<string, int> substrCount;
    //     for (size_t i = 0; i <= n-windowSize; ++i)
    //         substrCount[s.substr(i, windowSize)]++;
    //     for (const auto& [substr, cnt] : substrCount)
    //         if (cnt > 1)
    //             ans.push_back(substr);
    //     return ans;
    // }
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        const size_t windowSize = 10;
        size_t n = s.size();
        if (n < windowSize)
            return ans;
        
        auto charIdx = [](char c) {
            switch (c) {
                case 'A': return 0;
                case 'C': return 1;
                case 'G': return 2;
                case 'T': return 3;
                default: assert(0);
            }
        };
        
        long hash = 0;
        const int BASE = 7;
        const int POW = pow(BASE, windowSize);
        auto rollHash = [&hash, BASE, POW](char cNew, char cOld = -1) {
            hash = hash * BASE + cNew;
            if (cOld != -1) {
                hash -= POW * cOld;
            }
        };

        // <hash, count>
        unordered_map<long, int> cnt;
        for (int i = 0; i < windowSize; ++i) {
            rollHash(charIdx(s[i]));
        }
        
        cnt[hash]++;
        for (int i = windowSize; i < n; ++i) {
            rollHash(charIdx(s[i]), charIdx(s[i-windowSize]));
            if (++cnt[hash] == 2) {
                ans.push_back(s.substr(i-windowSize+1, windowSize));
            }
        }
        
        return ans;
    }
};