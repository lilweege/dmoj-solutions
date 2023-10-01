class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        constexpr unsigned long long primes[] = { 2ULL, 3ULL, 5ULL, 7ULL, 11ULL, 13ULL, 17ULL, 19ULL, 23ULL, 29ULL, 31ULL, 37ULL, 41ULL, 43ULL, 47ULL, 53ULL, 59ULL, 61ULL, 67ULL, 71ULL, 73ULL, 79ULL, 83ULL, 89ULL, 97ULL, 101ULL, 103ULL };
        auto encode = [](const string& s) {
            return accumulate(s.begin(), s.end(), 1ULL, [](unsigned long long x, char c) { return x * primes[c-'a'+1]; });
        };
        int n = strs.size();
        vector<unsigned long long> encoded(n);
        transform(strs.begin(), strs.end(), encoded.begin(), encode);
        // for (unsigned long long x : encoded)
        //     cout << x << '\n';
        
        vector<vector<string>> groups;
        // hash -> index
        unordered_map<unsigned long long, int> m;
        for (int i = 0; i < n; ++i) {
            unsigned long long h = encoded[i];
            int j = groups.size();
            auto it = m.find(h);
            if (it == m.end()) {
                m[h] = j;
                groups.emplace_back();
            }
            else {
                j = it->second;
            }
            groups[j].push_back(strs[i]);
        }
        
        return groups;
    }
};