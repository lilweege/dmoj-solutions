class Solution {
    int n;
    string digits;
    vector<string> ans;
    void dfs(string& s, int i=0) {
        if (i == n) {
            ans.push_back(s);
            return;
        }
        char d = digits[i];
        switch (d) {
            case '2':
                s[i] = 'a'; dfs(s, i+1);
                s[i] = 'b'; dfs(s, i+1);
                s[i] = 'c'; dfs(s, i+1);
                break;
            case '3':
                s[i] = 'd'; dfs(s, i+1);
                s[i] = 'e'; dfs(s, i+1);
                s[i] = 'f'; dfs(s, i+1);
                break;
            case '4':
                s[i] = 'g'; dfs(s, i+1);
                s[i] = 'h'; dfs(s, i+1);
                s[i] = 'i'; dfs(s, i+1);
                break;
            case '5':
                s[i] = 'j'; dfs(s, i+1);
                s[i] = 'k'; dfs(s, i+1);
                s[i] = 'l'; dfs(s, i+1);
                break;
            case '6':
                s[i] = 'm'; dfs(s, i+1);
                s[i] = 'n'; dfs(s, i+1);
                s[i] = 'o'; dfs(s, i+1);
                break;
            case '7':
                s[i] = 'p'; dfs(s, i+1);
                s[i] = 'q'; dfs(s, i+1);
                s[i] = 'r'; dfs(s, i+1);
                s[i] = 's'; dfs(s, i+1);
                break;
            case '8':
                s[i] = 't'; dfs(s, i+1);
                s[i] = 'u'; dfs(s, i+1);
                s[i] = 'v'; dfs(s, i+1);
                break;
            case '9':
                s[i] = 'w'; dfs(s, i+1);
                s[i] = 'x'; dfs(s, i+1);
                s[i] = 'y'; dfs(s, i+1);
                s[i] = 'z'; dfs(s, i+1);
                break;
        }
    }
public:
    vector<string> letterCombinations(string digits_) {
        digits = digits_;
        n = digits.size();
        if (n == 0) return {};
        ans.clear();
        string s(n, 'a');
        dfs(s);
        return ans;
    }
};