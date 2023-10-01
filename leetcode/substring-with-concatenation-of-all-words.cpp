class Solution {
    using ll = long long;
    static constexpr ll BASE = 31, MOD = 1e9+9;
    ll POW;
    void rollHash(ll& hash, char cNew, char cOld) {
        hash -= (POW * (cOld-'a'+1)) % MOD;
        if (hash < 0) hash += MOD;
        rollHash(hash, cNew);
    }
    void rollHash(ll& hash, char cNew) {
        hash = (hash * BASE + (cNew-'a'+1)) % MOD;
    }
    
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n = words.size();
        int N = s.size();
        if (n > N) return ans;
        int M = words[0].size();

        POW = 1;
        for (int i = 1; i < M; ++i)
            POW = (POW * BASE) % MOD;

        vector<int> expect(n);
        // hash -> idx0
        unordered_map<ll, int> m;
        for (int i = 0; i < n; ++i) {
            ll hash = 0;
            for (int j = 0; j < M; ++j)
                rollHash(hash, words[i][j]);
            if (m.find(hash) != m.end()) {
                ++expect[m.find(hash)->second];
            }
            else {
                m.emplace(hash, i);
                expect[i] = 1;
            }
        }

        vector<ll> hashes(N/M);
        for (int i = 0; i+M <= N; i += M) {
            for (int j = i; j < i+M; ++j) {
                rollHash(hashes[i/M], s[j]);
            }
        }

        for (int o = 0; o < M; ++o) {
            int nWords = (N-M-o)/M+1;
            if (nWords < n) break;
            
            // char idx, word idx
            queue<pair<int, int>> indices;
            vector<int> cnt(n);
            int cntcnt = 0;
            for (int i = o; i+M <= N; i += M) {
                if (!indices.empty() && indices.front().first == i-M*n) {
                    --cntcnt;
                    --cnt[indices.front().second];
                    indices.pop();
                }
                auto it = m.find(hashes[i/M]);
                if (it != m.end()) {
                    indices.emplace(i, it->second);
                    ++cntcnt;
                    ++cnt[it->second];
                    if (cntcnt == n && cnt == expect) {
                        if (i+M-M*n <= N-M*n)
                        ans.push_back(i+M-M*n);
                    }
                }
            }
            
            for (int i = M+o; i < N; i += M) {
                rollHash(hashes[i/M-1], s[i], s[i-M]);
            }
        }
        
        return ans;
    }
};