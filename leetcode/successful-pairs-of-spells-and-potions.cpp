class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> pairs(n);

        sort(potions.begin(), potions.end());
        for (int i = 0; i < n; ++i) {
            long x = success / spells[i] + (success % spells[i] != 0);
            auto it = lower_bound(potions.begin(), potions.end(), x);
            ptrdiff_t diff = potions.end() - it;
            pairs[i] = diff;
        }
        return pairs;
    }
};