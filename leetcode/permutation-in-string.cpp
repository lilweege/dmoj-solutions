// https://leetcode.com/problems/permutation-in-string

class Solution {
public:
    bool checkInclusion(string n, string h) {
        int N = n.size(), H = h.size();
        if (N > H)
            return false;
        
        vector<int> diff(26);
        for (int i = 0; i < N; ++i) {
            --diff[n[i] - 'a'];
            ++diff[h[i] - 'a'];
        }
        
        for (int i = 0; i < H - N; ++i) {
            bool broke = false;
            for (const int& cnt : diff) {
                if (cnt) {
                    broke = true;
                    break;
                }
            }
            if (!broke)
                return true;
            
            --diff[h[i] - 'a'];
            ++diff[h[i + N] - 'a'];
        }
        bool broke = false;
        for (const int& cnt : diff) {
            if (cnt) {
                broke = true;
                break;
            }
        }
        if (!broke)
            return true;
        return false;
    }
};