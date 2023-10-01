class Solution {
public:
    bool checkValidString(string s) {
        int l = 0, w = 0;
        for (char& c : s) {
            w += (c == ')' ? -1 : 1);
            l += (c == '(' ? 1 : -1);
            l = max(l, 0);
            if (w < 0) return false;
        }
        return l == 0;
    }
};