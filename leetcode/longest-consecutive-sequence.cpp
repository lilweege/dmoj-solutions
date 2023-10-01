class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        size_t n = v.size();
        
        if (n == 0) return 0;
        sort(v.begin(), v.end());
        int best = 1;
        int streak = 1;
        for (size_t i = 1; i < n; ++i) {
            if (v[i-1] == v[i]-1) {
                ++streak;
            }
            else if (v[i-1] != v[i]) {
                streak = 1;
            }
            best = max(best, streak);
        }
        return best;
        
//         unordered_set<int> nums(n);
//         for (int x : v)
//             nums.insert(x);
//         int best = 0;
//         for (int x : v) {
//             if (nums.find(x-1) != nums.end()) {
//                 // don't start here
//                 // only start at first num
//                 continue;
//             }
//             int num = 1;
//             for (int w = x+1;; ++w) {
//                 if (nums.find(w) == nums.end())
//                     break;
//                 ++num;
//             }
//             best = max(best, num);
//         }
//         return best;
    }
};