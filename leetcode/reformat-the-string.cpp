class Solution {
public:
    string reformat(string s) {
        vector<char> letters;
        vector<char> digits;
        for (char c : s) {
            if ('0' <= c && c <= '9')
                digits.push_back(c);
            else
                letters.push_back(c);
        }
        int diff = letters.size() - digits.size();
        if (diff < -1 || diff > 1)
            return "";
        bool isDig = diff > 0;
        int n = letters.size() + digits.size();
        string b;
        b.resize(n);
        for (int i = 0; i < n; ++i) {
            b[i] = (isDig ? letters : digits)[i/2];
            isDig = !isDig;
        }
        return b;
    }
};