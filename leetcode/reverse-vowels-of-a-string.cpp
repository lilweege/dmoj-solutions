class Solution {
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    string reverseVowels(string s) {
        int n = s.size();
        for (int i = 0, j = n-1; i < j; ++i, --j) {
            while (!isVowel(s[i]) && i < j) ++i;
            while (!isVowel(s[j]) && i < j) --j;
            swap(s[i], s[j]);
        }
        return s;
    }
};