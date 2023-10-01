class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        // lol
        int n = arr.size();
        vector<int> cnt(int(1e5)+10);
        for (int i = 0; i < n; ++i)
            ++cnt[arr[i]];
            
        int mi = 0;
        int mc = cnt[0];
        for (int i = 1; i < 1e5+10; ++i)
            if (cnt[i] > mc) {
                mc = cnt[i];
                mi = i;
            }
        return mi;
    }
};