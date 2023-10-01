class Solution {
public:
    int minDeletions(string s) {
        int ans = 0;
        int cnt[26]{};
        for (char c : s)
            ++cnt[c-'a'];
        // good if all cnt different
        // subtract until all different

        // sort(cnt, cnt+26);
        // for (int i = 25; i > 0; --i) {
        //     int& cur = cnt[i];
        //     if (cnt[i-1] == 0) break;
        //     for (int j = i-1; j >= 0; --j) {
        //         int& nxt = cnt[j];
        //         if (cur == nxt) {
        //             --nxt;
        //             ++ans;
        //         }
        //         else break;
        //     }
        // }
        // return ans;

        unordered_set<int> used;
        for (int i = 0; i < 26; ++i) {
            while (cnt[i] > 0) {
                auto it = used.find(cnt[i]);
                if (it == used.end())
                    break;
                --cnt[i];
                ++ans;
            }
            used.insert(cnt[i]);
        }
        return ans;
    }
};