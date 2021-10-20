// https://leetcode.com/problems/minimum-moves-to-convert-string

class Solution {
public:
    int minimumMoves(string s) {
        int n = size(s);
        int x = 0;
        for (int i = 0; i < n; ++i)
            if (s[i] == 'X') {
                ++x;
                i += 2;
            }
        return x;
    }
};