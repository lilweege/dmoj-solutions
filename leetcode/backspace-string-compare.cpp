// https://leetcode.com/problems/backspace-string-compare

class Solution {
    string simulate(string s) {
        vector<char> sb;
        sb.reserve(s.length());
        for (char c : s) {
            if (c == '#') {
                if (!sb.empty()) {
                    sb.pop_back();
                }
            }
            else {
                sb.push_back(c);
            }
        }
        return string(sb.begin(), sb.end());
    }
public:
    bool backspaceCompare(string S, string T) {
        return simulate(S) == simulate(T);
    }
};