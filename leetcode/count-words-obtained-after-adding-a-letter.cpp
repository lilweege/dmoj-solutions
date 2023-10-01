class Solution {
    
    int getCount(const string& s) {
        int bs = 0;
        for (char c : s)
            bs |= 1 << (c-'a');
        return bs;
    }
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<int> s;
        for (const string& start : startWords) {
            s.insert(getCount(start));
        }

        int cnt = 0;
        for (const string& target : targetWords) {
            int bs = getCount(target);
            for (int i = 0; i < 26; ++i) {
                if (bs & (1 << i)) {
                    int bs1 = bs ^ (1 << i);
                    if (s.find(bs1) != s.end()) {
                        ++cnt;
                        break;
                    }
                }
            }
        }
        return cnt;
    }
};