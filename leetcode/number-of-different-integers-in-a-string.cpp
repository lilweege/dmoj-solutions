class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> s;
        bool counting = false;
        int startIdx = 0;
        int n = word.size();
        for (int i = 0; i < n; ++i) {
            char c = word[i];
            if ('0' <= c && c <= '9') {
                if (!counting) {
                    counting = true;
                    startIdx = i;
                }
            }
            else if (counting) {
                counting = false;
                string w = word.substr(startIdx, i-startIdx);
                auto x = w.find_first_not_of("0");
                if (x == string::npos)
                    s.insert("0");
                else
                    s.insert(w.substr(x));
            }
        }
        if (counting) {
            string w = word.substr(startIdx);
            auto x = w.find_first_not_of("0");
            if (x == string::npos)
                s.insert("0");
            else
                s.insert(w.substr(x));
        }
        
        return s.size();
    }
};