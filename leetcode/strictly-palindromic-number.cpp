class Solution {
public:
    bool isStrictlyPalindromic(int n) { return n < 4; }
    bool isStrictlyPalindromic_(int n) {
        vector<int> parts;
        for (int b = 2; b <= n-2; ++b) {
            parts.clear();
            int x = n;
            while (x > 0) {
                parts.push_back(x % b);
                x /= b;
            }
            for (int i = 0; i < parts.size() / 2; ++i)
                if (parts[i] != parts[parts.size()-i-1])
                    return false;
        }
        return true;
    }
};