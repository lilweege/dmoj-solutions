class Solution {
    void addPerms(string& s, vector<string>& out, size_t idx=0) {
        if (idx == s.size()) return;
        char c = s[idx];
        if ('0' <= c && c <= '9') {
            addPerms(s, out, idx+1);
        }
        else {
            addPerms(s, out, idx+1);
            bool isLower = 'a' <= c && c <= 'z';
            s[idx] = c + (isLower ? 1 : -1) * ('A' - 'a');
            out.push_back(s);
            addPerms(s, out, idx+1);
            s[idx] = c;
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        ans.push_back(s);
        addPerms(s, ans);
        return ans;
    }
};