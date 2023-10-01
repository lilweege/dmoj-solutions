class Solution {
    int par[26], rnk[26];

    int find(int x) {
        if (x == par[x]) return x;
        return par[x] = find(par[x]);
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (rnk[x] < rnk[y])
                swap(x, y);
            par[y] = x;
            if (rnk[x] == rnk[y])
                ++rnk[x];
        }
    }

public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for (int i = 0; i < 26; ++i) {
            par[i] = i;
            rnk[i] = 0;
        }

        int n = s1.size();
        for (int i = 0; i < n; ++i)
            merge(s1[i]-'a', s2[i]-'a');
        
        int mins[26];
        for (int x = 0; x < 26; ++x)
            for (int y = 0; y < 26; ++y)
                if (find(x) == find(y)) {
                    mins[x] = (char)(y+'a');
                    break;
                }

        for (char& c : baseStr)
            c = mins[c-'a'];
        return baseStr;
    }
};